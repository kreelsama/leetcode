class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int hash[501] = {0};
        for(auto&& n:nums){
            hash[n] ++;
        }
        for(auto&& cnt:hash){
            if(cnt & 1)
                return false;
        }
        return true;
    }
};