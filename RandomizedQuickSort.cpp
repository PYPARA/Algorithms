#include<iostream>
int partition(int *a, int lhs, int rhs);
int RandomizedPartition(int *a, int lhs, int rhs) {
	int rad = (rand() % (rhs - lhs + 1)) + lhs;
	int pivot = a[rad];
	int temp = a[lhs];
	a[lhs] = pivot;
	a[rad] = temp;
	return partition(a, lhs, rhs);

}

void RandomizedQuickSort(int *a, int lhs, int rhs) {
	if (lhs >= rhs) {
		return;
	}
	int q = RandomizedPartition(a, lhs, rhs);
	RandomizedQuickSort(a, lhs, q);
	RandomizedQuickSort(a, q + 1, rhs);
}


int partition(int *a, int lhs, int rhs) {
	int i = lhs;
	int j = lhs + 1;
	int pivot = a[lhs];
	while (j <= rhs) {
		if (a[j] >= pivot) {
			++j;
		}
		else {
			++i;
			int temp = a[i];
			a[i] = a[j];
			a[j] = temp;
			++j;
		}
	}
	int temp2 = a[i];
	a[i] = pivot;
	a[lhs] = temp2;
	return i;
}



void QuickSort(int *a, int lhs, int rhs) {
	if (lhs >= rhs) {
		return;
	}
	int q = partition(a, lhs, rhs);
	QuickSort(a, lhs, q);
	QuickSort(a, q + 1, rhs);
}

int main() {

	int a[22] = { 9,8,7,6,5,4,3,2,1,0,5,65,435,224,234,84,642,32,13,87,215,21 };
	RandomizedQuickSort(a, 0, 21);
	for (auto c : a) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	return 0;
}