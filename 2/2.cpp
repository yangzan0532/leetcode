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

			int lc1 =0, lc2 =0;
			int diff_len = 0;
			ListNode *tl1 = l1;
			ListNode *tl2 = l2;
			while(tl1 != NULL){
				tl1 = tl1->next;
				++lc1;
			};
			while(tl2 != NULL){
				tl2 = tl2->next;
				++lc2;
			};
			if(lc1 < lc2){
				diff_len = lc2 -lc1;	
				ListNode *tl = l1;
				l1 = l2;
				l2 = tl;
			}
			else{
				diff_len = lc1 - lc2;
			}

			ListNode *res = NULL;
			ListNode *cur = NULL;
			tl1 = l1;
			tl2 = l2;
			while(diff_len>0){
				if(res == NULL){
					res = new ListNode(tl1->val);
					cur = res;
					tl1 = tl1->next;
				}
				else{
					cur->next = new ListNode(tl1->val);	
					tl1 = tl1->next;
					cur = cur->next;
				}
				--diff_len;	
			}
			
			int flag = 0;
			while(tl1 != NULL){
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
	//l2->next = new ListNode(9);
	l1->next = new ListNode(8);
	ListNode *l3 = s.addTwoNumbers(l1,l2);
	while(l3){
		cout << l3->val << "->" ;
		l3 = l3->next;
	}
	cout << endl;
	return 0;
}
