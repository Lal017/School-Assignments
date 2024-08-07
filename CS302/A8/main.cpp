#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <list>
using namespace std;

bool saveAshley(string,int,unordered_map<string,list<string>>,unordered_map<string,int>,
    unordered_map<string,int>&,unordered_map<string,string>&);                                      // recursive function to find the "shortest" path

int main()
{
    unordered_map<string, list<string>> adjList;                                                    // holds the game map
    unordered_map<string, int> enemiesAtLocation;                                                   // stores the number of enemies at each location
    unordered_map<string, int> ammoAtLocation;                                                      // stores how much ammo you have left at each location
    unordered_map<string, string> predecessor;                                                      // stores a locations predecessor
    string from, to, location, file_name;
    int value;
    ifstream iFile;

    cout << endl << "LEON!!!" << endl << endl;
    cout << "Enter map file: ";
    cin >> file_name;
    cout << endl;

    iFile.open(file_name);

    while(!iFile.eof())
    {
        iFile >> from >> to;
        if(from == "")
            break;
        adjList[from].push_back(to);
        from.clear();
    }

    iFile.close();

    cout << "Enter enemies file: ";
    cin >> file_name;
    cout << endl;

    iFile.open(file_name);

    while(!iFile.eof())
    {
        iFile >> location >> value;
        enemiesAtLocation[location] = value;
    }

    saveAshley("Village",10,adjList,enemiesAtLocation,ammoAtLocation,predecessor);

    string curr = "Church";
    vector<string> output;
    while(curr != "Village")
    {
        output.push_back(curr);
        curr = predecessor[curr];
    }
    output.push_back(curr);

    cout << "I'm coming Ashley!" << endl;
    for(int i = output.size()-1; i >= 0; i--)
    {
        cout << output[i];
        if(i != 0)
            cout << " -> ";
    }
    
    cout << endl;

    return 0;
}

bool saveAshley(string leon, int ammo, unordered_map<string,list<string>> map, unordered_map<string,int> enemiesAtLocation,
    unordered_map<string,int>& ammoAtLocation, unordered_map<string,string>& predecessor)
{
    ammo -= enemiesAtLocation[leon];
    if(ammo < 0)
        return false;
    if(leon == "Church")
        return true;

    for(auto neighbor : map[leon])
    {
        if(ammoAtLocation[leon] <= ammo)
        {
            ammoAtLocation[leon] = ammo;
            if(saveAshley(neighbor,ammo,map,enemiesAtLocation,ammoAtLocation,predecessor) == true)
            {
                if(leon != "Church")
                    predecessor[neighbor] = leon;
                return true;
            }
        }
    }

    return false;
}