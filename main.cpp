#include <iostream>
#include "StudentProfilesManagement.h"
// #include "StudentProfile.h"
// #include "MessageQueue.h"
// #include "DoublyLinkedList.h"
// #include "MessageQueue.cpp"

int main()
{
    StudentProfilesManagement spf;
    std::cout << "----- Student Profile Management System -----" << std::endl;
    spf.createStudentProfile("24863293", "Chloe", "Computer Science");
    spf.createStudentProfile("24863293", "Ezra", "Computer Science");
    spf.createStudentProfile("24863293", "John", "Computer Science");
    spf.createStudentProfile("24863293", "Zedd", "Computer Science");
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

    // std::cout << "----- Student Profile Management System -----" << std::endl;
    // std::cout << "1. Create a new student profile" << std::endl;
    // std::cout << "2. View all student profiles" << std::endl;
    // std::cout << "3. Add a friend" << std::endl;
    // std::cout << "4. Send a message to another student" << std::endl;
    // std::cout << "5. View message inbox" << std::endl;
    // std::cout << "6. Undo last action" << std::endl;
    // std::cout << "7. View or rotate through study group members" << std::endl;
    // std::cout << "8. Exit the application" << std::endl;
    // std::cout << "Please select an option (1-8): ";
    // int choice;
    // std::cin >> choice;
    // while (choice < 1 || choice > 8)
    // {
    //     std::cout << "Invalid choice. Please select a valid option (1-8): ";
    //     std::cin >> choice;
    // }
    // switch (choice)
    // {
    // case 1:
    //     std::cout << "Creating a new student profile..." << std::endl;
    //     // Logic to create a new student profile
    //     break;
    // case 2:
    //     std::cout << "Viewing all student profiles..." << std::endl;
    //     // Logic to view all student profiles
    //     break;
    // case 3:
    //     std::cout << "Adding a friend..." << std::endl;
    //     // Logic to add a friend
    //     break;
    // case 4:
    //     std::cout << "Sending a message to another student..." << std::endl;
    //     // Logic to send a message
    //     break;
    // case 5:
    //     std::cout << "Viewing message inbox..." << std::endl;
    //     // Logic to view message inbox
    //     break;
    // case 6:
    //     std::cout << "Undoing last action..." << std::endl;
    //     // Logic to undo last action
    //     break;
    // case 7:
    //     std::cout << "Viewing or rotating through study group members..." << std::endl;
    //     // Logic to view or rotate through study group members
    //     break;
    // case 8:
    //     std::cout << "Exiting the application. Goodbye!" << std::endl;
    //     return 0; // Exit the application
    // }
    return 0;
}