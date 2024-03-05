template <class T> class List;

template <class T>
class Node {
private:
	Node<T>* m_next = nullptr;
	T m_value;
	friend class List<T>;
public:
	Node(const T& v) : m_value{ v } {}
	Node* getNext() const {
		return m_next;
	}

	const T& getValue() const {
		return m_value;
	}

	void setValue(const T& v) {
		m_value = v;
	}
};

template <class T>
class List {
private:
	Node<T>* m_first;
	Node<T>* m_last;
	int m_size;
public:
	List() {
		m_first = nullptr;
		m_last = nullptr;
		m_size = 0;
	}

	~List() {
		Node<T>* current = m_first;
		while (current != nullptr) {
			Node<T>* next = current->m_next;
			delete current;
			current = next;
		}
	}

	void addElement(const T& value) {
		Node<T>* newNode = new Node<T>{ value };
		if (m_first == nullptr) {
			m_first = newNode;

		}
		else
			m_last->m_next = newNode;
		m_last = newNode;
		m_size++;
	}

	int getSize() const {
		return m_size;
	}

	Node<T>* getFirst() const {
		return m_first;
	}

	Node<T>* getLast() const {
		return m_last;
	}
};