/*
 * 用分治的思想 ，另m＝(l+r)/2. 比较target与nums[m]的大小，如果相等，则将nums的纷呈[0,m-1],以及[m+1, r]两个字串，
 * 在左边寻找l，右边寻找r，如果nums[m] > target，则在左边寻找，反之亦然。
 *
 * */
class Solution {
public:
    int target;
    vector<int> searchRange(vector<int>& nums, int target) {
        int l=0, r=nums.size()-1;
        int m=0;
        int rl=r+1,rr=-1;
        this->target =target;
        find(nums, 0, r, &rl, &rr);
        vector<int>res;
        if(rl > rr){
            rl=-1;
            rr=-1;
        }
        res.push_back(rl);
        res.push_back(rr);
        return res;
    }
    
    int find(vector<int>&nums, int l, int r, int *rl, int *rr){
        int m = (l+r)/2;
        if(l > r){
            return 0;
        }
        if(nums[m] == target){
            *rl = m < *rl ? m : *rl;
            *rr = m > *rr ? m : *rr;
            find(nums, l, m-1, rl, rr);
            find(nums, m+1, r, rl, rr);
        }
        else if(nums[m] < target){
            find(nums, m+1, r, rl, rr);
        }
        else{
            find(nums, l, m-1, rl, rr);
        }
    }
};
