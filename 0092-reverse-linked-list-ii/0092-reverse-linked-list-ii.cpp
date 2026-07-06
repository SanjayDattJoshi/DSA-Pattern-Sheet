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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==nullptr) return head;
        if(right==left) return head;
        ListNode *temp=head, *beforeLeft=nullptr;
        int k = 1;
        while(temp){
            if(k<left){
                beforeLeft = temp;
                temp = temp->next;
                k++;
                continue;
            }
            ListNode *cur = temp, *prev = nullptr, *nxt;
            int times = right-left+1;
            while(times--){
            nxt = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nxt;
            }
            temp->next = cur;
            if(beforeLeft){
            beforeLeft->next = prev;
            return head;
            }
            return prev;
        }
        return head;
    }
};