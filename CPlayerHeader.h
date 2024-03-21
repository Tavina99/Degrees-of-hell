#pragma once
#include <iostream>;
using namespace std;

class CPlayer
{
private:
	string mName;
	int mMotivation = 1000;
	int mSuccess = 0;
	int mPosition = 1;
public:
	CPlayer(string name, int motivation = 1000, int success = 0, int position = 0) 
	{
		mName = name; 
		mMotivation = motivation;
		mSuccess = success;
		mPosition = position;

	}
		 
	string GetName();
	int GetMotivation();
	int GetSuccess();
	int GetPosition();
	void SetName(string name = "");
	void SetMotivation(int motivation = 0);
	void SetSuccess(int success = 0);
	void SetPosition(int position = 0);


};
