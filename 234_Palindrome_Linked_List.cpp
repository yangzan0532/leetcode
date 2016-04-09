/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

// 从链表的中间，将链表反转，然后以此比较
// 例如 1->2->3->2->1  分成 1->2 , 1->2->3 两个小链表，然后以此比较
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast && slow){
            if(!fast->next) break;
            fast = fast->next->next;
            slow = slow->next;
        }
        ListNode *new_head;
        if(fast)
            new_head = reverse(slow->next);
        else
            new_head = reverse(slow);
        bool isPalindrome = true;
        while(new_head){
            if(new_head->val != head->val) {
                isPalindrome = false;
                break;
            }
            new_head = new_head->next;
            head = head->next;
        }
        return isPalindrome;
    }
    ListNode * reverse(ListNode *head){
        if(!head) return head;
        ListNode *cur = head;
        ListNode *next = cur;
        head = NULL;
        while(next){
            next = next->next;
            cur->next = head;
            head = cur;
            cur = next;
        }
        return head;
    }
};
