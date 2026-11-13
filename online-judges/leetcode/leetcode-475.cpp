
// 1 <= houses.length, heaters.length <= 3 * 104
// 1 <= houses[i], heaters[i] <= 109
class Solution {
       // space: O(houses)
       // Time: O(max(houses, min(houses, heaters)))
       bool can(int raduis, vector<int>& houses_pos, vector<int>& heaters_pos) {
              vector<bool> heatered_houses(houses_pos.size());
              
              int cur_heater_idx {};
              for(int i {}; i < houses_pos.size() && cur_heater_idx < (int) heaters_pos.size(); ) 
                     if(heaters_pos[cur_heater_idx] + raduis >= houses_pos[i] && heaters_pos[cur_heater_idx] - raduis <= houses_pos[i])
                            heatered_houses[i] =  true, ++i;
                     else ++cur_heater_idx;
              
              for(bool f: heatered_houses)
                     if(!f) return false;
              
              return true;
       }
public:
       // O(log 1e9 * O(can function))
       int findRadius(vector<int>& houses, vector<int>& heaters) {
              // there is no any evedence that the given array is sorted, so lets sort
              sort(houses.begin(), houses.end());            
              sort(heaters.begin(), heaters.end());

              int l {}, r {(int) 1e9}, mid, ans {-1};
              while(l <= r) {
                     mid = l + (r - l) / 2;
                     
                     if(can(mid, houses, heaters))
                            ans = mid, r = mid - 1;
                     else l = mid + 1;
              } return ans;
       }
};
