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
    Stack();
    ~Stack();
    void push(const T value);
    void pop();
    T *top() const;
    bool isEmpty() const;
};

// Constructor to initialize the stack
template <class T>
Stack<T>::Stack() : topNode(nullptr) {}

// Destructor to clean up the stack
template <class T>
Stack<T>::~Stack()
{
    while (!isEmpty())
    {
        pop();
    }
}

/*
    Pushes a new value onto the stack.
*/
template <class T>
void Stack<T>::push(const T value)
{

    Node *newNode = new Node;
    newNode->data = value;

    //  If the stack is empty, set the new node as the top node
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

/*
    Pops the top value from the stack.
    Throws an error if the stack is empty.
*/
template <class T>
void Stack<T>::pop()
{
    if (isEmpty())
        throw "Stack is empty\n";

    Node *temp = nullptr;
    temp = topNode->next;
    delete topNode;
    topNode = temp;
}

/*
    Returns a pointer to the top value of the stack.
    Throws an error if the stack is empty.
*/
template <class T>
T *Stack<T>::top() const
{
    if (isEmpty())
        throw "Stack is empty\n";
    return &topNode->data;
}

/*
    Checks if the stack is empty.
*/
template <class T>
bool Stack<T>::isEmpty() const
{
    return !topNode;
}

#endif