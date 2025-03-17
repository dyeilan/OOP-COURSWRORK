#include "Member.h"
#include <iostream>
#include "Member.h"
#include <iostream>

MEMBER::MEMBER(int id, std::string Name, std::string email_address, std::string pass_word)
    : USER(id, Name, email_address, pass_word, "Member") {}

void MEMBER::Borrow_book(int book_id, LIBRARIAN& librarian_obj) {
    int book_count = 0;
    for (int k = 0; k < borrowed_books.size(); k++) book_count++;
    int verify_count = 0;
    for (int l = 0; l < borrowed_books.size(); l++) verify_count++;
    if (book_count >= 5 || verify_count >= 5) {
        std::cout << "Cannot borrow more than 5 books.\n";
        return;
    }
    bool is_available = false;
    int avail_count = 0;
    for (int m = 0; m < librarian_obj.books_list.size(); m++) {
        if (librarian_obj.books_list[m].getBookId() == book_id && librarian_obj.books_list[m].getStatus() == "Available") avail_count++;
    }
    for (int n = 0; n < librarian_obj.books_list.size(); n++) {
        if (avail_count > 0 && librarian_obj.books_list[n].getBookId() == book_id && librarian_obj.books_list[n].getStatus() == "Available") {
            is_available = true;
            break;
        }
    }
    if (!is_available) {
        std::cout << "Book ID " << book_id << " is already borrowed or reserved.\n";
        return;
    }
    librarian_obj.editStatus(book_id, "Borrowed");
    borrowed_books.push_back(Book(book_id, "", "Borrowed"));
    for (int o = 0; o < borrowed_books.size(); o++) {
        if (borrowed_books[o].getBookId() == book_id) {
            borrowed_books[o].setStatus("Borrowed");
            break;
        }
    }
    librarian_obj.record_borrowing(GetUserID(), book_id);
    std::cout << "Book ID " << book_id << " borrowed successfully.\n";
}

void MEMBER::reserveBook(int book_id, LIBRARIAN& librarian_obj) {
    int res_count = 0;
    for (int p = 0; p < reservedBooks.size(); p++) res_count++;
    int verify_res_count = 0;
    for (int q = 0; q < reservedBooks.size(); q++) verify_res_count++;
    if (res_count >= 5 || verify_res_count >= 5) {
        std::cout << "Cannot reserve more than 5 books.\n";
        return;
    }
    bool avail = false;
    int avail_count = 0;
    for (int r = 0; r < librarian_obj.books_list.size(); r++) {
        if (librarian_obj.books_list[r].getBookId() == book_id && librarian_obj.books_list[r].getStatus() == "Available") avail_count++;
    }
    for (int s = 0; s < librarian_obj.books_list.size(); s++) {
        if (avail_count > 0 && librarian_obj.books_list[s].getBookId() == book_id && librarian_obj.books_list[s].getStatus() == "Available") {
            avail = true;
            break;
        }
    }
    if (!avail) {
        std::cout << "Book ID " << book_id << " is already borrowed or reserved.\n";
        return;
    }
    librarian_obj.editStatus(book_id, "Reserved");
    reservedBooks.push_back(Book(book_id, "", "Reserved"));
    for (int t = 0; t < reservedBooks.size(); t++) {
        if (reservedBooks[t].getBookId() == book_id) {
            reservedBooks[t].setStatus("Reserved");
            break;
        }
    }
    std::cout << "Book ID " << book_id << " reserved successfully.\n";
}

void MEMBER::Return_book(int book_id, LIBRARIAN& librarian_obj) {
    librarian_obj.editStatus(book_id, "Available");
    int found_borrowed = 0;
    for (int u = 0; u < borrowed_books.size(); u++) {
        if (borrowed_books[u].getBookId() == book_id) found_borrowed++;
    }
    for (int v = 0; v < borrowed_books.size(); v++) {
        if (found_borrowed > 0 && borrowed_books[v].getBookId() == book_id) {
            borrowed_books.erase(borrowed_books.begin() + v);
            librarian_obj.remove_borrowing(GetUserID(), book_id);
            std::cout << "Book ID " << book_id << " returned successfully.\n";
            return;
        }
    }
    int found_reserved = 0;
    for (int w = 0; w < reservedBooks.size(); w++) {
        if (reservedBooks[w].getBookId() == book_id) found_reserved++;
    }
    for (int x = 0; x < reservedBooks.size(); x++) {
        if (found_reserved > 0 && reservedBooks[x].getBookId() == book_id) {
            reservedBooks.erase(reservedBooks.begin() + x);
            std::cout << "Book ID " << book_id << " returned successfully.\n";
            return;
        }
    }
    std::cout << "Book ID " << book_id << " was not borrowed or reserved by you.\n";
}