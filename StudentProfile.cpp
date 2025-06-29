#include "StudentProfile.h"
#include <ctime>
#include <iomanip>

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

StudentProfile::~StudentProfile()
{
    // Clean up the linked list of friends
    FriendNode *current = friendHead;
    while (current)
    {
        FriendNode *temp = current;
        current = current->nextFriend;
        delete temp;
    }
}

std::string StudentProfile::getStudentName() const
{
    return name;
}

std::string StudentProfile::getStudentId() const
{
    return studentId;
}

std::string StudentProfile::getCourse() const
{
    return course;
}

void StudentProfile::printProfile() const
{
    std::cout << std::setw(20) << std::left << name << std::setw(15) << studentId << std::setw(20) << course << std::endl;
    // std::cout << "Student Name: " << name << std::endl;
    // std::cout << "Student ID: " << studentId << std::endl;
    // std::cout << "Course: " << course << std::endl;
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
        throw "No sent messages to unsend.\n";
        return;
    }
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
        throw "No inbox messages to unsend.\n";
        return;
    }
    int totalMessages = messageInbox.getTotalMessages();
    for (int i = 0; i < totalMessages - 1; ++i)
    {
        Message *msg = messageInbox.peek();
        messageInbox.enqueue(*msg);
        messageInbox.dequeue(); // Remove the message from the original queue
    }
    messageInbox.dequeue();
}

bool StudentProfile::compare(const StudentProfile &other) const
{
    return this->name > other.name; // Compare by name
}

void StudentProfile::displayFriendList()
{
    if (!friendHead)
    {
        throw "No friends added yet.\n";
        return;
    }
    FriendNode *current = friendHead;
    while (current)
    {
        std::cout << current->friendProfile->getStudentName() << std::endl;
        current = current->nextFriend;
    }
}

StudentProfile *StudentProfile::searchFriend(std::string friendName)
{
    FriendNode *current = friendHead;
    while (current)
    {
        if (current->friendProfile->getStudentName() == friendName)
        {
            return current->friendProfile; // Return the friend profile if found
        }
        current = current->nextFriend;
    }
    return nullptr; // Return nullptr if not found
}

bool StudentProfile::isFriend(const StudentProfile *friendProfile) const
{
    FriendNode *current = friendHead;
    while (current)
    {
        if (current->friendProfile == friendProfile)
        {
            return true;
        }
        current = current->nextFriend;
    }
    return false;
}

int StudentProfile::friendCount() const
{
    int count = 0;
    FriendNode *current = friendHead;
    while (current)
    {
        count++;
        current = current->nextFriend;
    }
    return count; // Return the total number of friends
}

void StudentProfile::addFriend(StudentProfile *friendProfile)
{
    if (isFriend(friendProfile))
    {
        throw "This student is already your friend.\n";
        return;
    }
    if (this == friendProfile)
    {
        throw "You cannot add yourself as a friend.\n";
        return;
    }
    FriendNode *newFriendNode = new FriendNode;
    newFriendNode->friendProfile = friendProfile;
    newFriendNode->nextFriend = nullptr;

    if (!friendHead)
    {
        friendHead = newFriendNode; // If no friends, set the new friend as head
    }
    else
    {
        FriendNode *current = friendHead;
        while (current->nextFriend) // Traverse to the end of the list
        {
            current = current->nextFriend;
        }
        current->nextFriend = newFriendNode; // Add the new friend at the end
    }
}

void StudentProfile::deleteFriend(StudentProfile *friendProfile)
{
    if (!friendHead)
    {
        throw "No friends to delete.\n";
        return;
    }
    FriendNode *current = friendHead;
    FriendNode *prev = nullptr;
    while (current)
    {
        if (current->friendProfile == friendProfile)
        {
            if (prev)
                prev->nextFriend = current->nextFriend;
            else
                friendHead = current->nextFriend;
            return;
        }
        else
        {
            prev = current; // Move to the next friend
            current = current->nextFriend;
        }
    }
}

void StudentProfile::deleteAllFriends()
{
    FriendNode *current = friendHead;
    while (current)
    {
        FriendNode *temp = current;
        temp->friendProfile->deleteFriend(this);
        current = current->nextFriend;
        delete temp; // Delete each friend node
    }
    friendHead = nullptr; // Reset the head to nullptr
}
