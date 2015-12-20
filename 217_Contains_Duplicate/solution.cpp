class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>my_map;
        for(vector<int>::iterator curr=nums.begin();
        curr != nums.end();
        ++curr){
            if((my_map.insert(make_pair(*curr, 1))).second== false){
                return true;
            }
        }
        return false;
    }
};
