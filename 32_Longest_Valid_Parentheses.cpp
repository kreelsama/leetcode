#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        if(!len)
            return 0;
        stack<pair<char, int>> st;
        vector<int> valid(len, 0);
        st.push(make_pair(s[0], 0));
        for(int i = 1; i < len; ++i){
            if(s[i] == '('){
                st.push(make_pair(s[i], i));
            }
            else if(st.size() && st.top().first == '('){
                if(st.top().second - 1  >= 0)
                    valid[i] = valid[i - 1] + valid[st.top().second - 1] + 2;
                else valid[i] = valid[i - 1]  + 2;
                st.pop();
            }
        }   
        return *max_element(valid.begin(), valid.end());
    }
};

int main(void){
    string s("(())()()(()()((())))()())))(())))))()())())((()()()())()()((()(()(()((()()()()(((((((()())(()()(()()");
    cout << Solution().longestValidParentheses(s) << endl;
    return 0;
}