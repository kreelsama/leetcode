#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> validNums {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    vector<string> romans {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    string intToRoman(int num) {
        string res;
        for(int i = 0; i < 13; ++i){
            while(num - validNums[i] >= 0){
                num -= validNums[i];
                res += romans[i];
            }
        }
        return res;
    }
};

int main(void){
    cout<<Solution().intToRoman(1994)<<endl;
    return 0;
}