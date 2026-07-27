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
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL||head->next==NULL||head->next->next==NULL){
            return head;
        }
        ListNode* left = head;
        ListNode* right = head->next;
        ListNode* secondHead = head->next;
        while(right->next!=NULL){
            left->next=right->next;
            left=left->next;
            if(left->next==NULL){
                right->next=NULL;
                break;
            }
            right->next=left->next;
            right=right->next;
        }
        left->next=secondHead;
        return head;
    }
};