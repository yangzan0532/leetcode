bool compare(const string &a,const string &b)
{
    return a+b > b+a;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>temp ; 
        string result  ;
        for(int i=0; i<nums.size(); ++i){
            temp.push_back(to_string(nums[i]));
        }
        sort(temp.begin(), temp.end(),compare);
        if(temp[0][0] == '0') return "0";
        for(int i=0; i<temp.size(); ++i){
            cout << i << " " << temp[i] <<  endl;
            result += temp[i];
        }
        return result;
    }
};
