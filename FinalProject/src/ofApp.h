#pragma once
#include <ctime>
#include <cstdlib>
#include <utility>

#include "ofMain.h"
#include "Basketball.h"
#include "ofxGui.h"

enum GameState{
	PAUSED,
	IN_PROGRESS,
	NEXT_ROUND,
	GAME_OVER
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
		ofParameter<float> endTime;
		ofImage basketball;
		ofImage hoop;
		vector <shared_ptr<ofxBox2dCircle> > circles;

		
private:
	GameState current_state = IN_PROGRESS;
	Basketball basketball_game_;


		
};
