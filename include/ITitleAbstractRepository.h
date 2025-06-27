#pragma once
#include <vector>
#include <string>
#include <optional>
#include "TitleAbstract.h"

// Interface
class ITitleAbstractRepository {
public:
    virtual ~ITitleAbstractRepository() = default;

    virtual bool connect(const std::string& dbPath) = 0;
    virtual bool createTable() = 0;
    virtual std::optional<int> addAbstract(const TitleAbstract& record) = 0;
    virtual std::vector<TitleAbstract> getAllAbstracts() = 0;
    virtual std::optional<TitleAbstract> getAbstractById(int id) = 0;
    virtual bool updateAbstract(const TitleAbstract& record) = 0;
    virtual bool deleteAbstract(int id) = 0;
};
