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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *result = new ListNode(0), *temp = result;
        ListNode *ptr1 = l1, *ptr2 = l2;
        int carry = 0;
        while(ptr1 != nullptr || ptr2 != nullptr){
            int sum = 0;
            if(ptr1 != nullptr) sum += ptr1->val; 
            if(ptr2 != nullptr) sum += ptr2->val;
            sum += carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode *node = new ListNode(sum);
            temp->next = node;
            temp = temp->next;
            if(ptr1 != nullptr) ptr1 = ptr1->next;
            if(ptr2 != nullptr) ptr2 = ptr2->next;
        }
        
        if(carry != 0){
            ListNode *node = new ListNode(carry);
            temp->next = node;
            temp = temp->next;
        }
        return result->next;
    }
};