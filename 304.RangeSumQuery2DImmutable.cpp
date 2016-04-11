// data[i][j] 表示矩阵 data[0][0] 到 data[i][j] 的和
// 则举证 row1, col1 , row2, col2 的和为:
// res  = data[row2][col2] - data[row1-1][col2] - data[row2][col1-1] + data[row-1][col1-1]; 
//

class NumMatrix {
public:
    vector< vector<int> > data;
    NumMatrix(vector<vector<int>> &m) {
        data = m;
        for(size_t i=0; i<m.size(); ++i){
            for(size_t j=1; j<m[0].size(); ++j){
                data[i][j] += data[i][j-1];
            }
        }
        if(m.size() > 0){ 
            for(size_t j=0; j<m[0].size(); ++j){
                for(size_t i=1; i<m.size(); ++i){
                    data[i][j] += data[i-1][j];
                }
            }
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int res = data[row2][col2];
        if(col1 >= 1  && row1 >= 1) res += data[row1-1][col1-1];
        if(col1 >= 1) res -= data[row2][col1-1]; 
        if(row1 >= 1) res -= data[row1-1][col2];
        return res;
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);
