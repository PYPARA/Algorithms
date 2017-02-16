#include"Queue.h"
#include<iostream>

const int N = 10;
template<class T>
queue<T>::queue():head(0),tail(0),data(new T[N]){}

template<class T>
queue<T>::~queue() {
	delete[] data;
}
template<class T>
bool queue<T>::empty() const{
	if (head == tail)
		return true;
	return false;
}

template<class T>
bool queue<T>::full() const{
	if (tail == (N - 1) && head == 0) {
		return true;
	}
	else if (head == tail + 1) {
		return true;
	}
	return false;

}
template<class T>
bool queue<T>::enqueue(const T elem) {
	if (!full()) {
		data[tail] = elem;
		if (tail == N - 1) {
			tail = 0;
		}
		else {
			++tail;
		}
		return true;
	}
	else {
		std::cout << "queue is full" << std::endl;
		return false;
	}
}

template<class T>
T queue<T>::dequeue() {
	if (empty()) {
		std::cout << "queue is empty!" << std::endl;
		return T();
	}
	else {
		return data[head++];
	}
}
//**************************** text *********************
/*
int main() {
	queue<int> text;
	text.enqueue(6);
	text.enqueue(7);
	text.enqueue(8);
	text.enqueue(9);
	std::cout << text.dequeue() << std::endl;
	std::cout << text.dequeue() << std::endl;
	std::cout << text.dequeue() << std::endl;
	std::cout << text.dequeue() << std::endl;
	return 0;
}
*/