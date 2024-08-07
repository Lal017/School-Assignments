// Name: Eduardo Salazar
// NSHE: 5005695833
// Assignment: 7
// Description: use a priorityQ to simulate a video game leaderboard
#include <fstream>
#include <string>
#include <iomanip>
#include "priorityQ.h"

struct mercType
{
    int zombies;
    int spiders;
    int drainDeimos;
    int zombieDogs;
    int hunters;
    int nemesis;
    int civilians;

    mercType()                                  // sets all values to 0
    {
        zombies = 0;
        spiders = 0;
        drainDeimos = 0;
        zombieDogs = 0;
        hunters = 0;
        nemesis = 0;
        civilians = 0;
    }

    bool operator>(const mercType& rhs) const                                           // calculates scores and compares them both
    {
        double score1, score2;

        score1 = (zombies*1.0) + (spiders*1.1) + (drainDeimos*1.2) + (zombieDogs*1.3) + (hunters*
            1.4) + (nemesis*1.5) + (civilians*2.0);

        score2 = (rhs.zombies*1.0) + (rhs.spiders*1.1) + (rhs.drainDeimos*1.2) + (rhs.zombieDogs*1.3) + (rhs.hunters*
            1.4) + (rhs.nemesis*1.5) + (rhs.civilians*2.0);

        if(score1 > score2)
            return true;
        
        return false;
    }
    void operator+=(mercType rhs)                                                       // adds amount to already existing amount
    {
        zombies += rhs.zombies;
        spiders += rhs.spiders;
        drainDeimos += rhs.drainDeimos;
        zombieDogs += rhs.zombieDogs;
        hunters += rhs.hunters;
        nemesis += rhs.nemesis;
        civilians += rhs.civilians;
    }
};

int main()
{
    priorityQ<string, mercType> mercenaries;

    string merc_file, sim_file, name;

    cout << "Enter mercenaries file: ";
    cin >> merc_file;
    cout << endl;

    ifstream iFile(merc_file);

    while(!iFile.eof())                                                 // reads in names in file and initializes them into the PQ
    {
        getline(iFile,name);
        if(name.length() == 0)
            break;
        mercenaries.push_back(name, mercType());
    }
    iFile.close();

    cout << "Enter simulation file: ";
    cin >> sim_file;
    cout << endl;

    iFile.open(sim_file);
    double prev_score, new_score = 0;                                  // stores the two scores to compare
    string check = "", line, enemy;
    int amount;

    while(!iFile.eof())
    {
        mercType temp;
        prev_score = new_score;                                         // sets previous score

        getline(iFile,line);
        if(line.length() == 0)
            break;

        name = line.substr(0,line.find(" "));                           // seperates words in line
        line.erase(0,line.find(" ") + 1);
        enemy = line.substr(0,line.find(" "));
        line.erase(0,line.find(" ") + 1);
        amount = stoi(line);

        if(enemy == "zombies")
            temp.zombies = amount;
        else if(enemy == "spiders")
            temp.spiders = amount;
        else if(enemy == "drainDeimos")
            temp.drainDeimos = amount;
        else if(enemy == "zombieDogs")
            temp.zombieDogs = amount;
        else if(enemy == "hunters")
            temp.hunters = amount;
        else if(enemy == "nemesis")
            temp.nemesis = amount;
        else if(enemy == "civilians")
            temp.civilians = amount;

        mercenaries.increaseKey(name,temp);                                                                                 // shifts the priorityQ
        
        new_score = (mercenaries.get_front_priority().zombies*1.0) + (mercenaries.get_front_priority().spiders*
            1.1) + (mercenaries.get_front_priority().drainDeimos*1.2) + (mercenaries.get_front_priority().zombieDogs*
            1.3) + (mercenaries.get_front_priority().hunters*1.4) + (mercenaries.get_front_priority().nemesis*
            1.5) + (mercenaries.get_front_priority().civilians*2.0);                                                        // calculates the new score

        if(name != check && prev_score < new_score)
        {
            cout << fixed << setprecision(1);                                                                               // display decimal values
            cout << "We have a new leader: " << mercenaries.get_front_key() << " Score: " << new_score << endl << endl;
        }

        check = mercenaries.get_front_key();
    }

    iFile.close();

    int i = 1;
    while(mercenaries.isEmpty() != true)                                                                                    // outputs leaderboard
    {
        new_score = (mercenaries.get_front_priority().zombies*1.0) + (mercenaries.get_front_priority().spiders*
            1.1) + (mercenaries.get_front_priority().drainDeimos*1.2) + (mercenaries.get_front_priority().zombieDogs*
            1.3) + (mercenaries.get_front_priority().hunters*1.4) + (mercenaries.get_front_priority().nemesis*
            1.5) + (mercenaries.get_front_priority().civilians*2.0);

        cout << "Rank " << i << endl;
        cout << fixed << setprecision(1);
        cout << "Name: " << mercenaries.get_front_key() << " Score: " << new_score << endl << endl;
        mercenaries.pop_front();
        i++;
    }

    return 0;
}