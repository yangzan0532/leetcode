class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; ++i){
            int visit1[10]={0};
            int visit2[10]={0};
            for(int j=0; j<9; ++j){
                if( board[i][j] != '.' && visit1[board[i][j]-'0']++ >= 1 ) return false; //验证行是否正确
                if( board[j][i] != '.' && visit2[board[j][i]-'0']++ >= 1 ) return false; // 验证列是否正确
            }
        }
        // 验证小方格是否正确
        for(int is=0; is<=6; is+=3){
            for(int js=0; js<=6; js+=3){
                int visit3[10]={0};
                for(int i=0; i<3; ++i){
                    for(int j=0; j<3; ++j){
                        if(board[i+is][j+js] != '.' && visit3[board[i+is][j+js]-'0']++ >= 1 ) return false;
                    }
                }
            }
        }
        return true;
    }
};
