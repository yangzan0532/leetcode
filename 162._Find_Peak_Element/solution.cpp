class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int len = nums.size();
        if(len <= 1) return 0;
        if(nums[0] > nums[1]) return 0;
        if(nums[len-1] > nums[len-2]) return len-1;
        for(int i=2; i< len; ++i){
            if(nums[i] > nums[i-1]) continue;
            else return i-1;
        }
    }
};
