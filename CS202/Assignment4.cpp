/*
Name: Eduardo Salazar, 5005695833 ,Section 1003, Assignment 4
Description: display a grid of a game
Input: troops for the game
Output: visual grid for the game
*/
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

//valgring command : valgrind --leak-check=full ./a.out
//Superclass, keeps track of name 
class ent_t {
  public:
    ent_t(string n = "None") : id(ent_cnt++) {
        //My Code
        setName(n);
		//Just needs to initialize the name and id. 
		//I recommend getting the address of n and storing that
		//Count is automatically incremented above
    }
    ~ent_t(){
        //my code
        delete name;
        /*Deallocate the name*/
        } //Destructor
    ent_t(const ent_t &old){ //Copy Constructor
        name = new string(*old.name);
        //Your Code Here (copy constructor code here)
		//For the name, make sure to make a deep copy; don't set directly
        id = ent_cnt++; //don't copy old id, just keep increasing it.
    }
    //Your code here for void setName and string getName
    void setName(string n){
        name = new string(n);
    }
    string getName(){
        return name;
    }
    int getID() const {return id;}
  protected:
    string *name;
    int id;
    static int ent_cnt;
};
int ent_t::ent_cnt = 0; //initialize static

class infantrySquad_t : public ent_t {
  public:
    infantrySquad_t(string name = "Infantry Squad") : ent_t(name){
    //Your code here for constructor, call ent_t and pass name.  Use default "Infantry Squad"
    }
};

class armorSquad_t : public ent_t {
  public:
    armorSquad_t(string name = "Armor Squad") : ent_t(name) {
		//Armor aqud constructor. You can use this as a reference for the infantry squad constructor
    }
};

class artillerySquad_t : public ent_t {
  public:
    artillerySquad_t(string name = "Artillery Squad") : ent_t(name) {

    }
};

//Class to represent each point on the map and what it holds. Can hold up to 1 armor and artillery squad,
//but can also hold a variable amount of infantry squads (dynamic array)
class point_t {
  public:
    point_t(int x = 0, int y = 0) : arm(NULL), art(NULL), inf(NULL), x(x), y(y) {}
    ~point_t() { //Cleanup all the pointers. also de-allocate the inf array
        delete arm;
        arm = nullptr;
        delete art;
        art = nullptr;
        int i = 0;
        while(inf[i] != NULL){
            delete inf[i];
            i++;
        }
        delete[] inf;
        //Your Code Here
    }
    void print(){
        cout << "Point (" << x << ", " << y << ") contains:\n";
        if(arm != NULL){
            cout << arm << endl;
            //Your Code Here for couting using getName() in art
        }
        if(art != NULL){
            cout << art << endl;
        }
        //Your code here, same for art.
        if(inf != NULL){
            while(inf[i] != NULL){
                cout << inf[i] << endl;
                i++
            }
            //Your Code Here
            //loop to print the array. The inf array MUST be null terminated or this breaks!
        }
    }
    char getChar(){
        if(arm == NULL && art == NULL && inf == NULL){
            return '0';
        }
        else if(arm == 0 && art == 0 && inf == 0){
            return '0';
        }
        else if(arm == 0 && art == 0 && inf == 1){
            return 'I';
        }
        else if(arm == 0 && art == 1 && inf == 0){
            return 'A';
        }
        else if(arm == 0 && art == 1 && inf == 1){
            return 'D';
        }
        else if(arm == 1 && art == 0 && inf == 0){
            return 'T';
        }
        else if(arm == 1 && art == 0 && inf == 1){
            return 'C';
        }
        else if(arm == 1 && art == 1 && inf == 0){
            return 'B';
        }
        else if(arm == 1 && art == 1 && inf == 1){
            return '!';
        }
        //Your Code here, add the rest of the characters
		//Based on the table from the rubric
    }
    string getInfantryCount(){
        if(inf == NULL) return "  ";
        int count = 0;

        while(inf[count] != NULL){
            count++;
        }
        //Your Code Here
		//Start at the beginning of the infantry array and iterate until you hit a null,
		//signifying the end. Count as you iterate.
        return to_string(count);
    }
    armorSquad_t*     arm; //Pointer to a single armor squad unit, if it's at this point
    artillerySquad_t* art; //Pointer to a single artillery squad unit, if it's at this point
    infantrySquad_t**   inf; //Pointer to an array of any number of infantry squad units
    int x; //X position in the big array
    int y; //Y position in the big array
};


