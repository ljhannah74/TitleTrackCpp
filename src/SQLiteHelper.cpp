#include "SQLiteHelper.h"

SQLiteHelper::SQLiteHelper() : db(nullptr) {}

SQLiteHelper::~SQLiteHelper() {
    close();
}

bool SQLiteHelper::open(const std::string& dbPath) {
    int rc = sqlite3_open(dbPath.c_str(), &db);
    if (rc != SQLITE_OK) {
        lastError = sqlite3_errmsg(db);
        close();
        return false;
    }
    return true;
}

void SQLiteHelper::close() {
    if (db) {
        sqlite3_close(db);
        db = nullptr;
    }
}

bool SQLiteHelper::execute(const std::string& sql) {
    char* errMsg = nullptr;
    int rc = sqlite3_exec(db, sql.c_str(), nullptr, nullptr, &errMsg);
    if (rc != SQLITE_OK) {
        if (errMsg) {
            lastError = errMsg;
            sqlite3_free(errMsg);
        } else {
            lastError = "Unknown error";
        }
        return false;
    }
    return true;
}

bool SQLiteHelper::isOpen() const {
    return db != nullptr;
}

std::string SQLiteHelper::getLastError() const {
    return lastError;
}
