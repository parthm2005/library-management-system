#include "Book.h"
#include <string>
#include <sstream>
using namespace std;

Book* Book::get_details(const string &line)
{
    istringstream iss(line);
    string title, author, isbn, publication, isava;
    bool isavailable;
    getline(iss, isbn, '\t');
    getline(iss, title, '\t');
    getline(iss, author, '\t');
    getline(iss, publication, '\t');
    getline(iss, isava, '\t');

    isavailable = (isava == "1");
    return new Book(title, author, publication, isbn, isavailable);
}

std::string Book::to_string() const {
    // Implementation for converting book details to a string
}

void Book::borrow(const std::string &sid, const std::string &bid) {
    // Implementation for borrowing a book
}

void Book::returnBook(const std::string &bid, const std::string &sid) {
    // Implementation for returning a book
}

void Book::Available(const std::string &id) {
    // Implementation to check if a book is available
}

void Book::borrowed_Books(const std::string &id) {
    // Implementation to list borrowed books
}

void Book::display() const {
    // Implementation for displaying book details
}

bool Book::isBookThere(const std::string &id) const {
    // Implementation to check if a book exists
}