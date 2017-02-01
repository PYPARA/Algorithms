#include<iostream>

void MaxHeapify(int *a, int i, int heap_size) {
	int l = 2 * i + 1;
	int r = 2 * i + 2;
	int largest = i;
	if (l < heap_size && a[l] > a[i]) {
		largest = l;
	}
	if (r < heap_size && a[r] > a[largest]) {
		largest = r;
	}
	if (largest != i) {
		int temp = a[i];
		a[i] = a[largest];
		a[largest] = temp;
		MaxHeapify(a, largest, heap_size);
	}

}



void BuildMaxHeap(int *a, int len) {
	int heap_size = len;
	for (int i = (len-1) / 2; i >= 0; --i) {
		MaxHeapify(a, i,heap_size);
	}
}


void HeapSort(int *a, int len) {
	int heap_size = len;
	BuildMaxHeap(a, len);
	for (int i = len-1; i>=1;--i) {
		int max = a[0];
		a[0] = a[i];
		a[i] = max;
		--heap_size;
		MaxHeapify(a, 0,heap_size);
	}
}

int main() {
	int a[31] = { 5,6,8,7,41,2,3,1,64,84,31,24,6,1,7,7,6,3,2,1,4,5,6,8,4,5,2,16,315,6541,3151 };
	HeapSort(a, 31);
	for (auto c : a) {
		std::cout << c << " ";
	}
	std::cout << std::endl;
	return 0;
}
/*
MAX-HEAPIFY (A,i)
1. l=LEFT(i)
2. r=RIGHT(i)
3. if l <= A.heap-size and A[l]>A[i]
4.		largest=l
5. else largest=i
6. if r <= A.heap-size and A[r]>A[largest]
7.		largest=r
8. if largest!=i
9.		exchangeA[i] with A[largest]
10.		MAX-HEAPIFY (A,largest)

BUILD-MAX-HEAP(A)
1. A.heap-size = A.length
2. for i= [A.length/2] downto 1
3.		MAX-HEAPIFY (A,i)

HEAPSORT(A)
1. BUILD-MAX-HEAP(A)
2. for i=A.length downto 2
3.		exchange A[1] with A[i]
		A.heapsize =A.heap-size - 1
		MAX-HEAPIFY (A,1)


*/