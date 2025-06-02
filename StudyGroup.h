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

//     CircularLinkedList<StudentProfile> studyGroup;

// public:
//     StudyGroup(std::string course);
//     ~StudyGroup();

//     void removeStudent(std::string studentID);
//     void browseGroup();

//     void addStudyGroupMember(StudentProfile *other)
//     {
//         studyGroup.addNode(other);
//         std::cout << " Added " << other->getStudentName() << " to study group.\n";
//     }

//     void showStudyGroup()
//     {
//         std::cout << "\n--- Study Group Members for: (" << course << ") ---\n";
//         studyGroup.rotateAndPrintOnce();
//         std::cout << "--------------------------------------------------\n";
//     }

//     std::string getCourse() const { return course; }
// };

// #endif