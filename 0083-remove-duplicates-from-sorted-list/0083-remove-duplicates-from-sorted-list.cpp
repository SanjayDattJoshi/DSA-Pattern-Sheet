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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp = head;
        if(head == nullptr || head->next == nullptr) return head;
        ListNode *prev = temp;
        temp = temp->next;
        while(temp){
            if(temp->val == prev->val){
                ListNode* duplicate = temp;
                temp = temp->next;
                prev->next = temp;
                delete duplicate;
                continue;
            }
            prev = temp;
            temp = temp->next;
        }
        return head;
    }
};