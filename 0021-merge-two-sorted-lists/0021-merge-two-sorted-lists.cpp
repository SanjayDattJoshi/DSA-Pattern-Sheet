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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(!list1 && !list2) return nullptr;
        else if(!list1 && list2) return list2;
        else if(!list2 && list1) return list1; 
        
        ListNode* temp1 = list1, *temp2 = list2;
        ListNode* head = nullptr;
        if(list1->val<=list2->val) {
            head = temp1;
            temp1 = temp1->next;
        }
        else {
            head = temp2;
            temp2 = temp2->next;
        }
        ListNode* tail = head;
        while(temp1 && temp2){
            if(temp1->val<=temp2->val){
                tail->next = temp1;
                temp1 = temp1->next;
                tail = tail->next;
            }
            else{
                tail->next = temp2;
                temp2 = temp2->next;
                tail = tail->next;
            }
        }
        if(temp1 && !temp2) tail->next = temp1;
        else if(!temp1 && temp2) tail->next = temp2;

        return head;
    }
};