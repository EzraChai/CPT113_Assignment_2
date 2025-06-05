#ifndef STACK_H
#define STACK_H

template <class T>
class Stack
{
private:
    struct Node
    {
        T data;
        Node *next;
    };
    Node *topNode;

public:
    Stack() : topNode(nullptr) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(const T value)
    {

        Node *newNode = new Node;
        newNode->data = value;

        if (isEmpty())
        {
            topNode = newNode;
            newNode->next = nullptr;
        }
        else
        {
            newNode->next = topNode;
            topNode = newNode;
        }
    }

    void pop()
    {
        if (isEmpty())
            throw "Stack is empty\n";

        Node *temp = nullptr;
        temp = topNode->next;
        delete topNode;
        topNode = temp;
    }

    T *top() const
    {
        if (isEmpty())
            throw "Stack is empty\n";
        return &topNode->data;
    }

    bool isEmpty() const
    {
        return !topNode;
    }
};

#endif