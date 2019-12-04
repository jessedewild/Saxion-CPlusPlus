#include <iostream>

using namespace std;

int readNumber() {
    int input;
    cin >> input;
    return input;
}

bool writeResponse(int number, int guess) {
    if (guess < number) {
        cout << "Your guess is too low." << endl;
        return false;
    } else if (guess > number) {
        cout << "Your guess is too high." << endl;
        return false;
    } else {
        cout << "Correct! You win!" << endl;
        return true;
    }
}