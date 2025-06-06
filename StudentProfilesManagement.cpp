#include "StudentProfilesManagement.h"
#include "iomanip"

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
    undo.pushAction({ActionType::CREATE_PROFILE, newProfile});
}

void StudentProfilesManagement::searchStudentProfileByName(std::string name)
{
    StudentProfile *profile = studentList.searchByName(name);
    if (profile)
    {
        std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
        profile->printProfile();
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No student profile found with the name: " << name << std::endl;
    }
}

void StudentProfilesManagement::displayInboxMessages()
{
    if (studentList.getCurrentNode())
    {
        std::cout << "\n------ Inbox Messages ------" << std::endl;
        studentList.getCurrentNode()->printInboxMessages();
        std::cout << std::endl;
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
        std::cout << std::endl;
    }
    else
    {
        std::cout << "No current student profile selected." << std::endl;
    }
}

void StudentProfilesManagement::displayAllStudentProfiles()
{
    std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
    studentList.displayAllNodes();
    std::cout << std::endl;
}

void StudentProfilesManagement::displayCurrentStudentProfile()
{
    if (studentList.getCurrentNode())
    {
        std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
        studentList.getCurrentNode()->printProfile();
        std::cout << std::endl;
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
            undo.pushAction({ActionType::SEND_MESSAGE, currentProfile});

            recipientProfile->sendToInboxMessage(message, currentProfile->getStudentName());
            undo.pushAction({ActionType::SEND_MESSAGE, recipientProfile});
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

void StudentProfilesManagement::undoLastAction()
{
    // undo.displayAllAction();
    undo.popAction(studentList);
}