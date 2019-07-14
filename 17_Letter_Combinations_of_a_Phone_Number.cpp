#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<string> strmap{"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        if(!digits.length())
            return vector<string>{};
        else{
            vector<string> s{""};
            vector<int> dig;
            for(auto each : digits){
                dig.push_back(each - '0');
            }
            comb(dig, 0, s);
            return s;
        }

    }
    void comb(vector<int> digits, int pos, vector<string> & str){
        if(digits.size() <= pos){
            return;
        }
        auto last = str[str.size()-1];
        str.pop_back();
        for(int i = 0; i < strmap[digits[pos]].length(); i++){
            str.push_back(last + strmap[digits[pos]][i]);
            comb(digits, pos + 1, str);
        }
    }
};

int main(void){
    string digits{"257"};
    auto res = Solution().letterCombinations(digits);
    for(auto each:res){
        cout<<each<<' ';
    }
    return 0;
}
