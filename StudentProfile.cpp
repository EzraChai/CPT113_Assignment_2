#include "StudentProfile.h"
#include <ctime>

StudentProfile::StudentProfile()
{
}

StudentProfile::StudentProfile(std::string studentId, std::string name, std::string course)
{
    this->studentId = studentId;
    this->name = name;
    this->course = course;
    this->friendHead = nullptr;
    this->messageInbox = MessageQueue<Message>();
    this->messageSent = MessageQueue<Message>();
}

std::string StudentProfile::getStudentName() const
{
    return name;
}

std::string StudentProfile::getStudentId() const
{
    return studentId;
}

void StudentProfile::printProfile() const
{
    std::cout << "Student Name: " << name << std::endl;
    std::cout << "Student ID: " << studentId << std::endl;
    std::cout << "Course: " << course << std::endl;
}

void StudentProfile::printSentMessages()
{
    messageSent.displayMessages();
}

void StudentProfile::printInboxMessages()
{
    messageInbox.displayMessages();
}

void StudentProfile::sendToInboxMessage(std::string message, std::string senderName)
{
    // Logic to send a message to another student
    Message msg;
    msg.body = message;
    msg.name = senderName;
    msg.timestamp = std::time(0); // Set the current timestamp
    messageInbox.enqueue(msg);
}

void StudentProfile::sendToSentMessage(std::string message, std::string recipientName)
{
    // Logic to send a message to another student
    Message msg;
    msg.body = message;
    msg.name = recipientName;
    msg.timestamp = std::time(0); // Set the current timestamp
    messageSent.enqueue(msg);
}

void StudentProfile::unsendSentMessage()
{
    if (messageSent.isEmpty())
    {
        std::cout << "No sent messages to unsend." << std::endl;
        return;
    }
    MessageQueue<Message> messageSentCopy;
    int totalMessages = messageSent.getTotalMessages();
    for (int i = 0; i < totalMessages - 1; ++i)
    {
        Message *msg = messageSent.peek();
        messageSent.enqueue(*msg);
        messageSent.dequeue(); // Remove the message from the original queue
    }
    messageSent.dequeue();
}

void StudentProfile::unsendInboxMessage()
{
    if (messageInbox.isEmpty())
    {
        std::cout << "No inbox messages to unsend." << std::endl;
        return;
    }
    MessageQueue<Message> messageInboxCopy;
    int totalMessages = messageInbox.getTotalMessages();
    for (int i = 0; i < totalMessages - 1; ++i)
    {
        Message *msg = messageInbox.peek();
        messageInbox.enqueue(*msg);
        messageInbox.dequeue(); // Remove the message from the original queue
    }
    messageInbox.dequeue();
}