//Holds map, adds and removes entities
class map_t {
  public:
    map_t(int x = 10, int y = 9) : x(x), y(y) {
        //Your Code Here DO THIS FIRST
        point** = new point_t*[y];
        for(int i = 0; i < x; i++){
            point* = new point_t[x];
        }
		//Allocate the 2D array. Rememember that the convention is y before x
		//X and y here are set for you with the x(x) and y(y) syntax
        loadData();
    }
    ~map_t(){ //cleanup
        //Your Code Here DO THIS SECOND
        int i = 0;
        while(point[i] != NULL){
            delete point[i];
            i++
        }
        delete[] point;
		//Deallocate the 2D array.

    }
    void draw();
    void attackMove(point_t* origin, point_t* dest){
        
        //Your Code Here
    }
    //Fires at a point, destroys everything there.
    void fireAt(point_t *origin, point_t *target){
        //Your Code Here
    }
    void addInfantry(point_t* location, int amount,
                     const string &n = "501st Infantry Squad "){ //add + 1 for the null spot
        if(location->inf == NULL){
            //Your Code Here
        }
        else{ //deep copy practice
            //Your Code Here  

        }
    }
    point_t** point;
  private:
    void loadData();
    int x;
    int y;
};

void map_t::draw(){
    cout << getchar() << point_t::getInfantryCount() << endl;
    //Your Code Here
	//Go through the 2D array and print each char. Use the getChar function to help
    cout << endl;
}

void map_t::loadData(){
    cout << "The First Order is the best order..." << endl;
}

//----- Main function. This is fine as is -----
int main(int argc, char *argv[]) {
    map_t *Crait = new map_t;
    //The First Order
    Crait->addInfantry(&Crait->point[2][8], 13, "Stormtrooper Squads");
    Crait->addInfantry(&Crait->point[2][6], 22, "Stormtrooper Squads");
    Crait->point[1][7].arm = new armorSquad_t("AT-ATs");
    Crait->point[1][5].arm = new armorSquad_t("AT-ATs");
    Crait->point[8][6].arm = new armorSquad_t("AT-ATs");
    Crait->addInfantry(&Crait->point[8][6], 11, "Stormtrooper Squads");
    Crait->point[4][8].art = new artillerySquad_t("AT-MA");
    Crait->point[6][8].art = new artillerySquad_t("AT-MA");
    Crait->point[6][8].arm = new armorSquad_t("AT-ATs");
    Crait->addInfantry(&Crait->point[6][8], 11, "Kylo Ren's Private Army");
    Crait->addInfantry(&Crait->point[7][8], 33, "Stormtrooper Squads");
    Crait->point[7][8].art = new artillerySquad_t("AT-MA");
    Crait->addInfantry(&Crait->point[8][6], 14, "Stormtrooper Squads"); //MOAARRR
    //The Resitance
    Crait->point[6][2].art = new artillerySquad_t();
    Crait->point[6][2].arm = new armorSquad_t();
    Crait->point[4][2].arm = new armorSquad_t("Speeders");
    Crait->addInfantry(&Crait->point[5][3], 22, "The Resistance");
    Crait->point[1][4].arm = new armorSquad_t("Speeders");
    Crait->point[2][3].art = new artillerySquad_t("Damaged Artillery");
    Crait->point[2][3].arm = new armorSquad_t("Some rusty tanks acting as decoys");
    Crait->addInfantry(&Crait->point[2][3], 12, "Decoy Resistance Soldiers");
    Crait->draw();
    //The Action!
    Crait->attackMove(&Crait->point[2][4], &Crait->point[1][5]);
    Crait->attackMove(&Crait->point[1][4], &Crait->point[1][5]);
    Crait->fireAt(&Crait->point[4][8], &Crait->point[2][3]);
    Crait->draw();
    delete Crait; //lol
    return 0;
}
