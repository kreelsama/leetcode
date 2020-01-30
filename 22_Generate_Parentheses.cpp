#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string generating;
    int degree;
    vector<string> parantheses;
    vector<string> generateParenthesis(int n) {
        this->degree = 0;
        if(!n)
            return this->parantheses;
        this->gen(string(""), n, 0);
        return this->parantheses;
    }
    void gen(string generated, int n, int degree){
        if(!n){
            for(int i = 0;i < degree; ++i){
                generated += ')';
            }
            this->parantheses.push_back(generated);
            return;
        }
        this->gen(generated + '(', n-1, degree + 1);
        if(degree > 0){
            this->gen(generated + ')', n, degree - 1);
        }
    }
};

int main(){
    vector<string> p = Solution().generateParenthesis(3);
    for(auto& each:p){
        cout << each << endl;
    }
    return 0;
}