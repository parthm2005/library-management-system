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
    Book get_details(const string &line);
    string to_string() const;
    void borrow(string sid, string bid);
    void returnBook(string bid, string sid);
    void Available(string id);
    void borrowed_books(string id);
    friend ostream &operator<<(ostream &os, const Book &book);
    bool isBookThere(string id);
};

Book Book::get_details(const string &line)
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

string Book::to_string() const
{
    return isbn + "\t" + title + "\t" + author + "\t" + publication + "\t" + (isAvailable ? "1" : "0");
}

void Book::borrow(string sid, string bid)
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
                    cout << "Book is not available to borrow." << endl;
                }
                flag = true;
            }
            books.push_back(b);
        }
        if (!flag)
        {
            cout << "Book not found" << endl;
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

void Book::returnBook(string bid, string sid)
{
    vector<Book> books;
    bool found = false;
    bool returned = false;
    ifstream readf("books.txt");
    if (!readf.is_open())
    {
        cout << "Unable to open book.txt" << endl;
        return;
    }
    else
    {
        string line;
        while (getline(readf, line))
        {
            Book b = get_details(line);
            if (b.isbn == bid)
            {
                found = true;
                if (!b.isAvailable)
                {
                    b.isAvailable = true;
                    returned = true;
                }
                else
                {
                    cout << "You can't return book which you have not borrowed! Book is already available in the library" << endl;
                }
            }
            books.push_back(b);
        }
        readf.close();
    }
    if (returned)
    {
        ofstream writef("books.txt", ios::trunc);
        if (!writef.is_open())
        {
            cout << "Unable to open books.txt for writing " << endl;
            return;
        }
        for (const auto &book : books)
        {
            writef << book.to_string() << endl;
        }
        writef.close();
        cout << "Book with "<<bid<<" id  returned successfully " << endl;
    }
    if (returned)
    {
        ifstream readf("bothids.txt");
        vector<string> updated_enteries;
        if (!readf.is_open())
        {
            cout << "Unable to open bothids.txt " << endl;
            return;
        }
        string line;
        while (getline(readf, line))
        {
            istringstream iss(line);
            string ssid, sbid;
            getline(iss, ssid, '\t');
            getline(iss, sbid, '\t');

            if (!(ssid == sid && sbid == bid))
            {
                updated_enteries.push_back(line);
            }
        }
        readf.close();

        ofstream writef("bothids.txt", ios::trunc);
        if (!writef.is_open())
        {
            cout << "Unable to open bothids.txt to write " << endl;
            return;
        }
        for (const auto &entry : updated_enteries)
        {
            writef << entry << endl;
        }
        writef.close();
        cout << "Updated the bothids.txt file " << endl;
    }
    else if (!found)
    {
        cout << "Book not found in the library " << endl;
    }
}

void Book::Available(string id)
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
                    cout << book;
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

void Book::borrowed_books(string id)
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
                cout << book;
            }
        }
        readf.close();
    }
    else
    {
        cout << "unable to open" << endl;
    }
}

ostream &operator<<(ostream &os, const Book &book)
{
    os << left << setw(30) << book.title << setw(20) << book.author << setw(20) << book.publication << setw(10) << book.isbn << setw(5) << (book.isAvailable ? "Yes" : "No") << endl;
    return os;
}

bool Book::isBookThere(string id)
{
    string line;
    ifstream readf("books.txt");
    if (readf.is_open())
    {
        string line;
        while (getline(readf, line))
        {
            Book b = get_details(line);
            if (b.isbn == id)
            {
                readf.close();
                return true;
            }
        }
        readf.close();
        return false;
    }
    else
    {
        cerr << "Unable to open the file students.txt" << endl;
    }
    return false;
}

