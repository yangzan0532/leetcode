// 最大连续子序列 
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxval = nums[0], maxtmp = nums[0];
        for(int i=1; i<nums.size(); ++i){
            if(maxtmp > 0){
                maxtmp += nums[i];
            }   
            else{
                maxtmp = nums[i];
            }
            if(maxtmp > maxval){
                maxval = maxtmp;
            }
        }
        return maxval;
    }
};
