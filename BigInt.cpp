#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <bits/stdc++.h>
#include <stdbool.h>
using std::cout;

#define INT32_SIZE 4
#define UINT32_SIZE 4294967295

struct BigInt {
    std::unique_ptr<uint32_t[]> digits;
    unsigned int size;
    unsigned int capacity;
};

char IntToDigt(int digit){
    if (digit < 0 || digit > 9) throw std::invalid_argument("Not a valid digit 0-9");
    return '0' + digit;
}

void DisplayIntArr(const unsigned int arr[], unsigned long long length){
        cout << "[";
        for (unsigned long long i = 0; i < length; i++){
                cout << arr[i];
                if (i < (length - 1)){
                        cout << ", ";
                }
        }
        cout << "]" << '\n';
}

bool IsOverflow(unsigned int Num1, unsigned int Num2){
    return Num2 > UINT32_MAX - Num1; 
}

void CreateBigInt(BigInt& nums) {
    nums.capacity = 10;
    nums.size = 0;
    nums.digits = std::make_unique<uint32_t[]>(nums.capacity);
}

void Resize(BigInt& bigInt, unsigned int newCapacity) {
    std::unique_ptr<uint32_t[]> newDigits = std::make_unique<uint32_t[]>(newCapacity);
    std::copy(bigInt.digits.get(), bigInt.digits.get() + bigInt.size, newDigits.get());
    bigInt.digits = std::move(newDigits);
    bigInt.capacity = newCapacity;
}

void SetBigIntVal(BigInt& nums, unsigned int num) {
    if (nums.capacity == nums.size) {
        nums.capacity += 10;
        Resize(nums, nums.capacity);
    }
    nums.digits[nums.size] = num;
    nums.size++;
}

int CmpNums(const BigInt& NumberOne,const BigInt& NumberTwo){
        if (NumberOne.size < NumberTwo.size) { return -1; }
        else if (NumberOne.size > NumberTwo.size) { return 1; }

        const unsigned long long size = NumberOne.size - 1;

        for (int i = NumberOne.size - 1; i >= 0; i--) {
            if (NumberOne.digits[i] < NumberTwo.digits[i]) return -1;
            if (NumberOne.digits[i] > NumberTwo.digits[i]) return 1;
        }

        return 0;
}

BigInt AddNums(const BigInt& nums1, const BigInt& nums2) {
    BigInt result;
    result.capacity = std::max(nums1.size, nums2.size) + 1;
    result.size = result.capacity;
    result.digits = std::make_unique<uint32_t[]>(result.capacity);

    uint64_t carry = 0;

    for (unsigned int i = 0; i < result.capacity; i++) {
        uint64_t a = (i < nums1.size) ? nums1.digits[i] : 0;
        uint64_t b = (i < nums2.size) ? nums2.digits[i] : 0;

        uint64_t sum = a + b + carry;
        result.digits[i] = static_cast<uint32_t>(sum & 0xFFFFFFFF);
        carry = sum >> 32;
    }
    
    while (result.size > 1 && result.digits[result.size - 1] == 0) {
        result.size--;
    }

    return result;
}

void PrintBigIntInfo(const BigInt& num) {
    cout << "Digits: ";
    DisplayIntArr(num.digits.get(), num.size);
    cout << "Size: " << num.size << "\n";
    cout << "Capacity: " << num.capacity << "\n";
}

