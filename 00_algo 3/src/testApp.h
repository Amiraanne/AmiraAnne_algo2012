#pragma once
#include "ofMain.h"
#include "ofxBox2d.h"
#include "ofxSVG.h"

// ------------------------------------------------- a simple extended box2d circle
class CustomParticle : public ofxBox2dCircle {
	
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
};


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
	vector		<CustomParticle>	customParticles;  //	this is a custom particle the extends a cirlce
	vector      <ofImage>      images;
	vector      <ofImage>      images02;
	vector      <ofImage>      images03;
	vector      <ofImage>      images04;
	
	vector <int> wordLengths;
	string currentWord;
	int strLen;
	string typeStr;
	int w;
	
	
	ofTrueTypeFont  franklinBook14;
	
	bool bFirst;
	bool markPixels;
	bool openCircle;
	bool openArm;
	bool openBear;
	bool openGiraffe;
	bool openBird;
	
	
	ofxSVG svg;
    ofPolyline poli;
	
	int svg_x, svg_y;
	ofImage bird02;
	int r;
	
	//ofColor randomColor;
};
