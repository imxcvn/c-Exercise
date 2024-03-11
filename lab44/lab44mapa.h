
template<class K, class V> class Map;

template <class K, class V>
class MapEntry {
private:
	K m_key;
	V m_value;
	MapEntry(const K& key, const V& value)
		:
		m_key{ key },
		m_value{ value }
	{}

	friend class Map<K, V>;

};

template <class K, class V>
class Map {
private:
	std::vector<std::unique_ptr<MapEntry<K, V>>> m_entries;
public:

	Map() = default;
	Map(Map<K, V>&& m)
		:
		m_entries{ std::move(m.m_entries) }
	{}

	void clear() {
		m_entries.clear();
	}

	Map<K, V>& operator=(Map<K, V>&& m) {
		clear();
		m_entries = std::move(m.m_entries);
		return *this;
	}

	int findEntry(const K& key) const {
		for (int i = 0; i < m_entries.size(); i++) {
			if (m_entries[i]->m_key == key) {
				return i;
			}

		}
		return -1;
	}

	void set(const K& key, const V& value) {
		int entryIndex = findEntry(key);
		if (entryIndex >= 0) {
			m_entries[entryIndex]->m_value = value;
		}
		else {
			m_entries.emplace_back(new MapEntry<K, V>{ key, value });
		}
	}

	const V& get(const K& key) const {
		int entryIndeks = findEntry(key);
		if (entryIndeks >= 0) {
			return m_entries[entryIndeks]->m_value;
		}
		throw std::exception{ "Nie ma takiego klucza w mapie." };
	}

	void print() const {
		if (m_entries.size() == 0) {
			std::cout << "Mapa jest pusta." << std::endl;
		}
		else {
			for (int i = 0; i < m_entries.size(); i++) {
				std::cout << m_entries[i]->m_key << " -> " << m_entries[i]->m_value << std::endl;
			}
			std::cout << std::endl;
		}

	}

	int entriesSize() {
		return m_entries.size();
	}
};