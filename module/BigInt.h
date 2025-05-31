#ifndef BIGINT_H
#define BIGINT_H

#include <memory>
#include <iostream>

struct BigInt {
    std::unique_ptr<uint32_t[]> digits;
    unsigned int size;
    unsigned int capacity;
};

void CreateBigInt(BigInt& nums);
void Resize(BigInt& bigInt, unsigned int newCapacity);
void SetBigIntVal(BigInt& nums, unsigned int num);
int CmpNums(const BigInt& NumberOne, const BigInt& NumberTwo);
BigInt AddNums(const BigInt& nums1, const BigInt& nums2);
void PrintBigIntInfo(const BigInt& num);
void DisplayIntArr(const unsigned int arr[], unsigned long long length);

#endif

