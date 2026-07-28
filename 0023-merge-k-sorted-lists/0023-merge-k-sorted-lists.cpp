/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    struct cmp{
        bool operator()(ListNode *a, ListNode *b){
            return a->val>b->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n = lists.size();
        if(n==0) return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;
        for(int i=0; i<n; i++) if(lists[i] != nullptr) pq.push(lists[i]);
        ListNode *dummy = new ListNode(0);
        ListNode *tail = dummy;
        while(!pq.empty()){
            ListNode *cur = pq.top();
            pq.pop();
            if(cur->next) pq.push(cur->next);
            tail->next = cur;
            tail = tail->next;
        }
        return dummy->next;
    }
};