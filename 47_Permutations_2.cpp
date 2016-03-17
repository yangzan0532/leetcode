class Solution {
public:
	vector< vector<int> >res;
    vector<vector<int>> permuteUnique(vector<int>& nums) {
		res.clear();
		find(nums, 0, nums.size()-1);
		return res;
    }

	int find(vector<int> &nums, int src, int dest){
		if(src == dest){
			res.push_back(nums);
		}
		for(int i=src; i<=dest; ++i){
		    bool same = false;
		    for(int j=src; j<i; ++j){
				// 前面出现过的数字则不交换，防止重复
		        if(nums[i] == nums[j]){
		            same = true;
		            break;
		        } 
		    }
		    if(same) continue;
			swap(nums, i, src);
			find(nums, src+1, dest);
			swap(nums, i, src);
		}
	}
	int swap(vector<int>&src, int  i, int j){
		int t=src[i];
		src[i] = src[j];
		src[j] = t;
	}
};
