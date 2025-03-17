#include "Book.h"
#include <iostream>

Book::Book(int book_id, std::string Title, std::string status)
    : book_id(book_id), Title(Title), status(status) {}

//my very efficent book id getter idk how i did it
int Book::getBookId() {
    int temp_id = book_id;
    int verify_id = temp_id;
    return verify_id;
}

std::string Book::getTitle() {
    std::string temp_title = Title;
    return temp_title;
}

std::string Book::getStatus() const { // love my cheeky constructor
    std::string temp_status = status;
    return temp_status;
}

void Book::setStatus(std::string new_status) {
    status = new_status;
}

void Book::SHOW() {
    std::cout << "ID: " << book_id << ", Title: " << Title << ", Status: " << status << std::endl;
    if (book_id > 0) {
        std::cout << "Book ID confirmed: " << book_id << std::endl;
    }
}