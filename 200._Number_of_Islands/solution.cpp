// 用图的宽搜应该很容易解决
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int island_flag=1;
        if(grid.size() == 0 ) return 0;
        vector<vector<int>>visit;
        for(int i=0, l = grid[0].size(); i<grid.size(); ++i){
            vector<int> item(l, 0);
            visit.push_back( item );
        }
        for(int i=0; i<grid.size(); ++i){
            for(int j=0; j<grid[0].size(); ++j){
                if(grid[i][j] == '1' && !visit[i][j]){
                    bfs(grid, visit, i, j, island_flag);
                    ++island_flag;
                }
            }
        }
        return island_flag-1;
    }
    
    void bfs(vector<vector<char>>& grid, vector<vector<int> >&visit,  int i, int j, int flag){
        pair<int, int>pos;
        queue<pair<int, int>>que;
        que.push(make_pair(i,j));
        grid[i][j] = flag;
        int d[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
        while(!que.empty()){
            pos = que.front();
            que.pop();
            int i = pos.first;
            int j = pos.second;
            for(int t=0; t<4; ++t){ //遍历四个方向，看是否连通
                int ni = i+d[t][0];
                int nj = j+d[t][1];
                if(ni >= 0 && ni < grid.size() && nj >=0 && nj < grid[0].size()){
                    if(grid[ni][nj] == '1' && !visit[ni][nj]){
                        visit[ni][nj] = flag;
                        que.push(make_pair(ni, nj));
                    }
                }
            }
        }
    }
};
