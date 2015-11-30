#include<iostream>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
		{
			if(!l1) return l2;
			if(!l2) return l1;
			
			ListNode *l1_ptr=l1;
			ListNode *l2_ptr=l2;
			ListNode head(0);
			ListNode *curr = &head;

			while(l1_ptr && l2_ptr)
			{
				if(l1_ptr->val < l2_ptr->val)
				{
					curr->next = l1_ptr;
					l1_ptr = l1_ptr->next;
				}
				else
				{
					curr->next = l2_ptr;
					l2_ptr = l2_ptr->next;
				}
				curr=curr->next;
			}
			if(l1_ptr)
			{
				curr->next=l1_ptr;	
			}
			else
			{
				curr->next=l2_ptr;
			}
			return head.next;
		}
};

int main()
{
	return 0;
}
