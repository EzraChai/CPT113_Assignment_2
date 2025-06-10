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

    void removeNode(T *data)
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

    T *searchByCourseName(std::string courseName) const
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

    int getCount() const
    {
        return count;
    }

    void rotate()
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

    T *getCurrentNode() const
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

    void removeFront()
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