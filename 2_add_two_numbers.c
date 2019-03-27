#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    int addup = 0;
    int a,b;
    struct ListNode * result_head = (struct ListNode*) malloc(sizeof(struct ListNode));
    struct ListNode * result = result_head;
    while( 1 ){
        a = l1 ? l1->val : 0;
        b = l2 ? l2->val : 0;
        result -> val = a + b + addup;
        addup = 0;
        if(result->val >= 10){
            addup = result->val / 10;
            result->val %= 10;
        }
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        if(addup || l1 || l2){
            printf("%d", addup);
            result->next = (struct ListNode*) malloc(sizeof(struct ListNode));
            result = result->next;
        }
        else{
            result -> next = NULL;
            break;
        }
    }
    return result_head;
}
