#pragma once

template <class T> class List3;

template<class T>
class Node3 {
private:
    std::unique_ptr<Node3<T>> m_next;
    T m_value;
public:
    Node3(const T& v) : m_value{ v } {}

    Node3* getNext() {
        return m_next.get();
    }

    T& getValue() {
        return m_value;
    }

    void setValue(const T& v) {
        m_value = v;
    }

    friend class List3<T>;
};

template <class T>
class List3 {
private:
    std::unique_ptr<Node3<T>> m_first;
    Node3<T>* m_last;
    int m_size;

    static List3<T>& getSingletonInstance() {
        static List3<T> instance;
        return instance;
    }
    List3() : m_last(nullptr), m_size(0) {}

    List3(List3<T>&& p) : m_first(std::move(p.m_first)), m_last(p.m_last), m_size(p.m_size) {
        p.m_last = nullptr;
        p.m_size = 0;
    }

    template<class U>
    class Iterator
    {
    private:
        Node3<U>* node;
    public:
        Iterator(Node3<U>* node) : node(node) {}

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

    void addElement(const T& value) {
        Node3<T>* newNode = new Node3<T>{ value };
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

    List3<T>& operator=(List3<T>&& p) {
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

        Node3<T>* currentNode = m_first.get();
        for (int i = 0; i < index; ++i) {
            currentNode = currentNode->getNext();
        }

        return currentNode->getValue();
    }

    static List3<T>& getInstance() {
        return getSingletonInstance();
    }
};