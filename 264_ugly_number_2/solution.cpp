// 如果用下面的方法打表，会过，但是很慢。
// 猜测这段代码应该是每个测试用例对重新运行一次，所以每个测试用例都要调用打表算法，所以很慢
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>table;
        table.push_back(1);
        int i2=0,i3=0,i5=0;
        for(int i=0; i<n; i++){
            int curr2 = table[i2]*2;
            int curr3 = table[i3]*3;
            int curr5 = table[i5]*5;
            int currmin = min(curr2, min(curr3,curr5));
            if(currmin == curr2){
                i2++;
            }
            if(currmin == curr3){
                i3++;
            }
            if(currmin == curr5){
                i5++;
            }
            table.push_back(currmin);
            //cout << currmin << " ";
        }
        //cout << endl;
        return table[n-1];
    }
    
    int min(int a, int b){
        return a<b?a:b;
    }
};
/*
 *这段代码达标会超时的
 * 
class Solution {
public:
    vector<int> table;
    map<int, int>mymap;
    Solution(){
        int top = 0;
        int val = 0;
        int curr = 0L;
        table.push_back(1);
        while(top < table.size()){
            val = table[top++];
            if(val > 1073741823) continue;
            curr = val * 2L;
            if(check(curr)) table.push_back((int)curr);
            if(val > 715827882) continue;
            curr =val * 3;
            if(check(curr)) table.push_back((int)curr);
            if(val > 429496729) continue;
            curr =val * 5;
            if(check(curr)) table.push_back((int)curr);
        }
        //cout << table.size() << endl;
        sort(table.begin(), table.end());
        for(int i=0; i<table.size(); i++){
            cout <<table[i]<<",";
        }
        cout << endl;
    }
    bool check(int c){
        if(mymap.find(c) != mymap.end()) return false;
        else mymap[c] = 1;
        return true;
    }
    int nthUglyNumber(int n) {
        if(n>=1){
            return table[n-1];
        };
    }
};
*/