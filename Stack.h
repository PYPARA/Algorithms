#pragma once
template<class T>
class stack {
public:
	stack();
	~stack();

	bool empty();
	T pop();
	bool push(T);

private:
	T* data;
	int top;

};