#include <iostream>
#include <string>
#include <limits>

const int MAX_MEMBERS = 100; // Maximum number of members

struct Member {
    int id;
    std::string name;
    int age;
    std::string membershipType; 

} members[MAX_MEMBERS]; 

int memberCount = 0; // Tracks the number of members

void addMember() {
    if (memberCount >= MAX_MEMBERS) {
        std::cout << "Maximum member limit reached. Cannot add more members.\n";
        return;
    }

  
    std::string name;
    int id;
    int age;
    std::string membershipType; 
    int membershipOption;

    std::cout << "Enter member's ID: ";
    while (true) {
        if (std::cin >> id) {

            // Check if the ID already exists
            for (int i = 0; i < memberCount; i++) {
                if (members[i].id == id) {
                    std::cout << "A member with this ID already exists. Please use a different ID.\n";
                    return; // Exit the function if the ID is found
                }
            }
            break;

        } else {
            std::cout << "Invalid input. Please enter an integer for ID: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    std::cout << "Enter member's name: ";
    std::cin.ignore(); 
    getline(std::cin, name); 


    std::cout << "Enter member's age from 15 to 100 years old:";
    while (true) {
        if (std::cin >> age && age >= 15 && age <= 100) {
            break;

        } else {
            std::cout << "Invalid input. Invalid age. ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    while (true) {
        std::cout << "Select membership type: 1) Regular 2) Premium 3) VIP\n";
        if (std::cin >> membershipOption && (membershipOption >= 1 && membershipOption <= 3)) {
            switch (membershipOption) {
                case 1:
                    membershipType = "Regular";
                    break;
                case 2:
                    membershipType = "Premium";
                    break;
                case 3:
                    membershipType = "VIP";
                    break;
            }
            break;
        } else {
            std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
            std::cin.clear(); // Clear the error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input
        }
    }
    // Adding the new member to the members array
    members[memberCount] = {id, name, age, membershipType};
    memberCount++;
    std::cout << "Member has been added successfully!\n";
}

void showMembers() {
    if (memberCount == 0) {
        std::cout << "No members to display." << std::endl;
        return;
    }

    std::cout << "\nList of Members:\n";
    for (int i = 0; i < memberCount; i++) {
        std::cout << "Member ID: " << members[i].id
                << ", Name: " << members[i].name
                << ", Member ship type: " << members[i].membershipType
                << ", Age: " << members[i].age << std::endl;
    }
}

void updateMember() {
    if (memberCount == 0) {
        std::cout << "There are no members to update." << std::endl;
        return;
    }

    int updateId;
    std::cout << "Enter the ID of the member you wish to update: ";
    std::cin >> updateId;

    for (int i = 0; i < memberCount; i++) {
        if (members[i].id == updateId) {
            std::string newName;
            int newAge;
            int membershipOption;

            std::cout << "Found member: " << members[i].name << " (ID: " << members[i].id << ").\n";

            // Update Name
            std::cout << "Enter new name for member ";
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear the newline character from the stream
            getline(std::cin, newName);
            members[i].name = newName;


            // Update Age
            while (true) {
                std::cout << "Enter new age from 15 to 100 years old: ";

                if (std::cin >> newAge && newAge >= 15 && newAge <= 100) {
                    members[i].age = newAge;

                    break;

                } else {
                    std::cout << "Invalid input Invalid age. \n";
                    std::cin.clear();
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                }
            }

            //update membership
            while (true) {
                std::cout << "Select membership type: 1) Regular 2) Premium 3) VIP\n";
                if (std::cin >> membershipOption && (membershipOption >= 1 && membershipOption <= 3)) {
                    switch (membershipOption) {
                        case 1:
                            members[i].membershipType = "Regular";
                            break;
                        case 2:
                            members[i].membershipType = "Premium";
                            break;
                        case 3:
                            members[i].membershipType = "VIP";
                            break;
                    }
                    break;
                } else {
                    std::cout << "Invalid input. Please enter a number between 1 and 3.\n";
                    std::cin.clear(); // Clear the error flags
                    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard the input
                }
            }

            std::cout << "Member information updated.\n";
            return; // Exit the function after updating
        }
    }

    std::cout << "Member with ID " << updateId << " not found." << std::endl;
}

void deleteMember() {
    if (memberCount == 0) {
        std::cout << "There are no members to delete." << std::endl;
        return;
    }
    int deleteId;
    std::cout << "Enter the ID of the member you wish to delete: ";
    std::cin >> deleteId;

    int indexToDelete = -1;
    for (int i = 0; i < memberCount; i++) {
        if (members[i].id == deleteId) {
            indexToDelete = i;
            break;
        }
    }

    if (indexToDelete == -1) {
        std::cout << "Member with ID " << deleteId << " not found." << std::endl;
        return;
    }

    // Shift members after the index to delete one position up
    for (int i = indexToDelete; i < memberCount - 1; i++) {
        members[i] = members[i + 1];
    }

    memberCount--; // Decrease the total member count
    std::cout << "Member with ID " << deleteId << " has been deleted." << std::endl;
}

int main() {
    int choice;

    do {
        std::cout << "\nGym Management System\n";
        std::cout << "1) Add Member\n";
        std::cout << "2) Show Members\n";
        std::cout << "3) update Members\n";
        std::cout << "4) Delete Members\n";
        std::cout << "5) Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addMember();
                break;
            case 2:
                showMembers();
                break;
            case 3:
                updateMember();
                break;
            case 4:
                deleteMember();
                break;
            case 5:
                std::cout << "Exiting the system.\n";
                break;
            default:
                std::cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}