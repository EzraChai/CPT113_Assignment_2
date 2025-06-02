#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H
#include <string>
#include <ctime>
#include "MessageQueue.h"

class StudentProfile
{
private:
    std::string studentId;
    std::string name;
    std::string course;

    struct Message
    {
        std::string body;
        std::string name;
        std::time_t timestamp;
    };

    MessageQueue<Message> messageInbox;
    MessageQueue<Message> messageSent;

    struct FriendNode
    {
        StudentProfile *friendProfile;
        FriendNode *nextFriend;
    };

    FriendNode *friendHead; // Linked list of friends

public:
    StudentProfile();
    StudentProfile(std::string, std::string, std::string);

    std::string getStudentName() const;
    std::string getStudentId() const;
    std::string getCourse() const;
    void printProfile() const;

    void addFriend(StudentProfile *friendProfile);
    void sendToSentMessage(std::string message, const std::string recipientName);
    void sendToInboxMessage(std::string message, const std::string senderName);

    void printSentMessages();
    void printInboxMessages();
};

#endif