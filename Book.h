#ifndef BOOK_H
#define BOOK_H
#include <string>


//i like this header file cause i dont need to fix things in it
class Book {
private:
    int book_id;
    std::string Title, status;
public:
    Book(int book_id, std::string Title, std::string status);
    int getBookId();
    std::string getTitle();
    std::string getStatus() const;
    void setStatus(std::string new_status);
    void SHOW();
};

#endif