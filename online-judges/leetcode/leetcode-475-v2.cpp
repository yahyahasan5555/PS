class Solution {
       // Suppose n = houses's size && m = heaters' size
       // Time: O(n + m)
       // Space: O(1) extra
       bool possible(int raduis, vector<int>& houses, vector<int>& heaters) {
              int cur_house {};
              for(int heater: heaters) {
                     while(cur_house < (int)houses.size() && heater + raduis >= houses[cur_house] && heater - raduis <= houses[cur_house])
                            ++cur_house;
              }

              return cur_house == (int) houses.size();
       }
public:
       // Time: (10^9 * (n + m))
       int findRadius(vector<int>& houses, vector<int>& heaters) {
              sort(houses.begin(), houses.end());
              sort(heaters.begin(), heaters.end());

              int l {}, r {(int) 1e9 /*or max house pos*/}, mid, ans {-1};
              while(l <= r) {
                     mid = l + (r - l) / 2;
                     if(possible(mid, houses, heaters))
                            ans = mid, r = mid - 1;
                     else l = mid + 1;
              }  
              return ans;
       }
};