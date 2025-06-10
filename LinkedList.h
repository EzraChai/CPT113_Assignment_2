#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList
{
private:
    struct Node
    {
        T *data;
        Node *next;
    };
    Node *head;
    int count;

public:
    LinkedList();
    ~LinkedList();
    void insert(T *data);
    void printList() const;
    void remove(T *data);
    int size() const;
};

template <class T>
LinkedList<T>::LinkedList()
{
    head = nullptr;
    count = 0;
}

template <class T>
LinkedList<T>::~LinkedList()
{
    if (head)
    {
        Node *currentPtr = head;
        while (currentPtr)
        {
            Node *tempPtr = currentPtr;
            currentPtr = currentPtr->next;
            delete tempPtr;
        }
    }
}

template <class T>
int LinkedList<T>::size() const
{
    return count;
}

template <class T>
void LinkedList<T>::insert(T *data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    if (!head)
    {
        head = newNode;
    }
    else
    {
        Node *currentPtr = head;
        Node *prevPtr = nullptr;
        while (currentPtr && currentPtr->data->compare(*data))
        {
            prevPtr = currentPtr;
            currentPtr = currentPtr->next;
        }

        if (prevPtr == nullptr)
        {
            head = newNode;
            head->next = currentPtr;
        }
        else
        {
            prevPtr->next = newNode;
            newNode->next = currentPtr;
        }
    }
    count++;
}

template <class T>
void LinkedList<T>::printList() const
{
    if (!head)
    {
        throw "List is empty.\n";
        return;
    }

    Node *currentPtr = head;
    while (currentPtr)
    {
        currentPtr->data->printProfile(); // Assuming T has a printProfile method
        currentPtr = currentPtr->next;
    }
}

template <class T>
void LinkedList<T>::remove(T *data)
{
    if (!head)
    {
        throw "List is empty. Cannot remove data.\n";
        return;
    }
    Node *currentPtr = head;
    Node *prevPtr = nullptr;

    while (currentPtr)
    {
        if (currentPtr->data == data)
        {
            if (prevPtr == nullptr) // Deleting the head
            {
                head = currentPtr->next;
            }
            else
            {
                prevPtr->next = currentPtr->next;
            }
            delete currentPtr;
            count--;
            return;
        }
        prevPtr = currentPtr;
        currentPtr = currentPtr->next;
    }
    throw "Data not found in the list.\n";
}

#endif