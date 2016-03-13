#include<iostream>
#include<vector>
#include<algorithm>
/*
 *回朔，寻找答案
 * */

class Solution {
public:
	vector<vector<int> >res;
    vector<vector<int> > combinationSum(vector<int>& candidates, int target) {
		vector<int> tmp;
		res.clear();

		// 排序，然后去重，接着枚举的所有结果就是唯一的
		sort(candidates.begin(), candidates.end());
		vector<int>::iterator end_it = unique(candidates.begin(), candidates.end());

		candidates.erase(end_it, candidates.end());
		find(tmp, 0, 0, candidates, target);
		return res;
    }

	// tmp 用来存储零时组合的vector
	// sum 表示tmp中的和，这样没必要每次都计算sum(tmp)
	// 当前枚举到candidates第几个元素
	// 接下来的两个参数，就不说了
	void find(vector<int>& tmp, int sum, int index, vector<int>& sets, int target){
	    if(index >= sets.size()) return ;
		if(sum < target){ 
			tmp.push_back(sets[index]);
			find(tmp, sum+sets[index], index, sets, target);
			tmp.pop_back();
		}
		else if(sum == target){
			res.push_back(tmp);
			return ;
		}
		else{
		    return ;
		}
		if(index+1 < sets.size()){
		    
	        find(tmp, sum, index+1, sets, target);
		}
	}
};

int main(){
	return 0;
}
