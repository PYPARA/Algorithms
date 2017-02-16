#pragma once
template<class T>
class queue {
public:
	queue();
	~queue();

	bool enqueue(const T);
	T dequeue();
	bool empty() const;
	bool full() const;
private:
	T* data;
	int head;
	int tail;
};