#include <stack>
#include <vector>
#include <list>
#include <iostream>
using namespace std;

 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    //Non-trivial solution: use stack operations to store the nodes.
    ListNode* reverseKGroup(ListNode* head, int k) {
        stack<ListNode*> st;
        ListNode *s = head, *res, *prv, *nxt;
        for(int i = 0; i < k && s; ++i){
            st.push(s);
            s = s->next;
        }
        if(st.size()<k)
            return head;
        res = st.top();
        prv = res;
        st.pop();
        while(st.size()){
            prv->next = st.top();
            prv = prv->next;
            st.pop();
        }
        prv->next = s;
        bool ext = 0;
        while(!ext){
            for(int i = 0; i < k && s; ++i){
                st.push(s);
                s = s->next;
            }
            if(st.size() < k)
                break;
            while(st.size()){
                prv->next = st.top();
                prv = prv->next;
                st.pop();
            }
            prv->next = s;
        }
        return res;
    }
};

int main(){
   initializer_list<int> vals = {1,2,3,4,5,6,7,8,9, 10, 11, 12};
   ListNode* l = new ListNode{*vals.begin()};
   auto p = l;
   for(auto s = vals.begin()+1; s!=vals.end(); ++s){
       l->next = new ListNode(*s);
       l = l->next;
   }
   l = p;
   while(l){
       cout << l->val << ' ';
       l = l->next;
   }
   cout << endl;
   auto res = Solution().reverseKGroup(p, 12);
   while(res){
       cout << res->val << ' ';
       res = res->next;
   }
   return 0;
}