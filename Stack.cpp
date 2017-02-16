#include"Stack.h"
#include<iostream>
const int N = 100;
template<class T>
stack<T>::stack():top(0),data(new T[N]){}

template<class T>
stack<T>::~stack() {
	delete[] data;
}

template<class T>
bool stack<T>::empty() {
	if (top < 1)
		return true;
	else return false;
}
template<class T>
bool stack<T>::push(const T elem) {
	if (top < N) {
		data[top] = elem;
		++top;
		return true;
	}
	return false;
}
template<class T>
T stack<T>::pop() {
	if (empty()) {
		std::cout << "underflow" << std::endl;
		return T();
	}
	return data[--top];
}
// *****************************      text          ******************************
/*
int main() {
	stack<int> text;
	std::cout << "empty?:" << text.empty() << std::endl;
	text.push(1);
	text.push(15);
	text.push(6); 
	text.push(66); 
	text.push(8);
	
	std::cout <<"empty?:"<< text.empty() << std::endl;

	std::cout << "pop:" << text.pop() << std::endl;
	std::cout << "pop:" << text.pop() << std::endl; 
	std::cout << "pop:" << text.pop() << std::endl;
	std::cout << "pop:" << text.pop() << std::endl;
	std::cout << "pop:" << text.pop() << std::endl;
	
	std::cout << "empty?:" << text.empty() << std::endl;
}
*/