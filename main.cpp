#include <iostream>
#include "StudentProfilesManagement.h"
#include <iomanip>

int main()
{
    StudentProfilesManagement spf;
    std::cout << "----- Student Profile Management System -----" << std::endl;
    spf.createStudentProfile("24863293", "Chloe", "Computer Science");
    spf.createStudentProfile("24863293", "Ezra", "Computer Science");
    spf.createStudentProfile("24863293", "John", "Computer Science");
    spf.createStudentProfile("24863293", "Zedd", "Computer Science");
    spf.createStudentProfile("24863293", "Moses", "Mathematics");
    spf.createStudentProfile("24863293", "Jenny", "Mathematics");
    spf.createStudentProfile("24863293", "Winny", "Management");

    spf.displayAllStudentProfiles();
    spf.sendMessage("Ezra", "Hello, Ezra!");
    spf.sendMessage("Ezra", "Hello, Ezra 2!");
    spf.sendMessage("Ezra", "Hello, Ezra 3!");
    spf.displaySentMessages();
    spf.undoLastAction();
    spf.displaySentMessages();
    spf.createStudentProfile("24863293", "Fred", "Computer Science");
    spf.displayAllStudentProfiles();

    spf.undoLastAction();
    spf.displayAllStudentProfiles();
    spf.searchStudentProfileByName("Chloe");
    spf.browseForward();
    spf.displayCurrentStudentProfile();
    spf.displayInboxMessages();
    spf.displayStudyGroupMembers();
    spf.addNewFriend("Chloe");
    spf.displayFriendList();
    spf.undoLastAction();
    spf.displayFriendList();
    spf.displayStudyGroupMembers();
    spf.rotateStudyGroupMembers();
    spf.displayStudyGroupMembers();
    spf.rotateStudyGroupMembers();
    spf.displayStudyGroupMembers();

    spf.undoLastAction();
    spf.rotateStudyGroupMembers();
    spf.displayStudyGroupMembers();
    spf.rotateStudyGroupMembers();
    spf.displayStudyGroupMembers();
    spf.rotateStudyGroupMembers();
    spf.displayStudyGroupMembers();

    spf.undoLastAction();
    spf.undoLastAction();
    spf.undoLastAction();
    spf.undoLastAction();
    spf.undoLastAction();
    spf.displayCurrentStudentProfile();
    spf.displayAllStudentProfiles();
    spf.rotateStudyGroupMembers();

    // int choice = 0;
    // while (choice != 8)
    // {
    //     std::cout << "----- Student Profile Management System -----" << std::endl;
    //     std::cout << "1. Create a new student profile" << std::endl;
    //     std::cout << "2. View all student profiles" << std::endl;
    //     std::cout << "3. Add a friend" << std::endl;
    //     std::cout << "4. Send a message to another student" << std::endl;
    //     std::cout << "5. View message inbox" << std::endl;
    //     std::cout << "6. Undo last action" << std::endl;
    //     std::cout << "7. View or rotate through study group members" << std::endl;
    //     std::cout << "8. Exit the application" << std::endl;
    //     std::cout << "Please select an option (1-8): ";
    //     int choice;

    //     std::cin >> choice;
    //     switch (choice)
    //     {
    //     case 1:
    //     {

    //         std::cout << "Creating a new student profile..." << std::endl;
    //         std::cout << "Enter Student ID: ";
    //         std::string studentId;
    //         std::cin >> studentId;
    //         std::cout << "Enter Student Name: ";
    //         std::string studentName;
    //         std::cin.ignore(); // Clear the newline character from the input buffer
    //         std::getline(std::cin, studentName);
    //         std::cout << "Enter Course: ";
    //         std::string course;
    //         std::getline(std::cin, course);
    //         spf.createStudentProfile(studentId, studentName, course);
    //         std::cout << "Student profile created successfully!" << std::endl;
    //         break;
    //     }

    //     case 2:
    //     {

    //         std::cout << "Viewing all student profiles..." << std::endl;
    //         // Logic to view all student profiles
    //         std::cout << "\n--- All Student Profiles ---\n";
    //         std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
    //         spf.displayAllStudentProfiles();
    //         std::cout << "-----------------------------\n";
    //         break;
    //     }

    //     case 3:
    //     {
    //         std::cout << "Adding a friend..." << std::endl;
    //         // Logic to add a friend
    //         std::cout << "Enter friend's name: ";
    //         std::string friendName;
    //         std::cin.ignore(); // Clear the newline character from the input buffer
    //         std::getline(std::cin, friendName);
    //         spf.addNewFriend(friendName);
    //         std::cout << "Friend added successfully!" << std::endl;
    //         break;
    //     }
    //     case 4:
    //     {
    //         std::cout << "Sending a message to another student..." << std::endl;
    //         // Logic to send a message
    //         std::cout << "Enter recipient's name: ";
    //         std::string recipientName;
    //         std::cin.ignore(); // Clear the newline character from the input buffer
    //         std::getline(std::cin, recipientName);
    //         std::cout << "Enter message: ";
    //         std::string message;
    //         std::getline(std::cin, message);
    //         spf.sendMessage(recipientName, message);
    //         std::cout << "Message sent successfully!" << std::endl;
    //         break;
    //     }
    //     case 5:
    //     {
    //         std::cout << "Viewing message inbox..." << std::endl;
    //         // Logic to view message inbox
    //         spf.displayInboxMessages();
    //         spf.displaySentMessages();
    //         break;
    //     }
    //     case 6:
    //     {
    //         std::cout << "Undoing last action..." << std::endl;
    //         // Logic to undo last action
    //         spf.undoLastAction();
    //         std::cout << "Last action undone successfully!" << std::endl;
    //         break;
    //     }
    //     case 7:
    //     {
    //         std::cout << "Viewing or rotating through study group members..." << std::endl;
    //         // Logic to view or rotate through study group members
    //         std::cout << "Current Study Group Members:\n";
    //         std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
    //         spf.displayStudyGroupMembers();

    //         break;
    //     }
    //     case 8:
    //     {
    //         std::cout << "Exiting the application. Goodbye!" << std::endl;
    //         return 0; // Exit the application
    //     }
    //     default:
    //     {
    //         std::cout << "Invalid choice. Please select a valid option (1-8): ";
    //         std::cin >> choice;
    //     }
    //     }
    // }
    return 0;
}