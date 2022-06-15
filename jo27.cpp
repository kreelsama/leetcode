#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    TreeNode* mirrorTree(TreeNode* root) {
        stack<TreeNode*> st;
        TreeNode *ptr;
        TreeNode *node;
        if(root)   
            st.push(root);
        while(!st.empty()){
            node = st.top();
            st.pop();
            ptr = node->left;
            node->left = node->right;
            node->right = ptr;
            if(node->left)
                st.push(node->left);
            if(node->right)
                st.push(node->right);
        }
        return root;
    }  
};