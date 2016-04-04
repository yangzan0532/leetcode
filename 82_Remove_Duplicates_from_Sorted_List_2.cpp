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
        if(!head || !head->next) return head;
        ListNode *pre = new ListNode(0);
        pre->next = head;
        ListNode *cur = head;
        ListNode *next = head->next;
        head = pre;
        while(cur && next){
            next = cur->next;
            if(next &&  cur->val == next->val){
                while(next && cur->val == next->val){
                    next = next->next;  //and delete next;
                }
                pre->next = next;   // and delete cur;
                cur = next;
            }
            else{
                pre = cur;
                cur =next;
            }
        }
        // delete head and then return head->next;
        return head->next; 
    }
};
