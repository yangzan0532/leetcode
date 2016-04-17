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
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = NULL;
        ListNode *right = NULL;
        ListNode *lptr = NULL;
        ListNode *rptr = NULL;
        while(head){
            if(head->val < x){
                process(left, lptr, head);
            }
            else{
                process(right, rptr, head);
            }
            head=head->next;
        }
        if(left)  lptr->next = right;
        if(right) rptr->next = NULL;
        return left ? left : right;
    }
    void process(ListNode* &head, ListNode* &cur, ListNode *val){
        if(!head){
            head = val;
            cur = head;
        }
        else{
            cur->next=val;
            cur = cur->next;
        }
    }
};
