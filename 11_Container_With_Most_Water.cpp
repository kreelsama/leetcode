#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        // Double pointer solution.
        // Time: 97.9%, Mem: 61.2%
        int left = 0, right = height.size() - 1;
        int maxarea = (right - left) * min(height[left], height[right]);
        int area;
        while(right > left){
            area = (right - left) * min(height[left], height[right]);
            if(height[left] > height[right])
                -- right;
            else ++ left;
            if(area > maxarea)
                maxarea = area;
        }
        return maxarea;
    }
};

int main(void){
    vector<int> h {1,8,6,2,5,4,8,3,7};
    cout<<Solution().maxArea(h)<<endl;
    return 0;
}