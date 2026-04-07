#include "dblib/DBUtil.hpp"

#include <pqxx/pqxx>

#include <iostream>
#include <fstream>
#include <sstream>


constexpr std::string_view SCHEMA_VERSION_TABLE = "schema_version";
constexpr std::string_view CREATE_TABLES_SCRIPT = "/db/init.sql";

int main(int argc, char ** argv)
{
    std::unique_ptr<pqxx::connection> databaseConnection;
    try
    {
        // In a real app, we'd hide these credentials
        databaseConnection = std::make_unique<pqxx::connection>("host=postgres dbname=devdb user=devuser password=devpass");
    }
    catch (const std::exception &e)
    {
        std::cerr << "Connection failed: " << e.what() << "\n";
        return 1;
    }

    if (!dbutil::tableExists(*databaseConnection, SCHEMA_VERSION_TABLE))
    {
        // We need to create the tables
        std::cout << "No database tables found. Creating schema..." << std::endl;
    }

    return 0;
}
