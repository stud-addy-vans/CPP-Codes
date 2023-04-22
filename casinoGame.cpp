#include <cstdlib>

#include <iostream>

#include <math.h>

using namespace std;

int main() {

    bool game = true;
    int amount, number;
    cout << "Welcome to The Casino Game" << endl;
    cout << "Cost of Each Game: $7" << endl;
    cout << "Enter Your Bid(max $999): $";
    cin >> amount;

    if (amount < 7) {
        cout << "You Don't Have Enough Money" << endl;
        game = false;
    }

    while (amount > 999) {
        cout << "Excess Bid!" << endl;
        cout << "Enter Your Bid(max $999): $";
        cin >> amount;
    }

    while (game) {
        cout << "Enter Your Number: ";
        cin >> number;

        while (number > 999) {
            cout << "Invalid Number!" << endl;
            cout << "Enter Your Number: ";
            cin >> number;
        }

        srand((unsigned) time(NULL));

        int number_list[3];
        int m = 10;
        int i;

        for (i = 0; i < 3; i++) {
            number_list[i] = rand() % m;
        }

        cout << "Guessed Number: " << endl;
        cout << "__________________\n";
        cout << "|                |" << endl;
        cout << "|    $CASINO$    |" << endl;
        cout << "|________________|" << endl;
        cout << "|    ||    ||    |\n";

        for (i = 0; i < 3; i++) {
            cout << "|  " << number_list[i] << " |";
        }

        cout << "\n|____||____||____|\n";
        cout << "\n";

        int guessed_number = 0;
        int temp;

        for (i = 0; i < 3; i++) {
            temp = number_list[i] * (pow(10, 2 - i));
            guessed_number += temp;
        }

        if (number == guessed_number) {
            cout << "You Won" << endl;
            amount += 14;
        } else {
            cout << "You Lost" << endl;
            amount -= 7;
        }

        cout << "Your Current Balance: " << amount << endl;

        char user;
        cout << "Do You Want To Play Again? (Y/N): ";
        cin >> user;

        if (amount < 7) {
            cout << "OUT OF MONEY :(" << endl;
            game = false;
        }

        if (user == 'N'
            or user == 'n') {
            game = false;
            cout << "Money Refunded $";
            cout << amount << endl;
            cout << "Thank You For Playing" << endl;

        } else if (user == 'Y'
            or user == 'y') {} else {
            cout << "Invalid Input" << endl;
            cout << "Money Refunded $";
            cout << amount << endl;
            game = false;
        }
    }
    return 0;
}