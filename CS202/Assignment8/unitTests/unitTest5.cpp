#include "dataProcessing.h"
using namespace std;

int main(){
    /*************
     * Getting DataTypes from string.
    *************/
    cout << "Checking string data types." << endl;
    cout << getDataType("3");
    cout << getDataType("f");
    cout << getDataType("true");
    cout << getDataType("Cat in the Hat");
    cout << getDataType("3.14");
    cout << "Done." << endl;
    return 0;
}