#ifndef SAXION_CPLUSPLUS_DECK_H
#define SAXION_CPLUSPLUS_DECK_H

#include <vector>
#include "cards.h"

using namespace std;

class Deck {
private:
    vector<Card> deck;

public:
    vector<Card> &getCards() {
        return deck;
    }

    Card &getCard(const int pos) {
        return deck[pos];
    }
};
#endif //SAXION_CPLUSPLUS_DECK_H