class Student : public Book
{
protected:
    string studentId, name, email, password;
    vector<Book> borrowedBooks;

public:
    Student() {};
    Student(string ID, string n, string e, string pass) : studentId(ID), name(n), email(e), password(pass) {}
    Student get_student(const string &line)
    {
        istringstream iss(line);
        string name, email, studentId, password;

        getline(iss, studentId, '\t');
        getline(iss, name, '\t');
        getline(iss, email, '\t');
        getline(iss, password, '\t');

        return Student(studentId, name, email, password);
    }
    string to_string() const{
        return studentId + "\t" + name + "\t" + email + "\t" + password;
    }
    // void borrowBook(Book &book)
    // {
    // }
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
    bool isStudentRegistered(string id){
        string line;
        ifstream readf("students.txt");
        if (readf.is_open())
        {
            string line;
            while (getline(readf, line))
            {   
                Student s = get_student(line);
                if (s.studentId == id)
                {
                    readf.close();
                    return true;
                }
            }
            readf.close();
        }
        else
        {
            cerr << "Unable to open the file students.txt" << endl;
        }
    return false;
}
    bool isPasswordCorrect(string id, string pass){
        ifstream readf("students.txt");
        if (readf.is_open()){
            string line;
            while (getline(readf, line)){
                Student s = get_student(line);
                if (s.studentId == id && s.password == pass){
                    readf.close();
                    return true;
                }
            }
            readf.close();
            return false;
        }
        else{
            cerr << "Unable to open the file students.txt" << endl;
        }
        return false;
    }
    bool isEmailRegistered(string email){
        string line;
        ifstream readf("students.txt");
        if (readf.is_open())
        {
            string line;
            while (getline(readf, line))
            {   
                Student s = get_student(line);

                if (s.email == email)
                {
                    readf.close();
                    return true;
                }
            }
            readf.close();
        }
        else
        {
            cerr << "Unable to open the file students.txt" << endl;
        }
        return false;
    }
    bool isBorrowed(string stu_id)
    {
        vector<string> list;
        ifstream readf("bothids.txt");
        bool chk=false;
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
                    chk=true;
                    readf.close();
                    return chk;
                }
            }
            readf.close();
        }
        else
        {
            cout << "unable to open" << endl;
        }
        return chk;
    }
    void returnAllBook(string id){
        vector<string> list;
        ifstream readf("bothids.txt");
        if (readf.is_open())
        {
            string line;
            while (getline(readf, line))
            {
                string p = "";
                string b = get_mem_books(line, p);
                if (p == id)
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
            returnBook(it, id);
        }
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
    
    friend ostream &operator<<(ostream &os, const Student &student)
    {
        if (student.studentId != "123")
        {
            os << left << setw(15) << student.studentId << setw(25) << student.name << setw(30) << student.email << endl;
        }
        return os;
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
            writef << id << "\t" << tit << "\t" << auth << "\t" << publish << "\t" << isava << "\n";
            writef.close();
        }
        else
        {
            cerr << "Unable to open the file " << endl;
        }
    }
    bool isChar(char c)
    {
        return ((c>='A' && c<='Z')||(c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='@'||c=='.');
    }
    bool isEmailValid(string email)
    {
        if(email[0]=='@') return 0;
        if(!isChar(email[0])) return 0;
        int At=-1,Dot=-1;
        for(int i=0;i<email.length();i++)
        {
            if(!isChar(email[i])) return 0;
            if(email[i]=='@'&& At==-1) At=i;
            else if(email[i]=='@' && At!=-1) return 0;
            else if(email[i]=='.' && Dot!=i-1) Dot=i;
            else if(email[i]=='.' && Dot==i-1) return 0;
        }
        if(At==-1 || Dot==-1) return 0;
        if(At>Dot||At+1==Dot) return 0;
        if(Dot>=email.length()-1) return 0;
        return 1;
    }
    void addstudent(string studentId, string name, string email, string password)
    {
        ofstream writef("students.txt", ios::app);
        if (writef.is_open())
        {
            writef << studentId << "\t"  << name << "\t" << email << "\t" << password << "\n";
            writef.close();
        }
        else
        {
            cerr << "Unable to open the file " << endl;
        }
    }
    void removebook(string id){
        Book temp;
        vector<Book> books;
        if(temp.isBookThere(id)){
            ifstream readf("books.txt");
            if(!readf.is_open()){
                cout<<"Unable to open book.txt!"<<endl;
                return ;
            }
            else{
                string line;
                while(getline(readf,line)){
                    Book b = get_details(line);
                    istringstream iss(line);
                    string isbn;
                    getline(iss, isbn, '\t');
                    if(isbn!=id){
                        books.push_back(b);
                    }
                }
                readf.close();
            }
            
            ofstream writef("books.txt",ios::trunc);
            if(!writef.is_open()){
                cout<<"Unable to open books.txt for writing "<<endl;
                return;
            }
            for(const auto &book:books){
                writef<<book.to_string()<<endl;
            }
            writef.close();
            cout<<"Book with "<<id<<" id removed successfully!"<<endl;
        }
        
        else{
            cout<<"Book with "<<id<<" id not found in the library."<<endl;
        } 
    }

    void removestudent(string id){
        vector<Student> students;
        if(isStudentRegistered(id)){
            ifstream readf("students.txt");
            if(!readf.is_open()){
                cout<<"Unable to open students.txt!"<<endl;
                return ;
            }
            else{
                if(id=="123"){
                    cout<<"You can not remove admin!"<<endl;
                    return;
                }
                if(isBorrowed(id)){
                    cout<<"You can only remove student after returning all borrowed books!"<<endl;
                    cout<<"borrowed books are:"<<endl;
                    displayBorrowedBooks(id);
                }
                while(1){
                    if(isBorrowed(id)){
                        cout<<"Do you want to return all borrowed books? (y/n): ";
                        string response;
                        cin>>response;
                        if(response == "y" || response == "Y" || response == "yes" || response == "Yes" || response == "YES"){
                            returnAllBook(id);
                            break;
                        }
                        else if(response == "n" || response == "N" || response == "no" || response == "No" || response == "No"){
                            cout<<"You can not remove student without returning all borrowed books!"<<endl;
                            return;
                        }
                        else{
                            cout<<"Please enter valid input!"<<endl;
                        }
                    }
                    else{
                        break;
                    }
                }
                string line;
                while(getline(readf,line)){
                    Student s = get_student(line);
                    istringstream iss(line);
                    string sid;
                    getline(iss, sid, '\t');
                    if(sid!=id){
                        students.push_back(s);
                    }
                }
                readf.close();
            }
            
            ofstream writef("students.txt",ios::trunc);
            if(!writef.is_open()){
                cout<<"Unable to open students.txt for writting "<<endl;
                return;
            }
            for(const auto &student:students){
                writef<<student.to_string()<<endl;
            }
            writef.close();
            cout<<"Student with "<<id<<" id removed successfully!"<<endl;
        }
        
        else{
            cout<<"Student not found."<<endl;
        } 
    }
    
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
                cout << book;
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
                cout << student;
            }
            readf.close();
        }
        else
        {
            cout << "unable to open" << endl;
        }
    }
};


