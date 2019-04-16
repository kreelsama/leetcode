#include <iostream>
#include <string>
#include <limits>
using namespace std;

class Solution {
public:
    string strip(string str){
        int i = 0;
        while(str[i++]==' ');
        return str.substr(i-1);
    }

    int myAtoi(string str) {
        if(!str.length())
            return 0;
        int int_max = numeric_limits<int>::max();
        int int_min = numeric_limits<int>::min();
        str = strip(str);
        cout<<str<<endl;
        int res = 0, flag = 1, cur = 0;
        if(str[0] == '-'){
            flag = -1;
            cur ++;
        }else if(str[0] == '+'){
            cur ++;
        }
        for (; cur < str.length(); cur++){
            if(str[cur] < '0' || str[cur] > '9')
                break;
            int th = str[cur] - '0';
            if(flag > 0){
                if ((int_max - th) / 10 < res ){
                    cout<<"Overflow!"<<endl;
                    return int_max;
                }else res = res * 10 + th;
            }else{
                if((int_min + th) / 10 > res){
                    cout<<"Overlfow!"<<endl;
                    return int_min;
                }else res = res * 10 - th;
            }
        }
        return res;
    }
};

int main(void){
    cout<<Solution().myAtoi(string("42"))<<endl;
}