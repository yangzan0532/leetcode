class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int tot = nums.size();
        vector<int> tmp;
        for(int i=tot-1; i>=0; --i){
            if(i>0 && nums[i] > nums[i-1]){
                int curr = nums[i-1];
                nums[i-1] = nums[i];
                for(int j=0; j<tmp.size(); ++j){
                    if(tmp[j] < nums[i-1] && tmp[j] > curr){
                        int t = tmp[j];
                        tmp[j] = nums[i-1];
                        nums[i-1] = t;
                    }
                }
                tmp.push_back(curr);
                break;
            }
            else{
                tmp.push_back(nums[i]);
            }
        }
        sort(tmp.begin(), tmp.end());
        for(int i=0,  count = tmp.size(); i<count;  ++i){
            nums[tot-count+i] = tmp[i];
        }
    }
};
