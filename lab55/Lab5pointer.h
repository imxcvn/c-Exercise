#pragma once

template <class T, class Deleter=std::default_delete<T>>
class Pointer {
private:
	T* pointer;
public:
	Pointer() {
		pointer = nullptr;
	}

	Pointer(T* t) {
		pointer = t;
	}

	Pointer(Pointer<T>&& p) {
		pointer = p.pointer;
		p.pointer = nullptr;
	}

	Pointer(const Pointer<T>& p) = delete;

	~Pointer() {
		Deleter d;
		d(pointer);
	}

	T* get() const {
		return pointer;
	}

	void reset() {
		delete pointer;
		pointer = nullptr;
	}

	void reset(T* p) {
		delete pointer;
		pointer = p;
	}

	T* operator->() const {
		return pointer;
	}

	operator bool() const {
		return pointer != nullptr;
	}

	bool operator== (const Pointer<T>& el) const {
		return pointer == el.pointer;
	}

	bool operator!= (const Pointer<T>& el) const {
		return pointer != el.pointer;
	}

	Pointer<T>& operator=(Pointer<T>&& p) {
		delete pointer;
		pointer = p.pointer;
		p.pointer = nullptr;
		return *this;
	}

	Pointer<T>& operator=(const Pointer<T>& p) = delete;

};

template <class T> class ArrayDeleter
{
public:
	void operator()(T* array) {
		delete[] array;
	}
};
