#include <iostream>
#include "StudentProfilesManagement.h"
#include <iomanip>

int main()
{
    StudentProfilesManagement spf;
    spf.createStudentProfile("24863293", "Chadler", "Software Engineering");
    spf.createStudentProfile("24863294", "Ezra", "Software Engineering");
    spf.createStudentProfile("24863295", "Huam Jun Fei", "Software Engineering");
    spf.createStudentProfile("24863296", "Zedd", "Intelligent Computing");
    spf.createStudentProfile("24863298", "Dennis", "Computer Infrastructure");
    spf.createStudentProfile("24863299", "Jenny", "Computer Infrastructure");
    spf.createStudentProfile("24863210", "Winny", "Intelligent Computing");

    std::string userSelection;
    int choice;

    do
    {
        std::cout << "\n----- Student Profile Management System -----" << std::endl;
        std::cout << "1. Create a new student profile" << std::endl;
        std::cout << "2. View all student profiles" << std::endl;
        std::cout << "3. View current student profile" << std::endl;
        std::cout << "4. Search student profile by name" << std::endl;
        std::cout << "\n----- Friend Options -----" << std::endl;
        std::cout << "5. Add friend" << std::endl;
        std::cout << "6. Search friend" << std::endl;
        std::cout << "7. View friend list" << std::endl;
        std::cout << "\n----- Message Options -----" << std::endl;
        std::cout << "8. Send a message to a friend" << std::endl;
        std::cout << "9. View message inbox" << std::endl;
        std::cout << "10. View message sent" << std::endl;
        std::cout << "\n----- Undo Option -----" << std::endl;
        std::cout << "11. Undo last action" << std::endl;
        std::cout << "\n----- Study Group Options -----" << std::endl;
        std::cout << "12. View or rotate through study group members" << std::endl;
        std::cout << "13. Search study group" << std::endl;
        std::cout << "\n----- Browse Options -----" << std::endl;
        std::cout << "14. Browse Next Student" << std::endl;
        std::cout << "15. Browse Previous Student" << std::endl;
        std::cout << "\n----- Exit -----" << std::endl;
        std::cout << "16. Exit the application" << std::endl;
        std::cout << "\nPlease select an option (1-16): ";
        std::cin >> userSelection;
        std::cin.ignore();

        try
        {
            choice = std::stoi(userSelection);
        }
        catch (const std::invalid_argument &e)
        {
            std::cout << "\nInvalid input. Please enter a number between 1 and 14." << std::endl;
            continue; // Skip to the next iteration of the loop
        }

        switch (choice)
        {
        case 1:
        {
            std::string studentID, name, course;
            std::cout << "\nCreating Student Profile..." << std::endl;
            std::cout << "StudentID: ";
            std::getline(std::cin, studentID);
            std::cout << "Name: ";
            std::getline(std::cin, name);
            std::cout << "Course: ";
            std::getline(std::cin, course);
            try
            {
                spf.createStudentProfile(studentID, name, course);
            }
            catch (const char *e)
            {
                std::cout << e << std::endl;
                continue; // Skip to the next iteration of the loop
            }
            std::cout << "\nStudent Profile Created..." << std::endl;
            break;
        }

        case 2:
        {
            std::cout << "\n-------All Student Profiles ------\n";
            std::cout << std::setw(20) << std::left << "Name" << std::setw(15) << "Student ID" << std::setw(20) << "Course" << std::endl;
            spf.displayAllStudentProfiles();
            std::cout << "---------------------------------\n";
            break;
        }

        case 3:
        {
            try
            {
                spf.displayCurrentStudentProfile();
            }
            catch (const char *e)
            {
                std::cout << e << std::endl;
            }

            break;
        }

        case 4:
        {
            std::string name;
            std::cout << "\nSearching Student Profile by Name...\n"
                      << std::endl;
            std::cout << "Name: ";
            std::getline(std::cin, name);

            std::cout << std::endl;
            std::cout << name << "'s Profile" << std::endl;
            spf.searchStudentProfileByName(name);
            break;
        }

        case 5:
        {
            std::string friendName;
            std::cout << "\nAdding Friend..." << std::endl;
            std::cout << "Friend Name: ";
            std::getline(std::cin, friendName);
            spf.addNewFriend(friendName);
            // std::cout << "\nFriend added...\n" << std::endl;
            break;
        }
        case 6:
        {
            if (spf.getStudentCount() == 0)
            {
                std::cout << "\nNo current student profile selected." << std::endl;
                break;
            }
            std::string friendName;
            std::cout << "Friend Name: ";
            std::getline(std::cin, friendName);
            try
            {
                spf.searchFriendName(friendName);
            }
            catch (const char *e)
            {
                std::cout << e << std::endl;
            }
            break;
        }

        case 7:
        {
            std::cout << "\nViewing friend list..." << std::endl;
            spf.displayFriendList();
            break;
        }

        case 8:
        {
            if (spf.getStudentCount() == 0)
            {
                std::cout << "\nNo current student profile selected." << std::endl;
                break;
            }
            bool sent = false;
            while (!sent)
            {
                try
                {
                    std::string otherName, message;
                    std::cout << "\nSending message to your friend..." << std::endl;
                    std::cout << "Enter friend's name: ";
                    std::getline(std::cin, otherName);
                    std::cout << "Enter message: ";
                    std::getline(std::cin, message);
                    spf.sendMessage(otherName, message);
                    sent = true;
                }
                catch (const char *e)
                {
                    sent = false;
                    std::cout << "\nMessage not sent..." << std::endl;
                    std::cout << "\nError: " << e << std::endl;
                    if (e == std::string("You have no friends to send messages to."))
                    {
                        std::cout << "Please add friends first." << std::endl;
                        break; // Exit the loop if no friends are available
                    }
                    std::cout << "Please try again." << std::endl;
                    continue; // Continue to the next iteration of the loop
                }
            }
            if (sent)
            {
                std::cout << "\nMessage sent successfully..." << std::endl;
            }
            break;
        }

        case 9:
        {
            try
            {
                spf.displayInboxMessages();
            }
            catch (const char *e)
            {
                std::cout << e << std::endl;
            }
            break;
        }

        case 10:
        {
            try
            {
                spf.displaySentMessages();
            }
            catch (const char *e)
            {
                std::cout << e << std::endl;
            }
            break;
        }

        case 11:
        {
            spf.undoLastAction();
            break;
        }

        case 12:
        {
            char selection = 'Y';
            std::cout << "\nViewing or rotating through study group members..." << std::endl;
            try
            {
                spf.displayStudyGroupMembers();
            }
            catch (const char *e)
            {
                std::cout << e << std::endl;
                break; // Exit the case if no study group members are found
            }
            do
            {
                std::cout << "Rotate Next Group(Y/N): ";
                std::cin >> selection;
                if (selection == 'Y')
                {
                    std::cout << "\nRotating..." << std::endl;
                    spf.rotateStudyGroupMembers();
                    spf.displayStudyGroupMembers();
                }
            } while (selection != 'N');
            break;
        }
        case 13:
        {
            std::string groupName;
            std::cout << "\nSearching Study Group..." << std::endl;
            std::cout << "Enter study group name: ";
            std::getline(std::cin, groupName);
            StudyGroup *sp = spf.searchStudyGroup(groupName);
            if (sp)
            {
                sp->displayStudyGroup();
            }
            break;
        }

        case 14:
        {
            std::cout << "\nBrowsing Forward..." << std::endl;
            spf.browseForward();
            break;
        }

        case 15:
        {
            std::cout << "\nBrowsing Backward..." << std::endl;
            spf.browseBackward();
            break;
        }
        case 16:
        {
            std::cout << "\nExiting the application...";
            return 0;
        }
        default:
            std::cout << "\nInvalid selection." << std::endl;
            break;
        }

    } while (choice != 16);

    return 0;
}