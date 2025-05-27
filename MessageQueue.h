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
        std::string senderName;
        std::time_t timestamp;
        T message;
        MessageNode *next;
    };

    MessageNode *front;
    MessageNode *rear;
    int totalMessages;

public:
    MessageQueue();
    ~MessageQueue();
    void enqueue(T message, std::string studentName);
    void dequeue();
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
void MessageQueue<T>::enqueue(T message, std::string senderName)
{
    MessageNode *newNode = new MessageNode;
    newNode->message = message;
    newNode->senderName = senderName;
    newNode->timestamp = std::time(0);

    if (isEmpty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    totalMessages++;
}

template <class T>
void MessageQueue<T>::dequeue()
{
    if (isEmpty())
    {
        std::cout << "Queue is empty. Cannot dequeue." << std::endl;
        return;
    }
    MessageNode *temp = front;
    front = temp->next;
    delete temp;
    totalMessages--;
}

template <class T>
bool MessageQueue<T>::isEmpty()
{
    return totalMessages == 0;
}

template <class T>
void MessageQueue<T>::displayMessages()
{
    MessageNode *current = front;
    while (current)
    {
        time_t timestamp = current->timestamp;
        char formattedTime[20];
        std::strftime(formattedTime, sizeof(formattedTime), "%H:%M:%S %D", std::localtime(&timestamp));
        // std::cout << "Timestamp: " << formattedTime << "\nfrom: " << current->senderName << "\nMessage: " << current->message << std::endl;
        std::cout << current->senderName << " - " << current->message << " - " << formattedTime << "\n\n";
        current = current->next;
    }
}

#endif