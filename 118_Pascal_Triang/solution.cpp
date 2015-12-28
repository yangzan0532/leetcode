class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int> >res;
        if(numRows == 0) return res;
        for(int i=0; i<numRows; ++i){
            vector<int>t;
            for(int j=0; j<i; j++){
                if(0==j){
                    t.push_back(1);
                }
                else{
                    t.push_back(res[i-1][j] + res[i-1][j-1]);
                }
            } 
            t.push_back(1);
            res.push_back(t);
        }
        return res;
    }
};
