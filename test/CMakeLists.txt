include_directories(
    ${CMAKE_SOURCE_DIR}/include
    ${GTEST_INCLUDE_DIRS}
)

add_executable(hellotest
    main.cpp
    testCow.cpp
)

target_link_libraries(hellotest PUBLIC
    hellolib
    GTest::gtest
    GTest::gmock
)