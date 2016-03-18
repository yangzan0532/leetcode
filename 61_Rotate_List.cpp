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
    ListNode* rotateRight(ListNode* head, int k) {
        int step = k;
        if(!head) return head;
        ListNode *ptr = head;
        ListNode *first = head;
        first = to_k(head, &step);
        
        if(step>0 && k)
        {
            step =step % (k-step);
            first = to_k(head, &step);
        }
        if(first && first != head)
        {
            while(first->next)
            {
                ptr = ptr->next;
                first = first->next;
            }
            first->next = head;
            first = ptr->next;
            ptr->next = NULL;
        }
        else if(!first){
            return head;
        }
        return first;
    }
    ListNode *to_k(ListNode *head, int* k){
        while((*k) && head){
            head = head->next;
            --(*k);
        }
        return head;
    }
};
