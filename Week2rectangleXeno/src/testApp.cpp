#include "testApp.h"
#include "ofMain.h"
#include "rectangle.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	// macs by default run on non vertical sync, which can make animation very, very fast
	// this fixes that: 
	
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofBackground(30,30,30);
	
	
	// set the position of the rectangle:
	
	rectangles.pos.x = 100;
	rectangles.pos.y = 50;
	
	for (int i = 0; i < numRectangles; i++) {
		rectangle[i].setup(0.1 - 0.01 *i);
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	rectangles.xenoToPoint(mouseX, mouseY);
	
	for (int i = 0; i < rectangle.size; i++) {
		rectangles[i].update();
	}
	
	for (int i = 0; i < numRectangles; i++) {
		rectangles[i].update();
	}
}

//--------------------------------------------------------------
void testApp::draw(){
	//rectangles.draw();
	for (int i = 0; i < numRectangles; i++) {
		rectangles[i].draw();
	}
}

//--------------------------------------------------------------
void testApp::keyPressed  (int key){
}

//--------------------------------------------------------------
void testApp::keyReleased  (int key){
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
	
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
