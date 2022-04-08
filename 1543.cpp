#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
} TreeNode;

class Solution {
public:
    int paths = 0;
    int pseudoPalindromicPaths (TreeNode* root) {
        vector<int> occurences(10, 0); // index 0 is not used
        DFS(root, occurences);
        return paths;
    }

    void DFS(const TreeNode* tree, vector<int> occurences){
        occurences[tree->val] += 1;

        if(!tree->left && !tree->right){
            if(containPalindromic(occurences))
                paths += 1;
            return;
        }
        
        if(!tree -> left){
            DFS(tree->left, occurences);
        }
        if(!tree->right){
            DFS(tree->right, occurences);
        }
    }

    bool containPalindromic (vector<int> vec){
        int odd_numbers = 0;

        for(auto &&each: vec){
            if(each & 1){
                odd_numbers += 1;
            }
        }
        
        return !(odd_numbers >= 2);
    }
};