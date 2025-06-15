#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>
#include <string>

// Template class for Circular Linked List
template <class T>
class CircularLinkedList
{
private:
    // Node structure containing a pointer to data and next node
    struct Node
    {
        T *data;
        Node *next;
    };

    Node *tail;        // Pointer that points to the last node (tail) of the circular list
    int count;         // Number of nodes in the list
    Node *currentNode; // Pointer that points to the current node being accessed

public:
    //  Constructor and Destructor
    CircularLinkedList();
    ~CircularLinkedList();

    void addNode(T *newData);
    void removeNode(T *data);
    T *searchByCourseName(std::string courseName) const;
    int getCount() const;
    void rotate();
    T *getCurrentNode() const;
    void removeFront();
    bool isEmpty() const;
    int size() const;
};

template <class T>
CircularLinkedList<T>::CircularLinkedList() : tail(nullptr), count(0), currentNode(nullptr) {}

template <class T>
CircularLinkedList<T>::~CircularLinkedList()
{
    while (count > 0)
    {
        removeFront();
    }
}

/*
     Adds a node with the given data to the list
*/
template <class T>
void CircularLinkedList<T>::addNode(T *newData)
{
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;

    if (!tail)
    {
        tail = newNode;
        currentNode = newNode;
        tail->next = tail; // Point to itself
    }
    else
    {
        newNode->next = tail->next; // New node points to the first node
        tail->next = newNode;       // Tail points to the new node
        tail = newNode;             // Update tail to the new node
    }
    count++;
}

/*
    Removes a node by matching the data pointer
*/
template <class T>
void CircularLinkedList<T>::removeNode(T *data)
{
    if (!tail || count == 0)
        throw "List is empty. Cannot remove data.\n";
    return;

    Node *current = tail->next;
    Node *prev = tail;

    do
    {
        if (current->data == data)
        {
            if (current == tail) // If it's the tail node
            {
                if (tail == tail->next) // Only one node in the list
                {
                    delete current;
                    tail = nullptr;
                    currentNode = nullptr; // Reset currentNode
                }
                else
                {
                    prev->next = current->next; // Bypass the current node
                    delete current;
                    tail = prev;              // Update tail to previous node
                    currentNode = tail->next; // Reset currentNode to the new first node
                }
            }
            else
            {
                prev->next = current->next; // Bypass the current node
                delete current;
                currentNode = prev->next; // Reset currentNode to the next node
            }
            count--;
            return;
        }
        prev = current;
        current = current->next;
    } while (current != tail->next);
    throw "Data not found in the list.\n";
}

/*
    Search the list for a node with a matching course name
*/
template <class T>
T *CircularLinkedList<T>::searchByCourseName(std::string courseName) const
{
    if (!tail || count == 0)
    {
        throw "List is empty. Cannot search for course name.\n";
        return nullptr;
    }

    Node *current = tail->next;
    do
    {
        if (current->data->getCourse() == courseName)
            return current->data;
        current = current->next;
    } while (current != tail->next);

    throw "Course name not found in the list.\n";
    return nullptr;
}

/*
    Returns the number of nodes in the list
*/
template <class T>
int CircularLinkedList<T>::getCount() const
{
    return count;
}

/*
    Rotates to the next node in the circular list
*/
template <class T>
void CircularLinkedList<T>::rotate()
{
    if (!tail || count == 0)
    {
        throw "List is empty. Cannot rotate.\n";
        return;
    }

    currentNode = currentNode->next; // Move to the next node
    if (currentNode == tail->next)   // If we reached the start, reset to the first node
    {
        currentNode = tail->next;
    }
}

/*
    Returns the current node's data
*/
template <class T>
T *CircularLinkedList<T>::getCurrentNode() const
{
    if (!tail || count == 0)
    {
        throw "List is empty. Cannot get current node.\n";
        return nullptr;
    }

    if (currentNode == nullptr)
    {
        throw "Current node is not set.\n";
        return nullptr;
    }

    return currentNode->data;
}

/*
    Removes the front node from the circular linked list
*/
template <class T>
void CircularLinkedList<T>::removeFront()
{
    if (!tail)
    {
        throw "List is empty. Cannot remove front.\n";
        return;
    }

    Node *front = tail->next;

    if (tail == front)
    {
        delete front;
        tail = nullptr;
    }
    else
    {
        tail->next = front->next;
        delete front;
    }
    count--;
}

/*
    Checks if the circular linked list is empty
*/
template <class T>
bool CircularLinkedList<T>::isEmpty() const
{
    return count == 0;
}

/*
    Returns the size of the circular linked list
*/
template <class T>

int CircularLinkedList<T>::size() const
{
    return count;
}

#endif