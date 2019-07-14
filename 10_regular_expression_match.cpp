#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    bool isMatch(string s, string p){
        int ptrs = 0, ptrp = 0;
        if(p.length() == 0){
            if(s.length() == 0)
                return true;
            else return false;
        }
        while(ptrp < p.length()){
            if(ptrp == p.length() - 1){
                if(ptrs != s.length() - 1)
                    return false;
                if(p[ptrp] == '.')
                    return true;
                else
                    return s[ptrs] == p[ptrp];
            } 
            if (p[ptrp + 1] == '*'){//Assumming there is NO consecutive asterisks.
                if(p[ptrp] == '.'){
                    for(;ptrs <= s.length(); ptrs ++){
                        if(isMatch(s.substr(ptrs), p.substr(ptrp + 2))){
                            return true;
                        }
                    }
                    return false;
                }
                else{
                    for(;ptrs<=s.length(); ptrs ++){
                        if(s[ptrs] == p[ptrp]){
                            if(isMatch(s.substr(ptrs), p.substr(ptrp + 2)))
                                return true;
                        }
                        else break;
                    }
                    ptrp += 2;
                }
            }
            else if(p[ptrp] == '.'){
                if(ptrs >= s.length() )
                    return false;
                ptrp ++;
                ptrs ++;
            }
            else{
                if(s[ptrs] != p[ptrp])
                    return false;
                ptrp ++;
                ptrs ++;
            }
        }
        if(ptrp == p.length() && ptrs == s.length() )
            return true;
        else return false;
    }
};

int main(void){
    cout<<Solution().isMatch(string("aaa"), string("a.*a")) << endl;
    return 0;
}