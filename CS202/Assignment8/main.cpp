#include "dataProcessing.h"
#include <fstream>
using namespace std;

int main(int argc, char **argv){
    if(argc < 2){
        return 0;
    }

    garbagePile gp;

    for(int i = 1; i < argc; i++){
        ifstream in;
        in.open(string(argv[i]));
        while(true){
            if(in.eof()){
                break;
            }
            in >> gp;
        }
        in.close();
    }
    
    /* Testing Copy Constructor and assignment operator */
    garbagePile gp2;
    if(true){
        garbagePile gp3(gp);
        gp2 = gp;
    }

    /* Print Unsorted Garbage */
    cout << "Printing the garbage pile:" << endl
        << "--------------------------" << endl;
    cout << gp2 << endl;

    /* Sorting */
    cout << "*************" << endl
        <<  "*  Sorting  *" << endl
        << "*************" << endl;
    gp2.sort();

    /* Print sorted Garbage */
    cout << "Printing the garbage pile:" << endl
        << "--------------------------" << endl;
    cout << gp2 << endl;


    return 0;
}