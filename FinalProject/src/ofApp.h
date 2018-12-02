#pragma once
#include <ctime>
#include <cstdlib>
#include <utility>

#include "ofMain.h"
#include "Basketball.h"
#include "ofxGui.h"
#include "ofxBox2d.h"
#include "ofxBox2dCircle.h"
#include "ofxBox2dBaseShape.h"


enum GameState{
	PAUSED,
	IN_PROGRESS,
	NEXT_ROUND,
	GAME_OVER,
	SHOW_CURRENT_SCORE
};
class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofxPanel gameGui;
		ofxBox2d box2d;
		ofParameter<float> endTime;
		CONST int kTimeLimit = 30;

		//ofImage basketball;
		ofImage hoop;
		vector<shared_ptr<ofxBox2dCircle>> circles;
		vector<shared_ptr<ofxBox2dRect>> rectangles;
		void drawGravity(ofPoint p, ofPoint gravity);
		ofRectangle baketball_world;



		
private:
	GameState current_state = IN_PROGRESS;
	Basketball basketball_game_;


		
};
