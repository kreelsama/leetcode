#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    //KMP alg. to implement strstr()
    //if understood, KMP code can be surprisingly compact
    int strStr(string haystack, string needle) {
        if(!needle.size())
            return 0;
        int size = needle.size();
        int j = 0, i = 0;
        vector<int> pi(size, 0);
        // Find max length of common prefix and surfix, write into pi[]
        for(i = 1; i < size; ++i){
            while(j > 0 && needle[j] != needle[i])
                j = pi[j - 1];
            if(needle[i] == needle[j])
                ++j;
            pi[i] = j;
        }
        //find first occurrence
        i = 0; j = 0;
        while(j < size && i < haystack.size()){
            if(haystack[i] == needle[j]){
                ++i; ++j;
            }
            else if(!j)
                ++i;
            else{
                j = pi[j-1];
            }
        }
        return j == needle.size() ? i - needle.size() : -1;
    }
};

int main(void){
    cout << Solution().strStr(string(""), string("bcd"));
}