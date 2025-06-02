#ifndef UNDO_H
#define UNDO_H
#include "Stack.h"

enum class ActionType
{
    CREATE_PROFILE,
    ADD_FRIEND,
    SEND_MESSAGE
};

class Undo
{
private:
    // (creating profile, adding a friend or sending message)
    struct Action
    {
        ActionType actionType;                 // Type of action (e.g., "create", "addFriend", "sendMessage")
        StudentProfile *StudentProfilePointer; // Student ID related to the action
    };
    Stack<Action> undoStack; // Stack to keep track of actions for undo functionality
public:
    Undo();
    ~Undo();

    void pushAction(Action action);
    void popAction();
};

#endif
