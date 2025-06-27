#pragma once

#include <string>
#include <sqlite3.h>

class SQLiteHelper {
public:
    SQLiteHelper();
    ~SQLiteHelper();

    // Open SQLite database file
    bool open(const std::string& dbPath);

    // Close the database connection
    void close();

    // Execute a non-select SQL statement (INSERT, UPDATE, DELETE)
    bool execute(const std::string& sql);

    // Check if DB is open
    bool isOpen() const;

    // Get last error message
    std::string getLastError() const;

private:
    sqlite3* db = nullptr;
    std::string lastError;
};
