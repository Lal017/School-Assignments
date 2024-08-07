#include "dataProcessing.h"
using namespace std;

int main(){
    /*************
     * getNewDataElement
    *************/    
   cout << "Allocating Data Elements..." << endl;
    dataElementBase *debA = new dataElement<int>(INT, 3);
    dataElementBase *debB = new dataElement<char>(CHAR, 'f');
    dataElementBase *debC = new dataElement<bool>(BOOL, true);
    dataElementBase *debD = new dataElement<string>(STRING, "Cat in the Hat");
    dataElementBase *debE = new dataElement<double>(DOUBLE, 3.14);
    
    dataElementBase *deb1 = dataElementBase::deepCopyDataElement(debA);
    dataElementBase *deb2 = dataElementBase::deepCopyDataElement(debB);
    dataElementBase *deb3 = dataElementBase::deepCopyDataElement(debC);
    dataElementBase *deb4 = dataElementBase::deepCopyDataElement(debD);
    dataElementBase *deb5 = dataElementBase::deepCopyDataElement(debE);

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

    delete debA;
    delete debB;
    delete debC;
    delete debD;
    delete debE;
    cout << "Done." << endl;
    return 0;
}