#include <iostream>
#include <vector>
#include <random>
#include <ctime>
#include "cards.h"
#include "blackjack.h"

using namespace std;

// Initialize our mersenne twister with a random seed based on the clock
std::mt19937 mersenne(static_cast<unsigned int>(time(nullptr)));

// Create a reusable random number generator
uniform_int_distribution<> generator(0, 51);

void initDeck(vector<Card> &deck) {
    for (int rank = 0; rank < 13; ++rank) {
        for (int suit = 0; suit < 4; ++suit) {
            deck.emplace_back(rank, suit);
        }
    }
}

void printCard(const Card &card) {
    // Ranks
    switch (card.getRank()) {
        case RANK_2:
            cout << '2';
            break;
        case RANK_3:
            cout << '3';
            break;
        case RANK_4:
            cout << '4';
            break;
        case RANK_5:
            cout << '5';
            break;
        case RANK_6:
            cout << '6';
            break;
        case RANK_7:
            cout << '7';
            break;
        case RANK_8:
            cout << '8';
            break;
        case RANK_9:
            cout << '9';
            break;
        case RANK_10:
            cout << 'T';
            break;
        case JACK:
            cout << 'J';
            break;
        case QUEEN:
            cout << 'Q';
            break;
        case KING:
            cout << 'K';
            break;
        case ACE:
            cout << 'A';
            break;
    }

    // Suits
    switch (card.getSuit()) {
        case CLUBS:
            cout << 'C';
            break;
        case DIAMONDS:
            cout << 'D';
            break;
        case HEARTS:
            cout << 'H';
            break;
        case SPADES:
            cout << 'S';
            break;
    }
}

void printDeck(const vector<Card> &deck) {
    cout << "Deck: ";
    for (const Card &card : deck) {
        printCard(card);
        cout << ' ';
    }
    cout << '\n';
}

void swapCard(Card &cardOne, Card &cardTwo) {
    Card temp = cardOne;
    cardOne = cardTwo;
    cardTwo = temp;
}

int randomNumber() {
    return generator(mersenne);
}

void shuffleDeck(vector<Card> &deck) {
    for (int cardOne = 0; cardOne < 52; ++cardOne) {
        int cardTwo = randomNumber();
        swapCard(deck[cardOne], deck[cardTwo]);
    }
}

bool playBlackjack(const vector<Card> &deck) {
    // Set up the initial game state
    const Card &card = &deck[0];

    int playerTotal = 0;
    int dealerTotal = 0;

    // Deal the dealer one card
    dealerTotal += getCardValue(*cardPtr++);
    std::cout << "The dealer is showing: " << dealerTotal << '\n';

    // Deal the player two cards
    playerTotal += getCardValue(*cardPtr++);
    playerTotal += getCardValue(*cardPtr++);

    // Player goes first
    while (true) // infinite loop (until we break or return)
    {
        std::cout << "You have: " << playerTotal << '\n';

        // See if the player has busted
        if (playerTotal > 21)
            return false;

        char choice = getPlayerChoice();
        if (choice == 's')
            break;

        playerTotal += get(*cardPtr++);
    }

    // If player hasn't busted, dealer goes until he has at least 17 points
    while (dealerTotal < 17) {
        dealerTotal += getCardValue(*cardPtr++);
        std::cout << "The dealer now has: " << dealerTotal << '\n';
    }

    // If dealer busted, player wins
    if (dealerTotal > 21)
        return true;

    return (playerTotal > dealerTotal);
}

int main() {
    // Create Blackjack
    Blackjack blackjack;

    // Initialize deck
    vector<Card> deck = blackjack.getDeck();
    initDeck(deck);

    // Print deck
    printDeck(deck);

    // Shuffle deck
    shuffleDeck(deck);

    // Print deck
    printDeck(deck);

    return 1;
}
