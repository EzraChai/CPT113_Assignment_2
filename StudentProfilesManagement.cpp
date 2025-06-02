#include "StudentProfilesManagement.h"

StudentProfilesManagement::StudentProfilesManagement()
{
}
StudentProfilesManagement::~StudentProfilesManagement()
{
}

void StudentProfilesManagement::createStudentProfile(std::string studentId, std::string name, std::string course)
{
    StudentProfile *newProfile = new StudentProfile(studentId, name, course);
    studentList.insertNode(newProfile);
}

void StudentProfilesManagement::displayInboxMessages()
{
    if (studentList.getCurrentNode())
    {
        std::cout << "\n------ Inbox Messages ------" << std::endl;
        studentList.getCurrentNode()->printInboxMessages();
    }
    else
    {
        std::cout << "No current student profile selected." << std::endl;
    }
}

void StudentProfilesManagement::displaySentMessages()
{
    if (studentList.getCurrentNode())
    {
        std::cout << "\n------ Sent Messages ------" << std::endl;
        studentList.getCurrentNode()->printSentMessages();
    }
    else
    {
        std::cout << "No current student profile selected." << std::endl;
    }
}

void StudentProfilesManagement::displayAllStudentProfiles()
{
    studentList.displayAllNodes();
}

void StudentProfilesManagement::displayCurrentStudentProfile()
{
    if (studentList.getCurrentNode())
    {
        studentList.getCurrentNode()->printProfile();
    }
    else
    {
        std::cout << "No current student profile selected." << std::endl;
    }
}
void StudentProfilesManagement::browseForward()
{
    studentList.browseForward();
}
void StudentProfilesManagement::browseBackward()
{
    studentList.browseBackward();
}

void StudentProfilesManagement::sendMessage(std::string recipientName, std::string message)
{
    if (studentList.getCurrentNode())
    {
        StudentProfile *recipientProfile = studentList.searchByName(recipientName);
        StudentProfile *currentProfile = studentList.getCurrentNode();
        if (currentProfile != nullptr && recipientProfile != nullptr)
        {
            currentProfile->sendToSentMessage(message, recipientName);
            recipientProfile->sendToInboxMessage(message, currentProfile->getStudentName());
        }
        else
        {
            std::cout << "No current student profile selected." << std::endl;
        }
    }
    else
    {
        std::cout << "No student profiles available." << std::endl;
    }
}
