// #ifndef STUDYGROUP_H
// #define STUDYGROUP_H

// #include "CircularLinkedList.h"
// #include "StudentProfile.h"
// #include <string>
// #include <iostream>

// class StudyGroup
// {
// private:
//     std::string course;

//     CircularLinkedList<StudentProfile> studyGroups;

// public:
//     StudyGroup(std::string course);
//     ~StudyGroup();

//     void removeStudent(std::string studentID);
//     void browseGroup();

//     void addStudyGroupMember(StudentProfile *other)
//     {
//         studyGroups.addNode(other);
//         std::cout << " Added " << other->getStudentName() << " to study group.\n";
//     }

//     void showStudyGroup()
//     {
//         std::cout << "\n--- Study Group Members for: (" << course << ") ---\n";
//         studyGroups.rotateAndPrintOnce();
//         std::cout << "--------------------------------------------------\n";
//     }

//     std::string getCourse() const { return course; }
// };

// #endif

#ifndef STUDYGROUP_H
#define STUDYGROUP_H
#include "LinkedList.h"
#include <string>
#include "StudentProfile.h"

class StudyGroup
{
private:
    std::string course;
    LinkedList<StudentProfile> studyGroupMembers; // List of student profiles in the study group
    // CircularLinkedList<StudentProfile> studyGroupStudents;

public:
    StudyGroup(std::string course);
    ~StudyGroup();

    std::string getCourse() const;
    bool compare(const StudyGroup &other) const;
    void addStudyGroupMember(StudentProfile &);
    void deleteStudyGroupMember(StudentProfile *&);
    void displayStudyGroup() const;
};

#endif