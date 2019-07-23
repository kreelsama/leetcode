#include <string>
#include <iostream>
#include <vector>

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

    string longestPalindrome_Manacher(string s) {//Manacher's Algorithm
        string t("#");
        for(auto each : s){
            t += each;
            t += '#';
        }
        int max_mid = 0;
        int tmp_mid = 0;
        vector<int> p(t.length());
        for(int i = 1; i < t.length(); ++i){
            if(i >= tmp_mid + p[tmp_mid]){
                while(i - p[i] >= 0 && i + p[i] < t.length() && t[i + p[i]] == t[i - p[i]])
                    p[i]++;
                p[i] --;
            }
            else{
                int ix = 2 * tmp_mid - i;
                if(ix - p[ix] <= tmp_mid - p[tmp_mid]){
                    p[i] = tmp_mid + p[tmp_mid] - i;
                    while(i - p[i] >= 0 && i + p[i] < t.length() && t[i + p[i]] == t[i - p[i]] )
                        p[i]++;
                    p[i] --;
                }
                else
                    p[i] = p[ix];
                
            }
            if(p[max_mid] < p[i]){
                max_mid = i;
                tmp_mid = i;
            }
            if(tmp_mid + p[tmp_mid] < i + p[i])
                tmp_mid = i;
        }
        for(auto x:p)
            cout<<x<<' ';
        string res;
        for(int i = max_mid - p[max_mid] + 1; i <= max_mid + p[max_mid]; i += 2){
            res.push_back(t[i]);
        }
        return res;
    }
};

int main(void){
    cout<<Solution().longestPalindrome_CEA(string("axbbxaxx"))<<endl;
    cout<<Solution().longestPalindrome_Manacher(string(""))<<endl;
    return 0;
}