void menu(){
        string id="123";
        string pass="1111";
        Library admin;
        char chr;

        bool flag=1;

        while(flag){
            cout<<"What do you want?\n";
            cout<<"To add book, enter a \n";    
            cout<<"To add student, enter b \n";    
            cout<<"To remove book, enter c \n";    
            cout<<"To remove student, enter d \n";    
            cout<<"To search the book by id, enter e \n";    
            cout<<"To display all books, enter f \n";
            cout<<"To display all students, enter g \n";
            // cout<<"For doing student things, enter S\n";
            cout<<"To close the menu, enter z\n";
            cin>>chr;
            if(chr=='z'){
                break;
            }
            
            string tit, auth, publish, id, studentId, name, email, password, bid, check;
            bool isava;

            switch (chr)
            {
            case 'a':
            // addbook(string tit, string auth, string publish, string id, bool isava)
                while(1){


                    cout<<"For continue with adding book enter 1, for go to previous menu enter 2: ";
                    cin>>check;
                    while((check!="1")&&(check!="2")){
                        cout<<"Please enter 1 or 2 only for add book or go to previous menu respectively: ";
                        cin>>check;
                    }
                    if(check=="2"){
                        break;
                    }

                    while(1){
                        cout<<"Enter id of the book: ";
                        cin>>id;
                        if(admin.isBookThere(id)){
                            cout<<"This id is used for another book, please enter other book id!"<<endl;
                        }
                        else{
                            break;
                        }
                    }

                    do {
                        cout<<"Enter title of the book: ";
                        cin.ignore();
                        getline(cin, tit);
                        if (tit.empty()) {
                            cout << "Title cannot be empty. Please enter a valid title." << endl;
                        }
                    } while (tit.empty());

                    do {
                        cout<<"Enter author of the book: ";
                        getline(cin, auth);
                        if (auth.empty()) {
                            cout << "Author name cannot be empty. Please enter a valid author name." << endl;
                        }
                    } while (auth.empty());

                    do {
                        cout<<"Enter publisher name of the book: ";
                        getline(cin, publish);
                        if (publish.empty()) {
                            cout << "Publisher name cannot be empty. Please enter a valid publisher name." << endl;
                        }
                    } while (publish.empty());


                    admin.addbook(tit, auth, publish, id, 1);
                }
                break;
            
            case 'b':
                // addstudent(string studentId, string name, string email)
                
                while(1){


                    cout<<"For continue with add student enter 1, for go to previous menu enter 2: ";
                    cin>>check;
                    while((check!="1")&&(check!="2")){
                        cout<<"Please enter 1 or 2 only for add student or go to previous menu respectively: ";
                        cin>>check;
                    }
                    if(check=="2"){
                        break;
                    }


                    while(1){
                        cout<<"Enter student Id: ";
                        cin>>studentId;
                        if(admin.isStudentRegistered(studentId)){
                            cout<<"This student id is registered with another student, please enter other student id!"<<endl;
                        }
                        else{
                            break;
                        }
                    }

                    do {
                        cout<<"Enter name of the student: ";
                        cin.ignore();
                        getline(cin, name);
                        if (name.empty()) {
                            cout << "Name cannot be empty. Please enter a valid name." << endl;
                        }
                    } while (name.empty());

                    while(1){
                        cout<<"Enter email of the student: ";
                        cin>>email;
                        if(admin.isEmailRegistered(email)){
                            cout<<"This Email is already registered with different student, Kindly register with different email!"<<endl;
                        }
                        else if(!admin.isEmailValid(email)){
                            cout<<"Please enter valid email address!"<<endl;
                        }
                        else{
                            break;
                        }
                    }

                    do {
                        cout<<"Enter password for the student " << name << " : ";
                        cin.ignore();
                        getline(cin, password);
                        if (password.empty()) {
                            cout << "Password cannot be empty. Please enter a valid password." << endl;
                        }
                    } while (password.empty());

                    admin.addstudent(studentId, name, email, password);
                }
                    break;
            
            case 'c':
                while(1){


                    cout<<"For continue with remove book enter 1, for go to previous menu enter 2: ";
                    cin>>check;
                    while((check!="1")&&(check!="2")){
                        cout<<"Please enter 1 or 2 only for remove book or go to previous menu respectively: ";
                        cin>>check;
                    }
                    if(check=="2"){
                        break;
                    }

                    while(1){
                        cout<<"Enter id of the book: ";
                        cin>>id;
                        if(!admin.isBookThere(id)){
                            cout<<"This book is not there in the library, please check book id, and try again!"<<endl;
                        }
                        else{
                            break;
                        }
                    }

                    admin.removebook(id);
                }
                break;


            case 'd':
                
                while(1){


                    cout<<"For continue with remove student enter 1, for go to previous menu enter 2: ";
                    cin>>check;
                    while((check!="1")&&(check!="2")){
                        cout<<"Please enter 1 or 2 only for remove student or go to previous menu respectively: ";
                        cin>>check;
                    }
                    if(check=="2"){
                        break;
                    }


                    while(1){
                        cout<<"Enter student Id: ";
                        cin>>studentId;
                        if(!admin.isStudentRegistered(studentId)){
                            cout<<"This student is not registered, please check student id and try again!"<<endl;
                        }
                        else if(studentId=="123"){
                            cout<<"You can not remove admin!"<<endl;
                        }
                        else{
                            break;
                        }
                    }
                    admin.removestudent(studentId);
                }
                break;
            


            case 'e':

                while(1){


                    cout<<"For continue with searching the book, enter 1, for go to previous menu enter 2: ";
                    cin>>check;
                    while((check!="1")&&(check!="2")){
                        cout<<"Please enter 1 or 2 only for search the book or go to previous menu respectively: ";
                        cin>>check;
                    }
                    if(check=="2"){
                        break;
                    }

                    cout<<"Enter id of the book: ";
                    cin>>bid;
                    admin.searchbook(bid);
                }
                    break;
            
            case 'f':

                cout<<"For continue with displaying all books, enter 1; for go to previous menu enter 2: ";
                cin>>check;
                while((check!="1")&&(check!="2")){
                    cout<<"Please enter 1 or 2 only for display all books or go to previous menu respectively: ";
                    cin>>check;
                }

                if(check=="2"){
                    break;
                }
                cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publication" << setw(10) << "ISBN" << setw(5) << "Available" << endl;
                cout << string(95, '-') << endl;
                admin.dis_book();
                cout<<endl;
                break;
            
            case 'g':

                cout<<"For continue with displaying all students, enter 1; for go to previous menu enter 2: ";
                cin>>check;
                while((check!="1")&&(check!="2")){
                    cout<<"Please enter 1 or 2 only for display all students or go to previous menu respectively: ";
                    cin>>check;
                }
                if(check=="2"){
                    break;
                }
                cout << left << setw(15) << "Student ID" << setw(25) << "Name" << setw(30) << "Email" << endl;
                cout << string(70, '-') << endl;
                admin.dis_student();
                cout<<endl;
                break;

            // case 'S':

            //     bool stdchr;
            //     break;

            default:
                cout<<"You have to enter only 'a', 'b', 'c', 'd', 'e', or 'z' only for respective it's works!";
                break;
            }
        }
    }

