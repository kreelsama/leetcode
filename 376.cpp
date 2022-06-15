#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:

    int wiggleMaxLength(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1)
            return len;

        vector<int> dp_less(len, 1);
        vector<int> dp_more(len, 1);

        auto max = [](int a, int b){
            if(a > b)
                return a;
            else
                return b;
        };

        for(int i = len - 2; i >= 0; --i){
            for(int j = i + 1; j < len; ++j){
                if(nums[i] < nums[j]){
                    dp_more[i] = max(dp_more[i], dp_less[j] + 1);
                }
                else if (nums[i] > nums[j]){
                    dp_less[i] = max(dp_less[i], dp_more[j] + 1);
                } else
                    continue;
            }
        }

        int ans = 0;
        for(int i = 0; i < len; ++i){
            int tmp = max(dp_less[i], dp_more[i]);
            if(ans < tmp)
                ans = tmp;
        }
        return ans;
    }
};

int main(void){
    vector<int> nums = {1,17,5,10,13,15,10,5,16,8};
    cout << Solution().wiggleMaxLength(nums) << endl;
    return 0;
}