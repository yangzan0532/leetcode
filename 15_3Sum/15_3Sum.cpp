#include<vector>
#include<algorithm>
#include<iostream>
using namespace std;

class Solution {
	public:
			int target;
			Solution(){
				target = 0;
			}
		    vector< vector<int> > threeSum(vector<int>& nums) {
				vector< vector<int> > res;
				vector< int > t_res;
				sort(nums.begin(), nums.end());
				for(size_t cur = 0; cur < nums.size(); ++cur){
					size_t beg = cur+1;
					size_t end = nums.size()-1;
					while(beg < end){
						//cout << beg <<"|" << cur <<"|" << end << endl;
						int tmp = nums[cur] + nums[beg] + nums[end];
						if(tmp == 0){
							//cout << "<<<" << endl;
							t_res.clear();
							t_res.push_back( nums[cur] );
							t_res.push_back( nums[beg] );
							t_res.push_back( nums[end] );
							res.push_back(t_res);
							while(beg++ < end && nums[beg] == nums[beg-1]) ;
							while(end-- > beg && nums[end] == nums[end+1])  ;
						}
						else if(tmp < 0){
							++beg;
						}
						else{
							--end;
						}
					}
					while(cur+1 < nums.size() &&  nums[cur] == nums[cur+1]) cur++;
				}
				return res;
			}
};

int main(){
	int n, m, a;
	vector<int> nums;
	Solution s;
	while(1){
		cout << "input n:"<<endl;
		nums.clear();
		cin >> n;
		while(n--){
			cin >> m;
			nums.push_back(m);
		}
		vector< vector<int> > res = s.threeSum(nums);
		for(vector< vector<int> >::iterator t_res = res.begin();  t_res < res.end(); ++t_res){
			for(size_t j=0; j < (*t_res).size(); ++j){
				cout << (*t_res)[j];
			}
			cout << endl;
		}
	}
	return 0;
}
