#include "dataProcessing.h"
using namespace std;

int main(){
    cout << "Testing Sort" << endl;
    garbagePile gp;
    cout << gp << endl;
    gp.addItem("3");
    gp.addItem("f");
    gp.addItem("true");
    gp.addItem("The cat in the Hat");
    gp.addItem("3.14");

    cout << gp << endl;
    gp.sort();
    cout << gp << endl;

    cout << "Done." << endl;
    return 0;
}