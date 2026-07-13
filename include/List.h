#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include <iostream>
#include <cstdlib>
#include <stdexcept>

template<typename T>
class ListNode {
public:
    ListNode<T>* next;
    T value;

    ListNode(T val);
    ~ListNode();
};

template<typename T>
class Linkedlist {
public:
    ListNode<T>* head;
    ListNode<T>* tail;
    int count;

    Linkedlist();
    Linkedlist(const Linkedlist& ls);
    Linkedlist& operator=(const Linkedlist& ls);
    ~Linkedlist();

    void push(T& val);
    void pop();

    int Size();
    bool isempty();

    T& operator[](int idx);
};

#include "List.tpp"

#endif