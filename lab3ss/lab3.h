#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

template <typename T>
class Stack
{
	T* data;
	T* topOfStack;
	int capacity;

	class Iterator
	{
	private:
		T* pointer;
	public:
		Iterator(T* pointer) {
			this->pointer = pointer;
		}

		T operator*() const {
			return *pointer;
		}

		T operator->() const {
			return pointer;
		}

		Iterator& operator++() {
			--pointer;
			return *this;
		}

		Iterator& operator--() {
			++pointer;
			return *this;
		}

		bool operator== (const Iterator& el) {
			return pointer == el.pointer;
		};

		bool operator!= (const Iterator& el) {
			return pointer != el.pointer;
		};
	};

public:
	Stack(int size) {
		data = new T[size];
		topOfStack = data;
		capacity = size;
	}

	~Stack() {
		delete[] data;
	}

	Iterator begin() const {
		return Iterator(topOfStack - 1);
	}

	Iterator end() const {
		return Iterator(data - 1);
	}

	bool empty() const {
		return topOfStack == data;
	}

	void push(const T& element) {
		if (topOfStack == data + capacity)
		{
			throw std::exception("Stos jest pelny");
		}
		*topOfStack = element;
		topOfStack++;
	}

	void pop() {
		if (empty()) {
			throw std::exception("Stos jest pusty");
		}
		topOfStack--;
	}

	T& top() {
		if (empty()) {
			throw std::exception("Stos jest pusty");
		}
		return *(topOfStack - 1);
	}

	int size() const {
		return topOfStack - data;
	}
};

