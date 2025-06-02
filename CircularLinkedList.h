#ifndef CIRCULAR_LINKED_LIST_H
#define CIRCULAR_LINKED_LIST_H

#include <iostream>
#include <string>

template <class T>
class CircularLinkedList
{
private:
    T *tail;
    int count;

public:
    CircularLinkedList() : tail(nullptr), count(0) {}

    ~CircularLinkedList()
    {
        while (count > 0)
        {
            removeFront();
        }
    }

    void addNode(T *newNode)
    {
        if (!tail)
        {
            tail = newNode;
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

    void removeNode(T *nodeToRemove)
    {
        if (!tail || count == 0)
            return;

        T *current = tail->next;
        T *prev = tail;

        do
        {
            if (current == nodeToRemove)
            {
                if (current == tail) // If it's the tail
                {
                    if (tail->next == tail) // Only one node in the list
                    {
                        delete tail;
                        tail = nullptr;
                    }
                    else
                    {
                        prev->next = current->next; // Bypass the current node
                        delete current;
                        tail = prev; // Update tail to previous node
                    }
                }
                else
                {
                    prev->next = current->next; // Bypass the current node
                    delete current;
                }
                count--;
                return;
            }
            prev = current;
            current = current->next;
        } while (current != tail->next);
    }

    void rotateAndPrintOnce() const
    {
        if (!tail)
        {
            std::cout << "No members in study group.\n";
            return;
        }

        T *current = tail->next;
        do
        {
            current->printProfile();
            current = current->next;
        } while (current != tail->next);
    }

    void removeFront()
    {
        if (!tail)
            return;

        T *front = tail->next;

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