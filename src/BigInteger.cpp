//
// Created by Matthew Paletta on 2018-12-31.
//

#include <iostream>
#include "BigInteger.h"

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
    for (auto i = 0; i < std::max(this->repr.size(), b.repr.size()); i++) {
        // assume a and b are the same size first.

        int aDigit = 0, bDigit = 0;
        int aIndex = this->repr.size() - i - 1;
        int bIndex = b.repr.size() - i - 1;

        // TODO:// Fix these indexes!
        if (aIndex > 0) {
            aDigit = this->repr.at(aIndex);
        } else {
            aDigit = 0;
        }

        if (bIndex > 0) {
            bDigit = b.repr.at(bIndex);
        } else {
            bDigit = 0;
        }

        int newDigit = aDigit + bDigit + carry;

        if (carry > 0) {
            // Once we applied the carry once, we remove it.
            carry = 0;
        }

        if (newDigit >= NUMBASE) {
            carry = NUMBASE - newDigit;
            newDigit -= carry;
        }

        // Add this to the back of the list
        result.push_back(newDigit);
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
