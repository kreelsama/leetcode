#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows == s.length()){
            return s;
        }
        string t(s);
        int cur = 0;
        int j = 0;
        for (int i = 0; i < numRows; i++){
            j = 0;
            //cout << endl;
            while(true){
                //cout<<cur<<' '<<j<<endl;
                if(i == 0){
                    if(j*numRows - j >= s.length() ){
                        break;
                    }else{
                        t[cur++] = s[j*numRows - j];
                        j += 2;
                    }
                }else if(i == numRows - 1){
                    if((j+1)*numRows - (j+1) >= s.length() ){
                        break;
                    }else{
                        t[cur++] = s[(j+1)*numRows - (j+1)];
                        j += 2;
                    }
                }else {
                    if(j*(numRows-1) + i >= s.length()){
                        break;
                    }else{
                        t[cur++] = s[j*(numRows-1) + i];
                    }
                    j += 2;
                    if(j*(numRows  -1) - i >= s.length()){
                        break;
                    }else{
                        t[cur++] = s[j*(numRows  -1) - i];
                    }
                }
            }
        }
        return t;
    }
};

int main(void){
    string s ("ABCDE");
    cout<<Solution().convert(s, 4)<<endl;
    return 0;
}