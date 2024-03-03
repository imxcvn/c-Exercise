#pragma once
#include "Lab5pointer.h"
template <class T> class List;

template<class T>
class Node {
private:
	Pointer<Node<T>> m_next;
	T m_value;
public:
	Node(const T& v) : m_value{ v } {}
	Node* getNext() {
		return m_next.get();
	}

	T& getValue() {
		return m_value;
	}

	void setValue(const T& v) {
		m_value = v;
	}

	friend class List<T>;
};

template <class T>
class List {
private:
	Pointer<Node<T>> m_first;
	Node<T>* m_last;
	int m_size;

	template<class U>
	class Iterator
	{
	private:
		Node<U>* node;
	public:
		Iterator(Node<U>* node) {
			this->node = node;
		}

		Iterator() {
			node = nullptr;
		}

		U& operator*() const {
			return node->getValue();
		}

		U* operator->() const {
			return &node->getValue();
		}

		Iterator<U>& operator++() {
			node = node->getNext();
			return *this;
		}

		bool operator== (const Iterator<U>& el) const {
			return node == el.node;
		};

		bool operator!= (const Iterator<U>& el) const {
			return node != el.node;
		};
	};

public:
	using iterator = Iterator<T>;
	using const_iterator = Iterator<const T>;
	List() {
		m_last = nullptr;
		m_size = 0;
	}

	List(List<T>&& p) {
		m_first = std::move(p.m_first);
		m_last = p.m_last;
		m_size = p.m_size;
		p.m_last = nullptr;
		p.m_size = 0;
	}

	void addElement(const T& value) {
		Node<T>* newNode = new Node<T>{ value };
		if (m_first == nullptr) {
			m_first.reset(newNode);

		}
		else
			m_last->m_next.reset(newNode);
		m_last = newNode;
		m_size++;
	}

	int getSize() const {
		return m_size;
	}

	iterator begin() {
		return m_first.get();
	}

	const_iterator begin() const {
		return m_first.get();
	}

	iterator end() {
		return nullptr;
	}

	const_iterator end() const {
		return nullptr;
	}

	const_iterator cbegin() const {
		return m_first.get();
	}

	const_iterator cend() const {
		return nullptr;
	}

	void clear() {
		m_first.reset();
		m_last = nullptr;
		m_size = 0;
	}

	List<T>& operator=(List<T>&& p) {
		clear();

		m_first = std::move(p.m_first);
		m_last = p.m_last;
		m_size = p.m_size;

		p.m_last = nullptr;
		p.m_size = 0;

		return *this;
	}

	T& getElementAt(int index) {
		if (index < 0 || index >= m_size) {
			throw std::exception("Indeks poza zakresem.");
		}

		Node<T>* currentNode = m_first.get();
		for (int i = 0; i < index; ++i) {
			currentNode = currentNode->getNext();
		}

		return currentNode->getValue();
	}

	void sort() {
		if (m_size <= 1) {
			return;
		} 
		T* t = new T[m_size];
		Node<T>* current = m_first.get();
		int index = 0;
		while (current != nullptr) {
			t[index] = current->getValue();
			current = current->getNext();
			index++;
		}
		std::sort(t, t + m_size);

		index = 0;
		current = m_first.get();
		while (current != nullptr) {
			current->setValue(t[index]);
			current = current->getNext();
			index++;
		}
		delete[] t;
	}
};