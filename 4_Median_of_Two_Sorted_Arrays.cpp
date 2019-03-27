#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
static int fastio = [](){
        ios::sync_with_stdio(false);
        cin.tie(0);
        return 0;
}();
/* Attempts of Merging.
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merged(nums1.size() + nums2.size());
        ios::sync_with_stdio(false);
        cin.tie(0);
        //Ver1, artificial merge
        int i = 0, j = 0, k = 0;
        while (k < merged.size()){
            if (i < nums1.size() && j < nums2.size()){
                merged[k] = nums1[i] > nums2[j] ? nums2[j++] : nums1[i++];
            }
            else if (i == nums1.size()){
                merged[k] = nums2[j++];
            }
            else if (j == nums2.size()){
                merged[k] = nums1[i++];
            }
            else{
                break;
            }
            k++;
        }
        //Ver2: STL merge function, which performs worse than above.
        // merge( nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),back_inserter(merged) );
        int len = merged.size();
        if( len % 2 ){
            return merged[len / 2];
        }
        else{
            return ((double)merged[len/2] + (double)merged[len/2 -1]) / 2;
        }
        return 0;
    }
};
*/

//Attempts of find_k alg.
class Solution{
public:
    int find_k(vector<int> nums1, int start1, vector<int> nums2, int start2, int k){
        //cout << "start1:" << start1 << " start2:" << start2 << " k:" << k <<endl;
        if(nums1.size() <= start1 )
            return nums2[k + start2 - 1];
        if(nums2.size() <= start2 )
            return nums1[k + start1 - 1];
        if(k <= 1){
            return nums1[start1] < nums2[start2] ? nums1[start1] : nums2[start2];
        }
        int mid = k/2 - 1;
        int a = mid + start1 > nums1.size() - 1 ? nums1.size() - start1 - 1: mid;
        int b = mid + start2 > nums2.size() - 1 ? nums2.size() - start2 - 1: mid;
        //cout << "a:" << a << " b:" << b << endl;
        if(nums1[start1 + a] < nums2[start2 + b]){
            return find_k(nums1, start1 + a + 1, nums2, start2, k - a - 1);
        }
        else if(nums1[start1 + a] > nums2[start2 + b]){
            return find_k(nums1, start1, nums2, start2 + b + 1, k - b - 1);
        }
        else if(a + b + 2 < k){
            return find_k(nums1, start1 + 1, nums2, start2 + 1, k - 2);
        }
        else {
            return nums1[start1 + a];
        }
    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int k = nums1.size() + nums2.size();
        if (k % 2){
            return find_k(nums1, 0, nums2, 0, k / 2 + 1);
        }
        else{
            return (find_k(nums1, 0, nums2, 0, k/2) + find_k(nums1, 0, nums2, 0, k/2 + 1)) / 2.0;
        }
    }
};


int main(){
    auto vec1 = vector<int>{1,3};
    auto vec2 = vector<int>{2,4};
    cout<<Solution().findMedianSortedArrays(vec1, vec2)<< endl;
    return 0;
}
