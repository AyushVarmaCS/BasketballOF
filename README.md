# FinalProject
Final Project

This is a shooting basketball game in which realistic physics is involved. In my game, I was able to detect collision between two objects to create the appropriate reaction. It has sounds such as dribbling, swishes(made shot), and a crowd cheering for a made shot. It also has to blockers for to made the game more difficult. The game keeps tracking of score by updating every second. A lot of the objects are in the ofxcontactlistener.h because a lot of the game relied whether or not contact was made. Because of this, a lot of things had to be done in the ofxcontactlistener.cpp and not ofapp.cpp. The ball and hoop are dynamic objects, which is how my game detects this and make a "swish" sound. However, dynamic objects can move, so the way I implented this is by practically making hoop a static object(unmovable) by giving it a ridiculously high density, low density, and low fricition. With this, I was able to make the walls of the game stay as static objects and make the game play a dribble sound.

Enjoy!
