#include <random> // for std::mt19937
#include <ctime>
#include <iostream>
#include "../headers/io/io.h"

using namespace std;

// Initialize our mersenne twister with a random seed based on the clock
mt19937 mersenne(static_cast<unsigned int>(time(nullptr)));
// Create a reusable random number generator
uniform_int_distribution<> generator(1, 100);

int randomNumber() {
    return generator(mersenne);
}

int main() {
    bool quit = false;
    while (!quit) {
        cout << "Let's play a game. I'm thinking of a number.\n"
                "You have 7 tries to guess what it is." << endl;
        int number = randomNumber();
        int attempts = 7;

        int round = 0;
        bool stop = false;
        while (!stop) {
            round++;

            cout << "Guess #" << round << ": ";
            int guess = readNumber();
            bool right = writeResponse(number, guess);

            if (round == attempts) {
                cout << "Sorry, you lose. The correct number was " << number << endl;
                stop = true;
            } else if (right) {
                stop = true;
            }
        }

        bool play = false;
        while (!play) {
            char input;
            cout << "Would you like to play again (y/n)? ";
            cin >> input;

            if (input == 'y') {
                play = true;
            } else if (input == 'n') {
                cout << "Thank you for playing.";
                play = true;
                quit = true;
            }
        }
    }
    return 0;
}