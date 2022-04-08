#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int windowsize = 0;
        
        for(auto &&i:nums){
            if (i){
                windowsize ++;
            }
        }
        int ans = 0;
        int variational_window = 0;
        for(int i = 0; i < windowsize; i ++){
            if(!nums[i]){
                variational_window ++;
            }
        }
        ans = variational_window;
        for(int i = 1; i < nums.size() ; i ++){
            variational_window += (nums[i-1] - nums[(i+windowsize-1)%nums.size()]);
            if(variational_window < ans){
                ans = variational_window;
            }
        }
        return ans;
    }
};


int main(void){
    vector<int> arr =  { 1,1,0,0,1};

    cout << Solution().minSwaps(arr) << endl;
    return 0;
}