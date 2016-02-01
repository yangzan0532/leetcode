/*
 * O(1)  的空间复杂度，利用原用的矩阵的第一行和第一列存储信息
 * 
 */
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        bool col=false, row=false;
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0; i<rows; ++i){
            for(int j=0; j<cols; ++j){
                if(0 == matrix[i][j]){
                    if(0 == j) row=true;
                    if(0 == i) col=true;
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        for(int i=1; i<rows; ++i){
            if(0 == matrix[i][0]){
                for(int j=0; j< cols; ++j) matrix[i][j] =0;
            }
        }
        for(int j=1; j<cols; ++j){
            if(0 == matrix[0][j]){
                for(int i=0; i<rows; ++i) matrix[i][j] =0;
            }
        }
        if(row) for(int i=0; i<rows; ++i) matrix[i][0] =0;
        if(col) for(int i=0; i<cols; ++i) matrix[0][i] =0;
    }
};
