#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

const double EPS {1e-9};
const double PI {acos(-1)};

double get_area(double r) {
       return PI * r * r;
}

bool can(double ar, int f, vector<double>& pie) {
       long long pieces {};
       for(double& area: pie) {
              pieces += (long long)(area / ar);
              
              if(pieces >= f) 
                     return true;     
       } 

       return false;
}

void testCase(void) {
       int n, f; cin >> n >> f;
       
       vector<double> areas(n);
       for(double& area: areas) {
              int r; cin >> r;
              area = get_area((double) r);
       }

       ++f; // Friends and me too.
       double l {}, r {get_area(1e4)}, mid;
       for(int i {}; i < 100; ++i) {
              mid = l + (r - l) / 2;

              if(can(mid, f, areas))
                     l = mid;
              else r = mid;
       }

       // can I return mid, left or even the right.
       cout << fixed << setprecision(4) << mid << endl; 
}

signed main() {
       int t; cin >> t;
       while(t--) testCase();


       return 0;
}