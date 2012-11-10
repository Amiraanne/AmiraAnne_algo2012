#include "testApp.h"
#include "ofMain.h"
#include "rectangle.h"

//--------------------------------------------------------------
void testApp::setup(){

	
	ofSetVerticalSync(true);
	ofBackground(30,30,30);
	ofEnableAlphaBlending();
	
// set the position of the rectangle:
//	
//	myRectangle.pos.x = 100;
//	myRectangle.pos.y = 50;
	
	for (int i = 0; i < 25; i++) {
		
		myRectangle[i].pos.x = 200;
		myRectangle[i].pos.y = 200;
		
		myRectangle[i].radiusSize = 5;
		
		
		myRectangle[i].opacity = i;
		
		myRectangle[i].catchUpSpeed = .03f;
	}
	
}

//--------------------------------------------------------------
void testApp::update(){
	myRectangle[0].xenoToPoint(mouseX, mouseY);
	
		for (int i = 0; i < 25; i++) {
		myRectangle[i].xenoToPoint(myRectangle[i-1].pos.x,myRectangle[i-1].pos.y);
	}
	
}

//--------------------------------------------------------------
void testApp::draw(){
	
	for (int i=0; i<25; i++) {
		myRectangle[i].draw();
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
