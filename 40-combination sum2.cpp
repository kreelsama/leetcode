#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    int len = 0;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> results;
        if(candidates.size()){
            sort(candidates.begin(), candidates.end());
        }
        else{
            return results;
        }
        len = candidates.size();
        vector<int> dummy;
        recursion(candidates, 0, target, results, dummy);
        return results;
    }
    
    void recursion(vector<int>& candidates, int begin, int target, vector<vector<int>>& results, vector<int>& chain){
        if(target == 0){
            results.push_back(chain);
            return;
        }

        if(begin >= len)
            return;
        
        if(target < candidates[begin]){
            return;
        } 

        if(target == candidates[begin]){
            chain.push_back(target);
            results.push_back(chain);
            return;
        }

        for(int i = begin; i < len; ++i){
            if(i > begin && len >= 1 && candidates[i] == candidates[i-1]){
                continue;
            }
            vector<int> newchain(chain);
            newchain.push_back(candidates[i]);
            recursion(candidates, i+1, target - candidates[i], results, newchain);
        }

    }
};

int main(){
    auto x = vector<int>{2,5,2,1,2};
    cout << Solution().combinationSum2(x, 5).size() << endl;
}