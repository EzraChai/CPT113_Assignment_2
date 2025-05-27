#ifndef STUDENTPROFILE_H
#define STUDENTPROFILE_H
#include <string>
#include "MessageQueue.h"

class StudentProfile
{
private:
    std::string studentId;
    std::string name;

    MessageQueue<std::string> messageInbox;
    MessageQueue<std::string> messageSent;

    struct FriendNode
    {
        StudentProfile *friendProfile;
        FriendNode *nextFriend;
    };

    FriendNode *friendHead; // Linked list of friends

public:
    StudentProfile *prev; // Pointer to the previous student profile in the linked list
    StudentProfile *next;

    StudentProfile();
    StudentProfile(std::string, std::string);

    std::string getStudentName() const;
    std::string getStudentId() const;

    void addFriend(StudentProfile *friendProfile);
    void sendToSentMessage(const std::string &message, const std::string &recipientName);
    void sendToInboxMessage(const std::string &message, const std::string &recipientName);

    void printSentMessages();
    void printInboxMessages();
};

#endif