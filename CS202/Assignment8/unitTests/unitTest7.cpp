#include "dataProcessing.h"
using namespace std;

int main(){
    /*************
     * getNewDataElement
    *************/
    cout << "Allocating Data Elements..." << endl;
    dataElementBase *deb1 = dataElementBase::getNewDataElement(INT, "3");
    dataElementBase *deb2 = dataElementBase::getNewDataElement(CHAR, "f");
    dataElementBase *deb3 = dataElementBase::getNewDataElement(BOOL, "true");
    dataElementBase *deb4 = dataElementBase::getNewDataElement(STRING, "Cat in the Hat");
    dataElementBase *deb5 = dataElementBase::getNewDataElement(DOUBLE, "3.14");
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