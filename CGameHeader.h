#pragma once
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <memory>
#include "CSpaceHeader.h"
#include "CAssessmentHeader.h"
#include "CPlayerHeader.h"
using namespace std;
//#include "CAssessment.h" // Include headers for derived classes as needed

class CGame {
public:
    vector<unique_ptr<CSpace>> spaces;
    vector<CPlayer> players;
    void AddSpace(std::unique_ptr<CSpace> space);
    void AddPlayer(CPlayer player);
    void loadSpacesFromFile(string filename);
    void PlayRound();
    
};
