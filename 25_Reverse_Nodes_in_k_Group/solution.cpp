struct ListNode {
	int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution{
	public:
		ListNode* reverseKGroup(ListNode* head, int k){
			ListNode *beg = head;
			ListNode *end = head;
			ListNode *last = NULL;
			ListNode *real_head = NULL;
			ListNode *next_beg;
			while(1)
			{
				int i=1;
				for(i=1; i<k && end; ++i)
				{
					end=end->next;
				}
				if(end){
				    next_beg = end->next;
					swap_node(beg, end);
					if(last)
					{
					    last->next = end;
					}
					if(!real_head){
						real_head = end;
					}
					last = beg;
				}
				else
				{
				    if(last)
				    {
					    last->next = beg;
				    }
					break ;
				}
				beg=next_beg;
				end=beg;
			}
			if(!real_head){
				real_head = beg;
			}
			return real_head;
		};
		void swap_node(ListNode *head, ListNode *tail)
		{
			ListNode *curr_ptr = head;
			ListNode *last_ptr = NULL;
			ListNode *next_ptr = NULL;
			while(last_ptr != tail)
			{
				next_ptr = curr_ptr->next;
				curr_ptr->next = last_ptr;
				last_ptr = curr_ptr;
				curr_ptr = next_ptr;
			}
			tail = last_ptr;
		}
};

