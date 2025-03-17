#include "User.h"
#include "Admin.h"
#include "Member.h"
#include "Librarian.h"
#include <iostream>
#include <vector>
#include <limits> // For std::cin.clear() and std::cin.ignore()

int main() {
    std::vector<USER*> Users;
    Users.push_back(new LIBRARIAN(1, "Jane Smith", "jane.loves.books@weirdmail.com", "pass123"));
    Users.push_back(new ADMIN(2, "John Doe", "john.the.admin@funnyemail.org", "admin123"));
    Users.push_back(new MEMBER(3, "Alice Johnson", "alice.reads.all@oddmail.net", "user123"));

    // Cast librarian MIGHT BREAK HERE IF SOMTHING WENT WRONG ITS IN BELOW
    LIBRARIAN* librarian = (LIBRARIAN*)Users[0]; 
    // Validate the cast
    if (librarian->get_acc_type() != "Librarian") {
        std::cout << "if this comes up cast broke for lib class idk why around lin 16 of main " << librarian->get_acc_type() << "\n";
        for (USER* user : Users) delete user;
        return 1;
    }
  


    //adds to the user count with evey user made
    int user_count = 0;
    for (int a = 0; a < Users.size(); a++) user_count++;
    std::cout << "Total users: " << user_count << "\n";

    while (true) {
        std::cout << "1) Create 2) Login 3) Exit\n";
        std::cout << "Enter your choice: "; // Prompt for clarity
        std::cout << "Enter the number twice it dosnt work the first time \n ";

        int choice;
        // Clear input buffer and handle invalid input
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (!(std::cin >> choice)) {
            std::cout << "Invalid input. Please enter a number.\n"; //yayyy numbers
            continue;
        }

        std::cout << "Choice entered: " << choice << "\n"; // Debug output

        if (choice == 1) {
            std::cout << "Creating new user\n";
            std::string name, email, pass, type;
            std::cout << "Enter name: ";
            std::cin >> name;
            std::cout << "Enter email: ";
            std::cin >> email;
            std::cout << "Enter password: ";
            std::cin >> pass;
            std::cout << "Enter type (Admin/Member/Librarian): ";
            std::cin >> type;

            //adds a new id which works now
            int new_id = 0;
            for (int b = 0; b < Users.size(); b++) new_id++;
            new_id++;
            int type_valid = 0;
            for (int c = 0; c < type.size(); c++) {
                if (type == "Admin" || type == "Member" || type == "Librarian") type_valid++;
            }
            if (type_valid > 0) {
                if (type == "Admin") Users.push_back(new ADMIN(new_id, name, email, pass));
                else if (type == "Member") Users.push_back(new MEMBER(new_id, name, email, pass));
                else if (type == "Librarian") Users.push_back(new LIBRARIAN(new_id, name, email, pass));
                else std::cout << "Invalid type\n";
                std::cout << "Account created\n";
            }
            else {
                std::cout << "Invalid type\n";
            }
        }
        else if (choice == 2) {
            std::cout << "Logged in\n";
            std::string email, pass;
            std::cout << "Enter email: ";
            std::cin >> email;
            std::cout << "Enter password: ";
            std::cin >> pass;

            int login_count = 0;
            for (int d = 0; d < Users.size(); d++) {
                if (Users[d]->LOGIN(email, pass)) login_count++;
            }
            std::cout << "Login attempts successful: " << login_count << "\n";

            //dont touch i cant bear to go through that tutorial video again
            for (int z = 0; z < Users.size(); z++) {
                if (login_count > 0 && Users[z]->LOGIN(email, pass)) {
                    std::cout << "Logged in as " << Users[z]->get_acc_type() << std::endl;
                    if (Users[z]->get_acc_type() == "Librarian") {
                        while (true) {
                            std::cout << "1) Add 2) Remove 3) Edit 4) Show 5) Report 6) Logout\n";
                            std::cout << "Enter option: ";
                            int opt;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if (!(std::cin >> opt)) {
                                std::cout << "Invalid input. Please enter a number.\n";
                                continue;
                            }
                            std::cout << "Librarian option: " << opt << "\n";

                            if (opt == 1) {
                                int id;
                                std::string title;
                                std::cout << "Enter book ID: ";
                                std::cin >> id;
                                std::cout << "Enter book title: ";
                                std::cin >> title;
                                librarian->ADD_book(id, title);
                            }
                            else if (opt == 2) {
                                int id;
                                std::cout << "Enter book ID to remove: ";
                                std::cin >> id;
                                librarian->remove_book(id);
                            }
                            else if (opt == 3) {
                                int id;
                                std::string stat;
                                std::cout << "Enter book ID to edit: ";
                                std::cin >> id;
                                std::cout << "Enter new status: ";
                                std::cin >> stat;
                                librarian->editStatus(id, stat);
                            }
                            else if (opt == 4) {
                                librarian->ShowBooks();
                            }
                            else if (opt == 5) {
                                librarian->generateReport();
                            }
                            else if (opt == 6) {
                                std::cout << "Logging out\n";
                                break;
                            }
                            else {
                                std::cout << "Invalid \n";
                            }
                        }
                    }
                    else if (Users[z]->get_acc_type() == "Member") {
                        MEMBER* member = (MEMBER*)Users[z]; // erm forgot how this works just dont touch so it stays working
                        // Validate the cast
                        if (member->get_acc_type() != "Member") {
                            std::cout << "if this appears somthing went wrong lin 144" << member->get_acc_type() << "\n";
                            continue;
                        }
                        std::cout << "Member cast successful: " << member->getName() << "\n";

                        while (true) {
                            std::cout << "1) View 2) Borrow 3) Reserve 4) Return 5) Logout\n";
                            std::cout << "Enter option: ";
                            int opt;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if (!(std::cin >> opt)) {
                                std::cout << "Invalid input. Please enter a number.\n";
                                continue;
                            }
                            std::cout << "Member option: " << opt << "\n";

                            if (opt == 1) {
                                librarian->ShowBooks();
                            }
                            else if (opt == 2) {
                                int id;
                                std::cout << "Enter book ID to borrow: ";
                                std::cin >> id;
                                member->Borrow_book(id, *librarian);
                            }
                            else if (opt == 3) {
                                int id;
                                std::cout << "Enter book ID to reserve: ";
                                std::cin >> id;
                                member->reserveBook(id, *librarian);
                            }
                            else if (opt == 4) {
                                int id;
                                std::cout << "Enter book ID to return: ";
                                std::cin >> id;
                                member->Return_book(id, *librarian);
                            }
                            else if (opt == 5) {
                                std::cout << "Logging out\n";
                                break;
                            }
                            else {
                                std::cout << "Invalid option\n";
                            }
                        }
                    }
                    else if (Users[z]->get_acc_type() == "Admin") {
                        ADMIN* admin = (ADMIN*)Users[z]; // C-style cast
                        // Validate the cast
                        if (admin->get_acc_type() != "Admin") {
                            std::cout << "Failed to cast to ADMIN: type is " << admin->get_acc_type() << "\n";
                            continue;
                        }
                        std::cout << "Admin cast successful: " << admin->getName() << "\n";

                        while (true) {
                            std::cout << "1) View users 2) View books 3) Logout\n";
                            std::cout << "Enter option: ";
                            int opt;
                            std::cin.clear();
                            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                            if (!(std::cin >> opt)) {
                                std::cout << "try another number\n";
                                continue;
                            }
                            std::cout << "Admin option: " << opt << "\n";

                            if (opt == 1) {
                                admin->view_Users(Users);
                            }
                            else if (opt == 2) {
                                admin->ViewBooks(librarian->books_list);
                            }
                            else if (opt == 3) {
                                std::cout << "Logging out\n";
                                break;
                            }
                            else {
                                std::cout << "Invalid \n";
                            }
                        }
                    }
                }
                else {
                    std::cout << "A dylan production " << z << "\n";
                }
            }
        }
        else if (choice == 3) {
            std::cout << "Exiting\n";
            break;
        }
        else {
            std::cout << "Invalid \n";
        }
    }
    // Manual cleanup
    for (int i = 0; i < Users.size(); i++) {
        delete Users[i];
    }
    std::cout << "exiting\n";
    return 0;
}