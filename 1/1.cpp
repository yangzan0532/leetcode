/****
 * 使用stl中的map实现
 *****/
#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
	public:
		    vector<int> twoSum(vector<int>& nums, int target) {
				map<int, vector<int> > myMap;
				vector<int> res ;
				int count = 1;
				for(vector<int>::iterator it=nums.begin(); it!=nums.end(); ++it){
					map<int, vector<int> >::iterator mit;
					mit = myMap.find(*it);
					if(mit != myMap.end()){
						(mit->second).push_back(count);
					}
					else{
						vector<int> tv;
						tv.push_back(count);
						myMap[*it] = tv;
					}
					++count;
				}
				for(map<int,vector<int> >::iterator it=myMap.begin(); it!=myMap.end(); ++it){
					int other = target - (it->first);
					map<int, vector<int> >::iterator tmp = myMap.find(other);
					if(tmp != myMap.end()){
						if(it == tmp){
							return it->second;
						}
						else if(it->second[0] < tmp->second[0]){
							res.push_back(it->second[0]);
							res.push_back(tmp->second[0]);	
						}	
						else{
							res.push_back(tmp->second[0]);
							res.push_back(it->second[0]);
						}
						break;
					}
				}
				return res;		
			}
};

int main(){
	Solution s;
	int arr[] = {3,4,2,15};
	vector<int>nums(arr, arr+4);
	int target = 18;
	vector<int>res = s.twoSum(nums, target);
	cout << res[0] << res[1] << endl;
	return 0;
}
