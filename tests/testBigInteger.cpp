//
// Created by Matthew Paletta on 2018-12-31.
//

#include "gtest/gtest.h"
#include <iostream>
#include "../src/BigInteger.h"

TEST(test_sample_case, test_single_digit) {
    auto v1 = 5;
    auto v2 = 3;

    auto val1 = BigInteger(v1);
    auto val2 = BigInteger(v2);
    EXPECT_EQ(val1 + val2, BigInteger(v1 + v2));
}

TEST(test_sample_case2, test_multiple_digit) {
    auto v1 = 15;
    auto v2 = 3;

    auto val1 = BigInteger(v1);
    auto val2 = BigInteger(v2);

    EXPECT_EQ(val1 + val2, BigInteger(v1 + v2));
}