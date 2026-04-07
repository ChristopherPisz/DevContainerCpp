#include <pqxx/pqxx>

#include <string_view>

namespace dbutil 
{

/*
* @brief Checks if a table exists in the database
* @return True if the table exists, otherwise false.
*/
bool tableExists(pqxx::connection & connection, std::string_view tableName);

/*
* @brief Runs SQL from a file
* @details Contents are run within a transaction. Multiple statements separated by semicolons are supported. 
*          BEGIN and END are not, as they would result in nested transactions and cause errors.
* @return True if successful. Otherwise, false.
*/
bool runSQLScript(pqxx::connection &conn, std::string_view filename);

}