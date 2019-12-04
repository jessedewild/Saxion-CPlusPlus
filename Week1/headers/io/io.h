/**
 * A function that reads the number from standard input using cin (C++ basic i/o)
 * and returns an ‘int’.
 *
 * @return int
 */
int readNumber();

/**
 * A function that outputs hi/lo which indicates the user guessed the number too
 * high or low. The function should return a ‘bool’: true if the user guessed the right
 * number and false if the users guess was incorrect.
 *
 * @return bool
 */
bool writeResponse(int number, int guess);