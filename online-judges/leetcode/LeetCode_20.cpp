//https://leetcode.com/problems/valid-parentheses/

#include <stack>
class Solution {
private:
    bool is_opened(char c) {
        return c == '(' || c == '[' || c == '{';
    }

    char get_opened(char closed) {
        if(closed == ')') return '(';
        if(closed == ']') return '[';
        return '{';
    }

public:
    bool isValid(const string& str) { // O(n) time, O(1) memory
        stack<char> st;

        for(char c: str) {
            if(is_opened(c)) st.push(c);
            else {
                    if(st.empty() || st.top() != get_opened(c)) return false;
                    st.pop();
            }   
        } return st.empty();
    }
};
