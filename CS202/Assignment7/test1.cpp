#include "recursiveFuncs.cpp"
using namespace std;

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
    return 0;
}