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
    void rev(ListNode* head, int times){
        ListNode* cur = head, *prev = nullptr;
        while(times--){
            ListNode* nex = cur->next;
            cur->next = prev;
            prev = cur;
            cur = nex;
        }
        return;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head==nullptr) return head;
        ListNode *left = head, *res=nullptr, *prevLeft=nullptr, *right;
        int size = k;
        while(true){
            right = left;
            for(int i=0; i<(size-1); i++){
                if(right==nullptr) break;
                right = right->next;
            }
            if(right){
                ListNode *nextLeft = right->next;
                rev(left, size);
                if(prevLeft) prevLeft->next = right;
                prevLeft = left;
                if(res == nullptr) res = right;
                left = nextLeft;
            }
            else{
                if(prevLeft) prevLeft ->next= left;
                if(res==nullptr) res = left;
                break;
            }
        }
        return res;
    }
};