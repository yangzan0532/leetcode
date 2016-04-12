/**
 *  用一个快慢指针，快指针每次走两步，慢指针每次走一步。 如果有环，两个指针一定会相遇，反之则没有环
 * 
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *slow = head;
        while(fast){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
            if(fast == slow && fast != NULL ) return true;
        }
        return false;
    }
};
