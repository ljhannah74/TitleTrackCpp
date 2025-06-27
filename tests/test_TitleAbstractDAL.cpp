#include <iostream>
#include <cassert>
#include "../include/TitleAbstractDAL.h"

void test_create_and_insert() {
    TitleAbstractDAL dal;
    assert(dal.connect(":memory:"));
    assert(dal.createTable());

    TitleAbstract ta(0, "ORD-001", "2024-06-01", "2024-06-02", "2024-06-03",
                     "123 Main St", "Full", "Acme", "REF-001");

    auto id = dal.addAbstract(ta);
    assert(id.has_value());
    std::cout << "✅ test_create_and_insert passed\n";
}

void test_retrieve_and_update() {
    TitleAbstractDAL dal;
    dal.connect(":memory:");
    dal.createTable();

    TitleAbstract ta(0, "ORD-002", "2024-06-01", "2024-06-02", "2024-06-03",
                     "456 Elm St", "Summary", "Bravo", "REF-002");
    auto id = dal.addAbstract(ta);
    assert(id.has_value());

    auto fetched = dal.getAbstractById(id.value());
    assert(fetched.has_value());
    assert(fetched->OrderNo == "ORD-002");

    // Modify and update
    fetched->Client = "UpdatedClient";
    assert(dal.updateAbstract(*fetched));

    auto updated = dal.getAbstractById(id.value());
    assert(updated.has_value());
    assert(updated->Client == "UpdatedClient");

    std::cout << "✅ test_retrieve_and_update passed\n";
}

void test_delete() {
    TitleAbstractDAL dal;
    dal.connect(":memory:");
    dal.createTable();

    TitleAbstract ta(0, "ORD-003", "2024-06-01", "2024-06-02", "2024-06-03",
                     "789 Oak St", "Prelim", "Charlie", "REF-003");
    auto id = dal.addAbstract(ta);
    assert(id.has_value());

    assert(dal.deleteAbstract(id.value()));
    auto deleted = dal.getAbstractById(id.value());
    assert(!deleted.has_value());

    std::cout << "✅ test_delete passed\n";
}

void test_get_by_client() {
    TitleAbstractDAL dal;
    dal.connect(":memory:");
    dal.createTable();

    dal.addAbstract(TitleAbstract(0, "ORD-X", "2024-06-01", "2024-06-01", "2024-06-01", "Addr1", "Type", "Acme", "Ref"));
    dal.addAbstract(TitleAbstract(0, "ORD-Y", "2024-06-01", "2024-06-01", "2024-06-01", "Addr2", "Type", "Bravo", "Ref"));
    dal.addAbstract(TitleAbstract(0, "ORD-Z", "2024-06-01", "2024-06-01", "2024-06-01", "Addr3", "Type", "AcmeCorp", "Ref"));

    auto results = dal.getAbstractsByClient("Acme");
    assert(results.size() == 2);
    std::cout << "✅ test_get_by_client passed\n";
}

int main() {
    test_create_and_insert();
    test_retrieve_and_update();
    test_delete();
    test_get_by_client();
    std::cout << "🎉 All tests passed!\n";
    return 0;
}
