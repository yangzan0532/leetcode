// 素数筛法
class Solution {
public:
    int countPrimes(int n) {
       bool *isNotPrime = new bool[n];
       isNotPrime[0] = true;
       isNotPrime[1] = true;
       for(int step=2; step < n; ++step)
       {
           for(int i=step*2; i<n; i+= step)
           {
               isNotPrime[i] = true;
           }
       }
       int count = 0;
       for(int i=2; i<n; ++i)
       {
           if(!isNotPrime[i]) ++count;
       }
       return count;
    }
};
