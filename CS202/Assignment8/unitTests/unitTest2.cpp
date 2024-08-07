#include "dataProcessing.h"
using namespace std;

int main(){
    /*************
     * Getting the data
    *************/
    cout << "Allocating Data Elements..." << endl;
    dataElementBase *deb1 = new dataElement<int>(INT, 3);
    dataElementBase *deb2 = new dataElement<char>(CHAR, 'f');
    dataElementBase *deb3 = new dataElement<bool>(BOOL, true);
    dataElementBase *deb4 = new dataElement<string>(STRING, "Cat in the Hat");
    dataElementBase *deb5 = new dataElement<double>(DOUBLE, 3.14);
    cout << "Getting the elements" << endl;
    int x = *(static_cast<int*>(deb1->getData()));
    char w = *(static_cast<char*>(deb2->getData()));
    bool y = *(static_cast<bool*>(deb3->getData()));
    string z = *(static_cast<string*>(deb4->getData()));
    double g = *(static_cast<double*>(deb5->getData()));
    cout << "Printing the elements." << endl;
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