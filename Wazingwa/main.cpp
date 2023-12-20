#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void login();
void registration();
void forgot();

int main() {
    int c;
    cout << "\t\t\t______________________________________________________________________________________________________________\n\n\n";
    cout << "\t\t\t             Welcome to Matrix Designs, I'm your Assistant, Johab Kabwe from Kasumbales Boader lol!!           \n\n";
    cout << "\t\t\t______________________                               MENU                                _____________________\n\n";
    cout << "                                                                \n\n";
    cout << "\t| Press 1 to LOGIN                        " << endl;
    cout << "\t| Press 2 to REGISTER                     " << endl;
    cout << "\t| Press 3 to RESET YOUR PASSWORD                       " << endl;
    cout << "\t| Press 4 to EXIT                        " << endl;
    cout << "\n\t\t\t Please enter your choice : ";
    cin >> c;
    cout << endl;

    switch (c) {
        case 1:
            login();
            break;
        case 2:
            registration();
            break;
        case 3:
            forgot();
            break;
        case 4:
            cout << "\t\t\t Thank You! @WazDev❁´◡`❁Copyright 2023\n\n";
            break;
        default:
            cout << "\t\t\t Please Select from the options given from the above \n" << endl;
            main();
    }
    return 0;
}

void login() {
    int count = 0;
    string userId, password, id, pass;
    cout << "\t\t\t Please enter your username and Password : " << endl;
    cout << "\t\t\t USERNAME ";
    cin >> userId;
    cout << "\t\t\t PASSWORD";
    cin >> password;

    ifstream input("records.txt");

    while (input >> id >> pass) {
        if (id == userId && pass == password) {
            count = 1;
            break;
        }
    }
    input.close();

    if (count == 1) {
        cout << userId << "\n Your login is Successful\n Thanks for logging in! \n";
    } else {
        cout << "\n LOGIN ERROR \n Please check your Username and Password\n";
    }
}

void registration() {
    string ruserId, rpassword;
    cout << "\t\t\t Enter the username : ";
    cin >> ruserId;
    cout << "\t\t\t Enter the Password : ";
    cin >> rpassword;

    ofstream f1("records.txt", ios::app);
    f1 << ruserId << ' ' << rpassword << endl;
    f1.close();

    cout << "\n\t\t\t Registration is Successful! \n";
}

void forgot() {
    int option;
    cout << "\t\t\t You forgot your Password? No worries \n";
    cout << "Press 1 to search your id by username " << endl;
    cout << "Press 2 to go back to the main menu " << endl;
    cout << "\t\t\t Enter your choice : ";
    cin >> option;

    switch (option) {
        case 1: {
            int count = 0;
            string suserId, sId, spass;
            cout << "\n\t\t\t Enter the username which you remembered :";
            cin >> suserId;

            ifstream f2("records.txt");
            while (f2 >> sId >> spass) {
                if (sId == suserId) {
                    count = 1;
                    break;
                }
            }
            f2.close();

            if (count == 1) {
                cout << "\n\n Your account is Found! : ";
                cout << "\n\n Your Password is : " << spass;
            } else {
                cout << "\n\t Sorry! Your account is not found \n";
            }
            break;
        }
        case 2:
            // No action needed here, returning will go back to main menu
            break;
        default:
            cout << "\t\t\t Wrong Choice ! Please try again " << endl;
            break;
    }
}
// Hello, this is Wazingwa's first C++ project
