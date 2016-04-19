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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode *pre = new ListNode(0);
        pre->next = head;
        head = pre;
        
        int i = 1;
        while(i<m && pre){
            pre = pre->next;
            ++i;
        }
        ListNode *curr = pre->next;
        ListNode *tp = curr;    // 临时变量，表示遍历的位置
        ListNode *tail = curr;  // 保存翻转后的尾部
        while((i++)<=n){
            tp = curr->next;
            curr->next = pre->next;
            pre->next = curr;
            curr = tp;
        }
        tail->next = tp;
        return head->next;
    }
};
