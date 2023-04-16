//-----------------------------------------------------------------------------
// Edison Chen, edhachen
// 2022 Winter CSE101 PA6
// BigInteger.cpp
// Implementation file for the BigInteger ADT
//-----------------------------------------------------------------------------
#include<iostream>
#include<string>
#include<stdexcept>
#include"BigInteger.h"

#define power 9
#define base 1000000000

using namespace std;

//helper functions
int listCompare(List A, List B){
    if (A.length() > B.length()){
        return(1);
    } else if (B.length() > A.length()){
        return(-1);
    } else {
        for (A.moveFront(), B.moveFront(); A.position() < A.length() && B.position() < B.length(); A.moveNext(), B.moveNext()){
            if (A.peekNext() > B.peekNext()){
                return(1);
            } else if (B.peekNext() > A.peekNext()){
                return(-1);
            }
        }
        return(0);
    }
}
void negateList(List& L){
    for (L.moveFront(); L.position() < L.length(); L.moveNext()){
        L.setAfter(L.peekNext() * -1);
    }
    L.moveFront();
}

void sumList(List& S, List A, List B, int sgn){
    S.clear();
    for (A.moveBack(), B.moveBack(); A.position() > 0 && B.position() > 0; A.movePrev(), B.movePrev()){
        S.insertAfter(A.peekPrev() + (B.peekPrev() * sgn));
    }
    
    while (A.position() > 0){
        S.insertAfter(A.peekPrev());
        A.movePrev();
    }
    while (B.position() > 0){
        S.insertAfter(B.peekPrev());
        B.movePrev();
    } 
    A.moveFront();
    B.moveFront();
}

int normalizeList(List& L){
    if (L.length() == 0){
        return(0);
    }
    bool leftmost_digit_neg = false;
    bool pos_carry = false;
    bool neg_carry = false;
    int num_pos_carry = 0;
    int num_neg_carry = 0;
    L.moveFront();
    if (L.peekNext() < 0){
        negateList(L);
        leftmost_digit_neg = true;
    }
    L.moveBack();
    while (L.position() > 0){
        if (pos_carry == true){
            L.setBefore(L.peekPrev() + num_pos_carry);
            pos_carry = false;
            num_pos_carry = 0;
        } else if (neg_carry == true){
            L.setBefore(L.peekPrev() - num_neg_carry);
            neg_carry = false;
            num_neg_carry = 0;
        }
        if (L.peekPrev() >= base){
            num_pos_carry = (int)(L.peekPrev() / base);
            L.setBefore(L.peekPrev() % base);
            pos_carry = true;
        } else if (L.peekPrev() < 0){
            //num_neg_carry = (int)(L.peekPrev() / base) + 1;
            while (L.peekPrev() < 0){
                L.setBefore(L.peekPrev() + base);
                num_neg_carry += 1;
            }
            //L.setBefore(-1 * (L.peekPrev() % base));
            neg_carry = true;
        }
        L.movePrev();
    }
    if (pos_carry == true){
        L.insertAfter(num_pos_carry);
        if (leftmost_digit_neg == true){
            return(-1);
        }
        return(1);
    } else if (neg_carry == true){
        L.insertAfter(num_neg_carry);
        return(-1);
    }
    if (leftmost_digit_neg == true){
        return(-1);
    } else{
        return(1);
    }
}


void shiftList(List& L, int p){
    L.moveBack();
    for (int i = 0; i < p; i += 1){
        L.insertBefore(0);
    }
}

void scalarMultList(List& L , ListElement m){
    for (L.moveFront(); L.position() < L.length(); L.moveNext()){
        L.setAfter(L.peekNext() * m);
    }
    L.moveFront();
}
BigInteger::BigInteger(){
    signum = 0;
    digits = List();
}

