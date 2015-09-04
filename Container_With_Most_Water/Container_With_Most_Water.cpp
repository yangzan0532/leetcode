#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int start_p = 0;
        int end_p = height.size() - 1;
        int res = 0;
        while(start_p < end_p){
            int length = end_p -start_p;
            int m_height = height[start_p] < height[end_p] ? height[start_p++] : height[end_p--];
            int area = m_height *  length;
            res = res > area ? res : area ;
        }
        return res;
    }
};

int main(){
    int n, m;
    Solution s;
    while(1){
        vector<int> h;
        cin >> n;
        while(n--){
            cin >> m;
            h.push_back(m);
        }
        cout << s.maxArea(h) << endl;
    }
    return 0;
}


