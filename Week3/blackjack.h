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
    */
    bool play() {
        cout << "Blackjack is starting!" << endl;

        int card = 0;

        int playerTotal = 0;
        int dealerTotal = 0;

        // Dealer retrieves one card
        dealerTotal += deck.getCard(card++).getValue();
        cout << "The dealer is showing: " << dealerTotal << '\n';

        // Player retrieves two cards
        playerTotal += deck.getCard(card++).getValue();
        playerTotal += deck.getCard(card++).getValue();

        while (true) {
            cout << "You have: " << playerTotal << '\n';

            // See if the player has busted
            if (playerTotal > 21)
                return false;

            char choice = getPlayerChoice();

            if (choice == 's')
                break;

            playerTotal += deck.getCard(card++).getValue();
        }

        // If player hasn't busted, dealer goes until he has at least 17 points
        while (dealerTotal < 17) {
            dealerTotal += deck.getCard(card++).getValue();
            cout << "The dealer now has: " << dealerTotal << '\n';
        }

        // If dealer busted, player wins
        if (dealerTotal > 21)
            return true;

        return (playerTotal > dealerTotal);
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
