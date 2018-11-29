//physics working and ball

	////Background
	//ofSetBackgroundColor(0,0,0);

	////Basketball
	//ofSetColor(255, 165, 0);
	//ofDrawCircle(100, 500, 25);
	//ofSetCircleResolution(100);
	//ofFill();


	////Backboard
	//ofSetColor(255, 255, 255);
	//ofDrawRectangle(650, 50, 300, 200);

	////Sqaure
	//ofSetColor(255, 0, 0);
	//ofDrawRectangle(775, 125, 50, 50);
	//ofSetColor(255, 255, 255);
	//ofFill();

	////Smaller square
	//ofSetColor(255, 255, 255);
	//ofDrawRectangle(785, 135, 30, 30);

#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){
	basketball.load("C:\\Users\\ayush1\\Desktop\\basketballimage.jpg");
	hoop.load("C:\\Users\\ayush1\\Desktop\\hoop.png");
	
}

//--------------------------------------------------------------
void ofApp::update(){
	if (basketball_game_.getRound() == basketball_game_.last_round) {
		current_state = GAME_OVER;
	}
	if (basketball_game_.getTime() == 30 && basketball_game_.getRound()+1!= basketball_game_.last_round){ //&& next round != 9
		current_state = NEXT_ROUND;
		//round++;
	}

}

//--------------------------------------------------------------
void ofApp::draw(){


	basketball.draw(100, 100,100,100);
	hoop.draw(200, 200,100,100);
	gameGui.draw(); 
	



}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int player_key = toupper(key);


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
