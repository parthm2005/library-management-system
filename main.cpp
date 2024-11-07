#include <iostream>
#include "Admin.h"

int main() {
    Admin admin;
    
    // Adding books
    admin.addbook("The Great Gatsby", "F. Scott Fitzgerald", "1925", "B001", true);
    admin.addbook("1984", "George Orwell", "1949", "B002", true);
    
    // Adding students
    admin.addstudent("S001", "John Doe", "john@example.com", "password123");
    admin.addstudent("S002", "Jane Smith", "jane@example.com", "securepass");
    
    // Display all books
    admin.dis_book();
    
    // Display all students
    admin.dis_student();
    
    // Borrowing a book
    admin.borrow("S001", "B001");
    
    // Display borrowed books for a student
    admin.displayBorrowedBooks("S001");
    
    // Returning a book
    admin.returnBook("B001", "S001");
    
    // Checking if a book is available
    if (admin.isBookThere("B001")) {
        std::cout << "Book B001 is available." << std::endl;
    } else {
        std::cout << "Book B001 is not available." << std::endl;
    }
    
    // Removing a student
    admin.removestudent("S002");
    
    // Removing a book
    admin.removebook("B002");
    
    // Searching for a book
    admin.searchbook("B001");

    return 0;
}
