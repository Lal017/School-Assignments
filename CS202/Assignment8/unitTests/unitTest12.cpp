#include "dataProcessing.h"
using namespace std;

int main(){
    cout << "Testing Extraction Operator." << endl;
    garbagePile fp;
    cout << fp << endl;
    cin >> fp;
    cin >> fp;
    cin >> fp;
    cin >> fp;
    cin >> fp;
    cout << fp << endl;
    cout << "Done." << endl;
    return 0;
}