#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){

}

//--------------------------------------------------------------
void ofApp::update(){

}

//--------------------------------------------------------------
void ofApp::draw(){
	
	//Background
	ofSetBackgroundColor(0,0,0);


	//Basketball
	
	ofSetColor(255, 165, 0);
	ofDrawCircle(100, 500, 25);
	ofSetCircleResolution(100);
	ofFill();


	//Backboard
	ofSetColor(255, 255, 255);
	ofDrawRectangle(650, 50, 300, 200);

	//Sqaure
	ofSetColor(255, 0, 0);
	ofDrawRectangle(775, 125, 50, 50);
	ofSetColor(255, 255, 255);
	ofFill();

	//Smaller square
	ofSetColor(255, 255, 255);
	ofDrawRectangle(785, 135, 30, 30);




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
