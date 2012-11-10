#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
	
//	ofPushMatrix();
//	ofRect(ofGetWidth()/2, ofGetHeight()/2, 10, 10);
//    ofFill();
//    ofSetColor(255,0,0);
//    ofLine(ofGetWidth()/2 , ofGetHeight()/2, 5, 5);
//	ofLine(ofGetWidth()/2 + 6, ofGetHeight()/2, -5, 5);
//    ofPopMatrix();
	
	ofPushMatrix();
	ofRect(200, 200, 10, 10);
    ofFill();
    ofSetColor(255,0,0);
	
	
    ofLine(200, 200, 220, 220);
	ofLine(210, 200, 190, 220);
	ofSetColor(0,0,0);
	ofPopMatrix();
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