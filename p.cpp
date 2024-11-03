#include <bits/stdc++.h>
using namespace std;

class Book
{
    string title, author, publication, isbn;
    bool isAvailable = true;

public:
    Book(string t, string a, string p, string id, bool status) : title(t), author(a), publication(p), isbn(id), isAvailable(status) {}
    Book get_details(const string &line)
    {
        istringstream iss(line);
        string title, author, isbn, publication, isava;
        bool isavailable;
        getline(iss, isbn, '\t');
        getline(iss, title, '\t');
        getline(iss, author, '\t');
        getline(iss, publication, '\t');
        getline(iss, isava, '\t');

        isava == "1" ? isavailable = true : isavailable = false;
        return Book(title, author, publication, isbn, isavailable);
    }
    void borrow()
    {
        isAvailable = false;
    }
    void returnBook()
    {
        isAvailable = true;
    }
    bool Available(string id)
    {
        ifstream readf("books.txt");
        if (readf.is_open())
        {
            bool flag = false;
            string line;
            while (getline(readf, line))
            {
                Book book = get_details(line);
                if (book.isbn == id)
                {
                    if (book.isAvailable)
                    {

                        // book.display();
                        return book.isAvailable;
                    }
                    else
                    {
                        cout << "Book is not availabale" << endl;
                    }
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "Book not found" << endl;
            }

            readf.close();
        }
        else
        {
            cout << "unable to open" << endl;
        }
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
        string dummy;// for now
        if (book.Available(dummy))
        {
            book.borrow();
            borrowedBooks.push_back(book);
        }
        else
            cout << "Book not available." << endl;
    }
    // void returnBook(Book &book)
    // {
    //     auto it = find(borrowedBooks.begin(), borrowedBooks.end(), book);
    //     if (it != borrowedBooks.end())
    //     {
    //         book.returnBook();
    //         borrowedBooks.erase(it);
    //         cout << name << " returned ";
    //         book.display();
    //     }
    //     else
    //         cout << "This book was not borrowed by " << name << "." << endl;
    // }
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
    void studentDetails()
    {
        cout<<"Member Details : ";
        cout<<"Student ID : "<<studentId<<", Name : "<<name<<", Email : "<<email<<endl;
    }
};
int main()
{
    return 0;
}