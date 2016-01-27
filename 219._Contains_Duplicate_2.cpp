class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map<int, vector<int> >t;
        for(int i=0; i<nums.size(); ++i){
            t[nums[i]].push_back(i);
        }
        for(map<int, vector<int> >::iterator iter=t.begin(); iter !=t.end(); ++iter){
            vector<int> &v=iter->second;
            sort(v.begin(), v.end());
            for(int i=0; i<v.size()-1; ++i){
                if(v[i+1] - v[i] <= k){
                    return true;
                }
            }
        }
        return false;
    }
};
