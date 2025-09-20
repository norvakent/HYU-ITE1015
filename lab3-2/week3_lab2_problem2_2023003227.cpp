#include <iostream>
#include <string>
using namespace std;

namespace LibrarySystem
{
    struct Book
    {
        const int id;
        string title;
        string author;
        int availableCopies;
        int totalCopies;
    };
    
    const int BOOK_COUNT = 5;

    Book books[] = {{1, "C++", "Stroustrup", 3, 3},
                    {2, "DataStruct", "Weiss", 2, 2},
                    {3, "Algorithms", "Sedgewick", 1, 1},
                    {4, "Networks", "Tanenbaum", 4, 4},
                    {5, "OS", "Stallings", 2, 2}};


    int findBook(int id)
    {
        return ((id < 1) || (id > 6)) ? -1 : --id;
    }

    int findBook(const string *title)
    {
        for (int i = 0; i < BOOK_COUNT; i++) {
            if (books[i].title == *title) return i;
        }
        return -1;
    }

    bool borrowBook(int id, int days = 7)
    {
        if (days > 7) {
            cout << "\nNote, Borrowing for more than 7 days requires special permission." << endl;
            return false;
        }
        int idx = findBook(id);
        if (idx == -1 || books[idx].availableCopies == 0) return false;
        books[idx].availableCopies--;
        return true;
    }

    bool borrowBook(const string *title, int days = 7)
    {
        if (days > 7) {
            cout << "\nNote, Borrowing for more than 7 days requires special permission." << endl;
            return false;
        }
        int idx = findBook(title);
        if (idx == -1 || books[idx].availableCopies == 0) return false;
        books[idx].availableCopies--;
        return true;
    }

    bool borrowBook(int id, const string *borrowerName, int days = 14)
    {
        if ((*borrowerName).size() == 0) {
            cout << "\nNote, Borrowing for more than 7 days requires special permission." << endl;
            return false;
        }
        int idx = findBook(id);
        if (idx == -1 || books[idx].availableCopies == 0) return false;
        books[idx].availableCopies--;
        return true;
    }

    bool returnBook(int id)
    {
        int idx = findBook(id);
        if (idx == -1 || books[idx].availableCopies >= books[idx].totalCopies) return false;
        books[idx].availableCopies++;
        return true;
    }

    bool returnBook(const string *title)
    {
        int idx = findBook(title);
        if (idx == -1 || books[idx].availableCopies >= books[idx].totalCopies) return false;
        books[idx].availableCopies++;
        return true;
    }

    void listAllBooks()
    {
        cout << "\n=== Book List ===\n";
        for (int i = 0; i < BOOK_COUNT; ++i)
        {
            cout << "ID=" << books[i].id << ", Title=" << books[i].title
                 << ", Author=" << books[i].author
                 << ", Available=" << books[i].availableCopies
                 << "/" << books[i].totalCopies << endl;
        }
        cout << "=================\n\n";
    }

} // namespace LibrarySystem


int main()
{
    cout << "Borrow book ID 3 (default): "
         << (LibrarySystem::borrowBook(3) ? "Success" : "Failed") << endl;

    cout << "Borrow book ID 3 (out of stock): "
        << (LibrarySystem::borrowBook(3) ? "Success" : "Failed") << endl;

    string title1 = "DataStruct";
    cout << "Borrow book title \"DataStruct\": "
         << (LibrarySystem::borrowBook(&title1) ? "Success" : "Failed") << endl;

    cout << "Borrow book ID 4 by anonymouns for 21 days: "
         << (LibrarySystem::borrowBook(4, 21) ? "Success" : "Failed") << endl;

    string borrower2 = "Bob";
    cout << "Borrow book ID 4 by \"Bob\" for 21 days: "
         << (LibrarySystem::borrowBook(4, &borrower2, 21) ? "Success" : "Failed") << endl;

    LibrarySystem::listAllBooks();

    cout << "Return book ID 3: "
         << (LibrarySystem::returnBook(3) ? "Success" : "Failed") << endl;

    LibrarySystem::listAllBooks();

    return 0;
}