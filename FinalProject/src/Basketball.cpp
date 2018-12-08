#include <string>
#include "Basketball.h"
using namespace std;
#include "ofApp.h"
#include "ofxBox2d.h"




int Basketball::getScore(){
	return score;
}

int Basketball::getRound(){
	return round;
}

float Basketball::getTime(){
	clock_t start;
	float time;
	start = clock();
	time = (clock() - start) / (double)CLOCKS_PER_SEC;
	return time;

}

void Basketball::makeShot(){
	score++;
	string made_shot = "Nice shot!";
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(made_shot, ofGetWindowWidth() / 2, ofGetWindowHeight() / 3);
}

void Basketball::StartContact() {
	hoop_contact = true;
}

void Basketball::EndContact() {
	hoop_contact = false;
}



