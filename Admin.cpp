#include "Admin.h"
#include <iostream>

ADMIN::ADMIN(int id, std::string Name, std::string email_address, std::string pass_word)
    : USER(id, Name, email_address, pass_word, "Admin") {}

void ADMIN::view_Users(std::vector<USER*>& users_list) {
    int total_users = 0;
    for (int i = 0; i < users_list.size(); i++) {
        total_users++;
    }

    //just displays the email and id of the active user
    for (int i = 0; i < total_users; i++) {
        std::cout << "ID: " << users_list[i]->GetUserID() << ", Name: " << users_list[i]->getName()
            << ", Email: " << users_list[i]->getEmail() << ", Type: " << users_list[i]->get_acc_type() << std::endl;
        if (users_list[i]->get_acc_type() == "Admin" || users_list[i]->get_acc_type() == "Librarian" || users_list[i]->get_acc_type() == "Member") {
            std::cout << "User type verified: " << users_list[i]->get_acc_type() << std::endl;
        }
    }
}
//gets the book and changes the book list and adds 1 to the book id

void ADMIN::ViewBooks(std::vector<Book>& book_list) {
    int book_count = 0;
    for (int j = 0; j < book_list.size(); j++) {
        book_count++;
    }
    for (int k = 0; k < book_count; k++) {
        for (int m = 0; m < book_list.size(); m++) {
            if (book_list[m].getBookId() == book_list[k].getBookId()) {
                book_list[m].SHOW();
                break;
            }
        }
    }
}