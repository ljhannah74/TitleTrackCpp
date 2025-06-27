#include "TitleAbstractDAL.h"
#include <iostream>
#include <sqlite3.h>

TitleAbstractDAL::TitleAbstractDAL() = default;
TitleAbstractDAL::~TitleAbstractDAL() {
    db.close();
}

bool TitleAbstractDAL::connect(const std::string& dbPath) {
    return db.open(dbPath);
}

bool TitleAbstractDAL::createTable() {
const std::string sql = R"sql(
        CREATE TABLE IF NOT EXISTS TitleAbstracts (
            TitleAbstractID INTEGER PRIMARY KEY AUTOINCREMENT,
            OrderNo TEXT NOT NULL,
            OrderDate TEXT,
            SearchDate TEXT,
            EffectiveDate TEXT,
            PropertyAddress TEXT,
            ProductType TEXT,
            Client TEXT,
            ClientRefNo TEXT
        );
    )sql";
    return db.execute(sql);
}

std::optional<int> TitleAbstractDAL::addAbstract(const TitleAbstract& a) {
 const std::string sql = R"sql(
        INSERT INTO TitleAbstracts
        (OrderNo, OrderDate, SearchDate, EffectiveDate, PropertyAddress, ProductType, Client, ClientRefNo)
        VALUES (?, ?, ?, ?, ?, ?, ?, ?);
    )sql";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db.getHandle(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return std::nullopt;

    sqlite3_bind_text(stmt, 1, a.OrderNo.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, a.OrderDate.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, a.SearchDate.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, a.EffectiveDate.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, a.PropertyAddress.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, a.ProductType.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, a.Client.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, a.ClientRefNo.c_str(), -1, SQLITE_STATIC);

    if (sqlite3_step(stmt) != SQLITE_DONE) {
        sqlite3_finalize(stmt);
        return std::nullopt;
    }

    int id = static_cast<int>(sqlite3_last_insert_rowid(db.getHandle()));
    sqlite3_finalize(stmt);
    return id;
}

std::vector<TitleAbstract> TitleAbstractDAL::getAllAbstracts() {
    std::vector<TitleAbstract> result;
    const std::string sql = "SELECT * FROM TitleAbstracts;";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db.getHandle(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return result;

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        TitleAbstract a;
        a.TitleAbstractID   = sqlite3_column_int(stmt, 0);
        a.OrderNo           = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        a.OrderDate         = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        a.SearchDate        = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        a.EffectiveDate     = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        a.PropertyAddress   = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        a.ProductType       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        a.Client            = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        a.ClientRefNo       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        result.push_back(a);
    }

    sqlite3_finalize(stmt);
    return result;
}

std::optional<TitleAbstract> TitleAbstractDAL::getAbstractById(int id) {
    const std::string sql = "SELECT * FROM TitleAbstracts WHERE TitleAbstractID = ? LIMIT 1;";
    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db.getHandle(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return std::nullopt;

    sqlite3_bind_int(stmt, 1, id);

    TitleAbstract a;
    if (sqlite3_step(stmt) == SQLITE_ROW) {
        a.TitleAbstractID   = sqlite3_column_int(stmt, 0);
        a.OrderNo           = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        a.OrderDate         = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        a.SearchDate        = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        a.EffectiveDate     = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        a.PropertyAddress   = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        a.ProductType       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        a.Client            = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        a.ClientRefNo       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        sqlite3_finalize(stmt);
        return a;
    }

    sqlite3_finalize(stmt);
    return std::nullopt;
}

bool TitleAbstractDAL::updateAbstract(const TitleAbstract& a) {
    const std::string sql = R"sql(
        UPDATE TitleAbstracts
        SET OrderNo = ?, OrderDate = ?, SearchDate = ?, EffectiveDate = ?,
            PropertyAddress = ?, ProductType = ?, Client = ?, ClientRefNo = ?
        WHERE TitleAbstractID = ?;
    )sql";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db.getHandle(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_text(stmt, 1, a.OrderNo.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 2, a.OrderDate.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 3, a.SearchDate.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 4, a.EffectiveDate.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 5, a.PropertyAddress.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 6, a.ProductType.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 7, a.Client.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_text(stmt, 8, a.ClientRefNo.c_str(), -1, SQLITE_STATIC);
    sqlite3_bind_int(stmt, 9, a.TitleAbstractID);

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc == SQLITE_DONE;
}

bool TitleAbstractDAL::deleteAbstract(int id) {
    const std::string sql = "DELETE FROM TitleAbstracts WHERE TitleAbstractID = ?;";
    sqlite3_stmt* stmt = nullptr;

    if (sqlite3_prepare_v2(db.getHandle(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return false;

    sqlite3_bind_int(stmt, 1, id);

    int rc = sqlite3_step(stmt);
    sqlite3_finalize(stmt);
    return rc == SQLITE_DONE;
}

std::vector<TitleAbstract> TitleAbstractDAL::getAbstractsByOrderNo(const std::string& orderNoPattern) {
    std::vector<TitleAbstract> results;
    const std::string sql = "SELECT * FROM TitleAbstracts WHERE OrderNo LIKE ?;";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db.getHandle(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return results;

    std::string pattern = "%" + orderNoPattern + "%";
    sqlite3_bind_text(stmt, 1, pattern.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        TitleAbstract a;
        a.TitleAbstractID   = sqlite3_column_int(stmt, 0);
        a.OrderNo           = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        a.OrderDate         = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        a.SearchDate        = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        a.EffectiveDate     = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        a.PropertyAddress   = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        a.ProductType       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        a.Client            = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        a.ClientRefNo       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        results.push_back(a);
    }

    sqlite3_finalize(stmt);
    return results;
}

std::vector<TitleAbstract> TitleAbstractDAL::getAbstractsByClient(const std::string& clientPattern) {
    std::vector<TitleAbstract> results;
    const std::string sql = "SELECT * FROM TitleAbstracts WHERE Client LIKE ?;";

    sqlite3_stmt* stmt = nullptr;
    if (sqlite3_prepare_v2(db.getHandle(), sql.c_str(), -1, &stmt, nullptr) != SQLITE_OK)
        return results;

    std::string pattern = "%" + clientPattern + "%";
    sqlite3_bind_text(stmt, 1, pattern.c_str(), -1, SQLITE_STATIC);

    while (sqlite3_step(stmt) == SQLITE_ROW) {
        TitleAbstract a;
        a.TitleAbstractID   = sqlite3_column_int(stmt, 0);
        a.OrderNo           = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 1));
        a.OrderDate         = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
        a.SearchDate        = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 3));
        a.EffectiveDate     = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
        a.PropertyAddress   = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 5));
        a.ProductType       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 6));
        a.Client            = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 7));
        a.ClientRefNo       = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 8));
        results.push_back(a);
    }

    sqlite3_finalize(stmt);
    return results;
}
