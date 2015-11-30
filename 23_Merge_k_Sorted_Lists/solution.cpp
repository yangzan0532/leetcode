#include<iostream>
#include<vector>
using namespace std;

struct ListNode 
{
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
	public:
		ListNode *t_head;
		Solution()
		{
		    t_head = new ListNode(0);    
		}
		ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) 
		{
			if(!l1) return l2;
			if(!l2) return l1;

			ListNode *l1_ptr=l1;
			ListNode *l2_ptr=l2;
			ListNode *curr = t_head;

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
			return t_head->next;
		}

		// 在Merge Two Sorted Lists	的基础上，利用分治的思想，每次取两个进行合并，经过logk(2为底)次运算即可完成
		ListNode* mergeKLists(vector<ListNode*>& lists) 
		{
			if(lists.size() == 0)
			{
				return NULL;
			}
			else
			{
				int low = 0;
				int next = 1;
				int top = lists.size();
				int length = lists.size();
				while(next < top)
				{
					lists[top%length] = mergeTwoLists(lists[low%length], lists[next%length]);
					low += 2;
					next = low+1;
					top++;
				}
				return lists[low%length];
			}
		}
};


int main()
{
	return 0;
}
