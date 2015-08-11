/**
 *  * Definition for singly-linked list.
 *  * struct ListNode {
 *  *     int val;
 *  *     ListNode *next;
 *  *     ListNode(int x) : val(x), next(NULL) {}
 *  * };
 *  */
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
			if(l1 == NULL){
				return l2;
			}
			if(l2 == NULL){
				return l1;
			}
			ListNode *tl1 = l1;
			ListNode *tl2 = l2;

			ListNode *res = NULL;
			ListNode *cur = NULL;
			
			int flag = 0;
			while(tl1 != NULL && tl2 != NULL){
				int val = tl1->val + tl2->val + flag;
				flag = val / 10;
				if(res == NULL){
					res = new ListNode(val%10);
					cur = res;
				}
				else{
					cur->next = new ListNode(val%10);
					cur = cur -> next;
				}
				tl1 = tl1 -> next;
				tl2 = tl2 -> next;
			}
			if(tl2 != NULL){
				tl1 = tl2;
			}
			while(tl1 != NULL){
				int val = flag + tl1->val; 
				flag = val /10;
				cur->next = new ListNode(val%10);
				cur = cur->next;
				tl1 = tl1 -> next;
				if(flag == 0){
					cur->next = tl1;
					break;
				}
			}
			if(flag > 0){
				cur->next=new ListNode(flag);	
			}
			return res;
		}
};


int main(){
	Solution s;
	ListNode *l1 = new ListNode(9);
	ListNode *l2 = new ListNode(1);
	l1->next = new ListNode(2);
	l1->next->next = new ListNode(2);
	ListNode *l3 = s.addTwoNumbers(l1,l2);
	while(l3){
		cout << l3->val << "->" ;
		l3 = l3->next;
	}
	cout << endl;
	return 0;
}
