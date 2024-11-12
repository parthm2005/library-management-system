
```markdown
# 📚 Library Management System (LMS)

## 👥 Team Members

- **Nevil Vataliya** ([nevil213](https://github.com/nevil213)) - U23CS158
- **Prankit Vishwakarma** ([prank-vish](https://github.com/prank-vish)) - U23CS113
- **Parth Modi** ([parthm2005](https://github.com/parthm2005)) - U23CS107

## 📝 Problem Statement

The Library Management System (LMS) helps manage books, students, and transactions within a library. Developed with Object-Oriented Programming (OOP) principles, the system is split into two main panels:

### 🔐 Admin Panel
- 🆕 **Add Student**: Add a new student to the system.
- ❌ **Remove Student**: Remove an existing student from the system.
- 🆕 **Add Book**: Add new books to the library.
- ❌ **Remove Book**: Remove books from the library collection.
- 👥 **Display Students**: View a list of all students.
- 📚 **Display Books**: View a list of all books.
- 🔍 **Search Available Books**: Find books available for borrowing.

### 🧑‍🎓 Student Panel
- 📖 **Borrow Book**: Borrow a book if available.
- ↩️ **Return Book**: Return borrowed books.
- 📋 **Display Borrowed Books**: View a list of all borrowed books.

## 💡 C++/OOP Concepts Used

This system is built using several OOP concepts, including:

- **👨‍👩‍👦 Inheritance**: Classes like `Book`, `Student`, and `Library` inherit common properties and methods.
- **⚙️ Polymorphism**:
  - 🖋️ **Operator Overloading**: Overloaded operators (`<<`, `>>`) for input/output operations, such as displaying book details.
  - 📋 **Function Overloading**: Functions like `menu()` handle different arguments (e.g., ID,password).
  - 🛠️ **Function Overriding**: Specific functionalities for `to_string()` and `to_string()`.
- **💾 File Handling**: Records are saved in external files (e.g., `students.txt`, `books.txt`) for data persistence.
- **🖥️ Formatted Output**: Used `setw()` and other stream manipulators for neat output formatting.
- **🔒 Password Security**: Password-protected admin login.
- **📧 Email Validation**: Ensures email addresses follow a valid format.

## 🏗️ Program Structure

The system is organized into these main components:

- **📕 Book Class**: Stores book details such as ISBN, title, author, publisher, and status (available/borrowed).
- **🧑‍🎓 Student Class**: Manages borrowing and returning books.
- **🏛️ Library Class**: Handles adding/removing books and students, displaying books/students, and searching available books.

## 🚀 Installation

To run the Library Management System locally, follow these steps:

1. **📥 Clone the Repository**:
   ```bash
   git clone https://github.com/parthm2005/librrrrrrrrrrrrary.git
   cd librrrrrrrrrrrrary
   ```

2. **⚙️ Compile the Code**:
   Use a C++ compiler, like `g++`:
   ```bash
   g++ -o lms p.cpp
   ```

3. **▶️ Run the Program**:
   After compiling, run the executable:
   ```bash
   ./lms
   ```

## 📖 Usage

When you start the program, you’ll be prompted to log in as either an admin or a student:

- **🔐 Admin Login**: Use the admin panel for managing students and books.
- **👤 Student Login**: Access the student panel for borrowing and returning books.

### Example Operations:
- **🆕 Add a Book**: Admin enters details like ISBN, title, and author to add a book.
- **📖 Borrow a Book**: Students can search and borrow a book if it's available.

## 🌟 Features

- **Admin Features**:
  - 🆕 Add/Remove books and students
  - 🔍 Search for available books
  - 📋 Display student and book lists

- **Student Features**:
  - 📖 Borrow and return books
  - 📑 View borrowed books list

## 🤝 Contributing

Contributions are welcome! To contribute:

1. **Fork the repository**.
2. **Create a new branch** for your feature (`git checkout -b feature-name`).
3. **Commit your changes** (`git commit -m 'Add new feature'`).
4. **Push to the branch** (`git push origin feature-name`).
5. **Open a pull request**.

## 🙏 Credits

- **Nevil Vataliya**: Core functionality for admin and student panels.
- **Prankit Vishwakarma**: File handling and email validation features.
- **Parth Modi**: Integrated OOP concepts and book management.

## 📬 Contact

For any questions or feedback, feel free to open an issue or contact us!

---
