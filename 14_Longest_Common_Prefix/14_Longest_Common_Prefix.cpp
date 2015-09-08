#include<iostream>
#include<string>
#include<vector>

using namespace std;

class Node{
	public :
		Node(){
			left = NULL;
			right = NULL;
			num = 0;
			v = 0;
		}

		Node(char p_v){
			left = NULL;
			right = NULL;
			num = 1;
			v = p_v;
		}
		
		char get_value(){
			return v;
		}
		int get_count(){
			return num;
		}
		void add_child(Node *p){
			left = p;
		}
		void add_brother(Node *p){
			right = p;
		}
		Node* get_child(){
			return left;
		}
		Node* get_brother(){
			return right;
		}
		bool is_same(char p_v){
			return v == p_v;
		}
		bool has_child(){
			return left !=NULL;
		}
		bool has_brother(){
			return right != NULL;
		}
		
		void count_add(){
			++num;
		}

		~Node(){
			delete left;
			delete right;
		}
	private :	
		Node *left;
		Node *right;
		char v;
		int num;
};


bool build_trie(Node *head, const string &s){
	Node *pre = head;
	Node *current = pre->get_child();
	for(size_t i=0; i<s.length(); ++i){
		if(current == NULL){ // 如果当前节点不存在，则创建
			current = new Node(s[i]);		
			pre->add_child(current); //将当前节点设置为父节点的儿子节点
		}
		else if(current->is_same(s[i])){ //当前节点已经存在，
			current->count_add();
		}
		else{ //在兄弟节点遍历
			bool not_found_brother = true;
			pre = current;
			current = pre->get_brother();

			while(current){
				if(current->is_same(s[i])){
					current->count_add();
					not_found_brother = false;
					break;
				}
				pre = current;
				current = pre->get_brother();
			};
			if(not_found_brother){ //所有的兄弟节点遍历完，仍然没有找到，则添加一个兄弟节点
				current = new Node(s[i]);	
				pre->add_brother(current);	
			}
		}
		pre = current;
		current = pre->get_child();
	}
	return 0;
}
void show(Node *ptr){
	if(!ptr) return ;
	cout << ptr->get_value() << "(" << ptr->get_count() <<") ";
	if(!ptr->get_child()) cout << endl;
	show(ptr->get_child());
	show(ptr->get_brother());
}

class Solution {
	public:
		string longestCommonPrefix(vector<string>& strs) {
			Node *head = new Node(); 
			vector<char> res;
			int str_num = strs.size();
			for(size_t i=0; i<strs.size(); ++i){
				build_trie(head , strs[i]);		
			}
			for(Node *ptr = head->get_child(); ptr !=NULL; ptr=ptr->get_child()){
				if(ptr && str_num == ptr->get_count()){
					res.push_back(ptr->get_value());
				}
				else break;
			}
			return string(res.begin(), res.end());
		}
};

int main(){
	int n;
	string ss;
	cin >> n;
	vector<string> v;
	while(n--){
		cin >> ss;
		v.push_back(ss);
	}
	Solution s;
	cout <<"res :" <<  s.longestCommonPrefix(v) << endl;
}

