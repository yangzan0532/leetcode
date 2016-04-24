// 相当精辟的算法，将找重复数转变成了求环的入点问题

class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int fast = 0;
        int slow = 0;
        while(1){
            slow = nums[slow];
            fast = nums[fast];
            fast = nums[fast];
            if(fast == slow){
                break;
            }
        }
        slow = 0;
        while(1){
            slow = nums[slow];
            fast = nums[fast];
            if(slow == fast) return fast;
        }
    }
};