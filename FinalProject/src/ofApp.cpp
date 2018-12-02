


#include "ofApp.h"
using namespace std;

//--------------------------------------------------------------
void ofApp::setup(){

	baketball_world.set(500,500,500,500);
	//basketball.load("C:\\Users\\ayush1\\Desktop\\basketballimage.jpg");
	//hoop.load("C:\\Users\\ayush1\\Desktop\\hoop.png");

	box2d.init();
	box2d.setGravity(0, 0);
	box2d.createBounds();
	box2d.registerGrabbing();
	
	
	auto basketball = std::make_shared<ofxBox2dCircle>();
	basketball.get()->setPhysics(1, 0.5, 1); //density, bounce, friction
	basketball.get()->setup(box2d.getWorld(), ofGetWindowWidth()/6, ofGetWindowHeight()/2, 20); //world(gui), x, y, radius
	circles.push_back(basketball);

	auto rectangle = std::make_shared < ofxBox2dRect>();
	//rectangle.get()->setPhysics(1, 0.5, 1);
	rectangle.get()->setup(box2d.getWorld(), 20, 400, 225, 20); //world(gui), x, y, radius
	rectangles.push_back(rectangle);


	
}

//--------------------------------------------------------------
void ofApp::update(){


	box2d.update();

	if (basketball_game_.getRound() == basketball_game_.last_round) {
		current_state = GAME_OVER;
	}
	if (basketball_game_.getTime() == kTimeLimit && basketball_game_.getRound()+1!= basketball_game_.last_round){ //&& next round != 9
		current_state = NEXT_ROUND;
		//round++;
	} 

}

//--------------------------------------------------------------
void ofApp::draw(){

	/*baketball_world.inside(ofGetMouseX(), ofGetMouseY()) ? ofSetColor(80) : ofSetColor(100);
	ofFill();
	ofDrawRectangle(baketball_world);*/

	ofFill();
	ofSetColor(225, 165, 0);
	for (auto x : circles) {
		//ofFill();
		x.get()->draw();
	}
	for (auto x : rectangles) {
		ofSetColor(0, 0, 0);
		x.get()->draw();
	}
	ofSetColor(0, 0, 0);

	ofPoint center(500, 500);
	drawGravity(center, box2d.getGravity());
	


	//float len = MIN(200, gravity.length() * 10); // scale it up a bit

	//ofDrawRectangle(20, 400, 225, 20);

	


}

void ofApp::drawGravity(ofPoint p, ofPoint gravity)
{
	float angle = (atan2(gravity.y, gravity.x) * 180 / PI) - 90;
	float len = MIN(200, gravity.length() * 10); // scale it up a bit

	ofPushMatrix();
	ofTranslate(p.x, p.y);
	ofRotate(angle);
	ofDrawLine(0, 0, 0, len);
	ofDrawTriangle(0, len,
		-5, len - 10,
		5, len - 10);
	ofPopMatrix();
	//https://github.com/vanderlin/ofxBox2d/blob/master/example-TwoWorlds/src/ofApp.cpp
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
	int player_key = toupper(key);
	if (player_key == 'S') {
		//show score
	}


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
