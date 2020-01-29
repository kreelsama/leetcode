#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(!strs.size())
            return string("");
        string prefix;
        int minlen = strs[0].length();
        for(auto s:strs){
            if(s.length() < minlen)
                minlen = s.length();
        }
        char c;
        for(int i = 0; i < minlen; ++i){
            c = strs[0][i];
            for(int j = 0; j < strs.size(); ++j){
                if(strs[j][i] != c){
                    return prefix;
                }
            }
            prefix += c;
        }
        return prefix;
    }
};

int main(void){
    vector<string> strs {"abca", "abca"};

    cout << Solution().longestCommonPrefix( strs ) << endl;
    return 0;
}