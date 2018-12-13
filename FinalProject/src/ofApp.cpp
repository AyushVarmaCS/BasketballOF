#include "ofApp.h"
using namespace std;
#include "ofxBox2dContactListener.h"

auto basketball = std::make_shared<ofxBox2dCircle>();
bool check = false;

//--------------------------------------------------------------
void ofApp::setup(){

	box2d.init();
	box2d.setGravity(0, 0);
	box2d.createBounds();
	box2d.registerGrabbing();

	hoop_box.init();

	box2d.setContactListener(&hoop_contact);
	
	basketball.get()->setPhysics(hoop_contact.ball_density, hoop_contact.ball_bounce, hoop_contact.ball_friction); //density, bounce, friction
	basketball.get()->setup(box2d.getWorld(), ofGetWindowWidth() / 6, ofGetWindowHeight() / 2, 20); //world(gui), x, y, radius
	circles.push_back(basketball);

	auto hoop = std::make_shared < ofxBox2dRect>();
	hoop.get()->setPhysics(100000000, 0.0000001, 0.00000001);
	hoop.get()->setup(box2d.getWorld(), 900, 400, 30, 30);  //world, x,y,w,h
	rectangles.push_back(hoop);

	auto hoop_blocker_one = std::make_shared < ofxBox2dRect > ();
	hoop_blocker_one.get()->setPhysics(0, 0, 0);
	hoop_blocker_one.get()->setup(box2d.getWorld(),750, 150, 50, 300);
	rectangles.push_back(hoop_blocker_one);

	auto hoop_blocker_two = std::make_shared < ofxBox2dRect >();
	hoop_blocker_two.get()->setPhysics(0, 0, 0);
	hoop_blocker_two.get()->setup(box2d.getWorld(), 750, 600, 50, 300);
	rectangles.push_back(hoop_blocker_two);
	


}

//--------------------------------------------------------------
void ofApp::update() {


	box2d.update();
	

	if (basketball_game_.getRound() == basketball_game_.last_round) {
		current_state = GAME_OVER;
	}
	if (basketball_game_.getTime() == kTimeLimit && basketball_game_.getRound() + 1 != basketball_game_.last_round) { //&& next round != 9
		current_state = NEXT_ROUND;
		//round++;
	}





}

//--------------------------------------------------------------
void ofApp::draw() {


	ofFill();
	ofSetColor(225, 165, 0);
	for (auto x : circles) {
		x.get()->draw();

	}
	for (auto x : rectangles) {
		ofSetColor(0, 0, 0);
		x.get()->draw();
	}
	ofSetColor(0, 0, 0);

	ofDrawBitmapString("Score: ", ofGetWindowWidth() / 10.0, ofGetWindowHeight() / 4.0);
	ofDrawBitmapString(hoop_contact.score, ofGetWindowWidth() / 10.0, ofGetWindowHeight() / 3.6);
	
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
	//github.com/vanderlin/ofxBox2d/blob/master/example-TwoWorlds/src/ofApp.cpp
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}



//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}


