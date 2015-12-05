// 水题，不多说

class Solution {
	public:
		void moveZeroes(vector<int>& nums) {
		int curr = 0;
		for(int i=0; i<nums.size(); ++i)
  		{
            if(nums[i] != 0){
				nums[curr++] = nums[i];
			}
		}
		for(int i=curr; i<nums.size(); i++)
		{
		    nums[i]=0;
		}
	}
};
