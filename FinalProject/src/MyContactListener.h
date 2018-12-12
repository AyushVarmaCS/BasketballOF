#pragma once
#include "ofxBox2d.h"
#include "ofApp.h"
#include "Basketball.h"
class MyContactListener : public b2ContactListener {
	void BeginContact(b2Contact* contact);

	void EndContact(b2Contact* contact);


	void PreSolve(b2Contact* contact, const b2Manifold* oldManifold);


	void PostSolve(b2Contact* contact, const b2ContactImpulse* impulse);

}