/*
Name: Eduardo Salazar, 5005695833 ,Section 1003, Assignment 5
Description: fill a box with chocolates and then eat them
Input: seed to randomize chocolates
Output: removal of the chocolates
*/
#include <iostream> //preprocessor directive
#include <cstdlib>
#include <string>
using namespace std;

class Chocolate //base class
{
    public: 
    virtual string whatAmI() = 0; //virtual function
};

class Dark : public Chocolate //derived dark chocolate class
{
    public:
    void feelBitter(){ //output function
        cout << "Dark Chocolate: oof that was bitter!" << endl;
    }
    string whatAmI(){ //virtual function
        return "Dark"; //return dark
    }
};

class Milk : public Chocolate //derived milk chocolate class
{
    public:
    void feelSoft(){ //output function
        cout << "Milk Chocolate: Too soft, no chocolate taste!" << endl;
    }
    string whatAmI(){ //virtual function
        return "Milk"; //return milk
    }
};

class Hazelnut : public Chocolate //derived hazelnut chocolate class
{
    public:
    void getAllergy(){ //output function
        cout << "Hazelnut Chocolate: I don't feel so good." << endl;
    }
    string whatAmI(){ //virtual function
        return "Hazelnut"; //return hazelnut
    }
};

class Raspberry : public Chocolate //derived raspberry chocolate class
{
    public:
    void tellJoke(){ //output function
        cout << "Raspberry Chocolate: I don't always Raspberry,";
        cout << " but when I do, I Raspberry Pi" << endl;
    }
    string whatAmI(){ //virtual function
        return "Raspberry"; //return raspberry
    }
};

class White : public Chocolate //derived white chocolate class
{
    public:
    void feelScammed(){ //output function
        cout << "White Chocolate: Is this even real chocolate?" << endl;
    }
    string whatAmI(){ //virtual function
        return "White"; //return white
    }
};

class Mint : public Chocolate //derived mint chocolate class
{
    public:
    void feelInquisitive(){ //output function
        cout << "Mint Chocolate: Am I still eating chocolate";
        cout << " or am I brushing my teeth?" << endl;
    }
    string whatAmI(){ //virtual function
        return "Mint"; //return mint
    }
};

class boxOfChocolates //box of chocolates class
{
    int boxLength; //stores box length
    int boxWidth; //stores box width
    Chocolate*** box; //declares 2d array that respresents the box

    public:

    boxOfChocolates(int length = 6, int width = 5){ //constructor
        boxLength = length; //sets length of box
        boxWidth = width; //sets width of box

        box = new Chocolate**[boxLength]; //allocates the box
        for(int i = 0; i < boxLength; i++){
            box[i] = new Chocolate*[boxWidth];
        }
        fillBox(); //calls fillbox function
    }
    ~boxOfChocolates(){ //destructor
        for(int i = 0; i < boxLength; i++){
            for(int j = 0; j < boxWidth; j++){
                delete box[i][j];
            }
            delete[] box[i];
        }
        delete[] box; //deletes box
        box = NULL; //sets to null
    }
    void fillBox(){ //fill box function
        for(int i = 0; i < boxLength; i++){
            for(int j = 0; j < boxWidth; j++){
                switch (rand() % 6) //gets random number
                {
                case 0:
                    box[i][j] = new Dark; //adds dark chocolate
                    break;
                case 1:
                    box[i][j] = new Milk; //adds milk chocolate
                    break;
                case 2:
                    box[i][j] = new Hazelnut; //adds hazelnut chocolate
                    break;
                case 3:
                    box[i][j] = new Raspberry; //adds raspberry chocolate
                    break;
                case 4:
                    box[i][j] = new White; //adds white chocolate
                    break;
                case 5:
                    box[i][j] = new Mint; //adds mint chocolate
                    break;
                default:
                    break;
                }
            }
        }
    }
    bool takeChocolate(){
        string type;
        int randOne = rand() % boxLength; //gets random number for length
        int randTwo = rand() % boxWidth; //gets random number for width
        
        if(box[randOne][randTwo] != nullptr){ //location is not null
            type = box[randOne][randTwo]->whatAmI(); //calls whatami
        }
        else{
            return false; //return false
        }

        if(type == "Dark"){
            dynamic_cast<Dark*>(box[randOne][randTwo])->feelBitter();
            //calls feel bitter function
            delete dynamic_cast<Dark*>(box[randOne][randTwo]);
            //deletes chocolate
            box[randOne][randTwo] = nullptr; //sets to null
        }
        else if(type == "Milk"){
            dynamic_cast<Milk*>(box[randOne][randTwo])->feelSoft();
            //calls feel soft function
            delete dynamic_cast<Milk*>(box[randOne][randTwo]);
            //deletes chocolate
            box[randOne][randTwo] = nullptr; //sets to null
        }
        else if(type == "Hazelnut"){
            dynamic_cast<Hazelnut*>(box[randOne][randTwo])->getAllergy();
            //calls get allergy function
            delete dynamic_cast<Hazelnut*>(box[randOne][randTwo]);
            //deletes object
            box[randOne][randTwo] = nullptr; //sets to null
        }
        else if(type == "Raspberry"){
            dynamic_cast<Raspberry*>(box[randOne][randTwo])->tellJoke();
            //calls tell joke function
            delete dynamic_cast<Raspberry*>(box[randOne][randTwo]);
            //deletes object
            box[randOne][randTwo] = nullptr; //sets to null
        }
        else if(type == "White"){
            dynamic_cast<White*>(box[randOne][randTwo])->feelScammed();
            //calls feel scammed function
            delete dynamic_cast<White*>(box[randOne][randTwo]);
            //deletes object
            box[randOne][randTwo] = nullptr; //sets to null
        }
        else if(type == "Mint"){
            dynamic_cast<Mint*>(box[randOne][randTwo])->feelInquisitive();
            //calls feel inquisitive function
            delete dynamic_cast<Mint*>(box[randOne][randTwo]);
            //deletes object
            box[randOne][randTwo] = nullptr; //sets to null
        }
        return true; //returns true
    }
};

int main(int argc, char *argv[]) //command line arguments
{
    if(argc != 2){ //if 2 arguments are not passed
        cout << "Enter Seed as Argument: " << endl;
        return 1; //return
    }

    srand(stoi(string(argv[1]))); //sets seed

    cout << "\"My mom always said life was like a box of chocolates.";
    cout << " You never know what you're gonna get.\"";
    cout << " - Forrest Gump" << endl;

    boxOfChocolates box; //declares box object

    bool test; //break loop variable
    do{
        test = box.takeChocolate(); //calls take chocolate function
    }
    while(test == true); //loop while true

    return 0; //return
}