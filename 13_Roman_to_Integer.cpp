#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        map<string, int> intmap;
        int len = s.length();
        int num = 0;
        vector<int> validNums {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        vector<string> romans {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for(int i = 0; i < 13; i++){
            intmap.insert(map<string, int>::value_type(romans[i], validNums[i]));
        }
        for(int i = 0; i < len; ){
            if(i + 1 < len){
                if(intmap.find(s.substr(i, 2)) != intmap.end()){
                    num += intmap[s.substr(i, 2)];
                    i += 2;
                    continue;
                }
            }
            num += intmap[s.substr(i, 1)];
            ++i;
        }
        return num;
    }
};

int main(void){
    cout<<Solution().romanToInt(string("IV"))<<endl;
    return 0;
}