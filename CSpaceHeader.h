#pragma once
using namespace std;
class CSpace 
{
private:
	int mTypeNumber = 0;
	string mTypeName = "";
	int mMotivationalCost = 0;
	int mSuccessScore = 0;
	int mYear = 1;
public:
	//CSpace(int typeNumber = 0, string typeName = "");
	CSpace(int typeNumber , string typeName , int motivationalCost, int successScore , int year);
	int GetTypeNumber();
	string GetTypeName();
	int GetMotivationalCost();
	int GetSuccessScore();
	int GetYear();

	void SetTypeNumber(int typeNumber);
	void SetTypeName(string typeName);
	void SetMotivationalCost(int motivationalCost);
	void SetSuccessScore(int successScore );
	void SetYear(int year);

	virtual ~CSpace() {};
	virtual void print();
	
};
