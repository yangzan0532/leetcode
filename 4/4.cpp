#include<stdio.h>

int thek(int *n, int ns, int ne, int *m, int ms, int me, int k){
	int nm = (ns + ne)/2;
	int mm = (ms + me)/2;
	int nv = n[nm];
	int mv = m[mm];
	if(ns > ne){
		return m[ms+k-1];
	}
	if(ms > me){
		return n[ns+k-1];
	}
	if(mv > nv){
		if(k-1 <= nm -ns + mm -ms) return thek(n, ns, ne, m, ms, mm-1, k);
		else return thek(n, nm+1, ne, m, ms, me, k -1 - (nm -ns));
	}
	else{
		if(k-1 <= nm-ns + mm-ms) return thek(n, ns, nm-1, m, ms, me, k);
		else return thek(n, ns, ne, m,mm+1, me, k -1 -(mm -ms));
	}
}
double findMedianSortedArrays(int* nums1, int nsize, int* nums2, int msize) {
	int len = nsize + msize ;
	if(len % 2){
		int k = len/2+1;
		return thek(nums1, 0, nsize-1, nums2, 0, msize-1, k);
	}
	else {
		int k = len/2;
		int ret1 = thek(nums1, 0, nsize-1, nums2, 0, msize-1, k) ;
		int ret2 = thek(nums1, 0, nsize-1, nums2, 0, msize-1, k+1);
		return (ret1 + ret2)/2.0;
	}
}

int main(){
	int a[] = {1,2,4,5,7,11,100};
	int b[] = {1};//,3,6,8,12,34,56};
	double r = findMedianSortedArrays(a, 7, b, 0);
	printf("%lf\n",r);
	return 0;
}
