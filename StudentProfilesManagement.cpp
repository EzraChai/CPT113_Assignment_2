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
    try
    {
        StudentProfile *profile = studentList.searchByName(name);
        if (profile)
        {
            std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
            profile->printProfile();
            std::cout << std::endl;
        }
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        return;
    }
}

void StudentProfilesManagement::searchFriendName(std::string friendName)
{
    if (!studentList.getCurrentNode())
    {
        throw "No current student profile selected.";
        return;
    }
    StudentProfile *currentProfile = studentList.getCurrentNode();
    if (currentProfile->getStudentName() == friendName)
    {
        throw "You cannot search for yourself.";
        return;
    }
    StudentProfile *friendProfile = currentProfile->searchFriend(friendName);
    if (friendProfile)
    {
        std::cout << "Friend is found: " << friendProfile->getStudentName() << std::endl;
    }
    else
    {
        throw "Friend not found.";
    }
}

StudyGroup *StudentProfilesManagement::searchStudyGroup(std::string groupName)
{
    try
    {
        return studyGroups.searchByCourseName(groupName);
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        return nullptr;
    }
}

void StudentProfilesManagement::rotateStudyGroupMembers()
{
    studyGroups.rotate();
    // std::cout << "StudyGroup count" << studyGroups.getCount() << std::endl;
}

void StudentProfilesManagement::displayStudyGroupMembers()
{

    if (!studentList.getCurrentNode())
    {
        throw "No current student profile selected.";
        return;
    }

    StudyGroup *studyGroup = studyGroups.getCurrentNode();
    if (studyGroup == nullptr)
    {
        throw "No study group found for the current student profile.";
        return;
    }

    if (studyGroup)
    {
        studyGroup->displayStudyGroup();
    }
}

void StudentProfilesManagement::displayInboxMessages()
{
    if (!studentList.getCurrentNode())
    {
        throw "No current student profile selected.";
        return;
    }
    std::cout << "\n------ Inbox Messages for: " << studentList.getCurrentNode()->getStudentName() << " ------" << std::endl;
    studentList.getCurrentNode()->printInboxMessages();
    std::cout << std::endl;
}

void StudentProfilesManagement::displaySentMessages()
{
    if (!studentList.getCurrentNode())
    {
        throw "No current student profile selected.";
        return;
    }
    std::cout << "\n------ Sent Messages for: " << studentList.getCurrentNode()->getStudentName() << " ------" << std::endl;
    studentList.getCurrentNode()->printSentMessages();
    std::cout << std::endl;
}

void StudentProfilesManagement::displayAllStudentProfiles()
{
    try
    {
        studentList.displayAllNodes();
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        return;
    }
}

void StudentProfilesManagement::displayCurrentStudentProfile()
{
    if (!studentList.getCurrentNode())
    {
        throw "No current student profile selected.";
        return;
    }
    std::cout << "\n--- Current Student Profile ---\n";
    std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
    studentList.getCurrentNode()->printProfile();
    std::cout << std::endl;
}

void StudentProfilesManagement::browseForward()
{
    try
    {
        studentList.browseForward();
        std::cout << "Current Student Profile: " << studentList.getCurrentNode()->getStudentName() << std::endl;
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
        std::cout << "Current Student Profile: " << studentList.getCurrentNode()->getStudentName() << std::endl;
    }
    catch (const char *e)
    {
        std::cout << e << std::endl;
        return;
    }
}

void StudentProfilesManagement::sendMessage(std::string recipientName, std::string message)
{
    if (!studentList.getCurrentNode())
    {
        throw "No current student profile selected.";
    }
    if (studentList.getCount() == 0)
    {
        throw "No student profiles available.";
    }

    StudentProfile *recipientProfile = studentList.searchByName(recipientName);
    StudentProfile *currentProfile = studentList.getCurrentNode();

    if (recipientProfile == nullptr)
    {
        throw "Recipient profile not found.";
    }
    if (recipientProfile->getStudentName() == currentProfile->getStudentName())
    {
        throw "Cannot send a message to yourself.";
    }
    if (message.empty())
    {
        throw "Message cannot be empty.";
    }
    currentProfile->sendToSentMessage(message, recipientName);
    undo.pushAction({ActionType::SEND_MESSAGE, currentProfile});
    recipientProfile->sendToInboxMessage(message, currentProfile->getStudentName());
    undo.pushAction({ActionType::SEND_MESSAGE, recipientProfile});
}

void StudentProfilesManagement::addNewFriend(std::string friendName)
{
    try
    {
        StudentProfile *friendProfile = studentList.searchByName(friendName);
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
    catch (const char *e)
    {
        std::cout << e << std::endl;
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
    try
    {
        undo.popAction(studentList, studyGroups);
    }
    catch (const char *e)
    {
        std::cout << "Undo failed: " << e << std::endl;
    }
}

int StudentProfilesManagement::getStudentCount() const
{
    return studentList.getCount();
}