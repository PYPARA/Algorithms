#pragma once
template<class T>
class stack {
public:
	stack();
	~stack();

	bool empty() const;
	T pop();
	bool push(const T);

private:
	T* data;
	int top;

};
