#include "Undo.h"
#include <string>
#include "StudentProfile.h"

Undo::Undo()
{
}
Undo::~Undo()
{
}

void Undo::pushAction(Action action)
{
    undoStack.push(action);
}

void Undo::popAction()
{
    if (!undoStack.isEmpty())
    {
        switch (undoStack.top()->actionType)
        {
        case ActionType::CREATE_PROFILE:

            break;

        case ActionType::ADD_FRIEND:
            break;

        case ActionType::SEND_MESSAGE:
        {

            // Logic to undo sending a message
            // StudentProfile *sp = undoStack.top()->StudentProfilePointer;

            break;
        }

        default:
            break;
        }
        undoStack.pop();
    }
}