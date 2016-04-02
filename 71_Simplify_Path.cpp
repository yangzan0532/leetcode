// 一道简单的模拟题，
// .   移除
// ..  移除..以及上一级目录
// 如果所有的都移除了，则返回根目录 "/"
class Solution {
public:
    string simplifyPath(const string& path) {
        vector<string> path_array;
        split(path, "/", path_array);
        vector<string>::iterator it = path_array.begin();
        while(it != path_array.end()){
            if((*it).size() == 0){
                //cout << "1:erase:" << *it << endl;
                it = path_array.erase(it);
            }
            else if(*it == ".."){
                if(it != path_array.begin()){
                    --it;
                    it = path_array.erase(it);
                    //cout << "2:erase:" << *it << endl;
                }
                it = path_array.erase(it);
                //cout << "3:erase:" << *it << endl;
                
            }
            else if(*it == "."){
                it = path_array.erase(it);  
                //cout << "4:erase:" << *it << endl;
            }
            else{
                ++it;
            }
        }
        string res="";
        for(it=path_array.begin(); it != path_array.end(); ++it){
            res += ( "/" + *it);
        }
        if(res.size() == 0) res = "/";
        return res;
    }
    
    void split(const string &src, const string &c, vector<string> &res){
        size_t end = src.find(c);
        size_t start = 0;
        while(std::string::npos != end){
            res.push_back(src.substr(start, end-start));
            start = end + c.size();
            end = src.find(c, start);
        }
        if(start != src.length())
        {
            res.push_back(src.substr(start));
        }
    }
    
};
