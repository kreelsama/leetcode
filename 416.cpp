#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sum = 0;
        for(auto& each:nums){
            sum += each;
        }
        if(sum % 2)
            return false;
        sum /= 2;
        int len = nums.size();
        vector<vector<bool>> dp(len);
        for(auto &each:dp){
            each.resize(sum + 1);
        }
        dp[0][nums[0]] = 1;
        for(int i = 1; i < len; ++i){
            for(int j = 0; j < sum + 1; ++j){
                if(j == nums[i])
                    dp[i][j] = true;
                else if (j < nums[i])
                    dp[i][j] = dp[i-1][j];
                else
                    dp[i][j] = dp[i-1][j-nums[i]] || dp[i-1][j];
            }
        }
        return dp[len-1][sum];
    }
};

int main(void){
    vector<int> nums {2,2,1,1};
    cout << Solution().canPartition(nums) << endl;
    return 0;
}