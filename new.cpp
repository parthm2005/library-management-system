#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>

class LibraryEntity {
public:
    virtual LibraryEntity* get_details(const std::string &line) = 0;
    virtual std::string to_string() const = 0;
    virtual void display() const = 0;
    virtual ~LibraryEntity() {}
};

class Book : public virtual LibraryEntity {
private:
    std::string title, author, publication, isbn;
    bool isAvailable = true;

public:
    Book() = default;
    Book(const std::string &title, const std::string &author, const std::string &publication, const std::string &isbn, bool isAvailable = true)
        : title(title), author(author), publication(publication), isbn(isbn), isAvailable(isAvailable) {}
    Book* get_details(const std::string &line) override {
        // parse line to set Book details (implement parsing logic)
        // return *this for chaining
        return this;
    }
    std::string to_string() const override {
        return "Title: " + title + ", Author: " + author + ", ISBN: " + isbn;
    }
    void borrow(const std::string &sid, const std::string &bid) {
        if (isAvailable) {
            isAvailable = false;
            std::cout << "Book borrowed by Student ID: " << sid << std::endl;
        } else {
            std::cout << "Book is currently unavailable." << std::endl;
        }
    }
    void returnBook(const std::string &bid, const std::string &sid) {
        isAvailable = true;
        std::cout << "Book returned by Student ID: " << sid << std::endl;
    }
    void Available(const std::string &id) {
        std::cout << (isAvailable ? "Book is available." : "Book is not available.") << std::endl;
    }
    void borrowed_books(const std::string &id) {
        if (!isAvailable) {
            std::cout << "Borrowed by Student ID: " << id << std::endl;
        } else {
            std::cout << "This book is available." << std::endl;
        }
    }
    void display() const override {
        std::cout << "Book Details: " << to_string() << "\nAvailability: " << (isAvailable ? "Available" : "Unavailable") << std::endl;
    }
    bool isBookThere(const std::string &id) const {
        return isbn == id;
    }
};

class Student : public virtual LibraryEntity {
private:
    std::string studentId, name, email, password;
    std::vector<std::string> borrowedBooks;

public:
    Student() = default;
    Student(const std::string &studentId, const std::string &name, const std::string &email, const std::string &password)
        : studentId(studentId), name(name), email(email), password(password) {}
    Student* get_details(const std::string &line) override {
        // parse line to set Student details
        return this;
    }
    std::string to_string() const override {
        return "Student ID: " + studentId + ", Name: " + name + ", Email: " + email;
    }
    std::string get_mem_books(const std::string &line, const std::string &p) {
        // Process membership books or borrowed books list
        return "Borrowed Books list";
    }
    bool isStudentRegistered(const std::string &id) const {
        return studentId == id;
    }
    bool isPasswordCorrect(const std::string &id, const std::string &pass) const {
        return (studentId == id && password == pass);
    }
    bool isEmailRegistered(const std::string &email) const {
        return this->email == email;
    }
    bool isBorrowed(const std::string &stu_id) const {
        return !borrowedBooks.empty();
    }
    void displayBorrowedBooks(const std::string &stu_id) const {
        std::cout << "Borrowed Books for Student ID: " << stu_id << std::endl;
        for (const auto &book : borrowedBooks) {
            std::cout << " - " << book << std::endl;
        }
    }
    void display() const override {
        std::cout << "Student Details: " << to_string() << std::endl;
    }
};

class Admin : public Book, public Student {
public:
    Admin* get_details(const std::string &line) override {
        // Implement the logic for Admin's get_details
        return this;
    }
    std::string to_string() const override {
        return "Admin: " + Student::to_string();
    }
    void display() const override {
        std::cout << "Admin Details: " << to_string() << std::endl;
    }
    
    void addbook(const std::string &tit, const std::string &auth, const std::string &publish, const std::string &id, bool isava) {
        std::cout << "Adding book: " << tit << " by " << auth << std::endl;
    }
    bool isChar(char c) {
        return std::isalpha(c);
    }
    void addstudent(const std::string &studentId, const std::string &name, const std::string &email, const std::string &password) {
        std::cout << "Adding student: " << name << " with ID: " << studentId << std::endl;
    }
    void removebook(const std::string &id) {
        std::cout << "Removing book with ID: " << id << std::endl;
    }
    void removestudent(const std::string &id) {
        std::cout << "Removing student with ID: " << id << std::endl;
    }
    void searchbook(const std::string &id) {
        std::cout << "Searching for book with ID: " << id << std::endl;
    }
    void dis_book() {
        std::cout << "Displaying all books in the system." << std::endl;
    }
    void dis_student() {
        std::cout << "Displaying all students in the system." << std::endl;
    }
};

int main() {
    Admin admin;

    // Example actions
    admin.addbook("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "9780743273565", true);
    admin.addstudent("S123", "Alice", "alice@example.com", "password123");

    Book book("The Great Gatsby", "F. Scott Fitzgerald", "Scribner", "9780743273565");
    book.display();

    Student student("S123", "Alice", "alice@example.com", "password123");
    student.display();

    return 0;
}
