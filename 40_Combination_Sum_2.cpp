#include<iostream>
#include<vector>
#include<algorithm>
/*
 *回朔，寻找答案
 * */

class Solution {
public:
	vector<vector<int> >res;
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target) {
		vector<int> tmp;
		res.clear();
		sort(candidates.begin(), candidates.end());
		find(tmp, 0, 0, candidates, target);
		return res;
    }

	void find(vector<int>& tmp, int sum, int index, vector<int>& sets, int target){
		if(sum < target && index < sets.size()){
			//每个数都有两个可能，放入或者不放入
		    for(int i=index; i<sets.size(); ++i){ 
		        if(i > index && sets[i] == sets[i-1]) continue ; //避免出现重复值
			    tmp.push_back(sets[i]); // 放入这个数
			    find(tmp, sum+sets[i], i+1, sets, target);
			    tmp.pop_back();         // 不放这个数
		    }
		}
		else if(sum == target){
			res.push_back(tmp);
			return ;
		}
	}
};

int main(){
	return 0;
}
