#include<vector>
#include<algorithm>
#include<iostream>

using namespace std;

class Solution {
public:
    int len = 0;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
        if(target == candidates[begin]){
            chain.push_back(target);
            results.push_back(chain);
        }
        else if(target == 0){
            results.push_back(chain);
        }
        else if(target < candidates[begin]){
            return;
        } else{
            for(int i = begin; i < len; ++i){
                vector<int> newchain(chain);
                newchain.push_back(candidates[i]);
                recursion(candidates, i, target - candidates[i], results, newchain);
            }
            return;
        }
    }
};

int main(){
    auto x = vector<int>{2,3,5};
    cout << Solution().combinationSum(x, 8).size() << endl;
}