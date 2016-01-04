class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int> >res(n);
        for(int i=0; i<n; ++i){
            res[i].resize(n);
        }
        int tot = 1;
        int aim = n*n;
        int i=0,j=0;
        for(int level = 0; ; ++level){
            int end = n - level;
            for(j=level; j< end; j++){
                res[i][j] = tot++;
            }
            if(tot > aim) break;
            --j;
        
            for(i= level+1; i< end; i++){
                res[i][j] = tot++;
            }
            if(tot > aim) break;
            --i;
            --j;
            
            for(; j >= level; j--){
                res[i][j] = tot++;
            }
            if(tot > aim) break;
            ++j;
            --i;
            for(; i>level; i--){
                res[i][j] = tot++; 
            }
            if(tot > aim) break;
            ++i;
            ++j;
        }
        return res;
    }
};
