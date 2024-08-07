#include "recursiveFuncs.cpp"
using namespace std;

void printTitle(const char *c){
    cout << "################################################" << endl
        << " - " << c << endl
        << "################################################" << endl;
}


int main(){
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
    return 0;
}