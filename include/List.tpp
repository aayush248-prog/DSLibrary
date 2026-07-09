template<typename T>
Node<T>::Node(T val) {
    T* temp = (T*)malloc(sizeof(T));
    new(temp) T(val);

    value = *temp;

    temp->~T();
    free(temp);

    next = nullptr;
}

template<typename T>
Linkedlist<T>::Linkedlist() {
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template<typename T>
void Linkedlist<T>::push(T val) {
    Node<T>* temp = (Node<T>*)malloc(sizeof(Node<T>));
    new(temp) Node<T>(val);

    if (head == nullptr) {
        head = temp;
        tail = temp;
        count++;
        return;
    }

    tail->next = temp;
    tail = temp;
    count++;
}

template<typename T>
void Linkedlist<T>::pop() {
    if (head == nullptr) {
        throw std::underflow_error("underflow");
    }

    if (head == tail) {
        head->~Node<T>();
        free(head);

        head = nullptr;
        tail = nullptr;
        count--;

        return;
    }

    Node<T>* temp = head;

    while (temp->next != tail) {
        temp = temp->next;
    }

    Node<T>* last = tail;

    temp->next = nullptr;
    tail = temp;

    last->~Node<T>();
    free(last);

    count--;
}

template<typename T>
T& Linkedlist<T>::operator[](int idx) {
    if (idx >= count || idx < 0) {
        throw std::out_of_range("index out of range");
    }

    Node<T>* temp = head;

    while (idx--) {
        temp = temp->next;
    }

    return temp->value;
}

template<typename T>
Linkedlist<T>::~Linkedlist() {
    while (head != nullptr) {
        Node<T>* temp = head;
        head = head->next;

        temp->~Node<T>();
        free(temp);
    }

    tail = nullptr;
    count = 0;
}