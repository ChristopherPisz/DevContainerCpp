#include "dblib/DBUtil.hpp"

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

namespace dbutil
{

bool tableExists(pqxx::connection & connection, std::string_view tableName)
{
    pqxx::work transaction(connection);

    pqxx::result queryResult = transaction.exec(
        "SELECT EXISTS ("
        "SELECT FROM information_schema.tables "
        "WHERE table_schema='public' AND table_name=" + transaction.quote(std::string(tableName)) +
        ")"
    );

    transaction.commit();

    return queryResult[0][0].as<bool>();
}

bool runSQLScript(pqxx::connection &conn, std::string_view filename)
{
    std::ifstream file{std::string(filename)};
    if (!file)
    {
        std::cerr << "Could not open SQL file: " << filename << std::endl;
        return false;
    }

    file.seekg(0, std::ios::end);
    std::string fileContent;
    fileContent.reserve(file.tellg());
    file.seekg(0, std::ios::beg);

    fileContent.assign((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());

    try 
    {
        pqxx::work transaction(conn);
        transaction.exec(fileContent);
        transaction.commit();
    }
    catch (const pqxx::sql_error &sqlError) 
    {
        std::cerr << "SQL error: " << sqlError.what() << std::endl;
        std::cerr << "Query was: " << sqlError.query() << std::endl;
        return false;
    }

    return true;
}

} // end namespace dbutil