#include <iostream>
using namespace std; 
#include"CGameHeader.h"

void CGame:: loadSpacesFromFile(string filename)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error opening file" << std::endl;
        return;
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
        // First reading the typeNumber
        iss >> typeNumber;
        // Then read and construct the typeName and possibly integers
        while (iss >> temp)
        {
            //check first charactor of temp is a digit & ensures reading  numbers only happens once, right after reading the complete typeName.
            if (isdigit(temp[0]) && readingName)
            {
                motivationalCost = stoi(temp);//stoi use to convert string to integer
                readingName = false;// No longer reading typeName parts
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

        if (typeNumber == 1) {
            spaces.push_back(make_unique<CAssessment>(typeNumber, typeName, motivationalCost, successScore, year));
        }
        else {
            // For simplicity, using CSpace for types other than 1; extend as needed
            spaces.push_back(make_unique<CSpace>(typeNumber, typeName, motivationalCost, successScore, year));
        }
    }
}