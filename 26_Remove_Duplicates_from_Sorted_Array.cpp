#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    //Native STL operation.
    int removeDuplicates(vector<int>& nums) {
        for(auto val=nums.begin(); val!=nums.end();){
            if(val+1!=nums.end() && *val == *(val+1)){
                nums.erase(val);
                continue;
            }
            ++val;//tricky place
        }
        return nums.size();
    }
    //Another solution is Double Pointer, which is omitted.
};

int main(){
    vector<int> nums {0,0,1,1,1,2,2,3,3,4,5,5,5,5,5};
    int s = Solution().removeDuplicates(nums);
    for(auto& s:nums)
        cout << s << ' ';
    return 0;
}