#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxSVG.h"



#define N_SOUNDS 5



class SoundData {
public:
	int	 soundID;
	bool bHit;
};

// ------------------------------------------------- a simple extended box2d circle
/*class CustomParticle : public ofxBox2dCircle {
	
public:
	CustomParticle() {
	}
	ofColor color;
	void draw() {
		float radius = getRadius();
		
		glPushMatrix();
		glTranslatef(getPosition().x, getPosition().y, 0);
		
		ofSetColor(color.r, color.g, color.b);
		ofFill();
		ofCircle(0, 0, radius);	
		
		glPopMatrix();
		
	}
};*/

/*class ofImage_images {
public:
ofColor color;

	void draw(){
	ofSetColor(color.r, color.g, color.b);
	ofFill();
	}
};*/





// -------------------------------------------------
class testApp : public ofBaseApp {
	
public:
	
	void setup();
	void update();
	void draw();
	
	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void resized(int w, int h);
	
	float							px, py;
	bool							bDrawLines;
	bool							bMouseForce;
	
	ofxBox2d						box2d;			  //	the box2d world
	ofPolyline						drawing;		  //	we draw with this first
	ofxBox2dPolygon					polyLine;		  //	the box2d polygon/line shape
	vector		<ofxBox2dCircle>	circles;		  //	default box2d circles
	vector		<ofxBox2dRect>		boxes;			  //	defalut box2d rects
	
	vector      <ofImage>      images;
	

	vector <int> wordLengths;
	string currentWord;
	int strLen;
	string typeStr;
	int w;
	
	bool bFirst;
	bool markPixels;
	bool openCircle;
	bool openArm;
	bool openBear;
	bool openGiraffe;
	bool openBird;
	bool openOwl;
	
	
	ofxSVG svg;
	ofxSVG svg02;
	ofxSVG svg03;
	ofxSVG svg04;
    ofPolyline poli;

	
	
	// this is the function for contacts
	void contactStart(ofxBox2dContactArgs &e);
	void contactEnd(ofxBox2dContactArgs &e);
	
	// when the ball hits we play this sound
	ofSoundPlayer  sound[N_SOUNDS];
	ofSoundPlayer  backmusic;

	ofImage frontPage;
	ofImage back;
	ofImage back002;
	ofImage back003;
	ofImage back004;
	
	ofImage cbot01;
	bool b02;
	bool b02svg;
	bool b03;
	bool b03svg;
	bool b04;
	bool b05;
	
	bool startscreen;
	
	ofTrueTypeFont	font;
	
	
};