BigInteger::BigInteger(std::string s){
    std::string subString;
    int leftover = 0;
    bool sign = false;
    if (s.length() == 0){
        throw std::invalid_argument("BigInteger: Constructor: empty string");
    } else if (!isdigit(s[0])){
        if (s[0] == '+'){
            signum = 1;
        } else if (s[0] == '-'){
            signum = -1;
        }
        sign = true;
    } else{
        signum = 1;
    }
    if (s.length() > power){
        for (size_t i = s.length(); i > power; i -= power){
            subString = s.substr(i - power, power);
            this->digits.insertAfter(stol(subString));
            leftover = i - power;
        }
    } else{
        subString = s;
        this->digits.insertAfter(stol(subString));
    }
    if (sign){
        leftover -= 1;
    }
    if (leftover > 0){
        if (sign){
            subString = s.substr(1, leftover);
            this->digits.insertAfter(stol(subString));
        } else {
            subString = s.substr(0, leftover);
            this->digits.insertAfter(stol(subString));
        }
    }
    this->digits.moveFront();
    while(this->digits.peekNext() == 0){
        this->digits.eraseAfter();
    }
}

BigInteger::BigInteger(const BigInteger& N){
    signum = 0;
    digits = List();
    signum = N.signum;
    digits = N.digits;
}

int BigInteger::sign() const{
    return(signum);
}

int BigInteger::compare(const BigInteger& N) const{
    if (this->signum == 1 && N.signum == -1){
        return(1);
    } else if (this->signum == -1 && N.signum == 1){
        return(-1);
    }
    return listCompare(this->digits, N.digits);
}

void BigInteger::makeZero(){
    signum = 0;
    digits = List();
}

void BigInteger::negate(){
    if (signum == 1){
        signum = -1;
    } else if (signum == -1){
        signum = 1;
    }
}

BigInteger BigInteger::add(const BigInteger &N) const{
    BigInteger addition;
    List add;
    BigInteger copy = *this;
    if (this->signum == 1 && N.signum == 1){
        sumList(add, this->digits, N.digits, 1);
        addition.signum = 1;
    } else if (this->signum == 1 && N.signum == -1){
        //sumList(add, this->digits, N.digits, -1);
        if (this->digits == N.digits){
        addition.digits = add;
        return addition;
    }
        if (copy.compare(N) == 1){
            addition.signum = 1;
        } else if (copy.compare(N) == -1){
            addition.signum = -1;
        }
        if (listCompare(this->digits, N.digits) == 1){
            sumList(add, this->digits, N.digits, -1);
            addition.signum = 1;
        } else if (listCompare(this->digits, N.digits) == -1){
            sumList(add, N.digits, this->digits, -1);
            addition.signum = -1;
        }
    } else if (this->signum == -1 && N.signum == 1){
        sumList(add, N.digits, this->digits, -1);
        if (copy.compare(N) == 1){
            addition.signum = -1;
        } else if (copy.compare(N) == -1){
            addition.signum = 1;
        }
    } else if (this->signum == -1 && N.signum == -1){
        sumList(add, this->digits, N.digits, 1);
        negateList(add);
        addition.signum = -1;
    }
    normalizeList(add);
    addition.digits = add;
    return addition;
}

BigInteger BigInteger::sub(const BigInteger& N) const{
    BigInteger subtraction;
    List sub;
    if (this->digits == N.digits){
        subtraction.digits = sub;
        return subtraction;
    }
    if (this->signum == 1 && N.signum == 1){
        sumList(sub, this->digits, N.digits, -1);
        if (listCompare(this->digits, N.digits) == 1){
            subtraction.signum = 1;
        } else if (listCompare(this->digits, N.digits) == -1){
            subtraction.signum = -1;
        }
    } else if (this->signum == -1 && N.signum == 1){
        sumList(sub, this->digits, N.digits, 1);
        scalarMultList(sub, -1);
        //negateList(sub);
        subtraction.signum = -1;
    } else if (this->signum == 1 && N.signum == -1){
        sumList(sub, this->digits, N.digits, 1);
        subtraction.signum = 1;
    } else if (this->signum == -1 && N.signum == -1){
        if (listCompare(this->digits, N.digits) == 1){
            sumList(sub, N.digits, this->digits, -1);
            subtraction.signum = -1;
        } else if (listCompare(this->digits, N.digits) == -1){
            sumList(sub, N.digits, this->digits, -1);
            subtraction.signum = 1;
        }
    }
    normalizeList(sub);
    subtraction.digits = sub;
    return subtraction;
}


