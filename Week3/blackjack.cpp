#include <iostream>
#include <vector>
#include "src/cards.cpp"

using namespace std;


int main() {
    array<Card, 52> deck[];
    using index_t = array<Card, 52>::size_type;

    index_t card = 0;

    for (int suit = 0; suit < 4; ++suit) {
        for (int rank = 0; rank < 13; ++rank) {
            deck[card].suit = static_cast<CardSuit>(suit);
            deck[card].rank = static_cast<CardRank>(rank);
            ++card;
        }
    }

    return 0;
}