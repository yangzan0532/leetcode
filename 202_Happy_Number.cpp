class Solution {
public:
    map<int , int> visit;
    Solution(){
    }
    
    void getDig(int m, vector<int> &n){
        while(m >= 10){
            n.push_back(m % 10);
            m /= 10;
        }
        n.push_back(m);
    }
    

    bool isHappy(int n) {
        int m1[10]={0,1,4,9,16,25,36,49,64,81};
        visit.clear();
        vector<int> dig;
        while(1){
            dig.clear();
            getDig(n, dig);
            int res = 0;
            for(int i=0; i<dig.size(); ++i){
                res += m1[dig[i]];
            }

            if(res == 1) return true;
            
            if(visit.find(res) != visit.end()) return false;
            visit[res] = 1;
            n = res;
        }
    }
};
