#include "Undo.h"
#include <string>
#include "StudentProfile.h"
#include "DoublyLinkedList.h"

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

void Undo::popAction(DoublyLinkedList<StudentProfile> &studentList)
{
    if (!undoStack.isEmpty())
    {
        switch (undoStack.top()->actionType)
        {
        case ActionType::CREATE_PROFILE:
        {

            std::cout << "Undoing last action: Create Profile" << std::endl;
            StudentProfile *sp = undoStack.top()->StudentProfilePointer;
            studentList.deleteNode(sp);
            break;
        }
        case ActionType::ADD_FRIEND:
            break;

        case ActionType::SEND_MESSAGE:
        {
            std::cout << "Undoing last action: Sending message" << std::endl;
            // Logic to undo sending a message
            StudentProfile *spInbox = undoStack.top()->StudentProfilePointer;
            spInbox->unsendInboxMessage();
            undoStack.pop();

            StudentProfile *spSent = undoStack.top()->StudentProfilePointer;
            spSent->unsendSentMessage();
            undoStack.pop();
            break;
        }

        default:
            break;
        }
    }
}