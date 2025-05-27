#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include "StudentProfile.h"
#include <string>

class DoublyLinkedList
{
private:
    StudentProfile *head;
    StudentProfile *tail;
    StudentProfile *current; // Pointer to the current student profile for browsing

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    void addStudent(std::string studentId, std::string name);
    void browseForward();
    void browseBackward();
    void displayAllStudents();
    void searchByID(std::string id);
    StudentProfile *searchByName(std::string name);
    void deleteStudent(std::string id);
    void displayCurrentStudent();
    void addNewMessage(const std::string &message, const std::string &recipientName);
    void displayInboxMessages();
    void displaySentMessages();
};

#endif