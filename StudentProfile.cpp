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