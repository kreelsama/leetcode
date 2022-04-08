#include <string>
#include <vector>
#include <iostream>

using namespace std;


class Solution {
public:
    vector<long long> factorials= {1,1,2,6,24,120,720,5040,40320,362880};
    string getPermutation(int n, int k) {
        vector<char> digits(n, 0);

        for(auto i=0; i<n; ++i){
            digits[i] = '0' + i + 1;
        }

        string result;
        while(k>1){
            int idx = k / factorials[n-1];
            if(k % factorials[n-1] == 0){
                idx -= 1;
            }
            auto iter = digits.begin()+idx;

            cout << idx << endl;

            result.push_back(*iter);
            
            digits.erase(iter);
            n -= 1;
            k -= idx*factorials[n];
        }

        for(auto &&c:digits){
            result.push_back(c);
        }
        return result;

        // return find(digits, n, k);
    }

    string find(vector<char> digits, int n, int k){
        string result;
        if(k == 1){
            for(auto &&c:digits){
                result.push_back(c);
            }
            return result;
        }
        int idx = k / factorials[n-1];
        if(k % factorials[n-1] == 0){
            idx -= 1;
        }
        cout << idx << endl;
        auto iter = digits.begin()+idx;
        result.push_back(*iter);
        
        digits.erase(iter);

        return result + find(digits, n - 1, k - idx*factorials[n-1]);

    }
};


int main(void){
    cout << Solution().getPermutation(7,3333) << endl;

}