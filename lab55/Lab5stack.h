#pragma once
#include "Lab5pointer.h"

template <typename T>
class Stack
{
	Pointer<T, ArrayDeleter<T>> data;
	T* topOfStack;
	int capacity;

	class Iterator
	{
	private:
		T* pointer;
	public:
		using value_type = T;
		using difference_type = int;
		using reference = T&;


		Iterator(T* pointer) {
			this->pointer = pointer;
		}

		Iterator() {
			pointer = nullptr;
		}

		T& operator*() const {
			return *pointer;
		}

		int operator-(const Iterator& a) const {
			return pointer - a.pointer;
		}

		Iterator operator+(int n) const {
			return { pointer - n };
		}

		Iterator operator-(int n) const {
			return { pointer + n };
		}

		Iterator& operator++() {
			--pointer;
			return *this;
		}

		Iterator operator++(int) const {
			Iterator i = *this;
			--pointer;
			return i;
		}

		Iterator& operator--() {
			++pointer;
			return *this;
		}

		Iterator operator--(int) const {
			Iterator i = *this;
			++pointer;
			return i;
		}

		bool operator<(const Iterator& el) const {
			return pointer > el.pointer;
		}

		bool operator== (const Iterator& el) const {
			return pointer == el.pointer;
		};

		bool operator!= (const Iterator& el) const {
			return pointer != el.pointer;
		};
	};

public:
	using iterator = Iterator;

	Stack(int size) {
		data.reset(new T[size]);
		topOfStack = data.get();
		capacity = size;
	}

	Stack(Stack<T>&& other)
		: data(std::move(other.data)), topOfStack(other.topOfStack), capacity(other.capacity)
	{
		other.topOfStack = nullptr;
		other.capacity = 0;
	}

	~Stack() {
		
	}

	Iterator begin() const {
		return Iterator(topOfStack - 1);
	}

	Iterator end() const {
		return Iterator(data.get() - 1);
	}

	bool empty() const {
		return topOfStack == data.get();
	}

	void push(const T& element) {
		if (topOfStack == data.get() + capacity)
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
		return topOfStack - data.get();
	}

	Stack& operator=(Stack&& other) {
		if (this != &other)
		{

			data = std::move(other.data);
			topOfStack = other.topOfStack;
			capacity = other.capacity;

			other.topOfStack = nullptr;
			other.capacity = 0;
		}

		return *this;
	}

};