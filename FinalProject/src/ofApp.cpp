#include "ofApp.h"
using namespace std;
#include "ofxBox2dContactListener.h"

auto basketball = std::make_shared<ofxBox2dCircle>();

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
	hoop.get()->setPhysics(100000, 0.0000001, 0.00000001);
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
	bool check = false;

	if (basketball_game_.getRound() == basketball_game_.last_round) {
		current_state = GAME_OVER;
	}
	if (basketball_game_.getTime() == kTimeLimit && basketball_game_.getRound() + 1 != basketball_game_.last_round) { //&& next round != 9
		current_state = NEXT_ROUND;
		//round++;
	}

	if (hoop_contact.bucket == true) {
		basketball.get()->setup(box2d.getWorld(), ofGetWindowWidth() / 6, ofGetWindowHeight() / 2, 20); //world(gui), x, y, radius

	}

	//if (hoop_contact.score == 5) {
		
//	}
	//basketball.get()->setup(box2d.getWorld(), ofGetWindowWidth() / 6, ofGetWindowHeight() / 2, 20); //world(gui), x, y, radius



}

//--------------------------------------------------------------
void ofApp::draw() {

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

	ofDrawBitmapString("Score: ", ofGetWindowWidth() / 10.0, ofGetWindowHeight() / 4.0);
	ofDrawBitmapString(hoop_contact.score, ofGetWindowWidth() / 10.0, ofGetWindowHeight() / 3.6);
	


//	ofPoint center(500, 500);
	//drawGravity(center, box2d.getGravity());
	//basketball.get()->setup(box2d.getWorld(), ofGetWindowWidth() / 6, ofGetWindowHeight() / 2, 20); //world(gui), x, y, radius

	
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
	int player_key = toupper(key);
	if (player_key == 'S') {
		//show score
	}


}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
	/*float maxGravity = 1000;
	float gx = ofMap(x, 0, 500, -maxGravity, maxGravity);
	float gy = ofMap(y, 0, ofGetHeight(), -maxGravity, maxGravity);
	box2d.setGravity(gx, gy);*/
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


void ofApp::BeginContact(b2Contact* contact) {
	/*b2Fixture ball = contact->GetFixtureA;
	b2Fixture hoop = contact->GetFixtureB;
	b2Body ball_body = ball.GetBody;
	b2Body hoop_body = hoop.GetBody;

	if (basketball_contact) {
		score++;
	}
*/

}

void EndContact(b2Contact* contact)
{ /* handle end event */
}

void PreSolve(b2Contact* contact, const b2Manifold* oldManifold)
{ /* handle pre-solve event */
}

void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse)
{ /* handle post-solve event */
}
