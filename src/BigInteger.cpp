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

BigInteger::~BigInteger() {
    std::cout << "Deleting Big Float" << std::endl;
}