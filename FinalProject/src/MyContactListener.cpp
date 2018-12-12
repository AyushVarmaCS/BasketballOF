#include "ofxBox2d.h"
#include "ofApp.h"
#include "Basketball.h"
#include "MyContactListener.h"


void MyContactListener::BeginContact(b2Contact * contact)
{
	std::cout << "Begin contact" << std::endl;
	b2Body* basketball = contact->GetFixtureA()->GetBody();
	b2Body* hoop = contact->GetFixtureB()->GetBody();
}

void MyContactListener::EndContact(b2Contact * contact)
{
	std::cout << "End contact" << std::endl;
}

void MyContactListener::PreSolve(b2Contact * contact, const b2Manifold * oldManifold)
{
	std::cout << "Pre Solve" << endl;
}

void MyContactListener::PostSolve(b2Contact * contact, const b2ContactImpulse * impulse)
{
	std::cout << "Post Solve" << endl;
	Basketball basketball_game_;
	basketball_game_.score++;
	std::cout << "score is: " << basketball_game_.score++ << endl;
}
