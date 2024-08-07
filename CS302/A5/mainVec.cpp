// Name: Eduardo Salazar
// NSHE: 5005695833
// Assignment: 5
// Description: use a vector to spell check a text file.
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

void file_read(vector<string>&);                                        // inputs the contents of usa.txt into a vector
void suggestions(vector<string>, string);                               // generates the suggested words if a word is spelled incorrectly
bool check(vector<string>, string);                                     // function to check if word is in English dictionary vector
string upper(string);                                                   // used to convert string to all uppercase letters

int main()
{
    vector<string> Eng_Dic;                                             // vector that holds the contents of usa.txt
    string file_name;

    file_read(Eng_Dic);

    cout << "Enter filename: ";                                         // prompt to enter the file name
    cin >> file_name;
    cout << endl;

    ifstream iFile(file_name);                                          // open file input by user
    string word;

    while(!iFile.eof())                                                 // loop until the end of the file
    {
        iFile >> word;
        word = upper(word);                                             // convert word to all uppercase chars
        {
        if(check(Eng_Dic,word) != true)                                 // if current word was not in unordered map dictionary
            suggestions(Eng_Dic,word);
            Eng_Dic.push_back(word);                                    // add word to dictionary vector so it doesn't check word again
        }
    }

    return 0;
}

void suggestions(vector<string> Eng_Dic, string word)
{
    vector<string> suggestion;                                          // holds the suggested words that are valid;
    string split_1;
    string split_2;                                                     // temp variables to hold splits of strings
    string Full_String;
    string temp_1;                                                      // temp variables to hold strings.
    string temp_2;
    char letter;                                                        // holds the current letter to generate a word

    for(int i = 0; i < word.length(); i++)                              // iterates through each char in the word 
    {
        if(i > 0)
        {
            split_1 = word.substr(0,i);                                  // splits the string
            split_2 = word.substr(i,word.length());
        }
        for(int j = 0; j < 26; j++)                                     //iterates through size of alphabet
        {
            letter = j + 'A';
            if(i > 0)
            {
                Full_String = split_1 + letter + split_2;                      // concatenates string together
                if(check(Eng_Dic,Full_String) == true)
                    suggestion.push_back(Full_String);                       // add word to suggestion vector
            }

            if(i == 0)
            {
                temp_1 = letter + word;
                temp_2 = word + letter;

                if(check(Eng_Dic,temp_2) == true)                       // if concatenated string is in the unordered map dictionary
                    suggestion.push_back(temp_2);                       // add word to suggestion vector
                if(check(Eng_Dic,temp_1) == true)
                    suggestion.push_back(temp_1);
            }
            temp_1 = word;                
            temp_1[i] = letter;
            if(check(Eng_Dic,temp_1) == true)
                suggestion.push_back(temp_1);                           // add word to suggestion vector
        }
    }

    sort(suggestion.begin(),suggestion.end());

    cout << word << " is misspelled" << endl;                           // print out results
    cout << endl;
    if(suggestion.size() != 0)
    {
        cout << "Suggested words" << endl;
        for(int i = 0; i < suggestion.size(); i++)
            cout << suggestion[i] << endl;
    }
    else
        cout << "No suggestions" << endl;
    cout << endl;
}

bool check(vector<string> Eng_Dic, string word)
{
    for(int i = 0; i < Eng_Dic.size(); i++)
    {
        if(Eng_Dic[i] == word)
            return true;
    }
    return false;
}

void file_read(vector<string>& Eng_Dic)
{
    ifstream iFile("usa.txt");                                          // opens usa.txt file
    string word;

    while(!iFile.eof())                                                 // loop until end of file
    {
        iFile >> word;
        word = upper(word);                                             // convert to all uppercase letters
        Eng_Dic.push_back(word);                                        // store in vector
    }

    iFile.close();                                                      // close the file
}

string upper(string name)
{
    for(int i = 0; i < name.length(); i++)
        name[i] = toupper(name[i]);

    return name;
}