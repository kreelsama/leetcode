#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int size = nums.size();
        int min = 0x3fffff;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= size - 3; ++i){
            for(int j = i + 1, k = size - 1; j < k; ){
                int s = nums[i] + nums[j] + nums[k] ;
                if(s - target < 0)
                    j ++;
                else if(s - target > 0)
                    k --;
                else return s;
                if(abs(s - target) < abs(min - target))
                    min = s;
            }
        }
        return min;
    }
};

int main(){
    vector<int> nums {-4,-1,1,2};
    cout << Solution().threeSumClosest(nums, 1) << endl;
    return 0;
}