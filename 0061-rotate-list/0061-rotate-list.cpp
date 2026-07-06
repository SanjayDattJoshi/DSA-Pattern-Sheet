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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==nullptr || k==0) return head;
        int cnt = 0;
        ListNode* temp = head, *newHead=nullptr;
        while(temp){
            cnt++;
            temp=temp->next;
        }

        k = k%cnt;
        if(k==0) return head;
            int pos = cnt-k-1;
            ListNode* t = head, *nextNode;
            while(t && pos--){
                t = t->next;
            }
            nextNode = t->next;
            t->next = nullptr;
            newHead = nextNode;
            while(nextNode && nextNode->next) nextNode=nextNode->next;
            if(nextNode) nextNode->next = head;
            return newHead;
        
    }
};