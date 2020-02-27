#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int l = nums.size() - 1;
        if(!l)
            return;
        int flag = -1;
        for(; l >= 1; --l){
            if(nums[l - 1] < nums[l]){
                flag = l - 1;
                break;
            }
        }
        if(flag == -1){
            reverse(nums.begin(), nums.end());
            return;
        }
        int m = l;
        for(int i = l; i < nums.size(); ++i){
            if(nums[i] > nums[l - 1] && nums[i] < nums[m])
                m = i;
        }
        swap(nums[l - 1], nums[m]);
        sort(nums.begin() + l, nums.end());
    }
};

int main(void){
    vector<int> nums {1, 1};
    Solution().nextPermutation(nums);
    for(const auto& each : nums){
        cout << each << ' ';
    }
    return 0;
}