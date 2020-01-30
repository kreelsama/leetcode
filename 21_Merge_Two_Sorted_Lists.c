#include<stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* mergeTwoLists(struct ListNode* l1, struct ListNode* l2){
    if(!l1)
        return l2;
    if(!l2)
        return l1;
    typedef struct ListNode Node;
    Node* merged = NULL;
    if(l1->val <= l2->val){
        merged = l1;
        l1 = l1->next;
    }else{
        merged = l2;
        l2 = l2->next;
    }
    Node *cur = merged;
    while(l1 || l2){
        if(l1 && (!l2 || l1->val <= l2->val)){
            cur->next = l1;
            cur = cur->next;
            l1 = l1->next;
        }
        else{
            cur->next = l2;
            cur = cur->next;
            l2 = l2->next;
        }
    }
    return merged;
}