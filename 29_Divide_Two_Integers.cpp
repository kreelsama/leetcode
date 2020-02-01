#include <iostream>
#include <limits.h>
class Solution {
public:
    int divide(int A, int B) {
        if(A==INT_MIN&&B==-1) return INT_MAX;
        if(B==INT_MIN) return A==B;
        if(B==1) return A;
        int a=A,b=abs(B),res=0,i,j;
        for(;A>=0?a>=b:a<=-b;) {
            for(i=30;!((1<<i)&b);i--);
            for(j=30-i;A>=0?a<(b<<j):a>-(b<<j);j--);
            a-=A>=0?(b<<j):-(b<<j);
            res+=(1<<j);
        }
        return (A>0)==(B>0)?res:-res;
    }
};

int main(){
    std::cout << Solution().divide(-2147483648, -1) << std::endl;
    return 0;
}
