#ifndef SAXION_CPLUSPLUS_BLACKJACK_H
#define SAXION_CPLUSPLUS_BLACKJACK_H

#include "deck.h"

using namespace std;

/**
 * Blackjack class
 */
class Blackjack {
private:
    Deck deck;

public:
    Deck &getDeck() {
        return deck;
    }

    /**
     * Get player's choice to hit or stand.
     *
     * @return char
     */
    char getPlayerChoice() {
        cout << "(h) to hit, or (s) to stand: ";
        char choice;
        do {
            cin >> choice;
        } while (choice != 'h' && choice != 's');

        return choice;
    }

    /**
     * Play Blackjack.
     *
     * @return int 0 = player, 1 = dealer, 2 = tie
     */
    int play() {
        cout << "Blackjack is starting!" << endl;

        int card = 0;
        int playerTotal = 0;
        int dealerTotal = 0;

        // The dealer gets one card to start
        dealerTotal += deck.getCard(card++).getValue();
        cout << "The dealer is showing: " << dealerTotal << '\n';

        // The player gets two cards to start
        playerTotal += deck.getCard(card++).getValue();
        playerTotal += deck.getCard(card++).getValue();

        // The player goes first.
        while (true) {
            cout << "You have: " << playerTotal << '\n';

            // See if the player has busted
            if (playerTotal > 21)
                return 1;

            char choice = getPlayerChoice();

            if (choice == 's')
                break;

            int picked = deck.getCard(card++).getValue();
            if (picked == 11) {
                if (playerTotal + picked > 21) {
                    playerTotal += 1;
                } else {
                    playerTotal += picked;
                }
            } else {
                playerTotal += picked;
            }
        }

        // The dealer repeatedly draws until they reach a score of 17 or more, at which point they stand
        while (dealerTotal < 17) {
            dealerTotal += deck.getCard(card++).getValue();
            cout << "The dealer now has: " << dealerTotal << '\n';
        }

        // If the dealer goes over a score of 21, they bust and the player wins immediately
        if (dealerTotal > 21)
            return 0;

        // If the player has a higher score than the dealer, the player wins
        // If the dealer has a higher score than the player, the dealer wins
        // Otherwise, it's a tie
        if (playerTotal > dealerTotal) {
            return 0;
        } else if (dealerTotal < playerTotal) {
            return 1;
        } else {
            return 2;
        }
    }
};

/**
 * It takes the deck as a const reference parameter and prints the values in the deck.
 *
 * @param deck &vector<Card>
 */
void printDeck(const vector<Card> &deck);

/**
 * It shuffles the deck of cards.
 *
 * @param deck &vector<Card>
 */
void shuffleDeck(vector<Card> &deck);

#endif //SAXION_CPLUSPLUS_BLACKJACK_H
