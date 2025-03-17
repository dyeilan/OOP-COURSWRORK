#ifndef MEMBER_H
#define MEMBER_H
#include "User.h"
#include "Librarian.h"
#include <vector>

class MEMBER : public USER {
private:
    std::vector<Book> borrowed_books, reservedBooks;
public:
    MEMBER(int id, std::string Name, std::string email_address, std::string pass_word);
    void Borrow_book(int book_id, LIBRARIAN& librarian_obj);
    void reserveBook(int book_id, LIBRARIAN& librarian_obj);
    void Return_book(int book_id, LIBRARIAN& librarian_obj);
};

#endif