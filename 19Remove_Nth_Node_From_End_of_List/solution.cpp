#include<iostream>
using namespace std; 


struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
	public:
		ListNode* removeNthFromEnd(ListNode* head, int n) {
			if(n <= 0)
			{
				return head;
			}

			ListNode *pre=NULL;
			ListNode *cur=head;
			int length = 0;
            do
			{
				pre=cur;
				cur=cur->next;
				++length;
			}while(cur != NULL);
			int m = length - n; // 顺着数是删除第length－n＋1个；
			cur=head;
			if(m == 0)
			{
			    return head->next;
			}
			else
			{
			    do
			    {
				    pre=cur;
				    cur=cur->next;		
				    --m;
			    }while(m);
			    pre->next = cur->next;
			    return head;
		    }
		}
};

int main(){
	return 0;
}
