#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H
#include <string>
#include <ctime>
#include <iostream>

template <class T>
class MessageQueue
{
    struct MessageNode
    {
        T message;
        MessageNode *next;
    };

    MessageNode *front;
    MessageNode *rear;
    int totalMessages;

public:
    MessageQueue();
    ~MessageQueue();
    MessageQueue(const MessageQueue &other) = delete; // Disable copy constructor
    void enqueue(T &message);
    void dequeue();
    T *peek();
    int getTotalMessages() const;
    void displayMessages();
    bool isEmpty();
};

template <class T>
MessageQueue<T>::MessageQueue()
{
    front = nullptr;
    rear = nullptr;
    totalMessages = 0;
}

template <class T>
MessageQueue<T>::~MessageQueue()
{
    while (!isEmpty())
    {
        dequeue();
    }
}

template <class T>
void MessageQueue<T>::enqueue(T &message)
{
    MessageNode *newNode = new MessageNode;
    newNode->message = message;

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        newNode->next = nullptr; // New node will be the last node
        rear->next = newNode;
        rear = newNode;
    }
    totalMessages++;
}

template <class T>
int MessageQueue<T>::getTotalMessages() const
{
    return totalMessages;
}

template <class T>
void MessageQueue<T>::dequeue()
{
    if (isEmpty())
    {
        throw "MessageQueue is empty. Cannot dequeue.\n";
        return;
    }
    MessageNode *temp = front;
    front = front->next;
    delete temp;
    totalMessages--;
}

template <class T>
bool MessageQueue<T>::isEmpty()
{
    return totalMessages == 0;
}

template <class T>
T *MessageQueue<T>::peek()
{
    if (isEmpty())
    {
        throw "MessageQueue is empty. Cannot peek.\n";
        return nullptr;
    }
    return &front->message;
}

template <class T>
void MessageQueue<T>::displayMessages()
{
    if (isEmpty())
    {
        std::cout << "Total messages: " << totalMessages << std::endl;
        return;
    }

    MessageNode *current = front;

    while (current)
    {
        time_t timestamp = current->message.timestamp;
        char formattedTime[20];
        std::strftime(formattedTime, sizeof(formattedTime), "%H:%M:%S %D", std::localtime(&timestamp));
        std::cout << current->message.name << " - " << current->message.body << " - " << formattedTime << std::endl;
        current = current->next;
    }
    std::cout << "Total messages: " << totalMessages << std::endl;
}

#endif