#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <string>
#include <sstream>

#include "Vector.h"
#include "List.h"

using namespace std;

//================ Hashcode =================//

class Hashcode
{
public:
    Hashcode();

    int hash(const int s, int size);
    int hash(const string s, int size);
    int hash(const char a, int size);

    template<typename T>
    int hash(const T& obj, int size);
};

//================ HashNode =================//

template<typename K, typename V>
class HashNode
{
public:
    K Key;
    V Value;

    HashNode(const K& key, const V& value);

    bool operator==(const HashNode& hs) const;
    bool operator!=(const HashNode& hs) const;
};

//================ HashMap =================//

template<typename K, typename V>
class HashMap
{
public:
    Vector<Linkedlist<HashNode<K,V>>> v;
    int count;
    float load_factor;

    HashMap();
    HashMap(const HashMap& hs);

    HashMap& operator=(const HashMap& hs);

    void rehash();

    void push(const K& key, const V& val);

    HashNode<K,V>* find(const K& key);

    void pop(const K& key);

    V& operator[](const K& key);
    void keys() const;
};

#include "../src/Hashmap.tpp"

#endif // HASHMAP_H