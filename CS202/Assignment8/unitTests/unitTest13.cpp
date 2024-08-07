#include "dataProcessing.h"
using namespace std;

int main(){
    cout << "Testing Clear Pile." << endl;
    garbagePile fp;
    cout << fp << endl;
    fp.addItem("3");
    fp.addItem("f");
    fp.addItem("true");
    fp.addItem("The cat in the Hat");
    fp.addItem("3.14");
    cout << fp << endl;
    fp.clearGarbagePile();
    cout << fp << endl;
    cout << "Done." << endl;
    return 0;
}