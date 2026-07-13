#ifndef HASHMAP_H
#define HASHMAP_H

#include <iostream>
#include <sstream>
#include <cstdlib>



class Hashcode {
public:
    Hashcode();

    int hash(const int s, int size);
    int hash(const std::string s, int size);
    int hash(const char a, int size);

    template<typename T>
    int hash(const T& obj, int size);
};

template<typename K, typename V>
class Node {
public:
    K first;
    V second;
    Node<K,V>* next;

    Node(const K keyusr, const V value);
    ~Node();
};

template<typename K, typename V>
class Hashmap {
private:
    Node<K,V>** bucket;
    int size;
    int lst_count;
    float load_factor;

public:
    Hashmap();
    Hashmap(const Hashmap& hp);
    Hashmap& operator=(const Hashmap& hp);
    ~Hashmap();

    void rehash();
    void insert(const K& key, const V& value);
    void pop(const K& key);
    V* find(const K& key);
    V& operator[](const K& key);

    int Size();
    bool isempty();
};



#include "Hashmap.tpp"

#endif