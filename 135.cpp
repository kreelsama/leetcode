#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int size = ratings.size();

        vector<int> left(size, 0);
        vector<int> right(size, 0);
        left[0] = right[size-1] = 1;

        for(int i = 1; i < size; ++i){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            } else{
                left[i] = 1;
            }
        }

        for(int i = size - 2; i >= 0; --i){
            if(ratings[i] > ratings[i+1]){
                right[i] = right[i+1] + 1;
            }else{
                right[i] = 1;
            }
        }

        int sum = 0; 

        for(int i = 0; i < size; ++i){
            sum += max(left[i], right[i]);
        }
        return sum;
    }
};