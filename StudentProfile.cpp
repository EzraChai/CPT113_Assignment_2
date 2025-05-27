#include "StudentProfile.h"

StudentProfile::StudentProfile()
{
}

StudentProfile::StudentProfile(std::string studentId, std::string name)
{
    this->studentId = studentId;
    this->name = name;
}

std::string StudentProfile::getStudentName() const
{
    return name;
}

std::string StudentProfile::getStudentId() const
{
    return studentId;
}

void StudentProfile::sendToSentMessage(const std::string &message, const std::string &recipientName)
{
    // Logic to send a message to another student
    messageSent.enqueue(message, recipientName);
}

void StudentProfile::printSentMessages()
{
    messageSent.displayMessages();
}

void StudentProfile::printInboxMessages()
{
    messageInbox.displayMessages();
}

void StudentProfile::sendToInboxMessage(const std::string &message, const std::string &recipientName)
{
    // Logic to send a message to another student
    messageInbox.enqueue(message, recipientName);
}