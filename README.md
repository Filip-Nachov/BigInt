# BigInt

BigInt a day keeps the overflow away.

## What is BigInt?

BigInt is a C++ library that  allows you to work with numbers larger than standard fixed-width types like `uint32_t` without worrying about overflow.

## Features

- ⚡ Dynamic resizing of the underlying storage
- ➕ Addition of large numbers
- 🟰 Comparison between BigInts
- 🛠️ Utility functions for displaying and manipulating big integers
- ⛔ No Overflows


## Installation

Requirments:
 - git
 - terminal of your choice

To install the library for yourself you need to open your terminal of choice and run the following command:

- `git clone https://github.com/Filip-Nachov/BigInt.git`

after doing so you should be able to go inside the directory BigInt and start writing your code right there in the directory. for more info look into the Usage section.

## Usage

To code with the BigInt module, you will need to go into the BigInt directory which you can install from the Installation section and start writing your code.
The only requirment to use the library is to include the header file which you can do so by writing:

- `#include "module/BigInt.h"`

at the top of the file

### Example Code

```cpp
#include "module/BigInt.h"

int main() {
    BigInt num1, num2;
    CreateBigInt(num1);
    CreateBigInt(num2);

    SetBigIntVal(num1, 123456789);
    SetBigIntVal(num2, 987654321);

    BigInt sum = AddNums(num1, num2);

    PrintBigIntInfo(sum);
    return 0;
}
```

### Functions and their use

| Function Name      | Arguments                                           | Functionality                                                                 |
|--------------------|-----------------------------------------------------|------------------------------------------------------------------------------|
| `CreateBigInt`     | `BigInt& nums`                                      | Initializes a `BigInt` with default capacity and zero size.                 |
| `SetBigIntVal`     | `BigInt& nums, unsigned int num`                   | Appends an unsigned int to the BigInt’s digit array, resizes if needed.    |
| `Resize`           | `BigInt& bigInt, unsigned int newCapacity`         | Changes the capacity of a BigInt while preserving existing digits.          |
| `CmpNums`          | `const BigInt& NumberOne, const BigInt& NumberTwo` | Compares two `BigInt` values: returns `-1`, `0`, or `1`.                   |
| `AddNums`          | `const BigInt& nums1, const BigInt& nums2`         | Returns the result of adding two `BigInt` values.                          |
| `PrintBigIntInfo`  | `const BigInt& num`                                 | Outputs the digits, size, and capacity of a `BigInt`.                      |
| `DisplayIntArr`    | `const unsigned int arr[], unsigned long long len` | Prints a formatted array of unsigned integers.                             |
| `IsOverflow`       | `unsigned int Num1, unsigned int Num2`             | Checks whether adding two unsigned ints will cause overflow.               |
| `IntToDigt`        | `int digit`                                         | Converts an integer (0–9) to its ASCII character representation.           |



## Feedback

If you have any feedback, please reach out to us by making a issue.




## Contributing

Contributions are always welcome!

Please try to maintane the already existing coding style.


## Authors

- [@UserNotFound](https://github.com/USER-NOT-FOUND-maker) (started this repo)

- [@FilipNachov](https://github.com/filip-nachov) (rewrote the code and many files while keeping the same idea)


