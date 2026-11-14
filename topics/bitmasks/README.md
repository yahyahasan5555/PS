# Bit-masks & Bit-wise Operations

Problem-solving lecture notes + C++ code.

| File                                                                                                                                                   | What it has                                                                              |
| ------------------------------------------------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------- |
| [`bit_operations.cpp`]([https://claude.ai/chat/bit_operations.cpp](https://github.com/yahyahasan5555/PS/blob/main/topics/bitmasks/bit-operations.cpp)) | get / set / clear / toggle bit, count bits, power of 2, MSB / LSB, prefix AND / OR / XOR |
| [`bitset_demo.cpp`]([https://claude.ai/chat/bitset_demo.cpp](https://github.com/yahyahasan5555/PS/blob/main/topics/bitmasks/bitset-operations.cpp))    | `std::bitset` functions with examples                                                    |
| `apple_division.cpp`                                                                                                                                   | CSES 1623 solution (complete search with a bit-mask)                                     |
|                                                                                                                                                        |                                                                                          |

---

## 1. Logical vs bit-wise operators

||Logical|Bit-wise|
|---|---|---|
|AND|`&&`|`&`|
|OR|`\|`|`\|`|
|NOT|`!`|`~`|
|XOR|none|`^`|

- **Logical** operators work on the **whole value** (zero = false, anything else = true) and give `true` / `false`.
- **Bit-wise** operators work on **each bit separately** and give a number.

Truth table (per bit):

|a|b|a & b|a \| b|a ^ b|~a|
|---|---|:-:|:-:|:-:|:-:|
|0|0|0|0|0|1|
|0|1|0|1|1|1|
|1|0|0|1|1|0|
|1|1|1|1|0|0|

```
  6 = 0110
  3 = 0011
 6 & 3 = 0010 = 2
 6 | 3 = 0111 = 7
 6 ^ 3 = 0101 = 5
```

All bit operations on a normal `int` / `long long` are **O(1)**.

---

## 2. Bits, indexes, MSB and LSB

- Bits are **0-indexed from the right**: bit `i` has the value `2^i`.

```
number : 40 = 1 0 1 0 0 0
bit idx:      5 4 3 2 1 0
```

- Bit 3 = 8 and bit 5 = 32, so `40 = 32 + 8`.
- Any bit is bigger than the **sum of all the bits below it** (`2^i > 2^0 + ... + 2^(i-1)`).
- **MSB** (most significant bit) = the **leftmost active** bit (here: bit 5).
- **LSB** (least significant bit) = the **rightmost active** bit (here: bit 3).
- The **parity** (even / odd) of a number is its bit 0: `n & 1`.

---

## 3. Negative numbers: two's complement

The **leftmost bit (bit 31 for `int`) is the sign bit**, and it has a **negative** weight (`-2^31`).

```
-x = ~x + 1          ~x = -x - 1
~5 = -6              -5 = ~5 + 1 = -6 + 1
```

- Negating twice gives the number back.
- `INT_MIN` (`-2^31`) has **only the sign bit** active.

---

## 4. Shifts

|Operation|Meaning|
|---|---|
|`n << x`|`n * 2^x`|
|`n >> x`|`floor(n / 2^x)`|

```cpp
5 << 3      // 40
-7 >> 1     // -4   (floor, the sign bit is kept)
-7 / 2      // -3   (/ truncates toward zero, so they are NOT the same for negatives)
```

> Careful: bits shifted out of the top are **lost** (overflow). Use `1LL << x` when `x` can be 31 or more.

---

## 5. Useful XOR / AND / OR facts

|Fact|Use|
|---|---|
|`x ^ 0 = x`|XOR with 0 keeps the bit|
|`x ^ 1 = !x`|XOR with 1 **flips** the bit|
|`x ^ x = 0`|equal numbers cancel (find the single number in a list of pairs)|
|`x & 1 = x` , `x \| 0 = x`|AND with 1 / OR with 0 keep the bit|
|`x & 0 = 0` , `x \| 1 = 1`|force the bit to 0 / 1|

---

## 6. Operator precedence (the classic traps)

From **high to low**: arithmetic `+ - * /` > shifts `<< >>` > relational `< >` > equality `== !=` > `&` > `^` > `|` > `&&` > `||`

```cpp
a & b == c        // means a & (b == c)   -> WRONG, write (a & b) == c
1 << n - 1        // means 1 << (n - 1)   -> write (1 << n) - 1 for "n ones"
```

**When in doubt, use parentheses.**

---

## 7. Basic bit operations

|Operation|Code|Idea|
|---|---|---|
|Get bit `i`|`(num >> i) & 1`|move bit `i` to the right, keep it|
|Set bit `i` (turn on)|`num \| (1LL << i)`|OR with a mask|
|Clear bit `i` (turn off)|`num & ~(1LL << i)`|AND with the opposite mask|
|Toggle bit `i`|`num ^ (1LL << i)`|XOR with a mask|

### Count active bits

|#|Way|Time|
|---|---|---|
|1|shift right in a loop and add `num & 1`|O(bits)|
|2|loop over the 32 bits with `get_bit`|O(32)|
|3|**`__builtin_popcount(num)`** (`__builtin_popcountll` for `long long`)|fastest, recommended|

### Is it a power of 2?

A power of 2 has **exactly one active bit**. `n - 1` turns that bit off and turns all the lower bits on:

```
8     = 1000
8 - 1 = 0111
8 & 7 = 0000   -> power of 2
```

```cpp
bool is_power_of_2(int n) { return n > 0 && !(n & (n - 1)); }   // n > 0 because 0 & (-1) is also 0
```

### MSB / LSB

Loop over the bits from the left (MSB) or from the right (LSB) and return the first active one. Return `-1` when there is no active bit.

---

## 8. Complete search with bit-masks (subsets)

A number from `0` to `2^n - 1` can represent **a subset of n items**: bit `i` is on if item `i` is **taken**.

```cpp
for (int mask = 0; mask < (1 << n); ++mask) {
    for (int i = 0; i < n; ++i)
        if (mask >> i & 1) {
            // item i is in this subset
        }
}
```

**Time: O(n * 2^n)**. Good for `n <= 20`. Use `long long` for sums.

### Example: CSES 1623 - Apple Division

[Problem link](https://cses.fi/problemset/task/1623): split `n` apples into two groups so the difference between the group weights is **minimum**.

- Try every subset as "group 1" (`2^n` masks).
- `sum1 =` weights of the taken apples, `sum2 = total - sum1`.
- Answer = `min(abs(sum1 - sum2))`.

Solution: [`apple_division.cpp`](https://github.com/yahyahasan5555/PS/blob/main/topics/bitmasks/apple-division.cpp)

---

## 9. Prefix AND / OR / XOR (many range queries)

**Problem:** an array of `N` numbers and `Q` queries `(l, r)`. For each query print the AND / OR / XOR of `a[l..r]`.

Doing a loop per query costs **O(N * Q)**. With pre-processing it costs **O(N + Q)**.

### XOR (the easy one)

XOR is its own inverse (`x ^ x = 0`), so one prefix array is enough:

```cpp
px[i] = px[i-1] ^ a[i];
answer(l, r) = px[r] ^ px[l-1];
```

### AND / OR (no inverse, so work per bit)

For each bit `b` keep `pref[b][i]` = how many of the first `i` numbers have bit `b` on. For a query, `cnt = pref[b][r] - pref[b][l-1]`:

|Result|Bit `b` is on when|
|---|---|
|AND|`cnt == r - l + 1` (on in **all** the numbers)|
|OR|`cnt > 0` (on in **at least one**)|
|XOR|`cnt` is **odd**|

**Time: O(30 * (N + Q)), memory: O(30 * N).** The code is `prefix_and()` in [`bit-operations.cpp`](https://github.com/yahyahasan5555/PS/blob/main/topics/bitmasks/bit-operations.cpp).

Example, array `1 3 5 7`:

|Query|AND|OR|XOR|
|---|:-:|:-:|:-:|
|1 4|1|7|0|
|2 4|1|7|1|
|4 4|7|7|7|

---

## 10. Trick: minimum XOR of any two numbers

Instead of checking all pairs (`O(n^2)`):

1. **Sort** the array.
2. The answer is the minimum of `a[i] ^ a[i+1]` over **adjacent** elements.

Time: **O(n log n)**.

**Why?** Take `a <= b <= c`. Let `k` be the highest bit where `a` and `c` differ.

- If `b` has `0` at bit `k`, then `a ^ b < 2^k <= a ^ c`.
- Otherwise `b ^ c < 2^k <= a ^ c`.

So a far pair is never better than a closer pair in between.

---

## 11. `std::bitset`

Code: [`bitset-operations.cpp`](https://github.com/yahyahasan5555/PS/blob/main/topics/bitmasks/bitset-operations.cpp)

```cpp
#include <bitset>
bitset<100000000> big;     // global! 1e8 bits ~ 12.5 MB
```

|Question|Answer|
|---|---|
|Max size?|The size is a **compile-time constant**. Around `1e8` bits is fine (about 12.5 MB, 1 bit each). Declare big ones **global**.|
|Random access?|`b[i]` is **O(1)**.|
|Set / reset / flip|`b.set(i)`, `b.reset(i)`, `b.flip(i)`, or without an index for **all** bits.|
|Count active bits|`b.count()`|
|Checks|`b.test(i)` (throws if out of range), `b.any()`, `b.none()`, `b.all()`, `b.size()`|
|Init from an integer|`bitset<8> b(13);` -> `00001101`|
|Init from a string|`bitset<8> b("10100000");`|
|Print as binary|`cout << b;` or `b.to_string()` (**most significant bit first**)|
|Print as decimal|`b.to_ulong()` or `b.to_ullong()` (throws if the value doesn't fit)|
|Operators|`& \| ^ ~ << >>` work on the whole bitset|

Bitset operations on the whole set run about **64 times faster** than a plain loop, because it packs 64 bits in one machine word.

---

## Summary

- Bits are 0-indexed from the right, bit `i` = `2^i`.
- `get` = `(n >> i) & 1`, `set` = `|`, `clear` = `& ~`, `toggle` = `^`.
- `n & (n - 1) == 0` and `n > 0` -> power of 2.
- A mask from `0` to `2^n - 1` = a subset -> **complete search in O(n * 2^n)**.
- XOR prefix = one array. AND / OR prefix = count per bit.
- Min XOR pair = sort + adjacent.
- Use `1LL <<` for big shifts and parentheses for precedence.
