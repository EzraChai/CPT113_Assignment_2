#include "DoublyLinkedList.h"
#include <string>

DoublyLinkedList::DoublyLinkedList()
{
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
    StudentProfile *nodePtr = head;
    while (nodePtr != nullptr)
    {
        StudentProfile *next = nodePtr->next;
        delete nodePtr;
        nodePtr = next;
    }
}

void DoublyLinkedList::addStudent(std::string studentId, std::string name)
{
    StudentProfile *newStudent = new StudentProfile(studentId, name);
    if (head == nullptr)
    {
        head = newStudent;
        tail = newStudent;
        current = newStudent;
    }
    else
    {
        StudentProfile *nodePtr = head;
        while (nodePtr != nullptr && nodePtr->getStudentName() < name)
        {
            nodePtr = nodePtr->next;
        }

        if (nodePtr == head)
        {
            head = newStudent;
            newStudent->next = nodePtr;
            nodePtr->prev = newStudent;
        }
        else if (nodePtr == nullptr)
        {
            newStudent->prev = tail;
            tail->next = newStudent;
            tail = newStudent;
        }
        else
        {
            nodePtr->prev->next = newStudent;
            newStudent->prev = nodePtr->prev;
            nodePtr->prev = newStudent;
            newStudent->next = nodePtr;
        }
    }
}

void DoublyLinkedList::browseForward()
{
    if (current != nullptr)
    {
        current = current->next;
    }
}
void DoublyLinkedList::browseBackward()
{
    if (current != nullptr)
    {
        current = current->prev;
    }
}

void DoublyLinkedList::displayCurrentStudent()
{
    if (current != nullptr)
    {
        std::cout << "Name: " << current->getStudentName() << std::endl;
        std::cout << "ID: " << current->getStudentId() << std::endl; // Assuming studentId is public or accessible
    }
    else
    {
        std::cout << "No current student." << std::endl;
    }
}

void DoublyLinkedList::displayAllStudents()
{
    StudentProfile *nodePtr = head;
    if (nodePtr == nullptr)
    {
        std::cout << "No students in the list." << std::endl;
        return;
    }
    while (nodePtr != nullptr)
    {
        std::cout << "Name: " << nodePtr->getStudentName() << ", ID: " << nodePtr->getStudentId() << std::endl;
        nodePtr = nodePtr->next;
    }
}

StudentProfile *DoublyLinkedList::searchByName(std::string name)
{
    if (!head)
    {
        return nullptr;
    }
    StudentProfile *nodePtr = head;
    while (nodePtr != nullptr)
    {
        if (nodePtr->getStudentName() == name)
        {
            return nodePtr;
        }
        nodePtr = nodePtr->next;
    }
    return nullptr;
}

void DoublyLinkedList::addNewMessage(const std::string &message, const std::string &recipientName)
{
    if (current != nullptr)
    {

        StudentProfile *recipient = searchByName(recipientName);
        if (recipient)
        {
            current->sendToSentMessage(message, recipientName);
            recipient->sendToInboxMessage(message, current->getStudentName());
        }
    }
    else
    {
        std::cout << "No current student to send a message." << std::endl;
    }
}

void DoublyLinkedList::displayInboxMessages()
{
    std::cout << "------ Inbox Messages ------" << std::endl;
    current->printInboxMessages();
}

void DoublyLinkedList::displaySentMessages()
{
    std::cout << "------ Sent Messages ------" << std::endl;
    current->printSentMessages();
}
