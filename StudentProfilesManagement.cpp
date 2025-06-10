#include "StudentProfilesManagement.h"
#include "StudentProfile.h"
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

    StudyGroup *sg = nullptr;
    try
    {
        sg = studyGroups.searchByCourseName(course);
    }
    catch (const char *e)
    {
        sg = new StudyGroup(course);
        studyGroups.addNode(sg);
    }
    sg->addStudyGroupMember(*newProfile);
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

void StudentProfilesManagement::rotateStudyGroupMembers()
{
    studyGroups.rotate();
    std::cout << "StudyGroup count" << studyGroups.getCount() << std::endl;
}

void StudentProfilesManagement::displayStudyGroupMembers()
{
    if (studentList.getCurrentNode())
    {
        StudyGroup *studyGroup = studyGroups.getCurrentNode();
        if (studyGroup)
        {
            studyGroup->displayStudyGroup();
        }
    }
    else
    {
        std::cout << "No current student profile selected." << std::endl;
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
    studentList.displayAllNodes();
}

void StudentProfilesManagement::displayCurrentStudentProfile()
{
    if (studentList.getCurrentNode())
    {
        std::cout << "\n--- Current Student Profile ---\n";
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
    try
    {
        studentList.browseForward();
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        return;
    }
}
void StudentProfilesManagement::browseBackward()
{
    try
    {
        studentList.browseBackward();
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        return;
    }
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

void StudentProfilesManagement::addNewFriend(std::string friendName)
{
    StudentProfile *friendProfile = studentList.searchByName(friendName);
    if (friendProfile == nullptr)
    {
        std::cout << "Friend profile not found." << std::endl;
        return;
    }
    if (friendProfile == studentList.getCurrentNode())
    {
        std::cout << "Cannot add yourself as a friend." << std::endl;
        return;
    }

    if (friendProfile->isFriend(studentList.getCurrentNode()))
    {
        std::cout << "Already friends with " << friendProfile->getStudentName() << "." << std::endl;
        return;
    }

    StudentProfile *currentProfile = studentList.getCurrentNode();
    if (currentProfile != nullptr)
    {
        currentProfile->addFriend(friendProfile);
        undo.pushAction({ActionType::ADD_FRIEND, currentProfile});
        friendProfile->addFriend(currentProfile);
        undo.pushAction({ActionType::ADD_FRIEND, friendProfile});
        std::cout << "Added " << friendProfile->getStudentName() << " as a friend." << std::endl;
    }
}

void StudentProfilesManagement::displayFriendList()
{
    StudentProfile *currentProfile = studentList.getCurrentNode();
    if (currentProfile != nullptr)
    {
        std::cout << "\n--- Friend List for: " << currentProfile->getStudentName() << " ---\n";
        try
        {
            currentProfile->displayFriendList();
        }
        catch (const char *e)
        {
            std::cout << e << std::endl;
        }
    }
}

void StudentProfilesManagement::undoLastAction()
{
    // undo.displayAllAction();
    undo.popAction(studentList, studyGroups);
}