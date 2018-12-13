#include "ofxBox2d.h"
#include "ofApp.h"
#include "Basketball.h"
#include "ofxBox2dContactListener.h"
using namespace std;


void ofxBox2dContactListener::BeginContact(b2Contact* contact) {
}

void ofxBox2dContactListener::EndContact(b2Contact * contact)
{
	dribble_flag = true;
	dribble.load("BBOUNCE+2.mp3");
	swish.setVolume(2);
	
	swish.load("Swish.mp3");
	b2Body* A = contact->GetFixtureA()->GetBody();
	b2Body* B = contact->GetFixtureB()->GetBody();
	cheers.load("cheerCS.mp3");
	if (((b2BodyType)(A->GetType()) == b2_dynamicBody) && ((b2BodyType)(B->GetType() == b2_dynamicBody))){ 
		score++;
		swish.play();
		bucket = true;
		cheers.play();
		
	}
	if ((((b2BodyType)(A->GetType()) == b2_dynamicBody) && ((b2BodyType)(B->GetType() == b2_staticBody))) 
		|| (b2BodyType)(A->GetType()) == b2_staticBody && ((b2BodyType)(B->GetType()) == b2_dynamicBody)){
		dribble.play();
		dribble_flag = false;
	}
	
}

void ofxBox2dContactListener::contactAdd(ofPoint p)
{
	std::cout << "Contact Add" << std::endl;
	
}

void ofxBox2dContactListener::contactRemove(ofPoint p)
{
	std::cout << "Remove Contact" << std::endl;
}


