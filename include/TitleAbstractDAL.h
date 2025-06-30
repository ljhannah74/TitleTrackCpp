#pragma once
#include <vector>
#include <optional>
#include <string>
#include "SQLiteHelper.h"
#include "TitleAbstract.h"
#include "ITitleAbstractRepository.h"

class TitleAbstractDAL : public ITitleAbstractRepository {
public:
    TitleAbstractDAL();
    ~TitleAbstractDAL();

    bool connect(const std::string& dbPath);
    bool createTable();
    std::string getSafeText(sqlite3_stmt*, int);
    std::optional<int> addAbstract(const TitleAbstract& record);
    std::vector<TitleAbstract> getAllAbstracts();
    std::optional<TitleAbstract> getAbstractById(int id);
    bool updateAbstract(const TitleAbstract& record);
    bool deleteAbstract(int id);

    std::vector<TitleAbstract> getAbstractsByOrderNo(const std::string& orderNoPattern);
    std::vector<TitleAbstract> getAbstractsByClient(const std::string& clientPattern);

private:
    SQLiteHelper db;
};
