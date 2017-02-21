#include"List.h"
#include<iostream>
template<class T>
List<T>::List() :head(new Node<T>) {
	head->prev = nullptr;
	head->next = nullptr;
	head->data = T();
}
template<class T>
List<T>::~List() {
	while (head != nullptr) {
		auto de = head;
		head = head->next;
		delete de;
	}
}


template<class T>
Node<T>*  List<T>::ListSearch(const T& k) const {
	auto current = head;
	while (current != nullptr && current->data != k) {
		current = current->next;
	}
	return current;
}

template<class T>
bool  List<T>::ListInsert(const T rhs) {
	auto temp = new Node<T>;
	temp->data = rhs;
	head->prev = temp;
	temp->next = head;
	temp->prev = nullptr;
	head = temp;
	return true;
}

template<class T>
bool  List<T>::ListDelete(T x) {
	auto de = ListSearch(x);
	if (de != nullptr) {
		if (de->prev == nullptr&&de->next == nullptr) {
			delete de;
		}else if (de->prev == nullptr) {
			head = de->next;
			head->prev = nullptr;
			de->next = nullptr;
			delete de;
		}else if (de->next == nullptr){
			de->prev->next = nullptr;
			de->prev = nullptr;
			delete de;
		}
		else {
			de->prev->next = de->next;
			de->next->prev = de->prev;
			de->prev = nullptr;
			de->next = nullptr;
			delete de;
		}
		return true;
	}
	return false;
}
/*********************************text *******************************/
/*
int main() {

	List<int> Li;

	Li.ListInsert(1);
	Li.ListInsert(2);
	Li.ListInsert(3);
	Li.ListInsert(4);
	Li.ListInsert(5);
	std::cout << Li.ListSearch(1)->data << std::endl;
	std::cout << Li.ListSearch(2)->data << std::endl;
	std::cout << Li.ListSearch(3)->data << std::endl;
	std::cout << Li.ListSearch(4)->data << std::endl;
	std::cout << Li.ListSearch(5)->data << std::endl;

	Li.ListDelete(3);
	
	Li.ListDelete(5);
	
	return 0;

}
*/
