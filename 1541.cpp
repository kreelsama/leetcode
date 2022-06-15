#include <stack>
class Solution {
public:
    int minInsertions(string s) {
        int lsize = 0,inserts = 0;
        bool wait = false;

        for(int cur = 0; cur < s.size(); ++ cur){
            if(s[cur] == '('){
                if(wait){
                    inserts += 1;
                    if(lsize)
                        lsize --;
                    else
                        inserts ++;
                    wait = false;
                }
                lsize ++;
            }
            else { // match: ')'
                if(wait){
                    wait = false;
                }
                else{
                    wait = true;
                    continue;
                }

                if(lsize)
                    lsize --;
                else
                    inserts ++;
            }
        }

        if(wait){
            if(!lsize)
                inserts += 2;
            else{
                inserts ++;
                lsize --;
            }
        }

        inserts += lsize*2;

        return inserts;
    }
};

int minInsertions(char * s){
    int lsize = 0,inserts = 0;
    int wait = 0;

    for(int cur = 0; s[cur] != 0; ++ cur){
        if(s[cur] == '('){
            if(wait){
                inserts += 1;
                if(lsize)
                    lsize --;
                else
                    inserts ++;
                wait = 0;
            }
            lsize ++;
        }
        else { // match: ')'
            if(wait){
                wait = 0;
            }
            else{
                wait = 1;
                continue;
            }

            if(lsize)
                lsize --;
            else
                inserts ++;
        }
    }

    if(wait){
        if(!lsize)
            inserts += 2;
        else{
            inserts ++;
            lsize --;
        }
    }

    inserts += lsize*2;

    return inserts;

}