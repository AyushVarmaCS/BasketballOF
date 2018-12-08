#pragma once
using namespace std;
#include <string>
class Basketball {
	
public:
	int round = 1;
	int last_round = 9;
	//int next_round = round + 1;
	int score = 0;
	string current_round;
	void makeShot();
	void StartContact();
	void EndContact();
	int getScore();
	int getRound();
	float getTime();

	bool hoop_contact = false;

};