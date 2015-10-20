#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

using namespace std;

class Solution {
	public:
		int threeSumClosest(vector<int>& nums, int target) 
		{
			int diff_target=0x3f3f3f;
			int ans;
			int res_detail[3];
			sort(nums.begin(), nums.end());
			for(size_t i = 1; i<nums.size(); ++i)
			{
				size_t l = 0;
				size_t r = nums.size()-1;
				while(l<i && i<r)
				{
					 int tmp =  (nums[l] + nums[r] + nums[i]);
					 if(abs(target-tmp) < diff_target)
					 {
						diff_target = abs(target - tmp);
						ans = tmp;
						//cout << ans << "|"<<nums[l] << "|" << nums[i] << "|" << nums[r] << endl;
					 }
					 if(tmp < target){
						 ++l;
					 }
					 else if(tmp > target){
						 --r;
					 }
					 else{
						 return ans;
					 }
				}
			}
			return ans;
		}
};

int main()
{
	int m;
	vector<int>n;

	Solution s;
	while(1){
		int t;
		n.clear();
		cin >> t;
		while(t--){
			cin >> m;
			n.push_back(m);
		}
		cin >> m;
		cout << s.threeSumClosest(n, m) << endl;;
	}
	return 0;
}
