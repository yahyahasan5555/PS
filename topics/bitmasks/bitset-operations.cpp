
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

// 1) The size must be known at COMPILE time (a constant), not read from input.
// 2) Big sizes (like 1e8 bits ~ 12.5 MB) should be GLOBAL/static, not local (the stack is small).
bitset<100000000> big;

int main() {
    // ---- 1) size up to 1e8 and O(1) random access ----
    big[99999999] = 1;          // O(1): write one bit
    big.set(5);                 // O(1)
    cout << "big[5] = " << big[5] << ", big[6] = " << big[6] << ", big.count() = " << big.count() << "\n\n";

    // ---- 2) the common functions ----
    bitset<8> b;                // all zeros: 00000000
    b.set();                    // all ones : 11111111
    b.reset();                  // all zeros
    b.set(3);                   // bit 3 on : 00001000
    b.set(0);                   // bit 0 on : 00001001
    cout << "b = " << b << "\n"; // Binary repr
    cout << "count = " << b.count() << "  (number of active bits)\n";
    cout << "test(3) = " << b.test(3) << "  (like b[3] but throws if out of range)\n";
    b.flip(1);                  // toggle one bit
    cout << "after flip(1): " << b << "\n";
    b.reset(0);                 // clear one bit
    cout << "after reset(0): " << b << "\n";
    b.flip();                   // toggle ALL bits
    cout << "after flip():  " << b << "\n";
    cout << "size = " << b.size() << "\n\n";

    // ---- 3) initialize with an integer (or a string) ----
    bitset<8> from_int(13);                 // 13 = 00001101
    bitset<8> from_str("10100000");         // string of 0/1, leftmost char = highest bit
    cout << "from int 13     : " << from_int << "\n";
    cout << "from \"10100000\": " << from_str << " (= " << from_str.to_ulong() << ")\n\n";

    // ---- 4) print as binary / decimal ----
    bitset<8> x(40);
    cout << "binary -int-: " << x << "\n";                 // cout prints binary, MOST significant bit first
    cout << "binary -str-: " << x.to_string() << "\n";     // the same as a string
    cout << "decimal     : " << x.to_ulong() << "\n";      // to_ullong() for up to 64 bits
    // NOTE: to_ulong() throws std::overflow_error if the value does not fit in unsigned long.

    // ---- 5) bitwise operators work on whole bitsets ----
    bitset<8> p(12), q(10);   // 00001100, 00001010
    cout << "p & q = " << (p & q) << ", p | q = " << (p | q)
         << ", p ^ q = " << (p ^ q) << ", ~p = " << (~p)
         << ", p << 2 = " << (p << 2) << ", p >> 2 = " << (p >> 2) << "\n";
    return 0;
}

/* The output:

       sh-5.3$ g++ bitset-operations.cpp -o out
       sh-5.3$ ./out
       big[5] = 1, big[6] = 0, big.count() = 2

       b = 00001001
       count = 2  (number of active bits)
       test(3) = 1  (like b[3] but throws if out of range)
       after flip(1): 00001011
       after reset(0): 00001010
       after flip():  11110101
       size = 8

       from int 13     : 00001101
       from "10100000": 10100000 (= 160)

       binary -int-: 00101000
       binary -str-: 00101000
       decimal     : 40
       p & q = 00001000, p | q = 00001110, p ^ q = 00000110, ~p = 11110011, p << 2 = 00110000, p >> 2 = 00000011
*/