#include <bits/stdc++.h>
using namespace std;

class Book
{
protected:
    string title, author, publication, isbn;
    bool isAvailable = true;

public:
    Book() {};
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
    string to_string() const
    {
        return isbn + "\t" + title + "\t" + author + "\t" + publication + "\t" + (isAvailable ? "1" : "0");
    }
    void borrow(string sid, string bid)

    {
        bool isav = false;

        vector<Book> books;
        ifstream readf("books.txt");

        if (readf.is_open())

        {

            bool flag = false;

            string line;

            while (getline(readf, line))

            {

                Book b = get_details(line);
                if (b.isbn == bid)

                {

                    if (b.isAvailable)

                    {

                        std::ofstream file("bothids.txt", std::ios::app);

                        if (!file)

                        {

                            std::cerr << "Error opening file." << std::endl;

                            exit;
                        }

                        file << sid << "\t" << bid << endl;

                        file.close();
                        isav = true;
                        b.isAvailable = false;
                    }

                    else

                    {

                        cout << "Book is not availabale to borrow." << endl;

                        // return 2;
                    }

                    flag = true;
                }
                books.push_back(b);
            }
            if (!flag)

            {

                cout << "Book not found" << endl;

                // return -123;
            }

            readf.close();
        }
        if (isav)
        {
            ofstream writef("books.txt", ios::trunc); // Open with truncate mode to overwrite
            if (!writef.is_open())
            {
                cout << "Unable to open books.txt for writing" << endl;
                return;
            }
            for (const auto &book : books)
            {
                writef << book.to_string() << endl;
            }
            writef.close();
            cout << "Book borrowed successfully." << endl;
        }

        else

        {

            cout << "unable to open" << endl;
        }
    }
    void returnBook()
    {
        isAvailable = true;
    }
    void Available(string id)
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

                        book.display();
                        // return book.isAvailable;
                    }
                    else
                    {
                        cout << "Book is not availabale" << endl;
                        // return 2;
                    }
                    flag = true;
                }
            }
            if (!flag)
            {
                cout << "Book not found" << endl;
                // return -1;
            }

            readf.close();
        }
        else
        {
            cout << "unable to open" << endl;
        }
    }
    void borrowed_books(string id)
    {
        ifstream readf("books.txt");
        if (readf.is_open())
        {
            string line;
            while (getline(readf, line))
            {
                Book book = get_details(line);
                if (book.isbn == id)
                {
                    book.display();
                }
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

class Student : public Book
{
protected:
    string studentId, name, email;
    vector<Book> borrowedBooks;

public:
    Student() {};
    Student(string ID, string n, string e) : studentId(ID), name(n), email(e) {}
    Student get_student(const string &line)
    {
        istringstream iss(line);
        string name, email, studentId;

        getline(iss, studentId, '\t');
        getline(iss, name, '\t');
        getline(iss, email, '\t');

        return Student(studentId, name, email);
    }
    void borrowBook(Book &book)
    {
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
    string get_mem_books(string &line, string &p)
    {
        istringstream iss(line);
        string stu_id, book_id;
        getline(iss, stu_id, '\t');
        getline(iss, book_id, '\t');
        p = stu_id;
        return book_id;
    }
    void displayBorrowedBooks(string stu_id)
    {
        vector<string> list;
        ifstream readf("bothids.txt");
        if (readf.is_open())
        {

            string line;
            while (getline(readf, line))
            {
                string p = "";
                string b = get_mem_books(line, p);
                if (p == stu_id)
                {
                    list.push_back(b);
                }
            }
            readf.close();
        }
        else
        {
            cout << "unable to open" << endl;
        }

        for (auto it : list)
        {
            borrowed_books(it);
        }
    }
    void studentDetails()
    {
        cout << "Member Details : ";
        cout << "Student ID : " << studentId << ", Name : " << name << ", Email : " << email << endl;
    }
};
class Library : public Student
{
public:
    Library() {};
    void addbook(string tit, string auth, string publish, string id, bool isava)
    {
        // Book b1(tit,auth,publish,id,isava);
        ofstream writef("books.txt", ios::app);
        if (writef.is_open())
        {
            writef << isbn << "\t" << title << "\t" << author << "\t" << publication << "\t" << isAvailable << "\n";
            writef.close();
        }
        else
        {
            cerr << "Unable to open the file " << endl;
        }
    }
    void addstudent(string studentId, string name, string email)
    {
        ofstream writef("students.txt", ios::app);
        if (writef.is_open())
        {
            writef << studentId << "\t" << name << "\t" << email << "\n";
            writef.close();
        }
        else
        {
            cerr << "Unable to open the file " << endl;
        }
    }
    // void removebook(){

    // }
    // void removestudent(){

    // }
    void searchbook(string id)
    {
        Available(id);
    }
    void dis_book()
    {
        ifstream readf("books.txt");
        if (readf.is_open())
        {

            string line;
            while (getline(readf, line))
            {
                Book book = get_details(line);
                book.display();
            }
            readf.close();
        }
        else
        {
            cout << "unable to open" << endl;
        }
    }
    void dis_student()
    {
        ifstream readf("students.txt");
        if (readf.is_open())
        {

            string line;
            while (getline(readf, line))
            {
                Student student = get_student(line);
                student.studentDetails();
            }
            readf.close();
        }
        else
        {
            cout << "unable to open" << endl;
        }
    }
};
int main()
{
    return 0;
}