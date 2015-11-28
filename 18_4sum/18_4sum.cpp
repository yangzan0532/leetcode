#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<unordered_set>
using namespace std;

struct VectorHash 
{
	size_t operator()(const std::vector<int>& v) const {
		std::hash<int> hasher;
		size_t seed = 0;
		for (int i : v) 
		{
			seed ^= hasher(i) + 0x9e3779b9 + (seed<<6) + (seed>>2);
		}
		return seed;
	}
};

class Solution {
	public:
		vector<vector<int> > fourSum(vector<int>& nums, int target) 
		{
			sort(nums.begin(), nums.end());
			if(nums.size() < 4 )
			{
				return vector< vector<int> >();
			}
			unordered_set< vector<int> , VectorHash >hashset;
			for(int i1=0; i1<nums.size(); ++i1)
			{

				int i4=nums.size()-1;
				/* ************ start *********************
				*** 加上这段代码优化之后，时间缩短到24ms ***/
				int i2=i1+1;
				int i3=i1+2;
				int i5=i1+3;
				if(i5 > i4)
				{
					break;
				}
				if(nums[i1] + nums[i2] + nums[i3] + nums[i5] > target)
				{
					break;
				}
				/* ************ end *********************/
				for(; i4>i1; --i4)
				{
					int i2=i1+1;
					int i3=i4-1;

					/* ************ start *********************
					 *** 加上这段代码优化之后，时间缩短到60ms ***/
					int i5=i4-2;
					if(i5 <= i1)
					{
						break;
					}
					if(nums[i1] + nums[i4] + nums[i3] + nums[i5] < target)
					{
						break;
					}
					/* *************** end ******************** */
					while(i2 < i3)
					{
						int tmp_res = target - nums[i1] - nums[i2] - nums[i3] -nums[i4];
						if(tmp_res < 0)
						{
							--i3;
						}
						else if(tmp_res > 0)
						{
							++i2;
						}
						else
						{
							vector<int>record {nums[i1], nums[i2], nums[i3], nums[i4]};
							hashset.insert(record);
							--i3;
							++i2;
						}
					}
				}
			}
			return vector< vector<int> >(hashset.begin(), hashset.end());
		}
};

int main()
{
	while(1)
	{
		vector<int> nums;
		int target;
		int loop;
		int t_num;
		cin >> loop;
		while(loop)
		{
			cin >> t_num;
			nums.push_back(t_num);
			--loop;
		}
		cin >> target;
		Solution s;
		vector< vector<int> > res = s.fourSum(nums, target);
		for(int i=0; i< res.size(); i++)
		{
			for(int j=0; j<res[i].size();  ++j)
			{
				cout << res[i][j] << " ";
			}
			cout << endl;
		}
	}
	return 0;
}
