#include<iostream>
const int N = 100;
void merge(int * a,int lhs,int mid,int rhs) {
	int b[N];
	int p1 = lhs;    //数组1下标
	int p2 = mid + 1; //数组2下标
	int p3 = 0;  //b[] 下标
	while (p1 <= mid && p2 <= rhs) {
		if (a[p1] <= a[p2]) {
			b[p3] = a[p1];
			++p1;
			++p3;
		}
		else {
			b[p3] = a[p2];
			++p2;
			++p3;
		}
	}
	if (p1 <= mid) {
		for (;  p1<= mid; ++p1) {
			b[p3] = a[p1];
			++p3;
		}
	}
	else {
		for (; p2 <= rhs; ++p2) {
			b[p3] = a[p2];
			++p3;
		}
	}
	for (int i = lhs, j = 0 ; i <= rhs; ++i,++j) {
		a[i] = b[j];
	}
}

void MergeSort(int * a,int lhs,int rhs) {
	if (lhs < rhs) {
		int mid = (lhs + rhs) / 2;
		MergeSort(a, lhs, mid);
		MergeSort(a, mid + 1, rhs);
		merge(a, lhs, mid , rhs);
	}
}

int main() {
	int a[11] = { 10,9,8,7,6,5,4,3,2,1,0 };
	MergeSort(a, 0,10);
	for (auto c : a) {
		std::cout << c << std::endl;
	}


	return 0;
}

/*
Pseudocode：
MERGE-SORTA[1 . . n]
1.If n= 1, done.
2.Recursively sort A[ 1 . . ⎡n/2⎤]and A[ ⎡n/2⎤+1 . . n ] .
3.“Merge”the 2sorted lists.
*/