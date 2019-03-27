#include <map>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        ios::sync_with_stdio(false);
        cin.tie(0);
        unordered_map<int, int> table;
        for (int i = 0; i < nums.size(); i++){
            if(table.find(target - nums[i]) != table.end()){
                return {table[target - nums[i]], i };
            }
            table[nums[i]] = i;
        }
        return {};
    }
};

int main(){
    auto test = vector<int>{3,2,4};
    auto vec = Solution().twoSum(test, 6);
    cout << vec[0] << vec[1] << endl;

    return 0;
}
