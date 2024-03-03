#pragma once
#include <memory>

template <class T> class List2;

template<class T>
class Node2 {
private:
    std::unique_ptr<Node2<T>> m_next;
    T m_value;
public:
    Node2(const T& v) : m_value{ v } {}

    Node2* getNext() {
        return m_next.get();
    }

    T& getValue() {
        return m_value;
    }

    void setValue(const T& v) {
        m_value = v;
    }

    friend class List2<T>;
};

template <class T>
class List2 {
private:
    std::unique_ptr<Node2<T>> m_first;
    Node2<T>* m_last;
    int m_size;

    template<class U>
    class Iterator
    {
    private:
        Node2<U>* node;
    public:
        Iterator(Node2<U>* node) : node(node) {}

        Iterator() : node(nullptr) {}

        U& operator*() const {
            return node->getValue();
        }

        U* operator->() const {
            return &node->getValue();
        }

        Iterator<U>& operator++() {
            node = node->m_next.get();
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

    List2() : m_last(nullptr), m_size(0) {}

    List2(List2<T>&& p) : m_first(std::move(p.m_first)), m_last(p.m_last), m_size(p.m_size) {
        p.m_last = nullptr;
        p.m_size = 0;
    }

    void addElement(const T& value) {
        Node2<T>* newNode = new Node2<T>{ value };
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

    List2<T>& operator=(List2<T>&& p) {
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

        Node2<T>* currentNode = m_first.get();
        for (int i = 0; i < index; ++i) {
            currentNode = currentNode->getNext();
        }

        return currentNode->getValue();
    }
};