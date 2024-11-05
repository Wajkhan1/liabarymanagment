#include <iostream>
#include <fstream>
#include <ctime>
#include <cstring>
#include <string>
#include <vector>
#include <iomanip>
#include <conio.h>

using namespace std;  // This eliminates the need to prefix 'std::' to standard library components.

#define MAX_YR  9999
#define MIN_YR  1900
#define MAX_SIZE_USER_NAME 30
#define MAX_SIZE_PASSWORD  20

#define MAX_STUDENT_NAME 50
#define MAX_STUDENT_ADDRESS 300

class User {
public:
    string uname;
    string password;
};

class Borrower {
public:
    string name;
    string address;
    string phonenum;
    string id;
};

class Lib {
public:
    int acc_no;
    string book_title;
    string author;
    bool borrowed;
    unsigned int date[3], rdate[3];
    Borrower y;
};

class Bdonor {
public:
    string name;
    string title;
};

void gotoxy(int x, int y) {
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void loading(int N) {
    int i, j;
    gotoxy(25, 12);
    cout << "Loading....";
    gotoxy(23, 14);
    for (i = 1; i <= 15; i++) {
        for (j = 0; j <= N; j++);
        {
            cout << (char)219;
        }
    }
}

void login();
void signIn();
void signUp();
void admin();
void mainadminmenu();
void add_book();
void view_bookadmin();
void modify_book();
void deletebook();
void studentrequests();
void donations();
void funds_info();
void add_funds();
void student();
void mainstudentmenu();
void issue_book();
void donate_book();
void request();

void login() {
    system("cls");
    int choice;
    gotoxy(15, 3);
    for (int i = 0; i < 15; i++)
        cout << (char)219;
    gotoxy(15, 4);
    cout << (char)219 << (char)219 << " Main Menu " << (char)219 << (char)219;
    gotoxy(15, 5);
    for (int i = 0; i < 15; i++)
        cout << (char)219;
    gotoxy(9, 7);
    for (int i = 0; i < 27; i++)
        cout << (char)219;
    gotoxy(9, 8);
    cout << (char)219 << " 1 : Sign In             " << (char)219 << (char)219;
    gotoxy(9, 9);
    cout << (char)219 << " 2 : Sign Up             " << (char)219 << (char)219;
    gotoxy(9, 10);
    cout << (char)219 << " Any other key to exit  " << (char)219 << (char)219;
    gotoxy(9, 11);
    cout << (char)219 << "     Choose an option:   " << (char)219 << (char)219;
    gotoxy(9, 13);
    for (int i = 0; i < 27; i++)
        cout << (char)219;
    gotoxy(9, 12);
    cout << (char)219 << "                         " << (char)219 << (char)219;
    gotoxy(19, 12);
    cin >> choice;
    if (choice == 1)
        signIn();
    else if (choice == 2)
        signUp();
}

void signIn() {
    User user;
    User fileUser;
    cout << "\n\n\n\t\t\tEnter username: ";
    cin >> user.uname;
    cout << "\t\t\tEnter password: ";
    cin >> user.password;

    if (user.uname == "Farzaan" && user.password == "khan")
        admin();
    else {
        ifstream fp("students.txt", ios::binary);
        while (fp.read(reinterpret_cast<char*>(&fileUser), sizeof(User))) {
            if (user.uname == fileUser.uname && user.password == fileUser.password)
                student();
        }
        fp.close();
        cout << "\n\n\n\t\tUser doesn't exist. Create a new account to continue";
        getch();
        login();
    }
}

void signUp() {
    User u, f;
    cout << "\n\n\n\t\t\tEnter username: ";
    cin >> u.uname;
    cout << "\t\t\tEnter password: ";
    cin >> u.password;

    ofstream fp("students.txt", ios::app | ios::binary);
    ifstream infile("students.txt", ios::binary);
    while (infile.read(reinterpret_cast<char*>(&f), sizeof(User))) {
        if (u.uname == f.uname || u.uname == "Farzaan") {
            cout << "\n\t\t\tUser name already exists, choose a unique username\n";
            infile.close();
            signUp();
            return;
        }
    }

    fp.write(reinterpret_cast<char*>(&u), sizeof(User));
    infile.close();
    fp.close();
    cout << "\n\t\t\tSign Up successful!\n You can now login\n";
    login();
}

void admin() {
    system("cls");
    time_t t;
    time(&t);
    cout << "\n\t\t\t\t\t\t" << ctime(&t);
    gotoxy(15, 8);
    for (int i = 0; i < 18; i++)
        cout << (char)219;
    gotoxy(15, 9);
    cout << (char)219 << (char)219 << "Welcome Admin!" << (char)219 << (char)219;
    gotoxy(15, 10);
    for (int i = 0; i < 18; i++)
        cout << (char)219;
    loading(10000000);
    gotoxy(19, 15);
    cout << "Press any key to continue.";
    getch();
    mainadminmenu();
}

void mainadminmenu() {
    system("cls");
    int option;
    time_t t;
    time(&t);
    cout << "\n\t\t\t\t\t\t" << ctime(&t);
    int i;
    gotoxy(15, 3);
    for (i = 0; i < 16; i++)
        cout << (char)219;
    gotoxy(15, 4);
    cout << (char)219 << (char)219 << " Admin Menu " << (char)219 << (char)219;
    gotoxy(15, 5);
    for (i = 0; i < 16; i++)
        cout << (char)219;
    gotoxy(9, 7);
    for (i = 0; i < 27; i++)
        cout << (char)219;
    gotoxy(9, 8);
    cout << (char)219 << " 1 : Add Books           " << (char)219 << (char)219;
    gotoxy(9, 9);
    cout << (char)219 << " 2 : View Books          " << (char)219 << (char)219;
    gotoxy(9, 10);
    cout << (char)219 << " 3 : Delete Books        " << (char)219 << (char)219;
    gotoxy(9, 11);
    cout << (char)219 << " 4 : Students' Requests  " << (char)219 << (char)219;
    gotoxy(9, 12);
    cout << (char)219 << " 5 : Add Funds           " << (char)219 << (char)219;
    gotoxy(9, 13);
    cout << (char)219 << " 6 : Funds Info          " << (char)219 << (char)219;
    gotoxy(9, 14);
    cout << (char)219 << " 7 : Recent Donations    " << (char)219 << (char)219;
    gotoxy(9, 15);
    cout << (char)219 << " 8 : Sign Out            " << (char)219 << (char)219;
    gotoxy(9, 16);
    cout << (char)219 << " Any other key to exit  " << (char)219 << (char)219;
    gotoxy(9, 17);
    cout << (char)219 << " Choose an option: ";
    gotoxy(19, 17);
    cin >> option;
    if (option == 1)
        add_book();
    else if (option == 2)
        view_bookadmin();
    else if (option == 3)
        deletebook();
    else if (option == 4)
        studentrequests();
    else if (option == 5)
        add_funds();
    else if (option == 6)
        funds_info();
    else if (option == 7)
        donations();
    else if (option == 8)
        login();
}

void add_book() {
    // Placeholder function: Implement logic for adding a book
}

void view_bookadmin() {
    // Placeholder function: Implement logic for viewing books
}

// You can implement similar changes for other functions
