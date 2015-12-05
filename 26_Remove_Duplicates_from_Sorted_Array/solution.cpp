// solution 1
class Solution {
	public:
		int removeDuplicates(vector<int>& nums) {
			int top=1,curr=0;
			int len = nums.size();
			if(len == 0) return len;
			while(top != len)
			{
				if(nums[top] != nums[curr])
				{
					curr++;
					nums[curr] = nums[top];	
				}
				top++;
			}
			return curr+1;
		}
};
