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
        unit
        COMMAND
        ${CMAKE_BINARY_DIR}/${CMAKE_INSTALL_BINDIR}/unit_tests
)