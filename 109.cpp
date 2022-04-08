#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


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
    vector<ListNode*> sorted_array;
    void build(TreeNode* tree, int left, int right){
        if(left > right)
            return;
        int median = (right + left) / 2;
        TreeNode* node = new TreeNode(sorted_array[median]->val);
        if(sorted_array[median]->val < tree->val){
            tree->left = node;
        }
        else{
            tree->right = node;
        }
        if(left == right)
            return;
        build(node, left, median - 1);
        build(node, median+1, right);
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = 0;
        ListNode *ptr = head;
        if(!ptr)
            return nullptr;
        while(ptr) {n++; ptr = ptr->next;};
        ptr = head;
        sorted_array.reserve(n);
        for(int i = 0; i < n; ++i){
            sorted_array[i] = ptr;
            ptr = ptr->next;
        }
        int median = n / 2;

        TreeNode* tree = new TreeNode(sorted_array[median]->val);

        build(tree, 0, median-1);
        build(tree, median+1, n-1);

        return tree;
    }
};