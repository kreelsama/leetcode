#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int size = nums.size();
        vector<vector<int>> triplet;
        if(size < 3)
            return triplet;
        sort(nums.begin(), nums.end());
        for(int i = 0; nums[i] <= 0 && i <= size - 3;){
            for(int j = i + 1, k = size - 1; j < k;){
                if(nums[i] + nums[j] + nums[k] > 0){
                    --k;
                }else if (nums[i] + nums[j] + nums[k] < 0){
                    ++j;
                }else{ // equals 0
                    triplet.push_back(vector<int>({nums[i], nums[j], nums[k]}));
                    do{
                        ++j;
                    }while(j < k && nums[j] == nums[j-1]);
                    do{
                        --k;
                    }while(j < k && nums[k] == nums[k+1]);
                }
            }
            do{
                ++i;
            }while(i <= size -3 && nums[i] == nums[i-1]);
        }
        return triplet;
    }
};

int main(void){
vector<int> nums{0,0,0};
auto res = Solution().threeSum(nums);
for(auto each:res){
    for (auto c:each){
        cout << c << ' ' ;
    }
    cout << endl;
}
return 0;
}