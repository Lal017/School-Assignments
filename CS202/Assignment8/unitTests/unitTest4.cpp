#include "dataProcessing.h"
using namespace std;

int main(){
    /*************
     * Linking elements
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
    cout << "Checking the links..." << endl;
    dataElementBase *trvsl = deb1;
    while(trvsl != nullptr){
        // PREVIOUS
        cout << "Previous Node: ";
        if(trvsl->getPrev() == nullptr){
            cout << "nullptr" << endl;
        }
        else{
            trvsl->getPrev()->printElement(cout);
            cout << endl;
        }
        // CURRENT
        cout << "Current Node: ";
        if(trvsl == nullptr){
            cout << "nullptr" << endl;
        }
        else{
            trvsl->printElement(cout);
            cout << endl;
        }
        // NEXT
        cout << "Next Node: ";
        if(trvsl->getNext() == nullptr){
            cout << "nullptr" << endl;
        }
        else{
            trvsl->getNext()->printElement(cout);
            cout << endl;
        }
        // TRAVERSE
        cout << "Moving along..." << endl;
        trvsl = trvsl->getNext();
    }
    cout << "Deallocating Elements" << endl;
    delete deb1;
    delete deb2;
    delete deb3;
    delete deb4;
    delete deb5;
    cout << "Done." << endl;
    return 0;
}