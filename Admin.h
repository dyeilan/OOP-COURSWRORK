#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
#include "Book.h"
#include <vector>

class ADMIN : public USER {
public:
    ADMIN(int id, std::string Name, std::string email_address, std::string pass_word);
    void view_Users(std::vector<USER*>& users_list); // Updated to use raw pointers
    void ViewBooks(std::vector<Book>& book_list);
};

#endif