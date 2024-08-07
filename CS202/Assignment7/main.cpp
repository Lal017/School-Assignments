#include "recursiveFuncs.cpp"
#include <cstring>
#include <string.h> 
using namespace std;

void printGrid(char **g, unsigned int h, unsigned int w){
    cout << endl;
    for(unsigned int i = 0; i < w; i++){
        cout << "---";
    }
    cout << endl;
    for(unsigned int i = 0; i < h; i++){
        for(unsigned int j = 0; j < w; j++){
            cout << '[' << g[i][j] << ']';
        }
        cout << endl;
    }
    for(unsigned int i = 0; i < w; i++){
        cout << "---";
    }
    cout << endl;
}

void printTitle(const char *c){
    cout << "################################################" << endl
        << " - " << c << endl
        << "################################################" << endl;
}


int main(){
    /************************************
     * integerPow
    ************************************/
    printTitle("integerPow Test");
    cout << "2^3 : " << integerPow(2,3) << endl;
    cout << "2^2 : " << integerPow(2,2) << endl;
    cout << "2^1 : " << integerPow(2,1) << endl;
    cout << "2^0 : " << integerPow(2,0) << endl;
    cout << "10^4 : " << integerPow(10,4) << endl;
    cout << "3^3 : " << integerPow(3,3) << endl;
    cout << "7^4 : " << integerPow(7,4) << endl;

    /************************************
     * countChars
    ************************************/
    printTitle("countCharacter Test");
    const unsigned int length5 = 10;
    const unsigned int length6 = 5;
    const unsigned int length7 = 11;
    const unsigned int length8 = 1;

    char str5[length5 + 1] = {'1','2','3','4','5','5','4','3','2','1','\0'};
    char str6[length6 + 1] = {'p','a','t','t','y','\0'};
    char str7[length7 + 1] = {'m','i','s','s','i','s','s','i','p','p','i','\0'};
    char str8[length8 + 1] = {'E','\0'};

    const unsigned int testLen = 7;
    char test[testLen] = {'4', 't', 'i', 's', 'p', 'E', 'a'};
    for(unsigned int i = 0; i < testLen; i++){
        cout << str5 << " has " << countCharacter(str5,test[i],4,length5,true,true) << " '" << test[i] << "'s." << endl;
        cout << str6 << " has " << countCharacter(str6,test[i],2,length6,true,true) << " '" << test[i] << "'s." << endl;
        cout << str7 << " has " << countCharacter(str7,test[i],10,length7,true,true) << " '" << test[i] << "'s." << endl;
        cout << str8 << " has " << countCharacter(str8,test[i],0,length8,true,true) << " '" << test[i] << "'s." << endl;
    }

    /************************************
     * printGrid
    ************************************/
    printTitle("popBalloons Test");
    const unsigned int h1 = 5, w1 = 5;
    char pic1[h1][w1] = {
         {'B','B','B','Y','Y'}
        ,{'B','B','B','Y','Y'}
        ,{'R','R','B','R','R'}
        ,{'R','R','R','B','R'}
        ,{'R','R','R','R','R'}
    };

    const unsigned int h2 = 11, w2 = 7;
    char pic2[h2][w2] = {
         {'G','G','$','$','$','G','G'}
        ,{'G','G','$','G','$','G','G'}
        ,{'G','G','$','$','$','G','G'}
        ,{'G','G','G','$','G','G','G'}
        ,{'$','$','$','$','$','$','$'}
        ,{'G','G','G','$','G','G','G'}
        ,{'G','G','G','$','G','G','G'}
        ,{'G','G','$','$','$','G','G'}
        ,{'G','G','$','G','$','G','G'}
        ,{'G','G','$','G','$','G','G'}
        ,{'G','$','$','G','$','$','G'}
    };

    /*** PICTURE 1 ***/
    char **pic = new char*[h1];
    for(unsigned int i = 0; i < h1; i++){
        pic[i] = new char[w1];
        for(unsigned int j = 0; j < w1; j++){
            pic[i][j] = pic1[i][j];
        }
    }

    cout << endl;
    printGrid(pic,h1,w1);
    popBalloons(pic, 0, 0, h1, w1, 'B');
    printGrid(pic,h1,w1);
    cout << endl;

    for(unsigned int i = 0; i < h1; i++){
        delete[] pic[i];
    }
    delete[] pic;

    /*** PICTURE 2 ***/
    pic = new char*[h2];
    for(unsigned int i = 0; i < h2; i++){
        pic[i] = new char[w2];
        for(unsigned int j = 0; j < w2; j++){
            pic[i][j] = pic2[i][j];
        }
    }

    cout << endl;
    printGrid(pic,h2,w2);
    popBalloons(pic, 4, 6, h2, w2, '$');
    printGrid(pic,h2,w2);
    cout << endl;

    for(unsigned int i = 0; i < h2; i++){
        delete[] pic[i];
    }
    delete[] pic;

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


    /************************************
     * alphaMerge
    ************************************/
    printTitle("alphaMerge Test");
    string c1 = "aaaaaaaabc";
    string c2 = "bbbcd";

    char *arr1 = new char [c1.length()+1];
    strncpy (arr1, c1.c_str(), c1.length());

    char *arr2 = new char [c2.length()+1];
    strncpy (arr2, c2.c_str(), c2.length());

    arr1[c1.length()] = '\0';
    arr2[c2.length()] = '\0';

    cout << arr1 << ',' << arr2 << endl;

    char *result = nullptr;
    unsigned int size = alphaMerge(result, 0, arr1, arr2, 0, 0);
    cout << size << endl;
    for(unsigned int i = 0; i < size; i++){
        cout << result[i];
    }
    cout << endl;
    delete[] result;
    delete[] arr1;
    delete[] arr2;


    c1 = "aaaaaaaabcjjjjjjkkklmqrswx";
    c2 = "bbbbbbbbbbbcdeeefgggghinnnoptuvyz";

    arr1 = new char [c1.length()+1];
    strncpy (arr1, c1.c_str(), c1.length());

    arr2 = new char [c2.length()+1];
    strncpy (arr2, c2.c_str(), c2.length());
    
    arr1[c1.length()] = '\0';
    arr2[c2.length()] = '\0';

    cout << arr1 << ',' << arr2 << endl;

    result = nullptr;
    size = alphaMerge(result, 0, arr1, arr2, 0, 0);
    cout << size << endl;
    for(unsigned int i = 0; i < size; i++){
        cout << result[i];
    }
    cout << endl;
    delete[] result;
    delete[] arr1;
    delete[] arr2;  

    return 0;
}