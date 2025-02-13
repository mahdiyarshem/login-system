#include <sqlite3.h>
#include <string>

void CMenus::RegisterUser(const char* Username, const char* Password, const char* Email)
{
    sqlite3* db;
    char* errMsg = 0;
    int rc;

    // باز کردن پایگاه داده
    rc = sqlite3_open("users.db", &db);
    if (rc)
    {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return;
    }

    // ایجاد جدول کاربران اگر وجود نداشته باشد
    const char* sql = "CREATE TABLE IF NOT EXISTS Users("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "Username TEXT NOT NULL,"
                      "Password TEXT NOT NULL,"
                      "Email TEXT NOT NULL);";

    rc = sqlite3_exec(db, sql, 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }

    // درج اطلاعات کاربر جدید
    std::string query = "INSERT INTO Users (Username, Password, Email) VALUES ('"
                        + std::string(Username) + "', '"
                        + std::string(Password) + "', '"
                        + std::string(Email) + "');";

    rc = sqlite3_exec(db, query.c_str(), 0, 0, &errMsg);
    if (rc != SQLITE_OK)
    {
        fprintf(stderr, "SQL error: %s\n", errMsg);
        sqlite3_free(errMsg);
    }
    else
    {
        printf("User registered successfully!\n");
    }

    
    sqlite3_close(db);
}
