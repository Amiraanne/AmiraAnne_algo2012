#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){	
	
	ofBackground(0,51,85);
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	
	fw.setup(ofRandom(ofGetWidth()), ofRandom(ofGetHeight()));
	
}

//--------------------------------------------------------------
void testApp::update(){

	 fw.update();
}

//--------------------------------------------------------------
void testApp::draw(){

	fw.draw();
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
	fw.setup(x,y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}
