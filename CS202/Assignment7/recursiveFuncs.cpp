#include "recursiveFuncs.h"
using namespace std;

// * integerPow
unsigned int integerPow(unsigned int num, unsigned int pow)
{
    if(pow == 1) //base case 1
        return num; //return number
    else if(pow == 0) //base case 2
        return 1; //return 1
    else
        return num*integerPow(num,pow-1); //recursion and reduction operation
}

// * countChars
unsigned int countCharacter(char *str, char searchChar, unsigned int currentIndex, unsigned int strLength, bool left, bool right)
{
    return 0;
}

// * popBalloons
void popBalloons(char **grid, unsigned int currentHeight, unsigned int currentWidth, unsigned int height, unsigned int width, char balloon)
{
    if(currentHeight < 0 || currentWidth < 0 || currentHeight >= height || currentWidth >= width) //base case
        return; //return nothing to skip function
    else if(grid[currentHeight][currentWidth] == balloon){ //if current index has balloon
        grid[currentHeight][currentWidth] = ' '; //replace with space
        popBalloons(grid,currentHeight-1,currentWidth,height,width,balloon); //check index under
        popBalloons(grid,currentHeight,currentWidth-1,height,width,balloon); //check index to left
        popBalloons(grid,currentHeight+1,currentWidth,height,width,balloon); //check index above
        popBalloons(grid,currentHeight,currentWidth+1,height,width,balloon); //check index to right
    }
}

// * countLettersInSentence
unsigned int countLettersInSentence(char **sentence, unsigned int currentWord, unsigned int currentLetter)
{
    if(sentence[currentWord] == nullptr) //base case
        return 0; //return 0
    else if(sentence[currentWord][currentLetter] == '\0') //if word reaches end
        return countLettersInSentence(sentence,currentWord+1,0); //reduction operation and recursion
    else
        return 1 + countLettersInSentence(sentence,currentWord,currentLetter+1); //reduction operation and recursion
}

// * alphaMerge
unsigned int alphaMerge(char *&destArray, unsigned int currentSize, const char *arr1, const char *arr2, unsigned int p1, unsigned int p2)
{
    return 0;
}
