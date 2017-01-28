#include<iostream>

bool BinarySearch(int* a,int lhs,int rhs,int val) {
	if (lhs > rhs) {
		return false;
	}

	if (a[( lhs + rhs) / 2] == val) {
		return true;
	}
	else if (a[(lhs + rhs) / 2] < val) {
		BinarySearch(a, (lhs + rhs) / 2 + 1, rhs, val);
	}
	else {
		BinarySearch(a, lhs, (lhs + rhs) / 2 - 1, val);
	}
	
}
int main() {
	int a[] = { 0,1,2,3,4,5,6,7,8,9 };
	std::cout << BinarySearch(a, 0, 9, 5) << std::endl;
	std::cout << BinarySearch(a, 0, 9, 10) << std::endl;
	return 0;
}

/*
Find an element in a sorted array:
1.Divide:Check middle element.
2.Conquer:Recursively search 1subarray.
3.Combine:Trivial.
*/