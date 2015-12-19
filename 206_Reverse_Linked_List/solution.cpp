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
    //solution 1. Recursion
    /*
    ListNode* reverseList(ListNode* head) {
        if(NULL == head) return head;
        ListNode *nhead = Recursion(head);
        head->next=NULL;
        return nhead;
    }
    
    ListNode *Recursion(ListNode *curr){
        if(NULL == curr || NULL == curr->next){
            return curr;
        }
        else{
            ListNode *pre = curr->next;
            ListNode *head = Recursion(curr->next);
            pre->next = curr;
            return head;
        }
    }*/
    
    //solution 2
    //iteratively
    ListNode* reverseList(ListNode* head) {
        if(NULL == head || NULL == head->next) return head;
        ListNode *pre = head;
        ListNode *curr = head->next;
        ListNode *next = head->next;
        while(curr->next){
            next = curr->next;
            curr->next = pre;
            pre = curr;
            curr = next;
        }
        if(curr){
            curr->next = pre;
            head->next = NULL;
        }
        return curr;
    }
};
