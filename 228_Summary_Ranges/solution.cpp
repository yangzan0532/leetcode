class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
		vector<string>res;       
		if(nums.size() == 0) return res;
		int s = nums[0];
		for(int s=0; s<nums.size(); ){
			int e=s+1;
			while(e<nums.size() && nums[e] == nums[e-1]+1){
				e++;
			}
			if(e == s+1){
				res.push_back(to_string(nums[s]));
			}
			else{
				string t = to_string(nums[s]);	
				t+="->";
				t+=to_string(nums[e-1]);
				res.push_back(t);	
			}
			s=e;
		}
		return res;
    }
};
