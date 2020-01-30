#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n){
    typedef struct ListNode Node;
    Node *prev, *rear, *cur;
    prev = rear = cur = head;
    for(int i = 1; i < n && rear; ++i){
        rear = rear->next;
    }
    if(!rear){
        return head;
    }
    if(!rear->next){
        return head->next;
    }
    rear = rear->next;
    cur = cur->next;
    while(rear->next){
        rear = rear->next;
        cur = cur->next;
        prev = prev->next;
    }
    prev -> next = cur -> next;
    return head;
}
