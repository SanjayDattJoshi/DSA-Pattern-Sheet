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
        while(ptr1 != nullptr && ptr2 != nullptr){
            int sum = (ptr1->val + ptr2->val + carry) % 10;
            ListNode *node = new ListNode(sum);
            carry = (ptr1->val + ptr2->val + carry) / 10;
            temp->next = node;
            temp = temp->next;
            ptr1 = ptr1->next;
            ptr2 = ptr2->next;
        }
        while(ptr1 != nullptr){
            int sum = (ptr1->val + carry) % 10;
            ListNode *node = new ListNode(sum);
            carry = (ptr1->val + carry) / 10;
            temp->next = node;
            temp = temp->next;
            ptr1 = ptr1->next;
        }
        while(ptr2 != nullptr){
            int sum = (ptr2->val + carry) % 10;
            ListNode *node = new ListNode(sum);
            carry = (ptr2->val + carry) / 10;
            temp->next = node;
            temp = temp->next;
            ptr2 = ptr2->next;
        }
        if(carry != 0){
            ListNode *node = new ListNode(carry);
            temp->next = node;
            temp = temp->next;
        }
        return result->next;
    }
};