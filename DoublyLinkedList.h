#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <string>
#include <iostream>

template <class T>
class DoublyLinkedList
{
private:
    struct Node
    {
        T *data; // Pointer to the student profile
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;
    Node *current; // Pointer to the current student profile for browsing

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void insertNode(T *&newData);
    void browseForward();
    void browseBackward();
    T *getCurrentNode() const;
    T *searchByName(std::string name);
    void deleteNode(T *&node);
    void displayAllNodes();
    int getCount() const;
};

/*
    Constructor to initialize the doubly linked list
*/
template <class T>
DoublyLinkedList<T>::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr; // Initialize current to nullptr
}

/*
    Destructor to clean up the doubly linked list
*/
template <class T>
DoublyLinkedList<T>::~DoublyLinkedList()
{
    Node *nodePtr = head;
    while (nodePtr != nullptr)
    {
        Node *next = nodePtr->next; // Assuming T has a next pointer
        delete nodePtr;
        nodePtr = next;
    }
}

/*
    Inserts a new node with the given data into the doubly linked list
*/
template <class T>
void DoublyLinkedList<T>::insertNode(T *&newData)
{
    Node *newNode = new Node;
    newNode->data = newData;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr && tail == nullptr) // If the list is empty
    {
        head = newNode;
        tail = newNode;
        current = newNode; // Set current to the first node
    }
    else
    {
        Node *currentPtr = head;
        while (currentPtr != nullptr && currentPtr->data->getStudentName() < newNode->data->getStudentName()) // Assuming T has a getStudentName method
        {
            currentPtr = currentPtr->next; // Move to the next node
        }

        if (currentPtr == head) // Insert at the beginning
        {
            newNode->next = head;
            head->prev = newNode; // Assuming T has a prev pointer
            head = newNode;
            current = newNode; // Set current to the new head
        }
        else if (currentPtr == nullptr) // Insert at the end
        {
            tail->next = newNode;
            newNode->prev = tail; // Assuming T has a prev pointer
            tail = newNode;
        }
        else // Insert in the middle
        {
            newNode->next = currentPtr;
            newNode->prev = currentPtr->prev; // Assuming T has a prev pointer
            currentPtr->prev->next = newNode;
            currentPtr->prev = newNode;
        }
    }
}

/*
    Moves the current pointer to the next node in the list
    Throws an error if current is not set or if already at the end of the list
*/
template <class T>
void DoublyLinkedList<T>::browseForward()
{

    if (current == nullptr) // If current is not set
    {
        throw "Current node is not set.\n"; // Throw an error if current is nullptr
        return;
    }

    if (current->next == nullptr) // If current is the last node
    {
        throw "Already at the end of the list.\n"; // Throw an error if already at the end
        return;
    }

    current = current->next; // Move to the next node
    return;
}

/*
    Moves the current pointer to the previous node in the list
    Throws an error if current is not set or if already at the beginning of the list
*/
template <class T>
void DoublyLinkedList<T>::browseBackward()
{
    if (current == nullptr) // If current is not set
    {
        throw "Current node is not set.\n"; // Throw an error if current is nullptr
        return;
    }

    if (current->prev == nullptr) // If current is the last node
    {
        throw "Already at the end of the list.\n"; // Throw an error if already at the end
        return;
    }

    current = current->prev; // Move to the next node
    return;
}

/*
    Returns the current node's data
    Throws an error if current is not set
*/
template <class T>
T *DoublyLinkedList<T>::getCurrentNode() const
{
    if (current == nullptr)
    {
        return nullptr; // Return nullptr if current is not set
    }
    return current->data; // Return the current node
}

/*
    Searches for a node by name in the doubly linked list
    Throws an error if the student profile is not found
*/
template <class T>
T *DoublyLinkedList<T>::searchByName(std::string name)
{
    Node *nodePtr = head;
    while (nodePtr != nullptr)
    {
        if (nodePtr->data->getStudentName() == name) // Assuming T has a getStudentName method
        {
            return nodePtr->data; // Return the found node
        }
        nodePtr = nodePtr->next; // Move to the next node
    }
    throw "Student profile not found.\n"; // Throw an error if not found
    return nullptr;                       // Return nullptr if not found
}

/*
    Deletes a node from the doubly linked list
    Throws an error if the list is empty or if the node to delete is nullptr
    If the node is found, it updates the head or tail pointers accordingly
    If the node is not found, it throws an error
*/
template <class T>
void DoublyLinkedList<T>::deleteNode(T *&node)
{
    if (head == nullptr) // If the list is empty
    {
        throw "List is empty. Cannot delete node.\n";
        return;
    }
    if (node == nullptr) // If the node to delete is nullptr
    {
        throw "Node to delete is nullptr.\n";
        return;
    }
    Node *nodePtr = head;
    while (nodePtr != nullptr)
    {
        if (nodePtr->data == node) // Assuming T has an operator== defined
        {
            if (nodePtr == head) // If it's the head node
            {
                head = nodePtr->next;
                if (head != nullptr)
                    head->prev = nullptr; // Update the new head's prev pointer
            }
            else if (nodePtr == tail) // If it's the tail node
            {
                tail = nodePtr->prev;
                if (tail != nullptr)
                    tail->next = nullptr; // Update the new tail's next pointer
            }
            else // If it's a middle node
            {
                nodePtr->prev->next = nodePtr->next;
                nodePtr->next->prev = nodePtr->prev;
            }
            delete nodePtr; // Delete the node
            return;         // Exit after deleting the node
        }
        nodePtr = nodePtr->next; // Move to the next node
    }
    throw "Node not found in the list.\n"; // Throw an error if not found
}

/*
    Displays all nodes in the doubly linked list
    Throws an error if the list is empty
    Assumes T has a printProfile method to display student profile information
*/
template <class T>
void DoublyLinkedList<T>::displayAllNodes()
{
    Node *nodePtr = head;
    if (nodePtr == nullptr)
    {
        throw "List is empty. Cannot display nodes.\n"; // Throw an error if the list is empty
        return;
    }
    while (nodePtr != nullptr)
    {
        nodePtr->data->printProfile(); // Assuming T has a printProfile method
        nodePtr = nodePtr->next;       // Move to the next node
    }
}

/*
    Returns the count of nodes in the doubly linked list
    Iterates through the list and counts the nodes
*/
template <class T>
int DoublyLinkedList<T>::getCount() const
{
    int count = 0;
    Node *nodePtr = head;
    while (nodePtr != nullptr)
    {
        count++;
        nodePtr = nodePtr->next; // Move to the next node
    }
    return count; // Return the count of nodes
};

#endif