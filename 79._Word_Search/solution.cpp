//
//回朔处理
//
class Solution {
public:
	//  这里是方向数组，表示左右上下四个方向
    int d[4][2]={{0,1},{0,-1},{-1, 0},{1,0}};
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0) return false;
        const char *p = word.c_str();
        vector<vector<int> >visit;
        
        for(int i=0, j=board[0].size(); i<board.size(); ++i){
            vector<int> t(j, 0);
            visit.push_back(t);
        }
        for(int i=0; i<board.size(); ++i){
            for(int j=0; j<board[0].size(); ++j){
                if(board[i][j] == p[0]){
                    if(dfs(board, visit, p, i, j)){
                        return true;
                    }
                } 
            }    
        }
        return false;
    }
    
    bool dfs(vector<vector<char> >&board, vector<vector<int> >&visit,const char *p, int i, int j){
        if(p[0] == '\0'){
            return true;
        }
        if(i >=0 && j >= 0 && i < board.size() && j < board[0].size()){
            if(board[i][j] == p[0] && visit[i][j] != 1){
                visit[i][j] = 1;
                for(int t=0; t<4; ++t){
                    int ni = i+d[t][0];
                    int nj = j+d[t][1];
                    if(dfs(board, visit,p+1, ni, nj))
                    {
                        return true;
                    }
                }
				// 这个地方一定要恢复
                visit[i][j] = 0 ;
            }
        }
        return false;
    }
};
