class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int lens  = nums.size();
        if(lens == 0) return ;
        int steps = k % lens;
        if(steps == lens || steps == 0) return ;
        int start = lens - steps;
        nums.insert(nums.end(), nums.begin(), nums.begin()+start);
        nums.erase(nums.begin(), nums.begin()+start);
    }
};
