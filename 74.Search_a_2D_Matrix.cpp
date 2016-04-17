//
// 对行和列分别二分
//
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& m, int target) {
        int rowm = 0, rows = 0, rowe = m.size()-1;
        int colm = 0, cols = 0, cole = m[0].size()-1;
        while(rows <= rowe ){ // binary search rows
            rowm = (rows+rowe) / 2;
            if(m[rowm][0] == target || m[rowm][cole] == target) 
                return true;
            else if(m[rowm][0] > target){
                rowe = rowm - 1;
            }
            else{
                rows = rowm + 1;
            }
        }
        rowm = rowe;
        
        if(rowm < 0 || rowm >= m.size()) return false;
        while(cols <= cole){ // binary search cols
            colm = (cols + cole) / 2;
            if(m[rowm][colm] == target) return true;
            else if(m[rowm][colm] < target){
                cols = colm + 1;
            }
            else{
                cole = colm - 1; 
            }
        }
        return false;
    }
};
