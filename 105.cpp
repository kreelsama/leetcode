#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
 
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return build(preorder, 0, preorder.size(), inorder, 0, inorder.size());
    }

    TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir){
        if(pr - pl == 0){
            return nullptr;
        }

        TreeNode *node = new TreeNode(preorder[pl]);

        int mid_idx=0;

        for(int i = il; i < ir; ++i){
            if(inorder[i] == preorder[pl]){
                mid_idx = i;
                break;
            }
        }

        node->left = build(preorder, pl+1, pl+mid_idx, inorder, il, il+mid_idx-1);
        node->right = build(preorder, pl+mid_idx+1, pr, inorder, il+mid_idx+1, ir);
        
        return node;
    }
};