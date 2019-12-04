/**
 * Card ranks (2, 3, 4, 5, 6, 7, 8, 9, 10, Jack, Queen, King, Ace).
 */
enum CardRank {
};

/**
 * Card suits (clubs, diamonds, hearts, spades).
 */
enum CardSuit {
};

/**
 * A struct named Card that contains a rank and a suit.
 */
struct Card {
};

/**
 * It takes a const Card reference as a parameter and prints the card rank and value as a 2-letter code
 * (e.g. the jack of spades would print as JS).
 *
 * @param card Card
 */
void printCard(const Card *card);