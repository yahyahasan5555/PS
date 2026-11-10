#include<bits/stdc++.h>

#define Fast                ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define print(v)            for(auto& x: v) cout << x << ' '; cout << endl;
#define read(v)             for(auto& x: v) cin >> x;
#define sz(v)               ((int)((v).size()))
#define all(v)              ((v).begin()), ((v).end())
#define pb                  push_back

//    /\_/\
//   (= ._.)
//   / >  \>
using namespace std;
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

/***
 * There are 2 answers belowe:
 * 1. with next permutation built in function.
 * 2. collect the strings recursively
 */

vector<string> st;
vector<int> freq(26);
int n;

void collect(string cur = "") {
       if(cur.size() == n) {
              st.pb(cur);
              return;
       }

       for(int i {}; i < 26; ++i) {
              if(freq[i]) {
                     --freq[i];
                     collect(cur + char(i + 'a'));
                     ++freq[i];
              }
       }
}

void testCase(void) {
       string s; cin >> s;
       n = s.size();
       for(char c: s) ++freq[c - 'a'];
       collect();       

       cout << st.size() << endl;
       for(const string& str: st) cout << str << endl;
}

signed main() {
       #ifndef ONLINE_JUDGE
              freopen("in.txt", "r", stdin);
       #endif
       Fast

       // Ans #1
       testCase();

       // Ans #2
       // string str; cin >> str; sort(all(str));
       // vector<string> vec;
       // do {
       //        vec.pb(str);
       // } while(next_permutation(all(str)));

       // cout << vec.size() << endl;
       // for(const string& s: vec) cout << s << endl;
       return 0;
}