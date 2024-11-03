#include <bits/stdc++.h>
using namespace std;

class Book
{
    string title, author, publication, isbn;
    bool isAvailable = true;

public:
    Book(string t, string a, string p, string id, bool status) : title(t), author(a), publication(p), isbn(id), isAvailable(status) {}
    void borrow()
    {
        isAvailable = false;
    }
    void returnBook()
    {
        isAvailable = true;
    }
    bool Available()
    {
        return isAvailable;
    }
    void display()
    {
        cout << "Title : " << title << ", Author : " << author << ", Publication : " << publication << ", ISBN : " << isbn << ", Available : " << (isAvailable ? "Yes" : "No") << endl;
    }
};

class Student
{
    string studentId, name, email;
    vector<Book> borrowedBooks;

public:
    Student(string ID, string n, string e) : studentId(ID), name(n), email(e) {}
    void borrowBook(Book &book)
    {
        if (book.Available())
        {
            book.borrow();
            borrowedBooks.push_back(book);
        }
        else
            cout << "Book not available." << endl;
    }
    void returnBook(Book &book)
    {
        auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
        if (it != borrowedBooks.end())
        {
            book.returnBook();
            borrowedBooks.erase(it);
            cout << name << " returned " << book.display() << endl;
        }
        else
            cout << "This book was not borrowed by " << name << "." << endl;
    }
    void displayBorrowedBooks()
    {
        if (!borrowedBooks.empty())
        {
            cout << name << "'s borrowed books." << endl;
            for (auto book : borrowedBooks)
            {
                book.display();
            }
        }
    }
};
