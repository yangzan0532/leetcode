/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(NULL == head) return head;
        ListNode *pre=head;
        ListNode *curr = head->next;
        while(curr){
            if(curr->val != pre->val){
                pre->next = curr;
                pre=curr;
            }
            curr=curr->next;
        }
        pre->next=NULL;
        return head;
    }
};
