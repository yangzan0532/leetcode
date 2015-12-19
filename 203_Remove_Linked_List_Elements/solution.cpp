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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *newhead = new ListNode(0);
        ListNode *pre= newhead;
        ListNode *curr=head;
        pre->next=curr;
        while(curr!=NULL){
            if(curr->val == val){
                pre->next = curr->next;
            }
            else{
                pre=curr;
            }
            curr=curr->next;
        }
        curr=newhead->next;
        delete newhead;
        return curr;
    }
};
