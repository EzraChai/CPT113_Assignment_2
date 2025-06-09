#include "Undo.h"
#include <string>
#include "StudentProfile.h"
#include "DoublyLinkedList.h"
#include "CircularLinkedList.h"
#include "StudyGroup.h"

Undo::Undo()
{
}
Undo::~Undo()
{
}

void Undo::displayAllAction()
{
    if (undoStack.isEmpty())
    {
        std::cout << "No actions to undo." << std::endl;
        return;
    }

    std::cout << "Actions in undo stack:" << std::endl;
    Stack<Action> tempStack = undoStack; // Create a copy of the stack to display actions
    while (!tempStack.isEmpty())
    {
        Action *action = tempStack.top();
        switch (action->actionType)
        {
        case ActionType::CREATE_PROFILE:
            std::cout << "Action: Create Profile for " << action->StudentProfilePointer->getStudentName() << std::endl;
            break;

        case ActionType::ADD_FRIEND:
            std::cout << "Action: Add Friend for " << action->StudentProfilePointer->getStudentName() << std::endl;
            break;

        case ActionType::SEND_MESSAGE:
            std::cout << "Action: Send Message from " << action->StudentProfilePointer->getStudentName() << std::endl;
            break;

        default:
            break;
        }
        tempStack.pop();
    }
}

void Undo::pushAction(Action action)
{
    undoStack.push(action);
}

void Undo::popAction(DoublyLinkedList<StudentProfile> &studentList, CircularLinkedList<StudyGroup> &studyGroups)
{
    if (!undoStack.isEmpty())
    {
        switch (undoStack.top()->actionType)
        {
        case ActionType::CREATE_PROFILE:
        {

            StudentProfile *sp = undoStack.top()->StudentProfilePointer;
            sp->deleteAllFriends();
            StudyGroup *sg = studyGroups.searchByCourseName(sp->getCourse());
            sg->deleteStudyGroupMember(sp);
            studentList.deleteNode(sp);
            undoStack.pop();
            std::cout << "Undoing last action: Create Profile" << std::endl;

            break;
        }
        case ActionType::ADD_FRIEND:
        {
            StudentProfile *sp = undoStack.top()->StudentProfilePointer;
            undoStack.pop();
            StudentProfile *sp2 = undoStack.top()->StudentProfilePointer;
            sp->deleteFriend(sp2);
            sp2->deleteFriend(sp);
            undoStack.pop();
            std::cout << "Undoing last action: Adding friend" << std::endl;
        }

        case ActionType::SEND_MESSAGE:
        {
            // Logic to undo sending a message
            StudentProfile *spInbox = undoStack.top()->StudentProfilePointer;
            spInbox->unsendInboxMessage();
            undoStack.pop();

            StudentProfile *spSent = undoStack.top()->StudentProfilePointer;
            spSent->unsendSentMessage();
            undoStack.pop();
            std::cout << "Undoing last action: Sending message" << std::endl;

            break;
        }

        default:
            break;
        }
    }
}