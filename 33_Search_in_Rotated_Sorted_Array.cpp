#include <vector>
#include <iostream>

using namespace std;

    class Solution {
    public:
        int search(vector<int>& nums, int target) {
            int l = 0, r = nums.size() - 1;
            if(r < 0)
                return -1;
            int mid;
            while(l + 1 < r){
                mid = (l + r) / 2;
                if(nums[mid] > nums[l]){// pivot is right to the mid
                    if(target > nums[mid] || target < nums[l])
                        l = mid;
                    else r = mid;
                }
                else{// pivot is left to the mid
                    if(target < nums[mid] || target >= nums[l])
                        r = mid;
                    else l = mid;
                }
            }
            return nums[l] == target ? l : (nums[r] == target ? r : -1);
        }
    };

int main(void){
    vector<int> l {5, 6, 7, 3, 4};
    cout << Solution().search(l, 5) << endl;
    return 0;
}