#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

/*
      *    /\_/\
      *   (= ._.)
      *   / >  \>
      
# Bit-masks Basics:
      * every integer in the computer is stored as bits, and each bit represents a power of 2.
      * Each number has a UNIQUE representation in any base.

# Bit-wise operators in C++:
      
      * Bit-wise AND (&):
            - The result bit is 1 IFF both bits are 1 (1 & 1 = 1) otherwise 0.
            - Some use cases:
                  - Check if a bit is on (& with 1)
                  - Clear a bit (& with 0)
                  - Check parity (is the number even or odd)
      
      * Bit-wise OR (|):
            - The result bit is 1 if at least one bit is 1.
            - Common uses:
                  - active a bit (turn on).
                  - Merge two bit-masks.
      
      * Bit-wise X-OR (^):
            - The result bit is 1 if the number of 1's is Odd.
            
      * bit-wise complement (NOT) (~):
            - Flips every bit.
            - For signed integers usually produces a -ve numbers,
                  Because integers are stored using 2's complement.
            - Common use with invert a bit-mask.
            
      * Left shift (<<):
            - if (x << k) then: 
                  ** shift every bit left by k positions.
                  ** Mathematical meaning: x<<k = x * 2^k --> or (pow(2, k)).
                        - That's means if I wanna multiply a number with 2 then: n = n<<1;
                        - Then instead of x *= 2, can write: x<<=1 (multiply by 2^k).
                        
      * Right shift (>>):
            - Move every bit to the right by k positions.
            - Mathematical meaning:
                  ** x>>k = floor(x / 2^k).
                  ** Then instead of x /= 2, can write: x>>=1 (divide by 2^k).
            
      * NOTE:
            ** May happens an 'OVERFLOW' while shifting: suppose that formula --> (1 << 60)
                  - This is dangerous because 1 is an integer number that fits in 32 bits (integer domain)
                        this is shifted outside the integer domain (32 bits), then undefined behavior may happen.
                  - For prevent that overflow may always use 1LL instead of 1, to be the formula: (1LL << 60),
                        but take care that we haven't bits domain greater that the long long domain (64 bits).

      * NOTE:
            ** Bit-wise operators have lower priority than arithmetic operators 
                  (Only logical operators have lower priority than bit-wise operators)
                  Because of that, Always write parentheses.
                  
      * Important properties:
            - A ^ A = 0
            - A ^ 0 = A
            - When: A ^ B = C, then:
                  A ^ C = B,
                  B ^ C = A.   
            - For one bit only --> A^1 = (1-A), 
                  (Toggle then if x is a boolean value (one bit) and I wanna toggle it: 
                        instead of make: (X = !X), can make: (X^=1).
            - For one bit --> (A & 1 = A).
            - For A = any number of bits --> (A | 0 = A).
            - For A = any..... --> (A ^ 0 = A).

      * Parity:
            - Means Odd or Even
            - The least significant bit (LSB) determines parity.
*/    
// Check parity Odd numbers:
bool isOdd(long long n) {
      return (n & 1);
}

// Check parity Even numbers:
bool isEven(long long n) {
      return (n & 1) == 0;
}

/* Check if I-Th bit is ON: (We wanna know is bit number 'i' active?) */
// Method one --> Shift the desired bit to be the Least Significant bit.
bool isSet(ll n, int i) {
      return ((n >> i) & 1);
}
// Method Two --> shift the mask
bool isSet(ll n, int i) {
      return n & (1LL << i);
}
// Both methods are in O(1) Time complexity.


// Turn ON a bit
void setBit(ll n, int i) {
      n |= (1LL << i);
}

// Turn OFF a bit --> Bit become zero, Every thing else stayed unchanged.
void clearBit(ll n, int i) {
      n &= ~(1LL << i);
}

// Toggle a bit (use X-OR):
void toggleBit(ll n, int i) {
      n ^= (1LL << i);
}

//  Number of active bits, 2 Ways: built-in function , normal way (user-define function). 
// 1- Number of active bits with the normal way:
// Complexity O(number of bits) = O(64).
int countBits(ll n) {
      int cnt {};
      while(n) {
            cnt += n&1; // is LSB (lowest significant bit) = 1 or 0
            n >>= 1;
      }
      return cnt;
}


// 2- n.of active bits by built-in function:
// Faster than normal way (implemented by CPU instructions).
// For integers:
int pop_count(int n) {
      return __builtin_popcount(n);
}
// For long long
int pop_count_ll(ll n) {
      return __builtin_popcountll(n);
}

// Lowest set bit:
// get only the lowest set bit in a number:
ll lowestBit(ll n) {
      return n&(-n);
}     

// Remove lowest set bit:
// by the formula: a&(n-1) --> Only the lowest set bit disappears.
ll removeLowestBit(ll n) {    
      return n&(n-1);
}

// Check if number is power of 2.
// there are many methods:

// Method 1 (brute force - Loop):
// Complexity O(n.of bits) = O(64)
bool is_power2(ll n) {
      if(n <= 0)
            return false;
      
      int cnt {};
      while(n) {
            cnt += n&1;
            n >>= 1;
      }
      // Check that there is only one 1 in it's bits representation.
      return cnt == 1;
}

// Method 2 -> with built in function pop-count 
bool is_power2_2(ll n) {
      if(n <= 0)
            return false;
      return __builtin_popcountll(n) == 1;
}

// Method 3
// With formula n&(n-1) = 0 or not,But why this is true?
// suppose n's bits representation (n is power of 2) = 1000, then n-1 = 0111, then the formula's result should be 0.
// Time complexity is O(1).
bool is_power2_3(ll n) {
      if(n <= 0) 
            return false;
      return (n&(n-1)) == 0;
}

// Highest set bit:
int highestSetBit(ll n) {
      int pos {-1};
      while(n) {
            n >>= 1;
            ++pos;
      } return pos;
}

////////////////////////////////////////
// Bit-set is a fixed size container that stores bits efficiently, 
// each element stores 1 bit only --> Very memory efficient.
// Syntax: bitset<100> vis; --> initially all bits = 0s.
/////////////////////////////////

/*
      * Convert all zeros before first one to ones:
      * suppose n in binary = 10110000 , 
      *    then (n-1)'ll be = 10101111
      * then if take OR for n with n-1 will set all zeros that before first one.
*/
void convert(ll& n) {
      n |= (n-1);
}

/*
      * As same with the previos function:
      * To cnovert all 1's that before first 0 to 0's
      * Just take & (AND) with (n+1):
      * Suppose n in binary = 10101111, then n+1
      *                 n+1 = 10110000
      *  & (AND) ------------>10100000
      * As we see the result is Just convers the first 1's to 0's
*/
void ConvertFirstOnes(ll& n) {
      n &= (n+1);
}