void menu(string id, string password){
    Student student;
        char chr;

        bool flag=1;

        while(flag){
            cout<<"What do you want?\n";
            cout<<"To borrow the book, enter a \n";    
            cout<<"To return the book, enter b \n";
            cout<<"To display borrowed book, enter c \n";
            cout<<"To close the menu, enter z\n";
            cin>>chr;
            if(chr=='z'){
                break;
            }
            
            string bid, check;

            switch (chr)
            {
            case 'a':
                while(1){

                    cout<<"For continue with borrowing the book enter 1, for go to previous menu enter 2: ";
                    cin>>check;
                    while((check!="1")&&(check!="2")){
                        cout<<"Please enter 1 or 2 only for borrow the book or go to previous menu respectively: ";
                        cin>>check;
                    }
                    if(check=="2"){
                        break;
                    }

                    cout<<"Enter id of the book: ";
                    cin>>bid;
                    if(student.isBookThere(bid)){
                        student.borrow(id, bid);
                    }
                    else{
                        cout<<"Book is not there in library!"<<endl;
                    }
                    cout<<"Your current borrowed books:\n";
                    cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publication" << setw(10) << "ISBN" << setw(5) << "Available" << endl;
                    cout << string(95, '-') << endl;    
                    student.displayBorrowedBooks(id);
                    cout<<endl;
                }
                break;

            case 'b':
                while(1){

                    cout<<"For continue with return the book enter 1, for go to previous menu enter 2: ";
                    cin>>check;
                    while((check!="1")&&(check!="2")){
                        cout<<"Please enter 1 or 2 only for return the book or go to previous menu respectively: ";
                        cin>>check;
                    }
                    if(check=="2"){
                        break;
                    }

                    if(student.isBorrowed(id)){
                        cout<<"Your current borrowed books:\n";
                        cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publication" << setw(10) << "ISBN" << setw(5) << "Available" << endl;
                        cout << string(95, '-') << endl;    
                        student.displayBorrowedBooks(id);
                        cout<<endl;
                        cout<<"Enter id of the book: ";
                        cin>>bid;
                        student.returnBook(bid, id);
                        cout<<"Your current borrowed books:\n";
                        cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publication" << setw(10) << "ISBN" << setw(5) << "Available" << endl;
                        cout << string(95, '-') << endl;    
                        student.displayBorrowedBooks(id);
                        cout<<endl;
                    }
                    else{
                        cout<<"You have not borrowed any book!"<<endl;
                        break;
                    }
                }
                break;
            

            case 'c':

                cout<<"For continue with display borrowed books enter 1, for go to previous menu enter 2: ";
                cin>>check;
                while((check!="1")&&(check!="2")){
                    cout<<"Please enter 1 or 2 only for display borrowed books or go to previous menu respectively: ";
                    cin>>check;
                }
                if(check=="2"){
                    break;
                }

                if(student.isBorrowed(id)){
                    cout<<"Your current borrowed books:\n";
                    cout << left << setw(30) << "Title" << setw(20) << "Author" << setw(20) << "Publication" << setw(10) << "ISBN" << setw(5) << "Available" << endl;
                    cout << string(95, '-') << endl;    
                    student.displayBorrowedBooks(id);
                    cout<<endl;
                }
                else{
                    cout<<"You have not borrowed any book!"<<endl;
                    break;
                }
                break;
            

            default:
                cout<<"You have to enter only 'a', 'b', 'c' or 'z' only for respective it's works!";
                break;
            }
        }
    }

int main()
{

    Student temp;
    string id, pass;
    
    while(1){
        cout<<"Enter you ID: ";
        cin>>id;
            if(temp.isStudentRegistered(id)){
                break;
            }
            else{
                cout<<"Please enter valid id!"<<endl;
            }
    }

    int count=5;
    while(count--){
        cout<<"Enter your password: ";
        cin>>pass;
        if(temp.isPasswordCorrect(id, pass)){
            break;
        }
        else if(count>0){
            cout<<"Please enter correct password!";
            cout<<endl;
            if(count<=3 && count>0){
                cout<<"You have only "<<count<<" attempts left!"<<endl;
            }
        }
    }
    
    if(count<=0){
        cout<<"You have entered wrong password 5 times, please try again later!"<<endl;
        return 0;
    }


    
    if(id=="123"){
            menu();
    }
    else{
            menu(id, pass);
    }
    
    return 0;
}