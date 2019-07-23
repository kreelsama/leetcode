#include <string>
#include <iostream>

using namespace std;
class Solution {
public:
    string longestPalindrome_CEA(string s) {//Center expansion alg.
        string ex("#");
        string res;
        for(auto each : s){
            ex += each;
            ex += '#';
        }
        int longest = 1;
        int j = 0;
        for(int i = 0; i < ex.length(); i ++){
            for(j = 0; j + i < ex.length() && i - j >= 0 && ex[i + j] == ex[i - j]; ++j);
            --j;
            int len = j * 2 + 1;
            if(len > longest){
                longest = len;
                res = ex.substr(i - j, len);
            }
        }
        string ret;
        for(int i = 1; i < res.length(); i += 2){
            ret += res[i];
        }
        return ret;
    }
};

int main(void){
    cout<<Solution().longestPalindrome_CEA(string("axbbxaxx"))<<endl;
    return 0;
}