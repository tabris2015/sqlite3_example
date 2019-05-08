#include <iostream>
#include <cstdlib>
#include <string>
#include "sqlite3.h"

int main(int argc, char const *argv[])
{
    std::cout << "SQLITE version: " << sqlite3_libversion() << "\n";

    sqlite3 * db;
    int res;
    char * error = 0;

    // abrir base de datos
    res = sqlite3_open("../test.db", &db);
    if(res)
    {
        std::cerr << "no se pudo abrir la base de datos: " << sqlite3_errmsg(db);
        return -1;
    }

    // crear una tabla
    std::string query = "create table usuario (`id` INTEGER  PRIMARY KEY, `nombre` VARCHAR(40) NOT NULL, `edad` INTEGER NOT NULL)";

    // ejecutar la consulta
    res = sqlite3_exec(db, query.c_str(), NULL, 0, &error);
    if(res != SQLITE_OK)
    {
        std::cerr << "error: " << error;
        sqlite3_free(error);
    } 
    else std::cout << "exito!\n";
    sqlite3_close(db);
    return 0;
}
