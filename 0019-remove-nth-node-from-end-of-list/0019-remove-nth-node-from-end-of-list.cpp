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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head==nullptr) return head;
        int size = 0;
        ListNode* temp = head;
        while(temp){
            size++;
            temp = temp->next;
        }

        int ind = size-n+1;

        n = ind;

        if(n==1){
            ListNode *dltNode = head;
            head = head->next;
            delete(dltNode);
            return head;
        }

        temp = head;
        ind = 0;
        while(temp){
            ind++;
            if(ind==n-1){
                ListNode* dltNode = temp->next;
                temp->next = temp->next->next;
                delete(dltNode);
                break;
            }
            temp = temp->next;
        }
        return head;
    }
};