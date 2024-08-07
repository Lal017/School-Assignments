#include "dataProcessing.h"
using namespace std;

int main(){
    /*************
     * Getting the data types
    *************/
    cout << "Allocating Data Elements..." << endl;
    dataElementBase *deb1 = new dataElement<int>(INT, 3);
    dataElementBase *deb2 = new dataElement<char>(CHAR, 'f');
    dataElementBase *deb3 = new dataElement<bool>(BOOL, true);
    dataElementBase *deb4 = new dataElement<string>(STRING, "Cat in the Hat");
    dataElementBase *deb5 = new dataElement<double>(DOUBLE, 3.14);
    cout << "Getting the dataTypes" << endl;
    int x = deb1->getDataType();
    int w = deb2->getDataType();
    int y = deb3->getDataType();
    int z = deb4->getDataType();
    int g = deb5->getDataType();
    cout << "Printing the dataTypes." << endl;
    cout << x << " , " << w << " , " << y << " , " << z << " , " << g << endl; 
    cout << "Deallocating Elements" << endl;
    delete deb1;
    delete deb2;
    delete deb3;
    delete deb4;
    delete deb5;
    cout << "Done." << endl;
    return 0;
}