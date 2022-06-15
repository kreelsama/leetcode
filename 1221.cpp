class Solution {
public:
    int balancedStringSplit(string s) {
        int Rs = 0, Ls = 0, cur;
        int ans = 0;

        for(cur = 0; cur < s.size(); ++cur){
            if(s[cur] == 'R')
                Rs ++;
            else
                Ls ++;
            if(Rs == Ls){
                ans ++;
                Rs = Ls = 0;
            }
        }
        return ans;
    }
};