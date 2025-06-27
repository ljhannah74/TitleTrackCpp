#pragma once
#include <string>

class TitleAbstract {
public:
    int TitleAbstractID = 0;
    std::string OrderNo;
    std::string OrderDate;
    std::string SearchDate;
    std::string EffectiveDate;
    std::string PropertyAddress;
    std::string ProductType;
    std::string Client;
    std::string ClientRefNo;

    TitleAbstract() = default;

    TitleAbstract(
        int id,
        const std::string& orderNo,
        const std::string& orderDate,
        const std::string& searchDate,
        const std::string& effectiveDate,
        const std::string& propertyAddress,
        const std::string& productType,
        const std::string& client,
        const std::string& clientRefNo)
        : TitleAbstractID(id),
          OrderNo(orderNo),
          OrderDate(orderDate),
          SearchDate(searchDate),
          EffectiveDate(effectiveDate),
          PropertyAddress(propertyAddress),
          ProductType(productType),
          Client(client),
          ClientRefNo(clientRefNo)
    {}
};
