#ifndef SAXION_CPLUSPLUS_CARDS_H
#define SAXION_CPLUSPLUS_CARDS_H

/**
 * Card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace).
 */
enum CardRank {
    RANK_2,
    RANK_3,
    RANK_4,
    RANK_5,
    RANK_6,
    RANK_7,
    RANK_8,
    RANK_9,
    RANK_10,
    JACK,
    QUEEN,
    KING,
    ACE
};

/**
 * Card suits (clubs, diamonds, hearts, spades).
 */
enum CardSuit {
    CLUBS,
    DIAMONDS,
    HEARTS,
    SPADES
};

/**
 * A struct named Card that contains a rank and a suit.
 */
class Card {
private:
    CardRank rank;
    CardSuit suit;

public:
    Card(int rank, int suit) {
        this->rank = (CardRank) rank;
        this->suit = (CardSuit) suit;
    }

    CardRank getRank() const {
        return rank;
    }

    CardSuit getSuit() const {
        return suit;
    }

    int getValue() {
        switch (rank) {
            case RANK_2:
                return 2;
            case RANK_3:
                return 3;
            case RANK_4:
                return 4;
            case RANK_5:
                return 5;
            case RANK_6:
                return 6;
            case RANK_7:
                return 7;
            case RANK_8:
                return 8;
            case RANK_9:
                return 9;
            case RANK_10:
                return 10;
            case JACK:
                return 10;
            case QUEEN:
                return 10;
            case KING:
                return 10;
            case ACE:
                return 11;
        }
    }
};

/**
 * It takes a const Card reference as a parameter and prints the card rank and value as a 2-letter code
 * (e.g. the jack of spades would print as JS).
 *
 * @param card &Card
 */
void printCard(const Card &card);

/**
 * It takes two Cards and swaps their values.
 *
 * @param cardOne &Card
 * @param cardTwo &Card
 */
void swapCard(Card &cardOne, Card &cardTwo);

#endif //SAXION_CPLUSPLUS_CARDS_H
