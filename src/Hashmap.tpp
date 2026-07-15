#ifndef HASHMAP_TPP
#define HASHMAP_TPP

#include <type_traits>

//================ Hashcode =================//

inline Hashcode::Hashcode()
{
}

inline int Hashcode::hash(const int s, int size)
{
    return s % size;
}

inline int Hashcode::hash(const string s, int size)
{
    int idx = 0;

    for(char ch : s)
        idx += ch;

    return idx % size;
}

inline int Hashcode::hash(const char a, int size)
{
    return a % size;
}

template<typename T>
int Hashcode::hash(const T& obj, int size)
{
    if constexpr (requires { obj.formhash(); })
    {
        return obj.formhash() % size;
    }
    else
    {
        static_assert(sizeof(T) == 0,
        "No hash available for this type");
    }
}

//================ HashNode =================//

template<typename K, typename V>
HashNode<K,V>::HashNode(const K& key, const V& value)
    : Key(key), Value(value)
{
}

template<typename K, typename V>
bool HashNode<K,V>::operator==(const HashNode& hs) const
{
    return Key == hs.Key;
}

template<typename K, typename V>
bool HashNode<K,V>::operator!=(const HashNode& hs) const
{
    return Key != hs.Key;
}

//================ HashMap =================//

template<typename K, typename V>
HashMap<K,V>::HashMap()
{
    count = 0;
    load_factor = 0.0f;

    for(int i = 0; i < 4; i++)
    {
        v.push_back(Linkedlist<HashNode<K,V>>());
    }
}

template<typename K, typename V>
HashMap<K,V>::HashMap(const HashMap& hs)
{
    int size = hs.v.Size();

    count = 0;
    load_factor = 0.0f;

    for(int i = 0; i < size; i++)
    {
        v.push_back(Linkedlist<HashNode<K,V>>());
    }

    for(int i = 0; i < size; i++)
    {
        Node<HashNode<K,V>>* ptr = hs.v[i].begin();

        while(ptr != NULL)
        {
            push(ptr->value.Key, ptr->value.Value);
            ptr = ptr->next;
        }
    }
}

template<typename K, typename V>
HashMap<K,V>& HashMap<K,V>::operator=(const HashMap& hs)
{
    if(this == &hs)
        return *this;

    v = hs.v;
    count = hs.count;
    load_factor = hs.load_factor;

    return *this;
}

template<typename K, typename V>
void HashMap<K,V>::rehash()
{
    Vector<Linkedlist<HashNode<K,V>>> v1;

    for(int i = 0; i < 2 * v.Size(); i++)
    {
        v1.push_back(Linkedlist<HashNode<K,V>>());
    }

    int size = v1.Size();

    Hashcode hs;

    for(int i = 0; i < v.Size(); i++)
    {
        Node<HashNode<K,V>>* ptr = v[i].begin();

        while(ptr != NULL)
        {
            int idx = hs.hash(ptr->value.Key, size);

            v1[idx].push(ptr->value);

            ptr = ptr->next;
        }
    }

    v = v1;
}

template<typename K, typename V>
void HashMap<K,V>::push(const K& key, const V& val)
{
    HashNode<K,V>* existing = find(key);

    if(existing)
    {
        existing->Value = val;
        return;
    }

    load_factor = (float)(count + 1) / v.Size();

    if(load_factor >= 0.75f)
    {
        rehash();
    }

    Hashcode hs;

    int idx = hs.hash(key, v.Size());

    HashNode<K,V> temp(key, val);

    v[idx].push(temp);

    count++;
}

template<typename K, typename V>
HashNode<K,V>* HashMap<K,V>::find(const K& key)
{
    Hashcode hs;

    int idx = hs.hash(key, v.Size());

    Node<HashNode<K,V>>* ptr = v[idx].begin();

    while(ptr != NULL && ptr->value.Key != key)
    {
        ptr = ptr->next;
    }

    if(ptr != NULL)
        return &(ptr->value);

    return NULL;
}

template<typename K, typename V>
void HashMap<K,V>::pop(const K& key)
{
    Hashcode hs;

    int idx = hs.hash(key, v.Size());

    HashNode<K,V>* ptr = find(key);

    if(ptr != NULL)
    {
        v[idx].delete_any(*ptr);
        count--;
    }
}

template<typename K, typename V>
V& HashMap<K,V>::operator[](const K& key)
{
    HashNode<K,V>* ptr = find(key);

    if(ptr != NULL)
    {
        return ptr->Value;
    }

    push(key, V());

    ptr = find(key);

    return ptr->Value;
}
template<typename K, typename V>
void HashMap<K, V>::keys() const
{
    for(int i = 0; i < v.Size(); i++)
    {
        Node<HashNode<K, V>>* ptr = v[i].begin();

        while(ptr != NULL)
        {
            std::cout << ptr->value.Key << '\n';
            ptr = ptr->next;
        }
    }
}

#endif