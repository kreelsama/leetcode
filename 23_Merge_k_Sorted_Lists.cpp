#include <iostream>
#include <cmath>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    //Attempt 1: O(n^2) solution
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0)
            return nullptr;
        using Node = struct ListNode;
        Node *merged = nullptr, *res = nullptr;
        int nmin = 0xffffff, minidx = 0;
        auto ptrs = lists;
        for(int i = 0; i < size; ++i){
            if(lists[i] && lists[i]->val < nmin){
                nmin = lists[i]->val;
                minidx = i;
            }
        }
        merged = lists[minidx];
        res = merged;
        if(!res)
            return res;
        lists[minidx] = lists[minidx]->next;
        while(any_of(lists.begin(), lists.end(), [](Node*p){return p;})){
            nmin = 0xFFFFFFF;
            for(int i = 0; i < size; ++i){
                if(lists[i] && nmin > lists[i]->val){
                    nmin = lists[i]->val;
                    minidx = i;
                }
            }
            merged->next = lists[minidx];
            merged = merged->next;
            lists[minidx] = lists[minidx]->next;
        }
        return res;
    }

    //Attempt 2: Devide and Conquer, O(klogN); k:# elements, N:#linked lists;
    //This solution will use mergeTwoLists of problem 21 and queue from STL;
    //It is tested that this solution performs MUCH BETTER than previous solution.
    ListNode* mergeKListsDC(vector<ListNode*>& lists){
        using Node = struct ListNode;
        queue<ListNode*> q;
        for(auto& each:lists){
            if(each)
                q.push(each);
        }
        ListNode *t1, *t2, *t3;
        if(!q.size())
            q.push(nullptr);
        while(q.size() > 1){
            t1 = q.front();
            q.pop();
            t2 = q.front();
            q.pop();
            t3 = this->mergeTwoLists(t1, t2);
            q.push(t3);
        }
        return q.front();
    }

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
};