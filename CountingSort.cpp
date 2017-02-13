/*
for	i←1 to k
	do C[i] ←0
for	j←1ton
	do C[A[j]] ←C[A[j]] + 1			⊳C[i] = |{key = i}|
for	i←2 to k
	doC[i] ←C[i] + C[i–1]				⊳C[i] = |{key ≤i}|
for j←n downto 1
	do B[C[A[j]]] ←A[j]
	   C[A[j]] ←C[A[j]] –1
*/
#include<iostream>

const int N = 100;
void CountingSort(int*a, int len, int k) {
	int c[N]; //辅助数组
	int b[N]; //新数组
	//由于数组是从0开始的，所以下面的下标可能会使你感到困惑，请画图对照理解
	for (int i = 0; i < k; ++i) {
		c[i] = 0;
	}
	for (int j = 0; j < len; ++j) {
		c[a[j] - 1] = c[a[j] - 1] + 1;
	}
	for (int i = 1; i < k; ++i) {
		c[i] = c[i] + c[i - 1];
	}
	for (int j = len - 1; j >= 0; --j) {
		b[c[a[j] - 1] - 1] = a[j];
		c[a[j] - 1] = c[a[j] - 1] - 1;
	}
	//把 b[] 还原到 a[]
	for (int j = 0; j < len; ++j) {
		a[j] = b[j];
	}
}

int main() {

	int a[18] = { 5,4,6,8,4,2,3,4,1,2,4,8,8,4,6,3,1,7};
	CountingSort(a, 18, 8);
	for (auto i:a) {
		std::cout << i << std::endl;
	}

}