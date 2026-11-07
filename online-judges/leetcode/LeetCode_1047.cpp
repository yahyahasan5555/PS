//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/

class Solution {
public:
  string removeDuplicates(string s) { // O(n) time, O(n) memory because copy the string s, and full the stack with 'n' chars
       stack<char> st;
       for(char c: s) {
              if(st.empty() || st.top() != c) st.push(c);
              else { // same adjacent letters
                     while(!st.empty() && st.top() == c) st.pop();
              }
       } 
       
       string res;
       while(!st.empty()) res.push_back(st.top()), st.pop();
       reverse(res.begin(), res.end());
       return res;
  }
};
