#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    bool isTransformable(string s, string t) {
        int len = s.size();
        vector<int> S(len);
        vector<int> T(len);
        vector<int> positions(10, -1);
        bool flag;


        for(int i = 0; i < len; ++i){
            S[i] = s[i] - '0';
            T[i] = t[i] - '0';
            if(positions[T[i]] == -1){
                positions[T[i]] = i;
            }
        }

        for(int i = 0; i < len; ++i){
            if(positions[S[i]] == -1){
                return false;
            }

            for(int n = S[i]+1; n < 10; ++n){
                if(positions[n] != -1 && positions[n] < positions[S[i]]){
                    return false;
                }
            }

            for(int pos = positions[S[i]]+1; pos < len; ++pos){
                if(S[i] == T[pos]){
                    positions[S[i]] = pos;
                    flag = true;
                    break;
                }
            }

            if(!flag){
                positions[S[i]] = -1;
            }
            flag = false;
        }
        return true;
    }
};