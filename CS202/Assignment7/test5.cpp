#include "recursiveFuncs.cpp"
#include <cstring>
#include <string.h> 
using namespace std;

void printTitle(const char *c){
    cout << "################################################" << endl
        << " - " << c << endl
        << "################################################" << endl;
}

int main(){
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