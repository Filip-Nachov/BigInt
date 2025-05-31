#include <iostream>
#include <cassert>
#include "../BigInt.h"

void TestCreateAndSet() {
    BigInt num;
    CreateBigInt(num);
    assert(num.size == 0);
    assert(num.capacity >= 10);

    SetBigIntVal(num, 42);
    assert(num.size == 1);
    assert(num.digits[0] == 42);

    std::cout << "TEST Create and Set: passed\n";
}

void TestCmpNums() {
    BigInt a, b;
    CreateBigInt(a);
    CreateBigInt(b);

    SetBigIntVal(a, 5);
    SetBigIntVal(b, 5);
    assert(CmpNums(a, b) == 0);

    SetBigIntVal(b, 10);
    assert(CmpNums(a, b) == -1);
    assert(CmpNums(b, a) == 1);

    std::cout << "TEST CmpNums: passed\n";
}

void TestAddNumsSimple() {
    BigInt a, b;
    CreateBigInt(a);
    CreateBigInt(b);

    SetBigIntVal(a, 1);
    SetBigIntVal(b, 2);

    BigInt sum = AddNums(a, b);
    assert(sum.size == 1);
    assert(sum.digits[0] == 3);

    std::cout << "TEST AddNums: passed\n";
}

void TestAddNumsWithCarry() {
    BigInt a, b;
    CreateBigInt(a);
    CreateBigInt(b);

    SetBigIntVal(a, UINT32_MAX);
    SetBigIntVal(b, 1);

    BigInt sum = AddNums(a, b);
    assert(sum.size == 2);
    assert(sum.digits[0] == 0);
    assert(sum.digits[1] == 1);

    std::cout << "TEST AddNums: passed\n";
}

void TestResize() {
    BigInt num;
    CreateBigInt(num);

    for (int i = 0; i < 15; i++) {
        SetBigIntVal(num, i);
    }

    assert(num.size == 15);
    assert(num.capacity >= 15);
    assert(num.digits[14] == 14);

    std::cout << "TEST Resize: passed\n";
}

int main() {
    TestCreateAndSet();
    TestCmpNums();
    TestAddNumsSimple();
    TestAddNumsWithCarry();
    TestResize();

    std::cout << "TESTS: PASSED\n";
    return 0;
}

