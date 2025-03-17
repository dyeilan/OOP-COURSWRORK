#ifndef LIBRARIAN_H
#define LIBRARIAN_H
#include "User.h"
#include "Book.h"
#include <vector>


//it works for now
class LIBRARIAN : public USER {
public:
    std::vector<Book> books_list;
private:
    std::vector<std::pair<int, int>> BorrowingRecords;
public:
    LIBRARIAN(int id, std::string Name, std::string email_address, std::string pass_word);
    void ADD_book(int book_id, std::string title);
    void remove_book(int book_id);
    void editStatus(int book_id, std::string new_status);
    void ShowBooks();
    void record_borrowing(int userID, int book_id);
    void remove_borrowing(int userID, int book_id);
    bool isBookAvailable(int book_id);
    void generateReport();
};

#endif