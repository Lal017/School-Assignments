#include "recursiveFuncs.cpp"
using namespace std;

void printTitle(const char *c){
    cout << "################################################" << endl
        << " - " << c << endl
        << "################################################" << endl;
}

int main(){
    /************************************
     * countLetters
    ************************************/
    printTitle("countLettersInSentence Test");
    const unsigned int w1L = 9, w2L = 2, w3L = 4;
    char word1[w1L + 1] = {'R','e','c','u','r','s','i','o','n','\0'};
    char word2[w2L + 1] = {'i','s','\0'};
    char word3[w3L + 1] = {'f','u','n','!','\0'};
    const unsigned int sen1Len = 3;

    char **sentence = new char*[sen1Len + 1]; 
    sentence[0] = (word1);
    sentence[1] = (word2);
    sentence[2] = (word3);
    sentence[3] = nullptr;

    cout << word1 << ' ' << word2 << ' ' << word3 << endl;

    cout << countLettersInSentence(sentence, 0, 0) << endl;

    delete[] sentence;
    sentence = nullptr;

    const unsigned int w4L = 3, w5L = 2, w6L = 5, w7L = 2, w8L = 7;
    char word4[w4L + 1] = {'B','u','t','\0'};
    char word5[w5L + 1] = {'m','y','\0'};
    char word6[w6L + 1] = {'b','r','a','i','n','\0'};
    char word7[w7L + 1] = {'i','s','\0'};
    char word8[w8L + 1] = {'h','u','r','t','i', 'n','g','\0'};
    const unsigned int sen2Len = 5;

    sentence = new char*[sen2Len + 1]; 
    sentence[0] = static_cast<char*>(word4);
    sentence[1] = static_cast<char*>(word5);
    sentence[2] = static_cast<char*>(word6);
    sentence[3] = static_cast<char*>(word7);
    sentence[4] = static_cast<char*>(word8);
    sentence[5] = nullptr;

    cout << word4 << ' ' << word5 << ' ' << word6 << ' ' << word7 << ' ' << word8 << endl;
    cout << countLettersInSentence(sentence, 0, 0) << endl;

    delete[] sentence;
    sentence = nullptr;

    return 0;
}