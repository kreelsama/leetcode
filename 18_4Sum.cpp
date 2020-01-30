#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int size = nums.size();
        vector<vector<int>> quad;
        if(size < 4)
            return quad;
        sort(nums.begin(), nums.end());
        int tmp;
        for(int a = 0; a <= size - 4;){
            for(int b = a + 1; b <= size - 3;){
                for(int c = b + 1, d = size - 1; c < d;){
                    tmp = nums[a] + nums[b] + nums[c] + nums[d] - target;
                    if(tmp > 0){
                        d --;
                    }
                    else if (tmp < 0){
                        c ++;
                    }
                    else{
                        quad.push_back(vector<int>{nums[a], nums[b], nums[c], nums[d]});
                        do{
                            c ++;
                        }while(c < d && nums[c] == nums[c-1]);
                        do{
                            d --;
                        }while(d > c && nums[d] == nums[d+1]);
                    }
                }
                do{
                    b ++;
                }while(b <= size - 3 && nums[b] == nums[b-1]);
            }
            do{
                a ++;
            }while(a <= size - 4 && nums[a] == nums[a-1]);
        }
        return quad;
    }
};

int main(){
    vector<int> nums {-1,0,-5,-2,-2,-4,0,1,-2};
    auto res = Solution().fourSum(nums, -9);
    for(auto each:res){
        for (auto c:each){
            cout << c << ' ' ;
        }
    cout << endl;
    }
    return 0;
}