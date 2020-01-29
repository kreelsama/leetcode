#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = height.size();
        int left = 0, right = l - 1;
        int maxarea = min(height[0], height[l-1]) * (l - 1);
        while(left < right){
            if(height[left] > height[right])
                right --;
            else left ++;
            maxarea = max(maxarea, min(height[left], height[right]) * (right - left));
        }
        return maxarea;
    }
};

int main(void){
    vector<int> h {1,8,6,2,5,4,8,3,7};
    cout<<Solution().maxArea(h)<<endl;
    return 0;
}