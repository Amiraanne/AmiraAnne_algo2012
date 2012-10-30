#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	ofEnableAlphaBlending();
	ofBackground(0, 0, 0);

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	

	
	float xfirst = ofGetWidth()/2;
	float yfirst = ofGetHeight()/2;

	for (int i = 0;i < 400; i ++){
	
		float radius = 10 + i;
			float angle = ofGetElapsedTimef() * ( 1 + i/50.0);

		float x = xfirst + radius * cos(angle);
	    	float y = yfirst + radius * -sin(angle);
			
		ofSetColor(ofRandom(0,255),ofRandom(0,255),255, ofRandom(0,80));
			
			ofRect(x, y, 50, 50);
		
		
		}
	
	
	float x2first = ofGetWidth()/2;
	float y2first = ofGetHeight()/2;
	
	for (int j = 0;j < 450; j ++){
		
		float radius = 10 + j;
		float angle = ofGetElapsedTimef() * ( 1 + j/50.0);
		
		float x2 = x2first + radius * -sin(angle);
		float y2 = y2first + radius * cos(angle);
		
		ofSetColor(255,ofRandom(0,255),255, ofRandom(0,80));
		
		ofRect(x2, y2, 10, 10);
		
		
	}
	

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

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
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}