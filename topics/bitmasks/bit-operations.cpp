#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>
using namespace std;
using ll = long long;

// detects whether the given bit is active in the given number or not!
// there are 2 implementations for this function:
// implementation #1: shift '1' to the left 'bit' times, then compare using the & bitwise operator:
bool get_bit(int num, int bit) {
    // !NOTE: the mask is a long long to avoid overflow (e.g. bit = 31).
    ll mask {1LL << bit};
    return num & mask; // is this mask active in the number?
}

// implementation #2: because of the overflow mistakes in the first implementation,
// this one shifts the given number to the right 'bit' times so the target bit becomes the most right bit,
// then checks it by (.... & 1)
bool get_bit2(int num, int bit) {
    return (num >> bit) & 1;
}

// SET BIT
// active/light the given bit (0-based) in the given number:
int set_bit(int num, int bit) {
    return num | (1LL << bit);
}


// CLEAR BIT
// inactive the given bit in the given number
int clear_bit(int num, int bit) {
    return num & (~(1LL << bit));
}

// TOGGLE BIT
// reverse the case of the given bit in the given number.
int toggle_bit(int num, int bit) {
    return num ^ (1LL << bit);
}

// COUNT BITS
// count the number of active/light bits in the given number
// There are 3 implementations:
// We can suppose that the time complexity of these implementations is O(log number)
// while the log number is actually the number of bits in the worst case
// and actually the time complexity is lower.

// Implementation #1
int count_bits(int num) {
    // unsigned: for a negative int, (num >>= 1) keeps the sign bit (1) forever and the loop never ends.
    unsigned int u {(unsigned int) num};

    int cnt {};
    while(u) {
        cnt += (u & 1); // is the most right bit active or not?
        u >>= 1; // right shift 1 step.
    } return cnt;
}

// Implementation #2
int count_bits2(int num) {
    int cnt {};

    // Note: if num is long long the loop range will be until 64 not 32
    for(int i {}; i < 32; ++i)
        cnt += get_bit2(num, i);

    return cnt;
}

// Implementation #3 (Recommended):
int count_bits3(int num) {
    // Using a built-in function (optimized than the previous two implementations)
    // in case dt = long long --> use __builtin_popcountll().
    return __builtin_popcount(num);
}


// IS POWER OF TWO?
// is the given number a power of 2 or not?
// the number is a power of 2 if it has ONLY ONE ACTIVE BIT (and it is positive).

// Implementation #1
bool is_power_of_2_v1(int num) {
    return num > 0 && __builtin_popcount(num) == 1;
}

// Implementation #2 (Recommended)
bool is_power_of_2(int num) {
    // if the given num is a power of 2 then its subtraction with one will activate all its previous bits
    // e.g. 8 = 1000 and 8 - 1 = 7 = 0111 and (8 & 7) = 0 then 8 is a power of 2
    // n & (n-1) == 0 also happens for n = 0 (not a power of 2), so check n > 0 first.
    return num > 0 && !(num & (num - 1));
}


// MSB: the index of the highest active bit (the most LEFT one). -1 if there are no active bits.
int msb(int num) {
    for(int i {31}; i >= 0; --i) {
        if(get_bit2(num, i))
            return i;
    } return -1; // there are no active bits.
}

// LSB: the index of the lowest active bit (the most RIGHT one). -1 if there are no active bits.
int lsb(int num) {
    for(int i {}; i < 32; ++i)
        if(get_bit2(num, i))
            return i;

    return -1; // there are no active bits
}


/* ==================
* Suppose a problem says that I'll have an array of numbers and a huge number of queries (q)
* each query contains 2 integers left, right
* then I should return the AND, OR or X-OR of all the numbers in that range.
* So instead of doing O(n) time for each query to be the total O(N * Q)
* let's find an answer that takes ONLY O(N + Q) time:
* HINT (pre-processing/pre-computation)
*
* Input:  n, then n numbers, then q, then q lines of (l r) (1-based, both included).
* Output: for each query: AND, OR and X-OR of the range.
*/
void prefix_bit_operations() {
    int n; cin >> n;
    vector<int> nums(n);
    for(int& x: nums) cin >> x;

    // let's make our pre-processing
    // cause the AND bit-wise operator doesn't have an inverse
    // we'll work on each individual bit.
    // suppose the max(nums) = 1e9 =~ 2^30
    // pref[bit][i] = how many numbers among the first i numbers have this bit active.
    vector<vector<int>> pref(30, vector<int>(n + 1)); // inner-vector is 1-based index (n + 1), initially zeros

    for(int i {1}; i <= n; ++i)
        for(int bit {}; bit < 30; ++bit)
            pref[bit][i] += pref[bit][i - 1] + (nums[i - 1 /*0-based*/] >> bit & 1);

    int q; cin >> q;
    while(q--) {
        int l, r; cin >> l >> r;

        // prefix AND/OR/XOR (find the AND/OR/XOR of the given range (l, r))
        int ans_and {};
        int ans_or {};
        int ans_xor {};

        for(int b {}; b < 30; ++b) {
            int cnt {pref[b][r] - pref[b][l - 1]};

            if(cnt == r - l + 1) ans_and |= 1LL<<b; // the bit is active in ALL the numbers
            if(cnt) ans_or |= 1LL<<b;               // the bit is active in AT LEAST one number
            if(cnt & 1) ans_xor |= 1LL<<b; // in case we've an odd number from this bit, because if it is even the x-or = 0
        }

        cout << "AND the range = " << ans_and
            << "\nOR the range = " << ans_or
            << "\nX-OR the range = " << ans_xor
            << endl;
    }
}


void test_case() {
    // get / set / clear / toggle (40 = 101000)
    assert(get_bit(40, 3) && get_bit2(40, 3));
    assert(!get_bit(40, 2) && !get_bit2(40, 2));
    assert(set_bit(40, 0) == 41);
    assert(clear_bit(40, 3) == 32);
    assert(toggle_bit(40, 5) == 8 && toggle_bit(40, 0) == 41);

    // the sign bit (bit 31) works too
    assert(get_bit(INT_MIN, 31) && get_bit2(INT_MIN, 31));
    assert(set_bit(0, 31) == INT_MIN);

    // count bits (all 3 implementations agree, even for negative numbers)
    for(int x : {0, 1, 7, 40, 255, INT_MAX, -1, INT_MIN}) {
        assert(count_bits(x) == count_bits2(x));
        assert(count_bits(x) == count_bits3(x));
    }
    assert(count_bits(-1) == 32 && count_bits(255) == 8 && count_bits(0) == 0);

    // power of 2
    for(int x : {-8, 0, 1, 2, 3, 6, 8, 12, 16, 1 << 30, INT_MIN, INT_MAX}) {
        assert(is_power_of_2(x) == is_power_of_2_v1(x));
    }
    assert(is_power_of_2(1) && is_power_of_2(16) && is_power_of_2(1 << 30));
    assert(!is_power_of_2(0) && !is_power_of_2(12) && !is_power_of_2(-8) && !is_power_of_2(INT_MIN));

    // msb / lsb (40 = 101000: highest bit is 5, lowest is 3)
    assert(msb(40) == 5 && lsb(40) == 3);
    assert(msb(1) == 0 && lsb(1) == 0);
    assert(msb(INT_MIN) == 31 && lsb(INT_MIN) == 31);
    assert(msb(0) == -1 && lsb(0) == -1);

    cout << "All checks passed." << endl;
}

int main() {
    test_case();
    return 0;
}