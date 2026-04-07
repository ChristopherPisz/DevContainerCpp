
include_directories(
    ${CMAKE_SOURCE_DIR}/include
)

add_library(dblib
    DBUtil.cpp
)

target_link_libraries(dblib PUBLIC
    libpqxx::pqxx
)


