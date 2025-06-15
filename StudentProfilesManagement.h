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
    CircularLinkedList<StudyGroup> studyGroups; // Study group management
    // CircularLinkedList<StudyGroup> studyGroupList; // Circular linked list for study group members
    // TODO: Add a linked list for study groups
    // LinkedList<StudyGroup *> studyGroups; // List of study groups
public:
    StudentProfilesManagement();
    ~StudentProfilesManagement();

    void createStudentProfile(std::string studentId, std::string name, std::string course);
    void displayAllStudentProfiles();
    void searchStudentProfileByName(std::string name);
    void addNewFriend(std::string friendName);
    void searchFriendName(std::string friendName);
    void sendMessage(std::string recipientName, std::string message);
    void displayInboxMessages();
    void displaySentMessages();
    void undoLastAction();
    StudyGroup *searchStudyGroup(std::string groupName);
    void rotateStudyGroupMembers();
    void displayCurrentStudentProfile();
    void browseForward();
    void browseBackward();
    void displayStudyGroupMembers();
    void displayFriendList();
    int getStudentCount() const;
};

#endif