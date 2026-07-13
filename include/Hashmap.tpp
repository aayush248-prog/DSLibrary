

inline Hashcode::Hashcode() = default;

inline int Hashcode::hash(const int s, int size) {
    return s % size;
}

inline int Hashcode::hash(const std::string s, int size) {
    int idx = 0;
    for (char ch : s)
        idx += ch;
    return idx % size;
}

inline int Hashcode::hash(const char a, int size) {
    return a % size;
}

template<typename T>
int Hashcode::hash(const T& obj, int size) {
    if constexpr (requires { obj.formhash(); }) {
        return obj.formhash() % size;
    } else {
        std::stringstream ss;
        ss << &obj;
        return hash(ss.str(), size);
    }
}

// ======================
// Node
// ======================

template<typename K, typename V>
Node<K,V>::Node(const K keyusr, const V value)
    : first(keyusr), second(value), next(nullptr) {}

template<typename K, typename V>
Node<K,V>::~Node() = default;

// ======================
// Hashmap
// ======================

template<typename K, typename V>
Hashmap<K,V>::Hashmap()
    : size(1), lst_count(0), load_factor(0.0f)
{
    bucket = (Node<K,V>**)calloc(size, sizeof(Node<K,V>*));
}

template<typename K, typename V>
void Hashmap<K,V>::rehash() {

    int oldSize = size;
    Node<K,V>** oldBucket = bucket;

    size *= 2;
    lst_count = 0;
    load_factor = 0;

    bucket = (Node<K,V>**)calloc(size, sizeof(Node<K,V>*));

    for (int i = 0; i < oldSize; i++) {

        Node<K,V>* ptr = oldBucket[i];

        while (ptr) {

            Node<K,V>* next = ptr->next;

            insert(ptr->first, ptr->second);

            ptr->~Node<K,V>();
            free(ptr);

            ptr = next;
        }
    }

    free(oldBucket);
}

template<typename K, typename V>
void Hashmap<K,V>::insert(const K& key, const V& value) {

    if (V* found = find(key)) {
        *found = value;
        return;
    }

    load_factor = (float)(lst_count + 1) / size;

    if (load_factor >= 0.75f) {
        rehash();
    }

    Node<K,V>* node = (Node<K,V>*)malloc(sizeof(Node<K,V>));
    new(node) Node<K,V>(key, value);

    Hashcode hs;
    int idx = hs.hash(key, size);

    if (bucket[idx] == nullptr) {
        bucket[idx] = node;
    } else {

        Node<K,V>* temp = bucket[idx];

        while (temp->next)
            temp = temp->next;

        temp->next = node;
    }

    lst_count++;
}

template<typename K, typename V>
void Hashmap<K,V>::pop(const K& key) {

    Hashcode hs;
    int idx = hs.hash(key, size);

    Node<K,V>* ptr = bucket[idx];
    Node<K,V>* prev = nullptr;

    while (ptr && ptr->first != key) {
        prev = ptr;
        ptr = ptr->next;
    }

    if (!ptr)
        return;

    if (!prev)
        bucket[idx] = ptr->next;
    else
        prev->next = ptr->next;

    ptr->~Node<K,V>();
    free(ptr);

    lst_count--;
}

template<typename K, typename V>
V* Hashmap<K,V>::find(const K& key) {

    Hashcode hs;
    int idx = hs.hash(key, size);

    Node<K,V>* ptr = bucket[idx];

    while (ptr && ptr->first != key)
        ptr = ptr->next;

    return ptr ? &ptr->second : nullptr;
}

template<typename K, typename V>
V& Hashmap<K,V>::operator[](const K& key) {

    if (V* ptr = find(key))
        return *ptr;

    insert(key, V{});

    return *find(key);
}

template<typename K, typename V>
Hashmap<K,V>::Hashmap(const Hashmap& other)
    : size(other.size), lst_count(0), load_factor(0.0f)
{
    bucket = (Node<K,V>**)calloc(size, sizeof(Node<K,V>*));

    for (int i = 0; i < size; i++) {

        Node<K,V>* ptr = other.bucket[i];

        while (ptr) {
            insert(ptr->first, ptr->second);
            ptr = ptr->next;
        }
    }
}

template<typename K, typename V>
Hashmap<K,V>& Hashmap<K,V>::operator=(const Hashmap& other) {

    if (this == &other)
        return *this;

    for (int i = 0; i < size; i++) {

        Node<K,V>* ptr = bucket[i];

        while (ptr) {

            Node<K,V>* next = ptr->next;

            ptr->~Node<K,V>();
            free(ptr);

            ptr = next;
        }
    }

    free(bucket);

    size = other.size;
    lst_count = 0;
    load_factor = 0;

    bucket = (Node<K,V>**)calloc(size, sizeof(Node<K,V>*));

    for (int i = 0; i < size; i++) {

        Node<K,V>* ptr = other.bucket[i];

        while (ptr) {
            insert(ptr->first, ptr->second);
            ptr = ptr->next;
        }
    }

    return *this;
}

template<typename K, typename V>
Hashmap<K,V>::~Hashmap() {

    for (int i = 0; i < size; i++) {

        Node<K,V>* ptr = bucket[i];

        while (ptr) {

            Node<K,V>* next = ptr->next;

            ptr->~Node<K,V>();
            free(ptr);

            ptr = next;
        }
    }

    free(bucket);
}

template<typename K, typename V>
int Hashmap<K,V>::Size() {
    return size;
}

template<typename K, typename V>
bool Hashmap<K,V>::isempty() {
    return lst_count == 0;
}
