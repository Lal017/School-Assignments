#include "dataProcessing.h"
using namespace std;

int main(){
    /*************
     * Assignment operator
    *************/
    cout << "Allocating Data Elements..." << endl;
    dataElementBase *deb1 = new dataElement<int>(INT, 3);
    dataElementBase *deb2 = new dataElement<char>(CHAR, 'f');
    dataElementBase *deb3 = new dataElement<bool>(BOOL, true);
    dataElementBase *deb4 = new dataElement<string>(STRING, "Cat in the Hat");
    dataElementBase *deb5 = new dataElement<double>(DOUBLE, 3.14);
    cout << "Linking the elements" << endl;
    deb1->link(deb2);
    deb2->link(deb3);
    deb3->link(deb4);
    deb4->link(deb5);
    cout << "Assignment operator..." << endl;
    dataElementBase *trvsl = new dataElement<char>(CHAR, 'f');
    *trvsl = *deb1;
    cout << "Checking links" << endl;
    cout << trvsl->getNext() << endl;
    cout << trvsl->getPrev() << endl;
    cout << "Assignment operator..." << endl;
    *deb3 = *trvsl;
    cout << "Checking links" << endl;
    if(deb3->getPrev() == deb2){
        cout << "Still linked!" << endl;
    }
    if(deb3->getNext() == deb4){
        cout << "Still linked!" << endl;
    }
    cout << "Deallocating Elements" << endl;
    delete deb1;
    delete deb2;
    delete deb3;
    delete deb4;
    delete deb5;
    delete trvsl;
    cout << "Done." << endl;
    return 0;
}