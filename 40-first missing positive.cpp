#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int N = nums.size();
        for(auto& num:nums){
            if(num <= 0){
                num = N+1;
            }
        }
        for(int i = 0; i < N; i++){
            if(abs(nums[i]) > N || nums[abs(nums[i]) - 1] < 0){
                continue;
            }
            else{
                nums[abs(nums[i]) - 1] = -nums[abs(nums[i]) - 1];
            }
        }
        for(int i = 0; i < N; i++){
            if(nums[i] >= 0){
                return i+1;
            }
        }
        return N+1;
    }
};