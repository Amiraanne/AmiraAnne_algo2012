#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofSetFrameRate(30);
	myRadius = 20;
	vel.x = 20;
	pos.x = 20;

}

//--------------------------------------------------------------
void testApp::update(){
	
	if(pos.x >= ofGetWidth() - myRadius || pos.x <= myRadius){
		vel.x *= -1.0;
	}

}

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0, 255, 0);
	
	ofCircle(pos.x, 500, myRadius);
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