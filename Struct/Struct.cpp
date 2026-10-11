#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Book {
    string name;
    string author;
    string vidavnitstvo;
    string genre;

    void print() {
        cout << "Book - " << endl;
        cout << "   Name - " << name << endl;
        cout << "   Author - " << author << endl;
        cout << "   Vidavnitstvo - " << vidavnitstvo << endl;
        cout << "   Genre - " << genre << endl;
    }
    void change() {
        cout << "New name - ";
        getline(cin, name);
        cout << "New author - ";
        getline(cin, author);
        cout << "New vidavnitstvo - ";
        getline(cin, vidavnitstvo);
        cout << "New genre - ";
        getline(cin, genre);
    }
};


int main()
{
    const int amount = 10;
    string auth;
    string name;
    int index;

    Book books[amount] = {
        {"Book 1", "Author 1", "Vidav 1", "Genre 1"},
        {"Book 2", "Author 2", "Vidav 2", "Genre 2"},
        {"Book 3", "Author 1", "Vidav 3", "Genre 3"},
        {"Book 4", "Author 3", "Vidav 3", "Genre 4"},
        {"Book 5", "Author 4", "Vidav 2", "Genre 5"},
        {"Book 6", "Author 5", "Vidav 1", "Genre 4"},
        {"Book 7", "Author 5", "Vidav 4", "Genre 2"},
        {"Book 8", "Author 2", "Vidav 5", "Genre 1"},
        {"Book 9", "Author 1", "Vidav 6", "Genre 3"},
        {"Book 10", "Author 6", "Vidav 15", "Genre 5"}
    };

    int choice = 1;
    cout << "----Menu----" << endl;
    cout << "1 - Change a book" << endl;
    cout << "2 - All books" << endl;
    cout << "3 - Search for a book by author " << endl;
    cout << "4 - Search for a book by name" << endl;
    cout << "5 - Sorting by book name" << endl;
    cout << "6 - Sorting by author" << endl;
    cout << "7 - Sorting by edition" << endl;
    cout << "Your choice: ";
    cin >> choice;
    switch (choice) {
        case 1: 
            cin.ignore();
            cout << "Choose a book to change (1-10): ";
            cin >> index;
            cin.ignore();
            if (index >= 1 && index <= amount) {
                books[index - 1].change();
            }
            break;
        case 2:
            cin.ignore();
            for (int i = 0; i < amount; i++) {
                cout << "Book - ";
                books[i].print();
            }
            break;
        case 3: 
            cin.ignore();
            cout << "Enter an author: ";
            getline(cin, auth);
            for (int i = 0; i < amount; i++) {
                if (books[i].author == auth) {
                    cout << "Book found at " << i + 1 << " place" << endl;
                    books[i].print();
                }
            }
            break;
        case 4:
            cin.ignore();
            cout << "Enter a name: ";
            getline(cin, name);
            for (int i = 0; i < amount; i++) {
                if (books[i].name == name) {
                    cout << "Book found at " << i + 1 << " place" << endl;
                    books[i].print();
                }
            }
            break;
        case 5: 
            cin.ignore();
            sort(books, books + amount, [](const Book& a, const Book& b) {return a.name < b.name; });
            cout << "Done" << endl;
            for (int i = 0; i < amount; i++) {
                cout << books[i].name << " ";
            }
            break;

        case 6:
            cin.ignore();
            sort(books, books + amount, [](const Book& a, const Book& b) {return a.author < b.author; });
            cout << "Done" << endl;
            for (int i = 0; i < amount; i++) {
                cout << books[i].name << " ";
            }
            break;
        case 7: 
            cin.ignore();
            sort(books, books + amount, [](const Book& a, const Book& b) {return a.vidavnitstvo < b.vidavnitstvo; });
            cout << "Done" << endl;
            for (int i = 0; i < amount; i++) {
                cout << books[i].name << " ";
            }
            break;
        default:
            cout << "Error" << endl;
            break;
    }
}
