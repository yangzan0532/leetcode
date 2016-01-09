class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int row = matrix.size();
        if(row == 0) return res; 
        int col = matrix[0].size();
        int length = row * col;
        int level = -1;
        int i=-1,j=-1;
        while(res.size() < length){
            for(level++,++i,++j; j<col-level; ++j){
                res.push_back(matrix[i][j]);
            }
            if(res.size() == length ) break;
            
            for(++i, --j; i<row-level; ++i){
                res.push_back(matrix[i][j]);
            }
            if(res.size() == length ) break;
            
            for(--j,--i;j>=level; --j){
                res.push_back(matrix[i][j]);
            }
            if(res.size() == length ) break;
            
            for(--i,++j; i>level; --i){
                res.push_back(matrix[i][j]);
            }
            if(res.size() == length ) break;
        }
        return res;
    }
    
    
};
