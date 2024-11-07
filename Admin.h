#ifndef ADMIN_H
#define ADMIN_H

#include "Book.h"
#include "Students.h"

class Admin : public Book, public Students {
public:
    void addbook(const std::string &tit, const std::string &auth, const std::string &publish, const std::string &id, bool isava);
    bool isChar(char c) const;
    void addstudent(const std::string &studentId, const std::string &name, const std::string &email, const std::string &password);
    void removebook(const std::string &id);
    void removestudent(const std::string &id);
    void searchbook(const std::string &id);
    void dis_book() const;
    void dis_student() const;

    // Implement the pure virtual functions from LibraryEntity
    void get_details(const std::string &line) override;
    std::string to_string() const override;
    void display() const override;
};

#endif // ADMIN_H
