#ifndef STUDENTS_H
#define STUDENTS_H

#include "LibraryEntity.h"
#include "Book.h"
#include <string>
#include <vector>

class Student : public LibraryEntity {
protected:
    std::string studentId, name, email, password;
    std::vector<Book> borrowedBooks;
public:
    Student() {};
    Student(std::string ID, std::string n, std::string e, std::string pass) : studentId(ID), name(n), email(e), password(pass) {}
    static Student* get_details(const std::string &line);
    std::string to_string() const override;
    void display() const override;
    std::string get_mem_books(const std::string &line, const std::string &p);
    bool isStudentRegistered(const std::string &id) const;
    bool isPasswordCorrect(const std::string &id, const std::string &pass) const;
    bool isEmailRegistered(const std::string &email) const;
    bool isBorrowed(const std::string &stu_id) const;
    void displayBorrowedBooks(const std::string &stu_id) const;
};

#endif // STUDENTS_H