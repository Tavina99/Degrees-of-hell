#include <iostream>
using namespace std;
#include "CSpaceHeader.h"
#include<memory>
CSpace::CSpace(int typeNumber = 0, string typeName = "", int motivationalCost = 0, int successScore = 0, int year = 0)
{
	mTypeNumber = typeNumber;
	mTypeName = typeName;
	mMotivationalCost = motivationalCost;
	mSuccessScore = successScore;
	mYear = year;
}

int CSpace::GetTypeNumber()
{ 
	return mTypeNumber; 
}
string CSpace:: GetTypeName() 
{
	return mTypeName; 
}
int CSpace:: GetMotivationalCost()
{
	return mMotivationalCost; 
}
int CSpace::GetSuccessScore() 
{ 
	return mSuccessScore;
}
int CSpace::GetYear()
{ 
	return mYear; 
}

void CSpace:: SetTypeNumber(int typeNumber = 0) 
{
	mTypeNumber = typeNumber; 
}
void CSpace:: SetTypeName(string typeName = "") 
{ 
	mTypeName = typeName; 
}
void CSpace:: SetMotivationalCost(int motivationalCost = 0) 
{ 
	mMotivationalCost = motivationalCost;
}
void CSpace:: SetSuccessScore(int successScore = 0) 
{ 
	mSuccessScore = successScore; 
}
void CSpace:: SetYear(int year = 0) 
{ 
	mYear = year; 
}

// Method to print CSpace data (for testing)
void CSpace:: print()  
{
	cout << "Type: " << mTypeNumber << ", Name: " << mTypeName << ", Motivational Cost: " << mMotivationalCost
		<< ", Success Score: " << mSuccessScore << ", Year: " << mYear << std::endl;
}