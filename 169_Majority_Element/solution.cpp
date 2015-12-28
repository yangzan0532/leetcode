class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> ss;
        int lens = nums.size();
        lens = lens - lens/2;
        for(int i=0; i<nums.size(); ++i){
            ss[nums[i]]++;
            if(ss[nums[i]] >= lens){
                return nums[i];
            }
        }
    }
};
