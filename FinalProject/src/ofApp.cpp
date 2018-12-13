#include "ofApp.h"
using namespace std;
#include "ofxBox2dContactListener.h"


//--------------------------------------------------------------
void ofApp::setup() {

	//basketball_world.set(500,500,500,500);

	//basketball.load("C:\\Users\\ayush1\\Desktop\\basketballimage.jpg");
	//hoop.load("C:\\Users\\ayush1\\Desktop\\hoop.png");


	box2d.init();
	box2d.setGravity(0, 0);
	box2d.createBounds();
	box2d.registerGrabbing();

	hoop_box.init();

	box2d.setContactListener(&hoop_contact);
	
	ofSoundPlayer dribble;
//	dribble.
	


	



	auto basketball = std::make_shared<ofxBox2dCircle>();
	basketball.get()->setPhysics(1, 0.5, 1); //density, bounce, friction
	basketball.get()->setup(box2d.getWorld(), ofGetWindowWidth() / 6, ofGetWindowHeight() / 2, 20); //world(gui), x, y, radius
	//basketball.get()->body->SetType(b2_ballBody);
	circles.push_back(basketball);

	auto hoop = std::make_shared < ofxBox2dRect>();
	hoop.get()->setPhysics(0, 0, 0);
	hoop.get()->setup(box2d.getWorld(), 650, 400, 225, 225);  //world, x,y,w,h
	//hoop.get()->body->SetType(b2_hoopBody);
	rectangles.push_back(hoop);






}

//--------------------------------------------------------------
void ofApp::update() {


	box2d.update();
	//cout << "hoop score" << hoop_contact.score << endl;


	if (basketball_game_.getRound() == basketball_game_.last_round) {
		current_state = GAME_OVER;
	}
	if (basketball_game_.getTime() == kTimeLimit && basketball_game_.getRound() + 1 != basketball_game_.last_round) { //&& next round != 9
		current_state = NEXT_ROUND;
		//round++;
	}

	//implement timer and launcher as well
}

//--------------------------------------------------------------
void ofApp::draw() {

	/*baketball_world.inside(ofGetMouseX(), ofGetMouseY()) ? ofSetColor(80) : ofSetColor(100);
	ofFill();
	ofDrawRectangle(baketball_world);*/


	//	b2Contact::IsTouching

		//if collision then score++





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
	for (auto x : test1) {
		ofSetColor(0, 0, 0);
		x.get()->draw();
	}
	ofSetColor(0, 0, 0);

//	ofPoint center(500, 500);
	//drawGravity(center, box2d.getGravity());


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
