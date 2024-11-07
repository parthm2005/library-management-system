#include "Student.h"
#include <iostream>
#include <sstream>
using namespace std;

Student* Student::get_details(const std::string &line)
{
    istringstream iss(line);
    string name, email, studentId, password;

    getline(iss, studentId, '\t');
    getline(iss, name, '\t');
    getline(iss, email, '\t');
    getline(iss, password, '\t');

    return new Student(studentId, name, email, password);
}

std::string Student::to_string() const {
    // Implementation for converting student details to a string
}

std::string Student::get_mem_books(const std::string &line, const std::string &p) {
    // Implementation to get member books
}

bool Student::isStudentRegistered(const std::string &id) const {
    // Implementation to check if a student is registered
}

bool Student::isPasswordCorrect(const std::string &id, const std::string &pass) const {
    // Implementation to check if password is correct
}

bool Student::isEmailRegistered(const std::string &email) const {
    // Implementation to check if email is registered
}

bool Student::isBorrowed(const std::string &stu_id) const {
    // Implementation to check if a student has borrowed books
}

void Student::displayBorrowedBooks(const std::string &stu_id) const {
    // Implementation to display borrowed books of a student
}

void Student::display() const {
    // Implementation for displaying student details
}