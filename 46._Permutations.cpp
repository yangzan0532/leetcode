// 常规解法，用回朔枚举所有的结果就可以了
class Solution {
public:
    vector<int> visit;
    vector< vector<int> >res;
    
    vector<vector<int>> permute(vector<int>& nums) {
        int tot = nums.size();
        vector<int>tmp(tot, 0);
        visit.resize(tot);
        for(int i=0; i<tot; ++i) visit[i]=0;
        res.clear();
        general(nums, tmp, 0);
        return res;
    }
    
    void general(vector<int>& nums, vector< int >&tmp, int curr){
        if(curr == nums.size()){
            res.push_back(tmp);
            return ;
        }
        for(int i=0; i<visit.size(); ++i){
            if(visit[i]) continue;       // 这个元素已经使用过，则跳过
            visit[i]=1;  // 标记为已经访问过
            tmp[curr] = nums[i];
            general(nums, tmp, curr+1);
            visit[i]=0;     // 回朔，这里记得重置为0
        }
    }
};
