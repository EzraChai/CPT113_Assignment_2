#include <iostream>
#include "StudentProfilesManagement.h"
#include <iomanip>

int main()
{
    StudentProfilesManagement spf;
    std::cout << "----- Student Profile Management System -----\n" << std::endl;
    spf.createStudentProfile("24863293", "Chloe", "Computer Science");
    spf.createStudentProfile("24863293", "Ezra", "Computer Science");
    spf.createStudentProfile("24863293", "John", "Computer Science");
    spf.createStudentProfile("24863293", "Zedd", "Computer Science");
    spf.createStudentProfile("24863293", "Moses", "Mathematics");
    spf.createStudentProfile("24863293", "Jenny", "Mathematics");
    spf.createStudentProfile("24863293", "Winny", "Management");

    std::string userSelection;
    int choice;

    do{

        std::cout << "\n----- Student Profile Management System -----" << std::endl;
        std::cout << "1. Create a new student profile" << std::endl;
        std::cout << "2. View all student profiles" << std::endl;
        std::cout << "3. View current student profile" << std::endl;
        std::cout << "4. Search student profile by name" << std::endl;
        std::cout << "5. Add friend" << std::endl;
        std::cout << "6. View friend list" << std::endl;
        std::cout << "7. Send a message to another student" << std::endl;
        std::cout << "8. View message inbox" << std::endl;
        std::cout << "9. View message sent" << std::endl;
        std::cout << "10. Undo last action" << std::endl;
        std::cout << "11. View or rotate through study group members" << std::endl;
        std::cout << "12. Browse Next Student" << std::endl;
        std::cout << "13. Browse Previous Student" << std::endl;
        std::cout << "14. Exit the application" << std::endl;
        std::cout << "\nPlease select an option (1-14): ";
        std::cin >> userSelection;
        std::cin.ignore();


        try{
            choice = std::stoi(userSelection);

        }catch(const char *e){
            std::cout << "\nInvalid input. Please enter a number between 1 and 14." << std::endl;
            continue; // Skip to the next iteration of the loop
        }

        switch (choice)
        {
            case 1:{
                std::string studentID,name,course;
                std::cout << "\nCreating Student Profile...\n" << std::endl;
                std::cout << "StudentID: ";
                std::getline(std::cin,studentID);
                std::cout << "Name: ";
                std::getline(std::cin,name);
                std::cout << "Course: ";
                std::getline(std::cin,course);
                spf.createStudentProfile(studentID,name,course);
                std::cout << "\nStudent Profile Created..." << std::endl;
                break;
            }

            case 2:{
                std::cout << "\n-------All Student Profiles ------\n";
                std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
                spf.displayAllStudentProfiles();
                std::cout << "---------------------------------\n";
                break;
            }

            case 3:{
                spf.displayCurrentStudentProfile();
                break;
            }

            case 4:{
                std::string name;
                std::cout << "\nSearching Profile by Name..." << std::endl;
                std::cout << "Name: ";
                std::cin.ignore();
                std::getline(std::cin,name);
                std::cout << std::endl;
                spf.searchStudentProfileByName(name);
                break;
            }

            case 5:{
                std::string friendName;
                std::cout << "\nAdding Friend...\n" << std::endl;
                std::cout << "Friend Name: ";
                std::cin.ignore();
                std::getline(std::cin,friendName);
                spf.addNewFriend(friendName);
                // std::cout << "\nFriend added...\n" << std::endl; 
                break;
            }

            case 6:{
                std::cout << "\nViewing friend list..." << std::endl;
                spf.displayFriendList();
                break;
            }

            case 7:{
                bool sent = false;
                while(!sent){
                    try {
                        std::string otherName,message;
                        std::cout << "\nSending message to other student..." << std::endl;
                        std::cout << "Enter recipient's name: ";
                        std::getline(std::cin, otherName);
                        std::cout << "Enter message: ";
                        std::getline(std::cin, message);
                        spf.sendMessage(otherName, message);
                        sent = true;
                    }catch (const char *e) {
                        sent = false;
                        std::cout << "\nMessage not sent..." << std::endl;
                        std::cout << "\nError: " << e << std::endl;
                    }
                }

                std::cout << "\nMessage sent successfully..." << std::endl;
                break;
            }

            case 8:{
                spf.displayInboxMessages();
                break;
            }

            case 9:{
                spf.displaySentMessages();
                break;
            }

            case 10:{
                std::cout << std::endl;
                spf.undoLastAction();
                break;
            }

            case 11:{
                char selection = 'Y';
                std::cout << "\nViewing or rotating through study group members..." << std::endl;
                spf.displayStudyGroupMembers();
                do{
                    std::cout << "Rotate Next Group(Y/N): ";
                    std::cin >> selection;
                    if(selection=='Y'){
                        std::cout << "\nRotating..." << std::endl;
                        spf.rotateStudyGroupMembers();
                        spf.displayStudyGroupMembers();
                    }
                }while(selection!='N');
                break;
            }

            case 12:{
                std::cout << "\nBrowsing Forward..." << std::endl;
                spf.browseForward();
                break;
            }

            case 13:{
                std::cout << "\nBrowsing Backward..." << std::endl;
                spf.browseBackward();
                break;
            }
            case 14:{
                std::cout << "\nExiting the application...";
                return 0;
            }
            default:
                std::cout << "\nInvalid selection." << std::endl;
                break;
            }

    }while(choice!=14);
    
    return 0;
}