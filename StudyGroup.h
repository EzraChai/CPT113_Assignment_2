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

public:
    StudyGroup(std::string course);
    ~StudyGroup();

    std::string getCourse() const;
    bool compare(const StudyGroup &other) const;
    void addStudyGroupMember(StudentProfile &);
    void deleteStudyGroupMember(StudentProfile *&);
    int getStudentCount() const;
    void displayStudyGroup() const;
};

#endif