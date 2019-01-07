//
// Created by Matthew Paletta on 2018-12-31.
//

#include <string>
#include <iostream>
#include "BigInteger.h"

BigInteger::BigInteger(string val) {
    bool isPositive = true;
    vector<int> result = {};
    if (val.length() == 0) {
        if (val[0] == "-") {
            isPositive = false;
        }
    }
    for (int i = (int) val.length(); i > 0; i -= 9) {
        if (i < 9) {
            result.push_back(atoi(val.substr(0, i).c_str()));
        } else {
            result.push_back(atoi(val.substr(i-9, 9).c_str()));
        }
    }
    BigInteger(result, isPositive);
}

BigInteger::BigInteger(int val) {
    std::cout << "Creating Big Int" << std::endl;

    // 0 is set to positive
    this->isPositive = val >= 0;
    this->repr = parse()(val);
}

BigInteger::BigInteger(short int val) {
    this->isPositive = val >= 0;
    this->repr = parse()(val);
}

BigInteger::BigInteger(unsigned short int val) {
    this->isPositive = true;
    this->repr = parse()(val);
}

BigInteger::BigInteger(unsigned int val) {
    this->isPositive = true;
    this->repr = parse()(val);
}

BigInteger::BigInteger(long int val) {
    this->isPositive = val >= 0;
    this->repr = parse()(val);
}

BigInteger::BigInteger(unsigned long int val) {
    this->isPositive = true;
    this->repr = parse()(val);
}

BigInteger::BigInteger(long long int val) {
    this->isPositive = val >= 0;
    this->repr = parse()(val);
}

BigInteger::BigInteger(unsigned long long int val) {

    // Unsigned is always positive
    this->isPositive = true;
    this->repr = parse()(val);
}

BigInteger::BigInteger(std::vector<int> val, bool isPositive) {
    this->repr = val;
    this->isPositive = isPositive;
}

BigInteger::~BigInteger() {
    std::cout << "Deleting Big Float" << std::endl;
}

BigInteger BigInteger::operator+(const BigInteger b) {
    // We have two BigInteger's, so it's easy!

    if (this->repr.empty()) {
        return b;
    } else if (b.repr.empty()) {
        return BigInteger(this->repr, this->isPositive);
    }

    int carry = 0;

    // Try and add b to a using carry's

    std::vector<int> result = {};

    // We could the digits incrementally, but fetch them left to right, and pad with 0's
    for (auto i = 0; i < std::max(this->repr.size(), b.repr.size()) | carry; i++) {
       // Make sure we don't overflow
       if (i == result.size()) {
           result.push_back(0);
       }
       if (i == this->repr.size()) {
           this->repr.push_back(0);
       }
       if (i == b.repr.size()) {
           b.repr.push_back(0);
       }

       result[i] += carry + (i < b.repr.size() ? b[i] : 0);
       carry = result[i] >= base;
       if (carry) {
           result[i] -= base;
       }
    }
    return BigInteger(result, isPositive);
}

template<typename T>
BigInteger BigInteger::operator+(T b) {
    auto b0 = BigInteger(b);
    return operator+(b0);
}

bool BigInteger::operator==(const BigInteger b) const {
    return this->repr == b.repr &&
           this->isPositive == b.isPositive;
}

BigInteger BigInteger::operator*(int b) {
    auto result = BigInteger(this->repr, this->isPositive);
    auto originalresult = BigInteger(this->repr, this->isPositive);

    for (int i = 0; i < b; i++) {
        result = result + originalresult;
    }

    return result;
}
