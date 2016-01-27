//(n+1)*(n)/2 - sum(nums[0...n])
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res=0;
        int tot=0;
        int n = nums.size();
        if(n%2){
            tot=(n+1)/2*n;
        }
        else{
            tot=n/2*(n+1);
        }
        for(int i=0; i<nums.size(); ++i){
            res+=nums[i];
        }
        return tot-res;
    }
};
