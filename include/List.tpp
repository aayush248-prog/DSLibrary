template<typename T>
ListNode<T>::ListNode(T val)
    : value(val), next(nullptr)
{
}

template<typename T>
ListNode<T>::~ListNode()
{
}

template<typename T>
Linkedlist<T>::Linkedlist()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}

template<typename T>
Linkedlist<T>::Linkedlist(const Linkedlist& ls)
{
    count = 0;
    head = nullptr;
    tail = nullptr;

    ListNode<T>* ptr = ls.head;

    while (ptr != nullptr)
    {
        push(ptr->value);
        ptr = ptr->next;
    }
}

template<typename T>
Linkedlist<T>& Linkedlist<T>::operator=(const Linkedlist& ls)
{
    if (this == &ls)
        return *this;

    ListNode<T>* temp = head;

    while (temp != nullptr)
    {
        ListNode<T>* nxt = temp->next;
        temp->~ListNode<T>();
        free(temp);
        temp = nxt;
    }

    head = nullptr;
    tail = nullptr;
    count = 0;

    ListNode<T>* ptr = ls.head;

    while (ptr != nullptr)
    {
        push(ptr->value);
        ptr = ptr->next;
    }

    return *this;
}

template<typename T>
Linkedlist<T>::~Linkedlist()
{
    while (head != nullptr)
    {
        ListNode<T>* temp = head;
        head = head->next;

        temp->~ListNode<T>();
        free(temp);
    }
}

template<typename T>
void Linkedlist<T>::push(T& val)
{
    ListNode<T>* temp = (ListNode<T>*)malloc(sizeof(ListNode<T>));
    new (temp) ListNode<T>(val);

    if (head == nullptr)
    {
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
void Linkedlist<T>::pop()
{
    if (head == nullptr)
        throw std::underflow_error("under flow");

    if (head == tail)
    {
        head->~ListNode<T>();
        free(head);

        head = nullptr;
        tail = nullptr;
        count--;

        return;
    }

    ListNode<T>* temp = head;
    ListNode<T>* last = tail;

    while (temp->next != tail)
        temp = temp->next;

    temp->next = nullptr;
    tail = temp;

    last->~ListNode<T>();
    free(last);

    count--;
}

template<typename T>
int Linkedlist<T>::Size()
{
    return count;
}

template<typename T>
bool Linkedlist<T>::isempty()
{
    return count == 0;
}

template<typename T>
T& Linkedlist<T>::operator[](int idx)
{
    if (idx >= count)
        throw std::out_of_range("out of bound");

    ListNode<T>* temp = head;

    while (idx--)
        temp = temp->next;

    return temp->value;
}
