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
    void returnBook(string bid,string sid)
    {
        vector<Book> books;
        bool found=false;
        bool returned = false;
        ifstream readf("books.txt");
        if(!readf.is_open()){
            cout<<"Unable to open book.txt wed"<<endl;
            return ;
        }
        else{
            string line;
            while(getline(readf,line)){
                Book b = get_details(line);
                if(b.isbn==bid){
                    found=true;
                    if(!b.isAvailable){
                        b.isAvailable=true;
                        returned = true;
                    }
                    else{
                        cout<<"Book is already available in the library "<<endl;
                    }
                }
                books.push_back(b);
            }
            readf.close();
        }
        if(returned){
            ofstream writef("books.txt",ios::trunc);
            if(!writef.is_open()){
                cout<<"Unable to open books.txt for writting "<<endl;
                return;
            }
            for(const auto &book:books){
                writef<<book.to_string()<<endl;
            }
            writef.close();
            cout<<"Book returned successfully "<<endl;
        }
        if(returned){
            ifstream readf("bothids.txt");
            vector<string>updated_enteries;
            if(!readf.is_open()){
                cout<<"Unable to open bothids.txt "<<endl;
                return;
            }
            string line;
            while(getline(readf,line)){
                istringstream iss(line);
                string ssid,sbid;
                getline(iss,ssid,'\t');
                getline(iss,sbid,'\t');

                if(!(ssid==sid && sbid==bid)){
                    updated_enteries.push_back(line);
                }
            }
            readf.close();

            ofstream writef("bothids.txt",ios::trunc);
            if(!writef.is_open()){
                cout<<"Unable to open bothids.txt to write "<<endl;
                return;
            }
            for(const auto &entry : updated_enteries){
                writef<<entry<<endl;
            }
            writef.close();
            cout<<"Updated the bothids.txt file "<<endl;
        }
        else if(!found){
            cout<<"Book not found in the library "<<endl;
        }
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
    bool isStudentRegistered(string id){
        string line;
        ifstream readf("students.txt");
        if (readf.is_open())
        {
            string line;
            while (getline(readf, line))
            {   
                istringstream iss(line);
                string sid;

                getline(iss, sid, '\t');
                if (sid == id)
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
    bool isBookThere(string id){
        string line;
        ifstream readf("books.txt");
        if (readf.is_open())
        {
            string line;
            while (getline(readf, line))
            {   
                istringstream iss(line);
                string sid;
                string name, email;

                getline(iss, sid, '\t');
                if (sid == id)
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
    bool displayBorrowedBooks(string stu_id)
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
        return chk;
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
            writef << id << "\t" << tit << "\t" << auth << "\t" << publish << "\t" << isava << "\n";
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

    string id;
    cout<<"Enter you ID: ";
    cin>>id;
    Student temp;

    if(temp.isStudentRegistered(id)){
    
    if(id=="123"){

        Library admin;
        char chr;

        bool flag=1;

        while(flag){
            cout<<"What do you want?\n";
            cout<<"For add book, enter A \n";    
            cout<<"For add student, enter B \n";    
            cout<<"For search the book by id, enter C \n";    
            cout<<"For display all books, enter D \n";
            cout<<"For display all students, enter E \n";
            // cout<<"For doing student things, enter S\n";
            cout<<"For close the menu, enter Z\n";
            cin>>chr;
            if(chr=='Z'){
                break;
            }
            
            string tit, auth, publish, id, studentId, name, email, bid;
            bool isava;

            switch (chr)
            {
            case 'A':
            // addbook(string tit, string auth, string publish, string id, bool isava)
                while(1){

                    int check;

                    cout<<"For continue with add book enter 1, for go to previouse menu enter 2: ";
                    cin>>check;
                    while((check!=1)&&(check!=2)){
                        cout<<"Please enter 1 or 2 only for add book or go to previouse menu respectively: ";
                        cin>>check;
                    }
                    if(check==2){
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

                    cout<<"Enter title of the book: ";
                    cin.ignore();
                    getline(cin, tit);

                    cout<<"Enter author of the book: ";
                    getline(cin, auth);

                    cout<<"Enter publisher name of the book: ";
                    getline(cin, publish);


                    admin.addbook(tit, auth, publish, id, 1);
                }
                break;
            
            case 'B':
                // addstudent(string studentId, string name, string email)
                
                while(1){

                    int check;

                    cout<<"For continue with add student enter 1, for go to previouse menu enter 2: ";
                    cin>>check;
                    while((check!=1)&&(check!=2)){
                        cout<<"Please enter 1 or 2 only for add student or go to previouse menu respectively: ";
                        cin>>check;
                    }
                    if(check==2){
                        break;
                    }


                    while(1){
                        cout<<"Enter student Id: ";
                        cin>>studentId;
                        if(admin.isStudentRegistered(studentId)){
                            cout<<"This student id is registered for another student, please enter other student id!"<<endl;
                        }
                        else{
                            break;
                        }
                    }

                    cout<<"Enter name of the student: ";
                    cin.ignore();
                    getline(cin, name);

                    cout<<"Enter email of the student: ";
                    cin>>email;

                    admin.addstudent(studentId, name, email);
                }
                    break;
            
            case 'C':

                while(1){

                    int check;

                    cout<<"For continue with search the book, enter 1, for go to previouse menu enter 2: ";
                    cin>>check;
                    while((check!=1)&&(check!=2)){
                        cout<<"Please enter 1 or 2 only for search the book or go to previouse menu respectively: ";
                        cin>>check;
                    }
                    if(check==2){
                        break;
                    }

                    cout<<"Enter id of the book: ";
                    cin>>bid;
                    admin.searchbook(bid);
                }
                    break;
            
            case 'D':

                int check;

                cout<<"For continue with display all books, enter 1; for go to previouse menu enter 2: ";
                cin>>check;
                while((check!=1)&&(check!=2)){
                    cout<<"Please enter 1 or 2 only for display all books or go to previouse menu respectively: ";
                    cin>>check;
                }

                if(check==2){
                    break;
                }
                admin.dis_book();                
                break;
            
            case 'E':

                cout<<"For continue with display all books, enter 1; for go to previouse menu enter 2: ";
                cin>>check;
                while((check!=1)&&(check!=2)){
                    cout<<"Please enter 1 or 2 only for display all books or go to previouse menu respectively: ";
                    cin>>check;
                }
                if(check==2){
                    break;
                }

                admin.dis_student();                
                break;

            // case 'S':

            //     bool stdchr;
            //     break;

            default:
                cout<<"You have to enter only 'A', 'B', 'C', 'D', 'E', or 'Z' only for respective it's works!";
                break;
            }
        }
    }
    else{

        Student student;
        char chr;

        bool flag=1;

        while(flag){
            cout<<"What do you want?\n";
            cout<<"For borrow the book, enter A \n";    
            cout<<"For return the book, enter B \n";
            cout<<"For close the menu, enter Z\n";
            cin>>chr;
            if(chr=='Z'){
                break;
            }
            
            string bid;

            switch (chr)
            {
            case 'A':
                while(1){

                    int check;

                    cout<<"For continue with borrow the book enter 1, for go to previouse menu enter 2: ";
                    cin>>check;
                    while((check!=1)&&(check!=2)){
                        cout<<"Please enter 1 or 2 only for borrow the book or go to previouse menu respectively: ";
                        cin>>check;
                    }
                    if(check==2){
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

                    student.displayBorrowedBooks(id);
                }
                break;

            case 'B':
            // addbook(string tit, string auth, string publish, string id, bool isava)
                while(1){

                    int check;

                    cout<<"For continue with return the book enter 1, for go to previouse menu enter 2: ";
                    cin>>check;
                    while((check!=1)&&(check!=2)){
                        cout<<"Please enter 1 or 2 only for return the book or go to previouse menu respectively: ";
                        cin>>check;
                    }
                    if(check==2){
                        break;
                    }

                    if(student.displayBorrowedBooks(id)){
                        cout<<"Your borrowed books:\n";
                        student.displayBorrowedBooks(id);
                        cout<<"Enter id of the book: ";
                        cin>>bid;
                        student.returnBook(bid, id);
                    }
                    else{
                        cout<<"You have not borrowed any book!"<<endl;
                        break;
                    }
                }
                break;
            

            default:
                cout<<"You have to enter only 'A', 'B', or 'Z' only for respective it's works!";
                break;
            }
        }
    }

    }
    else{
        cout<<"Please enter valid id!";
    }


    return 0;
}