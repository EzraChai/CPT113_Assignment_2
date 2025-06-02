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
    int topIndex;

public:
    Stack() : topNode(nullptr), topIndex(-1) {}

    ~Stack()
    {
        while (!isEmpty())
        {
            pop();
        }
    }

    void push(T value)
    {
        Node *newNode = new Node;
        newNode->data = value;
        newNode->next = topNode;
        topNode = newNode;
        topIndex++;
    }

    void pop()
    {
        if (isEmpty())
            return;

        Node *temp = topNode;
        topNode = topNode->next;
        delete temp;
        topIndex--;
    }

    T *top() const
    {
        if (isEmpty())
            throw std::out_of_range("Stack is empty");
        return topNode->data;
    }

    bool isEmpty() const
    {
        return topIndex == -1;
    }

    int size() const
    {
        return topIndex + 1;
    }
};

#endif