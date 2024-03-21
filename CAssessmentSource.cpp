#include <iostream>
#include "CAssessmentHeader.h";
using namespace std;


CAssessment::CAssessment(int typeNumber, string typeName, int motivationalCost, int successScore, int year)
	: CSpace(typeNumber, typeName, motivationalCost, successScore, year) {
	
}