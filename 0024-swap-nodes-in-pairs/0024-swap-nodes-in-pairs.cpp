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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL||head->next==NULL){
            return head;
        }
        ListNode* left = head;
        ListNode* right = head->next;

        head=right;

        while(left!=NULL&&right!=NULL){
            left->next=right->next;
            right->next=left;
            left=left->next;
            if(left!=NULL){
                if(left->next!=NULL){
                    right->next->next=left->next;
                }
                right=left->next;
            }

        }
        return head;

    }
};