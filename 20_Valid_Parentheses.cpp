#include <iostream>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        string t;
        map<char, char> parath;
        parath['}'] = '{';
        parath[']'] = '[';
        parath[')'] = '(';
        for(auto each : s){
            if(parath.find(each) == parath.end()){
                t.push_back(each);
            }
            else{
                if(t[t.length() - 1] != parath[each])
                    return false;
                t.pop_back();
            }
        }
        return !t.length();
    }
};

int main(void){
    cout<<Solution().isValid(string("{{{}}}"))<<endl;
    return 0;
}