BigInteger BigInteger::mult(const BigInteger& N) const{
    BigInteger multiplication;
    List Acopy = this->digits;
    List Bcopy = N.digits;
    List mult;
    int count = 0;
    for(Bcopy.moveBack(); Bcopy.position() > 0; Bcopy.movePrev()){
        scalarMultList(Acopy, Bcopy.peekPrev());
        shiftList(Acopy, count);
        count += 1;
        sumList(mult, mult, Acopy, 1);
        Acopy = this->digits; 
        normalizeList(mult);
        //std::cout << mult << endl;
    }
    if (this->signum == -1 && N.signum == -1){
        multiplication.signum = 1;
    } else if (this->signum == -1 && N.signum == 1){
        multiplication.signum = -1;
    } else if (this->signum == 1 && N.signum == -1){
        multiplication.signum = -1;
    } else if (this->signum == 1 && N.signum == 1){
        multiplication.signum = 1;
    }
    multiplication.digits = mult;
    return multiplication;
}
std::string BigInteger::to_string(){
    std::string bigInt = "";
    //int countt = 0;
    if (digits.length() == 0){
        bigInt += "0";
        return bigInt;
    }
    if (sign() == -1){
        bigInt += "-";
    }
    digits.moveFront();
    while (digits.position() < digits.length()){
        if (bigInt != "" && bigInt != "-"){
            for (size_t i = std::to_string(digits.peekNext()).length(); i < power; i += 1){
                bigInt += "0";
            }
        }
        bigInt += std::to_string(digits.peekNext());
        //bigInt += "|";
        digits.moveNext();
    }
    if (bigInt[0] == '-'){
        while(bigInt[1] == '0'){
            bigInt.erase(1, 1);
        }
    } else {
        while (bigInt[0] == '0'){
            bigInt.erase(0, 1);
        }
    }
    return bigInt;
}

std::ostream& operator<<( std::ostream& stream, BigInteger N){
    return stream << N.to_string();
}

bool operator==(const BigInteger& A, const BigInteger& B){
    if ((A.compare(B)) == 0){
        return true;
    } else{
        return false;
    }
}

bool operator<(const BigInteger& A, const BigInteger& B){
    if ((A.compare(B)) == -1){
        return true;
    } else{
        return false;
    }
}

bool operator<=(const BigInteger& A, const BigInteger& B){
    if ((A.compare(B)) == -1 || (A.compare(B)) == 0){
        return true;
    } else{
        return false;
    }
}

bool operator>(const BigInteger& A, const BigInteger& B){
    if (A.compare(B) == 1){
        return true;
    } else{
        return false;
    }
}

bool operator>=(const BigInteger& A, const BigInteger& B){
    if (A.compare(B) == 1 || (A.compare(B) == 0)){
        return true;
    } else{
        return false;
    }
}

BigInteger operator+(const BigInteger& A, const BigInteger& B){
    BigInteger plus = A.BigInteger::add(B);
    return plus;
}

BigInteger operator+=(BigInteger& A, const BigInteger& B){
    A = A.BigInteger::add(B);
    return A;
}

BigInteger operator-(const BigInteger& A, const BigInteger& B){
    BigInteger minus = A.BigInteger::sub(B);
    return minus;
}

BigInteger operator-=(BigInteger& A, const BigInteger& B){
    A = A.BigInteger::sub(B);
    return A;
}

BigInteger operator*(const BigInteger&A, const BigInteger& B){
    BigInteger product = A.BigInteger::mult(B);
    return product;
}

BigInteger operator*=(BigInteger& A, const BigInteger& B){
    A = A.BigInteger::mult(B);
    return A;
}
