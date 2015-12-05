class Solution {
	public:
		int removeElement(vector<int>& nums, int val) {
			int top=0,curr=0;
			int len = nums.size();
			if(len == 0) return len;
			while(top != len)
			{
				if(nums[top] != val)
				{
					nums[curr] = nums[top];	
					curr++;
				}
				top++;
			}
			return curr;
		}
};
