#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class Node {
public:
    Node<T>* next;
    T value;

    Node(T val);
};

template<typename T>
class Linkedlist {
public:
    Node<T>* head;
    Node<T>* tail;
    int count;

    Linkedlist();

    void push(T val);
    void pop();

    T& operator[](int idx);

    ~Linkedlist();
};

#include "List.tpp"

#endif