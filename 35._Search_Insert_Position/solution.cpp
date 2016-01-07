// 这道题二分搜索就可以搞定的,一道水体
// 1
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size();
        int m = 0;
        while(l < r){
            m = (l+r)/2;   
            if(nums[m] == target) return m;
            else if(nums[m] > target){
                if(m>0 && nums[m-1] < target) return m;
                r = m - 1;
            }
            else{
                if(m+1 < nums.size() && nums[m+1] > target) return m+1;
                l = m + 1;
            }
        }
    }
};
// 2
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size()-1;
        int m = 0;
        while(l <= r){
            m = (l+r)/2;   
            if(nums[m] == target) return m;
            else if(nums[m] > target){
                r = m - 1;
            }
            else{
                l = m + 1;
            }
        }
        return l;
    }
};
