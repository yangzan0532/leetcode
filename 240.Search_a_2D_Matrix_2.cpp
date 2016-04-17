// 遍历行，对列进行二分搜索
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int rowm = 0;
        while(rowm < m.size() ){ // binary search rows
            int cols = 0, cole = m[rowm].size()-1;
            if(m[rowm][cols] <= target && m[rowm][cole] >= target){
                while(cols <= cole){ // binary search cols
                    int colm = (cols + cole) / 2;
                    if(m[rowm][colm] == target) return true;
                    else if(m[rowm][colm] < target){
                        cols = colm + 1;
                    }
                    else{
                        cole = colm - 1; 
                    }
                }
            }
            ++rowm;
        }
        return false;
    }
};
