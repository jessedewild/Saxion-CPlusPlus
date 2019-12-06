#ifndef SAXION_CPLUSPLUS_BLACKJACK_H
#define SAXION_CPLUSPLUS_BLACKJACK_H

/**
 * Blackjack class
 */
class Blackjack {
private:
    std::vector<Card> deck;

public:
    std::vector<Card> &getDeck() {
        return deck;
    }
};

/**
 * It takes the deck as a const reference parameter and prints the values in the deck.
 *
 * @param deck &vector<Card>
 */
void printDeck(const std::vector<Card> &deck);

/**
 * It shuffles the deck of cards.
 *
 * @param deck &vector<Card>
 */
void shuffleDeck(std::vector<Card> &deck);

/**
 * Get player's choice to hit or stand.
 *
 * @return char
 */
char getPlayerChoice() {
    std::cout << "(h) to hit, or (s) to stand: ";
    char choice;
    do {
        std::cin >> choice;
    } while (choice != 'h' && choice != 's');

    return choice;
}

/**
 * Play Blackjack.
 * @param deck vector<Card>
 */
void play(const std::vector<Card> deck);

#endif //SAXION_CPLUSPLUS_BLACKJACK_H
