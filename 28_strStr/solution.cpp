
class Solution {
	public:
		int next[20000];
		int strStr(string &src, string &b) {
		    if(needle.size() == 0) return 0;
			int len = src.size();
			int len_b = b.size();
			int j=0;
			
			next[0] = next[1]= 0;
			for(int i=1; i<len_b; ++i)
			{
				while(j>0 && b[i] != b[j]) j=next[j];
				if(b[i] == b[j]) ++j;
				next[i+1] = j;
			}
			
			j = 0;
			for(int i=0; i < len; ++i){
				while(j>0 && src[i] != b[j])  j=next[j];
				if(src[i] == b[j])  ++j;	
				if(j == len_b){
					return i-j+1;
				}
			}
			return -1;
		}
};
