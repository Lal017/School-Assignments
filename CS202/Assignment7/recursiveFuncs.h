#include <iostream>
unsigned int integerPow(unsigned int num, unsigned int pow);
unsigned int countCharacter(char *str, char searchChar, unsigned int currentIndex, unsigned int strLength, bool left, bool right);
void popBalloons(char **grid, unsigned int currentHeight, unsigned int currentWidth, unsigned int height, unsigned int width, char balloon);
unsigned int countLettersInSentence(char **sentence, unsigned int currentWord, unsigned int currentLetter);
unsigned int alphaMerge(char *&destArray, unsigned int currentSize, const char *arr1, const char *arr2, unsigned int p1, unsigned int p2);