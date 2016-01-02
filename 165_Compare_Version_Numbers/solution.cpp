class Solution {
public:
    int split_2_int(const string &str, vector<int> &res){
        int last=0;
        size_t i = str.find_first_of(".", 0);
        while(i != string::npos){
            res.push_back(atoi(str.substr(last, i-last).c_str()));
            last = i+1;
            i=str.find_first_of(".", last);
        }
        if(i-last > 0){
            res.push_back(atoi(str.substr(last, i-last).c_str()));
        }
       // for(int j=0; j<res.size(); ++j) cout << " "<< res[j];
        //    cout << endl;
        return 0;
    }
    int compareVersion(string version1, string version2) {
        vector<int>v1;
        vector<int>v2;
        split_2_int(version1, v1);
        split_2_int(version2, v2);
        int minl = min(v1.size(), v2.size());
        for(int i=0; i<minl; ++i){
            if(v1[i] == v2[i]) continue;
            if(v1[i] < v2[i]) return -1;
            else return 1;
        }
        if(v1.size() < v2.size()){
            for(int i=minl; i<v2.size(); i++){
                if(v2[i]!=0) return -1;
            }
            return 0;
        }
        if(v1.size() > v2.size()){
            for(int i = minl; i<v1.size(); ++i){
                if(v1[i]!= 0) return 1;
            }
            return 0;
        }
        return 0;
    }
};
