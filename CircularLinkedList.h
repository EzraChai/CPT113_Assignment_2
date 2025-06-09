#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>
#include <string>

template <class T>
class CircularLinkedList
{
private:
    struct Node
    {
        T *data;
        Node *next;
    };

    Node *tail;
    int count;
    Node *currentNode;

public:
    CircularLinkedList() : tail(nullptr), count(0), currentNode(nullptr) {}

    ~CircularLinkedList()
    {
        while (count > 0)
        {
            removeFront();
        }
    }

    void addNode(T *newData)
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

    void deleteNode(T *value)
    {
        if (tail == nullptr)
        {
            std::cout << "List is empty. Cannot delete." << std::endl;
            return;
        }

        Node *current = tail->next;
        Node *prev = tail;

        do
        {
            if (current->data == value)
            {
                if (currentNode == current)
                {
                    // Move currentNode to next node unless list will be empty
                    if (current == tail && current->next == tail)
                        currentNode = nullptr;
                    else
                        currentNode = current->next;
                }
                if (current == tail && current->next == tail)
                {
                    // Single node case
                    delete current;
                    tail = nullptr;
                    currentNode = nullptr;
                }
                else
                {
                    prev->next = current->next;
                    if (current == tail)
                    {
                        tail = prev;
                        // currentNode already updated above if needed
                    }
                    delete current;
                }
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);
    }

    T *searchByCourseName(std::string courseName) const
    {
        if (!tail || count == 0)
        {
            return nullptr;
        }

        Node *current = tail->next;
        do
        {
            if (current->data->getCourse() == courseName)
                return current->data;
            current = current->next;
        } while (current != tail->next);

        return nullptr;
    }

    void rotate()
    {
        if (currentNode)
            currentNode = currentNode->next;
    }

    T *getCurrentNode() const
    {
        if (currentNode)
        {
            // Optionally print debug info:
            return currentNode->data;
        }
        return nullptr;
    }

    void removeFront()
    {
        if (!tail)
            return;

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

    bool isEmpty() const
    {
        return count == 0;
    }

    int size() const
    {
        return count;
    }
};

#endif