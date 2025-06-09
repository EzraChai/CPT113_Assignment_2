// #include "CircularLinkedList.h"
// #include "StudyGroup.h"
// #include <string>

// StudyGroup::StudyGroup(std::string course)
// {
//     this->course = course;
//     this->studyGroup = new CircularLinkedList<StudyGroupNode *>();
// }

// StudyGroup::~StudyGroup()
// {
//     delete studyGroup;
// }

// // void StudyGroup::addStudyGroupMember(StudentProfile *student)
// // {
// //     if (student == nullptr)
// //     {
// //         std::cout << "Cannot add a null student to the study group.\n";
// //         return;
// //     }

// //     StudyGroupNode *newNode = new StudyGroupNode;
// //     newNode->student = student;

// //     if (studyGroup->isEmpty())
// //     {
// //         studyGroup->addMember(newNode);
// //         std::cout << "Added " << student->getStudentName() << " to the study group.\n";
// //     }
// //     else
// //     {
// //         // Check if the student is already in the group
// //         // CircularLinkedList<StudyGroupNode *>::CircularNode *current = studyGroup->tail->next;
// //         // do
// //         // {
// //         //     if (current->value->student->getStudentId() == student->getStudentId())
// //         //     {
// //         //         std::cout << student->getStudentName() << " is already in the study group.\n";
// //         //         delete newNode; // Clean up allocated memory
// //         //         return;
// //         //     }
// //         //     current = current->next;
// //         // } while (current != studyGroup->tail->next);

// //         // Add the new member
// //         studyGroup->addMember(newNode);
// //         std::cout << "Added " << student->getStudentName() << " to the study group.\n";
// //     }
// // }

// // #include "CircularLinkedList.h"
// // #include "StudentProfile.h"
// // #include <string>
// // #include <iostream>
// // class Student;

// // class Student
// // {
// // private:
// //     StudentProfile *profile;
// //     std::string course;
// //     CircularLinkedList<Student *> *studyGroup;

// // public:
// //     Student(std::string n, std::string i, std::string c) : course(c)
// //     {
// //         profile = new StudentProfile(i, n);
// //         studyGroup = new CircularLinkedList<Student *>();
// //     }

// //     ~Student()
// //     {
// //         delete profile;
// //         delete studyGroup;
// //     }

// void StudyGroup::addStudyGroupMember(StudentProfile *other)
// {
//     if (other == this)
//     {
//         std::cout << profile->getStudentName() << " Cannot add yourself to study group.\n";
//         return;
//     }

//     if (other->getCourse() == this->course)
//     {
//         studyGroup->addMember(other);
//         std::cout << profile->getStudentName() << " Added " << other->getName() << " to study group.\n";
//     }
//     else
//     {
//         std::cout << profile->getStudentName() << " Cannot add " << other->getName()
//                   << " because courses do not match (" << course << " vs "
//                   << other->getCourse() << ").\n";
//     }
// }

// //     void showStudyGroup() const
// //     {
// //         std::cout << "\n--- Study Group Members for: " << profile->getStudentName() << " (" << course << ") ---\n";
// //         studyGroup->rotateAndPrintOnce();
// //         std::cout << "--------------------------------------------------\n";
// //     }

// //     std::string getCourse() const { return course; }

// //     std::string getName() const { return profile->getStudentName(); }

// //     std::string getId() const { return profile->getStudentId(); }

// //     void printProfile() const
// //     {
// //         std::cout << "Name: " << profile->getStudentName()
// //                   << ", ID: " << profile->getStudentId()
// //                   << ", Course: " << course << std::endl;
// //     }
// // };

#include "StudyGroup.h"
#include <string>
#include <iostream>
#include "StudentProfile.h"

StudyGroup::StudyGroup(std::string course)
{
    this->course = course;
};

StudyGroup::~StudyGroup()
{
}

std::string StudyGroup::getCourse() const
{
    return course;
}

bool StudyGroup::compare(const StudyGroup &other) const
{
    return this->course > other.course;
}

void StudyGroup::addStudyGroupMember(StudentProfile &student)
{
    studyGroupMembers.insert(&student);
    std::cout << "Added " << student.getStudentName() << " to study group.\n";
}

void StudyGroup::deleteStudyGroupMember(StudentProfile *&student)
{
    studyGroupMembers.remove(student);
    std::cout << "Deleted " << student->getStudentName() << " from study group.\n";
}

void StudyGroup::showStudyGroup() const
{
    std::cout << "\n--- Study Group Members for: " << course << " ---\n";
    studyGroupMembers.printList();
    std::cout << "--------------------------------------------------\n";
}