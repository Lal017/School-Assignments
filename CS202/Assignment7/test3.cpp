#include "recursiveFuncs.cpp"
using namespace std;

void printTitle(const char *c){
    cout << "################################################" << endl
        << " - " << c << endl
        << "################################################" << endl;
}

void printGrid(char **g, unsigned int h, unsigned int w){
    cout << endl;
    for(unsigned int i = 0; i < w; i++){
        cout << "---";
    }
    cout << endl;
    for(unsigned int i = 0; i < h; i++){
        for(unsigned int j = 0; j < w; j++){
            cout << '[' << g[i][j] << ']';
        }
        cout << endl;
    }
    for(unsigned int i = 0; i < w; i++){
        cout << "---";
    }
    cout << endl;
}

int main(){

    /************************************
     * popBalloons
    ************************************/
    printTitle("popBalloons Test");
    const unsigned int h1 = 5, w1 = 5;
    char pic1[h1][w1] = {
         {'B','B','B','Y','Y'}
        ,{'B','B','B','Y','Y'}
        ,{'R','R','B','R','R'}
        ,{'R','R','R','B','R'}
        ,{'R','R','R','R','R'}
    };

    const unsigned int h2 = 11, w2 = 7;
    char pic2[h2][w2] = {
         {'G','G','$','$','$','G','G'}
        ,{'G','G','$','G','$','G','G'}
        ,{'G','G','$','$','$','G','G'}
        ,{'G','G','G','$','G','G','G'}
        ,{'$','$','$','$','$','$','$'}
        ,{'G','G','G','$','G','G','G'}
        ,{'G','G','G','$','G','G','G'}
        ,{'G','G','$','$','$','G','G'}
        ,{'G','G','$','G','$','G','G'}
        ,{'G','G','$','G','$','G','G'}
        ,{'G','$','$','G','$','$','G'}
    };

    /*** PICTURE 1 ***/
    char **pic = new char*[h1];
    for(unsigned int i = 0; i < h1; i++){
        pic[i] = new char[w1];
        for(unsigned int j = 0; j < w1; j++){
            pic[i][j] = pic1[i][j];
        }
    }

    cout << endl;
    printGrid(pic,h1,w1);
    popBalloons(pic, 0, 0, h1, w1, 'B');
    printGrid(pic,h1,w1);
    cout << endl;

    for(unsigned int i = 0; i < h1; i++){
        delete[] pic[i];
    }
    delete[] pic;

    /*** PICTURE 2 ***/
    pic = new char*[h2];
    for(unsigned int i = 0; i < h2; i++){
        pic[i] = new char[w2];
        for(unsigned int j = 0; j < w2; j++){
            pic[i][j] = pic2[i][j];
        }
    }

    cout << endl;
    printGrid(pic,h2,w2);
    popBalloons(pic, 4, 6, h2, w2, '$');
    printGrid(pic,h2,w2);
    cout << endl;

    for(unsigned int i = 0; i < h2; i++){
        delete[] pic[i];
    }
    delete[] pic;

    return 0;

}