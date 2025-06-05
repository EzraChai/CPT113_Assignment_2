#ifndef STUDENTPROFILES_MANAGEMENT_H
#define STUDENTPROFILES_MANAGEMENT_H
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "MessageQueue.h"
#include "StudentProfile.h"
#include "StudyGroup.h"
#include "Undo.h"

class StudentProfilesManagement
{
private:
    DoublyLinkedList<StudentProfile> studentList;
    Undo undo;
    // CircularLinkedList<StudyGroup> studyGroupList; // Circular linked list for study group members
    // TODO: Add a linked list for study groups
    // LinkedList<StudyGroup *> studyGroups; // List of study groups
public:
    StudentProfilesManagement();
    ~StudentProfilesManagement();

    void createStudentProfile(std::string studentId, std::string name, std::string course);
    void displayAllStudentProfiles();
    // void addFriend(std::string studentId, std::string friendId);
    void sendMessage(std::string recipientName, std::string message);
    void displayInboxMessages();
    void displaySentMessages();
    void undoLastAction();
    void rotateStudyGroupMembers();
    void displayCurrentStudentProfile();
    void browseForward();
    void browseBackward();
};

#endif