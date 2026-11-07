#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// O(n) time ans:
vector<int> getDivs(int n) {
       vector<int> ans;
       for(int i {1}; i <= n; ++i) 
              if(n % i == 0)       
                     ans.push_back(i);
       return ans;
}

// O(sqrt(n)) time ans:
vector<int> getDivs2(int n) {
       vector<int> ans;

       int i;
       for(i = 1; i*i < n; ++i)
              if(n % i == 0)
                     ans.push_back(i), ans.push_back(n/i);
       return ans;
}
// ======================================================

// in O(n) (Check primarity):
bool isPrime(int n) {
       if(n == 1) return false; // Special case.

       for(int i {2}; i < n; ++i) 
              if(n % i == 0) return false;
       return true;
}

// In O(sqrt n):
bool isPrime2(int n) {
       if(n == 1) return false; // Special case:

       /* Note: We added <= n (the equal sign) for sqrt numbers check.*/
       for(int i {2}; i*i <= n; ++i) 
              if(n % i == 0) return false;
       return true;
}

/* Can we optimize the last version to be lower in the time complexity
 * cut the half time complexity.
 * by this inforoations:
 *  - the only primary even number is 2 (each other even number is complex)
 *  - so we can check in case 2, and iterate only on odd numbers to check
 * So:
 */
bool isPrime3(int n) {
       if(n == 2) return true;
       if(n == 1 || n % 2 == 0) return false;

       for(int i {3}; i <= n; i += 2)
              if(n % i == 0)
                     return false;
       return true;
}

//==========================================================================
// Prime factorization:
// In O(N) time
vector<int> primeFactorization(int n) {
       vector<int> ans;
       for(int i {2}; i <= n; ++i) {
              while(n % i == 0) {
                     n /= i;
                     ans.push_back(i);
              }
       } return ans;
}

// In O(sqrt n):
vector<int> primefactorization2(int n) {
       vector<int> ans;
       for(int i {2}; i * i <= n; ++i) {
              while(n % i == 0) {
                     n /= i;
                     ans.push_back(i);
              }
       }

       if(n != 1) ans.push_back(n);
       return ans;
}


/* Count of divisors	∏(aᵢ+1)
 * Sum of divisors	∏ (pᵢ^(aᵢ+1) − 1)/(pᵢ − 1)
 * Product of divisors	n^(d(n)/2)
 */

//=========================================
const int N = 1e6 + 10;
vector<int> arr[N]; // array of N  vectors
// int cnt[N];
void generateDivs() {
       for(int i {1}; i < N; ++i)
              for(int j {i}; j < N; j += i) {
                     arr[i].push_back(j);
                     // ++cnt[i];
              }
}

//=====================================

// O(n log log n)
vector<bool> is_prime(int n) {
       vector<bool> primes(n+1, true);
       primes[0] = primes[1] = false;

       for(int i {2}; i <= n; ++i) 
              if(primes[i])
                     for(int j {i*i}; j <= n; j += i)
                            primes[j] = false;

       return primes;
}

// Linear sieve in O(n) only (Euler sieve):
vector<int> linear_sieve(int n) {
       vector<int> primes;
       vector<bool> is_prime(n+1, true);
       is_prime[0] = is_prime[1] = false;

       for(int i {2}; i <= 2; ++i) {
              if(is_prime[i])
                     primes.push_back(i);

              for(int p: primes) {
                     if((ll)i * p > n) break;

                     is_prime[i*p] = false;

                     if(i % p == 0) break;
              }
       } return primes;
}
//==================

vector<int> lp;       // lp[i] = least prime factor of i
vector<int> primes;   // list of all primes found

void linear_sieve2(int n) {
       lp.assign(n + 1, 0);
       primes.clear();

       for(int i {2}; i <= n; ++i) {
              if(lp[i] == 0) {           // i has no smaller factor recorded → i is prime
                     lp[i] = i;
                     primes.push_back(i);
              }

              for(int p : primes) {
                     if(p > lp[i] || (long long)i * p > n) break;
                     lp[i * p] = p;
              }
       }
}

// Returns the prime factorization as a list of (prime, exponent) pairs.
vector<pair<int,int>> factorize(int x) {
       vector<pair<int,int>> factors;

       while(x > 1) {
              int p {lp[x]};
              int exp {};

              while(x % p == 0) {
                     x /= p;
                     ++exp;
              }

              factors.push_back({p, exp});
       }

       return factors;
}
//===================

void testCase(void) {
     
}

signed main() {
       // int t; cin >> t; while(t--)
       testCase();
       return 0;
}