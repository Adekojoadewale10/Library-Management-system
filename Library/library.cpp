                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                               // These are the header files that we need for the code.
// We need iostream for input and output, We also need string and vector.

#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <iomanip>

// The line below "using namespace std" statement makes
//it unnecessary to prefix the standard library functions with "std::".

using namespace std;

//title, author, and ISBN, and a constructor that initializes these variables. 
class Book {
    private:
        string title;
        string author;
        string ISBN;
    public:
        Book(string title, string author, string ISBN) {
            this->title = title;
            this->author = author;
            this->ISBN = ISBN;
        }

        string getTitle() {
            return this->title;
        }

        string getAuthor() {
            return this->author;
        }

        string getISBN() {
            return this->ISBN;
        }

};


//This Section has three member functions: addBook(), removeBook(), and displayBooks(), 
//which respectively add a new book to the library, remove a book and also display Newbook also.


class Library {
    private:
        vector<Book> books;
    public:
        void addBook(string title, string author, string ISBN) {
            Book newBook(title, author, ISBN);
            books.push_back(newBook);
        }

        void removeBook(string ISBN) {
            for (int i = 0; i < books.size(); i++) {
                if (books[i].getISBN() == ISBN) {
                    books.erase(books.begin() + i);
                    break;
                }
            }
        }

        void displayBooks() {
            if (books.size() == 0) {
                cout << "No books in library." << endl;
            } else {
                for (int i = 0; i < books.size(); i++) {
                    cout << "Title: " << books[i].getTitle() << endl;
                    cout << "Author: " << books[i].getAuthor() << endl;
                    cout << "ISBN: " << books[i].getISBN() << endl << endl;
                }
            }
        }
};
void intro();
int main() {
	intro();
    Library library;

    while (true) {
        cout << "Library Management System" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Remove Book" << endl;
        cout << "3. Display Books" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";

        int choice;
        cin >> choice;

        switch(choice) {
            case 1: {
                string title, author, ISBN;
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter author: ";
                getline(cin, author);
                cout << "Enter ISBN: ";
                getline(cin, ISBN);
                library.addBook(title, author, ISBN);
                cout << "Book added successfully." << endl << endl;
                break;
            }
            case 2: {
                string ISBN;
                cout << "Enter ISBN: ";
                cin.ignore();
                getline(cin, ISBN);
                library.removeBook(ISBN);
                cout << "Book removed successfully." << endl << endl;
                break;
            }
            case 3: {
                library.displayBooks();
                break;
            }
            case 4: {
                cout << "Exiting program." << endl;
                return 0;
            }
            default: {
                cout << "Invalid choice. Try again." << endl;
            }
        }
    }

    return 0;
}

        // Introduction section 
void intro(){
    cout << "\n\n\n\t     LIBRARY MANAGEMENT SYSTEM";
    cout << "\n\n\n\n\t     MADE BY:ADEKOJO ADEWALE";
    cout << "\n\n\n\n\t     MATRIC NO: H/CTE/22/0702";
    cout << "\n\n\n\n\t     SUPERVISOR : ENGR NZUBE";
    cout << "\n\n\n\n\t     SCHOOL : THE FEDERAL POLYTECHNIC ILARO";
    cin.get();
}
