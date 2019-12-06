#ifndef SAXION_CPLUSPLUS_DECK_H
#define SAXION_CPLUSPLUS_DECK_H

#include <vector>
#include "cards.h"

using namespace std;

class Deck {
private:
    vector<Card> deck;
    int card = 0;

public:
    vector<Card> &getCards() {
        return deck;
    }

    Card back() {
        return deck[card];
    }

    void popBack() {
        card++;
    }
};

#endif //SAXION_CPLUSPLUS_DECK_H
