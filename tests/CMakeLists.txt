add_executable(
        ${PROJECT_NAME}_test
        testBigInteger.cpp
)

target_link_libraries(
        ${PROJECT_NAME}_test
        gtest_main
        BigFloat
)

add_test(
        NAME
        ${PROJECT_NAME}_test
        COMMAND
        ${CMAKE_BINARY_DIR}/tests/${PROJECT_NAME}_test
)