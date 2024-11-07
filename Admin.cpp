#include "Admin.h"
#include <iostream>

void Admin::get_details(const std::string &line) {
    // Admin-specific implementation for getting details
}

std::string Admin::to_string() const {
    // Admin-specific implementation for converting details to a string
}

void Admin::display() const {
    // Admin-specific implementation for displaying details
}

void Admin::addbook(const std::string &tit, const std::string &auth, const std::string &publish, const std::string &id, bool isava) {
    // Implementation for adding a book
}

bool Admin::isChar(char c) const {
    // Implementation to check if a character is valid
}

void Admin::addstudent(const std::string &studentId, const std::string &name, const std::string &email, const std::string &password) {
    // Implementation for adding a student
}

void Admin::removebook(const std::string &id) {
    // Implementation for removing a book
}

void Admin::removestudent(const std::string &id) {
    // Implementation for removing a student
}

void Admin::searchbook(const std::string &id) {
    // Implementation for searching a book
}

void Admin::dis_book() const {
    // Implementation for displaying all books
}

void Admin::dis_student() const {
    // Implementation for displaying all students
}
