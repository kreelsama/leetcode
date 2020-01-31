struct ListNode {
    int val;
    struct ListNode *next;
};


struct ListNode* swapPairs(struct ListNode* head){
    typedef struct ListNode Node;
    if(!head || !head->next)
        return head;
    Node *prv, *nxt, *res;
    prv = head;
    nxt = head->next;
    res = nxt;
    prv->next = nxt->next;
    nxt->next = prv;
    nxt = prv->next;
    if(nxt)
        nxt = nxt->next;
    while(nxt){
        prv->next->next = nxt->next;
        nxt->next = prv->next;
        prv->next = nxt;
        nxt = nxt->next->next;
        if(nxt)
            nxt = nxt->next;
        prv = prv->next->next;
    }
    return res;
}
