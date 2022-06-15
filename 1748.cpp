class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0, hash[101] = {0};
        for(auto&& each:nums){
            hash[each] ++;
        }

        for(int n = 1; n <= 100; ++n ){
            if (hash[n] == 1)
                sum += n;
        }
        return sum;
    }
};