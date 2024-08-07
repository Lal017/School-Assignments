#include "dataProcessing.h"
using namespace std;

int main(){
    cout << "Testing Copy Constructor and Assignment" << endl;
    garbagePile gp;
    cout << gp << endl;
    gp.addItem("3");
    gp.addItem("f");
    gp.addItem("true");
    gp.addItem("The cat in the Hat");
    gp.addItem("3.14");

    /* Testing Copy Constructor and assignment operator */
    garbagePile gp2;
    if(true){
        garbagePile gp3(gp);
        gp2 = gp3;
    }

    /* Print Unsorted Garbage */
    cout << "Printing the garbage pile:" << endl
        << "--------------------------" << endl;
    cout << gp2 << endl;

    cout << "Done." << endl;
    return 0;
}