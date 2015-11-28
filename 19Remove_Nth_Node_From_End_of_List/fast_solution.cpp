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

			ListNode *fast=head;
			ListNode *slow=head;
			do{
				fast = fast->next;
			}while(--n);
			if(fast == NULL)
			{
			    return head->next;
			}
			while(fast->next){
				fast=fast->next;
				slow=slow->next;
			}
            slow->next = slow->next->next;
			return head;
		}
};
int main(){
	return 0;
}
