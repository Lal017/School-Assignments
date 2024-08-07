#include "dataProcessing.h"
using namespace std;

int main(){
    /*************
     * Printing elements
    *************/
    cout << "Allocating Data Elements..." << endl;
    dataElementBase *deb1 = new dataElement<int>(INT, 3);
    dataElementBase *deb2 = new dataElement<char>(CHAR, 'f');
    dataElementBase *deb3 = new dataElement<bool>(BOOL, true);
    dataElementBase *deb4 = new dataElement<string>(STRING, "Cat in the Hat");
    dataElementBase *deb5 = new dataElement<double>(DOUBLE, 3.14);
    cout << "Printing the elements" << endl;
    deb1->printElement(cout);
    cout << endl;
    deb2->printElement(cout);
    cout << endl;
    deb3->printElement(cout);
    cout << endl;
    deb4->printElement(cout);
    cout << endl;
    deb5->printElement(cout);
    cout << endl;
    cout << "Deallocating Elements" << endl;
    delete deb1;
    delete deb2;
    delete deb3;
    delete deb4;
    delete deb5;
    cout << "Done." << endl;
    return 0;
}