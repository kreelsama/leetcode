#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution{
public:
    bool isMatch_BruteForce(string s, string p){// TraceBack and Recursion
        int ptrs = 0, ptrp = 0;
        if(p.length() == 0){
            if(s.length() == 0)
                return true;
            else return false;
        }
        while(ptrp < p.length()){
            if(ptrp == p.length() - 1){
                if(ptrs != s.length() - 1)
                    return false;
                if(p[ptrp] == '.')
                    return true;
                else
                    return s[ptrs] == p[ptrp];
            } 
            if (p[ptrp + 1] == '*'){//Assumming there is NO consecutive asterisks.
                if(p[ptrp] == '.'){
                    for(;ptrs <= s.length(); ptrs ++){
                        if(isMatch_BruteForce(s.substr(ptrs), p.substr(ptrp + 2))){
                            return true;
                        }
                    }
                    return false;
                }
                else{
                    for(;ptrs<=s.length(); ptrs ++){
                        if(s[ptrs] == p[ptrp]){
                            if(isMatch_BruteForce(s.substr(ptrs), p.substr(ptrp + 2)))
                                return true;
                        }
                        else break;
                    }
                    ptrp += 2;
                }
            }
            else if(p[ptrp] == '.'){
                if(ptrs >= s.length() )
                    return false;
                ptrp ++;
                ptrs ++;
            }
            else{
                if(s[ptrs] != p[ptrp])
                    return false;
                ptrp ++;
                ptrs ++;
            }
        }
        if(ptrp == p.length() && ptrs == s.length() )
            return true;
        else return false;
    }

    bool isMatch_BruteForce_Improved(string s, string p){
        // Performance is worse than above.
        if(!p.length())
            return !s.length();
        bool first = bool(s.length()) & (p[0] == '.' | s[0] == p[0]);
        if(p.length() >= 2 && p[1] == '*'){
            return isMatch_BruteForce_Improved(s, p.substr(2)) \
            || (first && isMatch_BruteForce_Improved(s.substr(1), p));
        } else {
            return first && isMatch_BruteForce_Improved(s.substr(1), p.substr(1));
        }
    }

    bool isMatch_DP(string s, string p){// Dynamic Programming 
        int m = s.length(), n = p.length();
        vector<vector<bool>> dp(m + 1);
        for(auto &t:dp ){
            t.resize(n + 1);
        }

        dp[0][0] = true;
        for(int i = 1; i < n + 1; i++ ){
            if(p[i-1] == '*' && dp[0][i-2])
                dp[0][i] = true;
        }

        for(int i = 1; i < m + 1; ++i){
            for(int j = 1; j < n + 1; ++j){
                if(s[i-1] == p[j-1] || p[j-1] == '.')
                    dp[i][j] = dp[i - 1][j - 1];
                if(p[j-1] == '*'){
                    if(p[j - 2] == s[i-1] || p[j - 2] == '.')
                        dp[i][j] = dp[i - 1][j] || dp[i][j - 1] || dp[i][j - 2]; 
                    else
                        dp[i][j] = dp[i][j - 2];
                }
            }
        }
        return dp[m][n];
    }
};

int main(void){ 
    cout<<Solution().isMatch_DP(string("abb"), string("ab*b")) << endl;
    return 0;
}