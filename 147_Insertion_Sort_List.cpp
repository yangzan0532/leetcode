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
    ListNode* insertionSortList(ListNode* head) {
        if(!head) return head;
        ListNode *src = head->next;
        ListNode *new_head = new ListNode(0);;
        new_head->next = head;
        head->next=NULL;
        while(src != NULL){
            bool found = false;
            ListNode *dst = new_head->next;
            ListNode *dst_pre = new_head;
            for(; dst!=NULL; dst=dst->next){
                //cout <<"src:"<< src->val << " dst:" << dst->val << endl;
                if(src->val >= dst->val){
                }
                else{
                    found = true;
                    ListNode *curr = src;
                    src = src->next;
                    curr->next = dst_pre->next;
                    dst_pre->next = curr;
                    //cout << dst->val << "|" <<dst_pre->val<< "|" << dst_pre->next << "|" << dst->next << endl;
                    break;
                }
                dst_pre = dst;
            }
            if(!found){
                ListNode *curr = src;
                src = src->next;
                curr->next = dst_pre->next;
                dst_pre->next =  curr;
            }
        }
        return new_head->next;
    }
};
