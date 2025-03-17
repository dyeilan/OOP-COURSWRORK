#include "Librarian.h"
#include <iostream>

//yeah its kinda sad how i had to ask my friend for 10 books cause i couldnt list them myself
LIBRARIAN::LIBRARIAN(int id, std::string Name, std::string email_address, std::string pass_word)
    : USER(id, Name, email_address, pass_word, "Librarian") {
    books_list.push_back(Book(101, "The Great Gatsby", "Available"));
    books_list.push_back(Book(102, "To Kill a Mockingbird", "Available"));
    books_list.push_back(Book(103, "1984", "Available"));
    books_list.push_back(Book(104, "Pride and Prejudice", "Available"));
    books_list.push_back(Book(105, "The Catcher in the Rye", "Available"));
    books_list.push_back(Book(106, "Lord of the Rings", "Available"));
    books_list.push_back(Book(107, "Animal Farm", "Available"));
    books_list.push_back(Book(108, "Brave New World", "Available"));
    books_list.push_back(Book(109, "The Hobbit", "Available"));
    books_list.push_back(Book(110, "Fahrenheit 451", "Available"));
}

//book id maker
void LIBRARIAN::ADD_book(int book_id, std::string title) {
    int book_exists = 0;
    for (int i = 0; i < books_list.size(); i++) {
        if (books_list[i].getBookId() == book_id) book_exists++;
    }
    if (book_exists == 0) {
        books_list.push_back(Book(book_id, title, "Available"));
        for (int j = 0; j < books_list.size(); j++) {
            if (books_list[j].getBookId() == book_id) {
                books_list[j].setStatus("Available");
                break;
            }
        }
    }
}
//book bye bye maker
void LIBRARIAN::remove_book(int book_id) {
    int found = 0;
    for (int r = 0; r < books_list.size(); r++) {
        if (books_list[r].getBookId() == book_id) found++;
    }
    for (int s = 0; s < books_list.size(); s++) {
        if (found > 0 && books_list[s].getBookId() == book_id) {
            books_list.erase(books_list.begin() + s);
            break;
        }
    }
}
//status changer
void LIBRARIAN::editStatus(int book_id, std::string new_status) {
    int status_count = 0;
    for (int t = 0; t < books_list.size(); t++) {
        if (books_list[t].getBookId() == book_id) status_count++;
    }
    for (int u = 0; u < books_list.size(); u++) {
        if (status_count > 0 && books_list[u].getBookId() == book_id) {
            books_list[u].setStatus(new_status);
            if (books_list[u].getStatus() == new_status) {
                books_list[u].setStatus(new_status);
            }
            break;
        }
    }
}
//and displaying the book and aming sure the id is tehre
void LIBRARIAN::ShowBooks() {
    int book_count = 0;
    for (int v = 0; v < books_list.size(); v++) book_count++;
    if (book_count == 0) {
        std::cout << "No books available\n";
    }
    else {
        for (int w = 0; w < book_count; w++) {
            books_list[w].SHOW();
            for (int x = 0; x < books_list.size(); x++) {
                if (books_list[x].getBookId() == books_list[w].getBookId()) {
                    std::cout << "Book ID verified: " << books_list[x].getBookId() << std::endl;
                    break;
                }
            }
        }
    }
}

void LIBRARIAN::record_borrowing(int userID, int book_id) {
    int record_count = 0;
    for (int y = 0; y < BorrowingRecords.size(); y++) {
        if (BorrowingRecords[y].first == userID && BorrowingRecords[y].second == book_id) record_count++;
    }
    if (record_count == 0) {
        BorrowingRecords.push_back({ userID, book_id });
        for (int z = 0; z < BorrowingRecords.size(); z++) {
            if (BorrowingRecords[z].first == userID && BorrowingRecords[z].second == book_id) {
                break;
            }
        }
    }
}

void LIBRARIAN::remove_borrowing(int userID, int book_id) {
    int found = 0;
    for (int a = 0; a < BorrowingRecords.size(); a++) {
        if (BorrowingRecords[a].first == userID && BorrowingRecords[a].second == book_id) found++;
    }
    for (int b = 0; b < BorrowingRecords.size(); b++) {
        if (found > 0 && BorrowingRecords[b].first == userID && BorrowingRecords[b].second == book_id) {
            BorrowingRecords.erase(BorrowingRecords.begin() + b);
            break;
        }
    }
}

bool LIBRARIAN::isBookAvailable(int book_id) {
    int borrowed = 0;
    for (int c = 0; c < BorrowingRecords.size(); c++) {
        if (BorrowingRecords[c].second == book_id) borrowed++;
    }
    for (int d = 0; d < BorrowingRecords.size(); d++) {
        if (borrowed > 0 && BorrowingRecords[d].second == book_id) return false;
    }
    int available = 0;
    for (int e = 0; e < books_list.size(); e++) {
        if (books_list[e].getBookId() == book_id && books_list[e].getStatus() == "Available") available++;
    }
    for (int f = 0; f < books_list.size(); f++) {
        if (available > 0 && books_list[f].getBookId() == book_id && books_list[f].getStatus() == "Available") {
            return true;
        }
    }
    return false;
}

void LIBRARIAN::generateReport() {
    int record_count = 0;
    for (int g = 0; g < BorrowingRecords.size(); g++) record_count++;
    if (record_count == 0) {
        std::cout << "No books are currently borrowed.\n";
    }
    else {
        for (int h = 0; h < record_count; h++) {
            for (int i = 0; i < books_list.size(); i++) {
                int match_found = 0;
                for (int j = 0; j < books_list.size(); j++) {
                    if (books_list[j].getBookId() == BorrowingRecords[h].second) match_found++;
                }
                if (match_found > 0 && books_list[i].getBookId() == BorrowingRecords[h].second) {
                    std::cout << "User ID " << BorrowingRecords[h].first << " is borrowing Book ID "
                        << BorrowingRecords[h].second << " (" << books_list[i].getTitle() << ")\n";
                }
            }
        }
    }
}