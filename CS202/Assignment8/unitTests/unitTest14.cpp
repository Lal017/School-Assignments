#include "dataProcessing.h"
using namespace std;

int main(){
    cout << "Testing Operator[]" << endl;
    garbagePile fp;
    cout << fp << endl;
    fp.addItem("3");
    fp.addItem("f");
    fp.addItem("true");
    fp.addItem("The cat in the Hat");
    fp.addItem("3.14");
    fp[0]->printElement(cout);
    cout << endl;
    fp[1]->printElement(cout);
    cout << endl;
    fp[2]->printElement(cout);
    cout << endl;
    fp[3]->printElement(cout);
    cout << endl;
    fp[4]->printElement(cout);
    cout << endl;
    cout << "Done." << endl;
    return 0;
}