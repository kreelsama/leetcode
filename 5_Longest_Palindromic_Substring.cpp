#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

auto min = [](int a, int b) -> int{ return a > b ? b : a; };

using namespace std;
class Solution {
public:
    string CentralExpansion(string s){
        string added = "#";
        for(auto c = s.begin(); c != s.end(); ++c){
            added += *c;
            added += '#';
        }
        return added;
    }
    //Apply Manacher's algorithm
    vector<int> Manacher(string s){
        int l = s.length();
        vector<int> p(l, 0);
        p[0] = 1;
        int central = 0;
        for(int i = 1; i < l; ++i){
            if(p[central] + central - 1 <= i){
                int j = 1;
                while(i - j >= 0 && i + j < l && s[i - j] == s[i + j]) ++j;
                p[i] = j;
                central = i;
            } else if(central <= i + p[2 * central - i] - p[central]){
                int j = central + p[central] - 1 - i;
                while(i - j >= 0 && i + j < l && s[i - j] == s[i + j]) ++j;
                p[i] = j;
            }else{
                p[i] = p[2 * central - i];
            }
        }
        return p;
    }

    string longestPalindrome(string s){
        if(s.length() <= 1)
            return s;
        string expanded = CentralExpansion(s);
        vector<int> p = Manacher(expanded);
        int m = 0, index = 0;
        for(int i = 0; i < expanded.length(); ++i){
            if(p[i] >= m){
                index = i;
                m = p[i];
            }
        }
        
        string res;
        for(int j = index - m + 1; j <= index + m - 1; ++j){
            if(expanded[j] != '#')
                res += expanded[j];
        }
        return res;
    }
};

int main(void){
    cout<<Solution().longestPalindrome(string("babab"))<<endl;
    return 0;
}