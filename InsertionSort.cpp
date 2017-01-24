#include<iostream>
void InsertionSort(int *a,int len) {
	for (int j = 1; j < len ; ++j) {
		int key = a[j];
		int i = j - 1;
		while (i >= 0 && a[i] > key) {
			a[i + 1] = a[i];
			--i;
		}
		a[i+1] = key;
	}
}

int main() {
	int a[16] = { 8,6,5,9,2,3,4,7,5,3,5,6,1,6,4,15 };
	InsertionSort(a, 16);
	for (auto i : a) {
		std::cout << i << std::endl;
	}

	return 0;
}


/*
Pseudocode：
INSERTION-SORT (A, n)⊳A[1 . . n]
    for j ←2 to n 
        do  key ←A[ j]
            i ←j –1
            while  i > 0 and  A[i] > key
                do A[i+1] ←A[i]
                    i ←i –1
            A[i+1] = key
*/
