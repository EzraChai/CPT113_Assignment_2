#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include <string>

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
    DoublyLinkedList()
    {
        head = nullptr;
        tail = nullptr;
        current = nullptr; // Initialize current to nullptr
    }

    ~DoublyLinkedList()
    {
        Node *nodePtr = head;
        while (nodePtr != nullptr)
        {
            Node *next = nodePtr->next; // Assuming T has a next pointer
            delete nodePtr;
            nodePtr = next;
        }
    }
    void insertNode(T *newData)
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

    void browseForward()
    {
        if (current != nullptr)
        {
            current = current->next; // Move to the next node
        }
    }

    void browseBackward()
    {
        if (current != nullptr)
        {
            current = current->prev; // Move to the previous node
        }
    }

    T *getCurrentNode() const
    {
        return current->data; // Return the current node
    }

    T *searchByName(std::string name)
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
        return nullptr; // Return nullptr if not found
    }

    void deleteNode(T *node);

    void displayAllNodes()
    {
        Node *nodePtr = head;
        while (nodePtr != nullptr)
        {
            nodePtr->data->printProfile(); // Assuming T has a printProfile method
            nodePtr = nodePtr->next;       // Move to the next node
        }
    }
};

#endif