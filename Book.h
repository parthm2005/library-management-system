#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "LibraryEntity.h"

class Book : public LibraryEntity {
protected:
    std::string title, author, publication, isbn;
    bool isAvailable = true;
public:
    Book() {};
    Book(std::string t, std::string a, std::string p, std::string id, bool status) : title(t), author(a), publication(p), isbn(id), isAvailable(status) {}
    static Book* get_details(const std::string &line);
    std::string to_string() const override;
    void display() const override;
    void borrow(const std::string &sid, const std::string &bid);
    void returnBook(const std::string &bid, const std::string &sid);
    void Available(const std::string &id);
    void borrowed_Books(const std::string &id);
    bool isBookThere(const std::string &id) const;
};

#endif // BOOK_H