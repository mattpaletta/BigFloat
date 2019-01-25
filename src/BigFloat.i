%module BigInteger

%ignore BigInteger(int val);
%ignore BigInteger(short int val);
%ignore BigInteger(unsigned short int val);
%ignore BigInteger(unsigned int val);
%ignore BigInteger(long int val);
%ignore BigInteger(unsigned long int val);
%ignore BigInteger(long long int val);
%rename(__add__) BigInteger::operator+;

// Add necessary symbols to generated header
%{
#include "BigInteger.h"
%}

// Process symbols in header
%include "BigInteger.h"