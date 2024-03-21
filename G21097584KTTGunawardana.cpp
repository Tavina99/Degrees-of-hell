
#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <ctime>
#include "CSpaceHeader.h";
#include "CPlayerHeader.h";
#include "CAssessmentHeader.h";
#include "CGameHeader.h";
using namespace std;
int Random() {
    return static_cast<int>(static_cast<double>(rand()) / (RAND_MAX + 1) * 10.0f + 1);
}
int main()
{
    
    vector<CSpace*> spaces;//vector to store pointers to CSpace
    srand(48);
    ifstream file("degrees.txt"); 
    if (!file.is_open()) 
    {
        cout<< "Error opening file" << endl;
    }
    string line;

    while (getline(file, line)) 
    {
        istringstream iss(line);
        int typeNumber;
        int motivationalCost = 0;
        int successScore = 0;
        int year = 0;
        string typeName;
        string temp;
        bool readingName = true;

        // First read the typeNumber
        iss >> typeNumber;

        // Then read and construct the typeName and possibly integers
        while (iss >> temp) 
        {
            if (isdigit(temp[0]) && readingName) //check first charactor of temp is a digit & ensures reading  numbers only happens once, right after reading the complete typeName.
            {
                // Switch to reading numbers once we hit the first digit after typeName
                motivationalCost = stoi(temp); //stoi use to convert string to integer
                readingName = false; // No longer reading typeName parts
                if (!(iss >> successScore)) // Attempt to read successScore
                { 
                    break; 
                } 
                if (!(iss >> year))  // Attempt to read year
                {
                    break;
                }
            }
            else if (readingName) {
                
                /*This line appends the current token(temp) to the typeName string.If typeName is not empty,
                it prepends a space to temp before appending, ensuring words in typeName are properly spaced.
                This builds the typeName by concatenating all the string parts until a digit is encountered.*/
                typeName += (typeName.empty() ? "" : " ") + temp;
            }
        }
        if (typeNumber == 1 || typeNumber == 3) {
            iss >> motivationalCost >> successScore >> year;
        }

        // Create CAssessment objects for typeNumber 1, otherwise create CSpace objects
        if (typeNumber == 1) {
            spaces.push_back(new CAssessment(typeNumber, typeName, motivationalCost, successScore, year));
        }
        else {
            spaces.push_back(new CSpace(typeNumber, typeName, motivationalCost, successScore, year));
        }
    }
    cout << "Welcome to Scumbag College\n";
    for (int roundNumber = 1; roundNumber <= 20; roundNumber++) {
        cout << "round " << roundNumber << endl;

        // Simulate two players taking turns in each round
        for (int player = 1; player <= 2; ++player) {
            int spinResult = Random();
            cout << "Player " << player << " spins " << spinResult << std::endl;
            // Here, you would update the player's position based on spinResult
            // and handle the landing space's effects

        }
    }




    // For testing: Print all objects to verify and then clean up
    //for (const auto& space : spaces) {
    //    space->print();
    //}

    // Delete the created objects to avoid memory leaks
    for (auto& space : spaces) {
        delete space;
    }
    spaces.clear();

    CGame game;
    game.loadSpacesFromFile("degrees.txt");

    game.AddPlayer(CPlayer("Vyvyan", 1000, 0, 0));

}

