/*
 * 图的搜素，由于图中有环，访问过的点要标记，不要死循环了
 *
 * */
#include<iostream>
#include<vector>
#include<map>

using namespace std;

class UndirectedGraphNode {
	public:
      int label;
      vector<UndirectedGraphNode *> neighbors;
      UndirectedGraphNode(int x) : label(x) {};
};

class Solution {
public:
    
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node){
        map<int, UndirectedGraphNode*> node_ptrs;
        return dfs(node, node_ptrs);
    }
    
    UndirectedGraphNode *dfs (UndirectedGraphNode *node, map<int, UndirectedGraphNode*> &node_ptrs)
	{

        if(!node){
            return node;
        }
        UndirectedGraphNode *curr_node =NULL;
        int curr_label = node->label;
        map<int, UndirectedGraphNode*>::iterator  iter = node_ptrs.find(curr_label);
        if(iter == node_ptrs.end() ){ //说明没找到，则这是一个新的节点；
            curr_node = new UndirectedGraphNode(curr_label);
            node_ptrs[curr_label] = curr_node;
            for(size_t i=0; i < node->neighbors.size(); ++i){
                curr_node->neighbors.push_back(dfs(node->neighbors[i], node_ptrs));
            }
        }
        else{
            curr_node = iter->second;
        }
        return curr_node;
    }
};

int main(){
	Solution s;
	return 0;
}
