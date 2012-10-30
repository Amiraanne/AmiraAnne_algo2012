#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	ofBackground(12, 151, 244);
	
	ofSetVerticalSync(TRUE);
	ofSetFrameRate(30);
	ofEnableAlphaBlending();
	ofEnableSmoothing();
	ofSetCircleResolution(100);
	
	
	for (int i = 0; i < 500; i++){
		Particles theParticles;
		vx = ofRandom(-4,4);
		vy = ofRandom(-4,4);
		theParticles.setInitialCondition(ofGetWidth()/2,ofGetHeight()/2,vx, vy, vz);
		theParticles.damping = ofRandom(0.01, 0.03);
		particleVector.push_back(theParticles);
		
		
	}

}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i = 0; i < fireworks.size(); i++){
		
		if (fireworks[i].elapsed > fireworks[i].lifetime)
			fireworks.erase(fireworks.begin()+i);
		else
			fireworks[i].update();
	}
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(255, 255, 255);
	for (int i = 0; i < fireworks.size(); i++){
		fireworks[i].draw();
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
	
	for (int i = 0; particles.size(); i++){
		float vx = ofRandom(-4,4);
		float vy = ofRandom(-4,4);
		particleVector[i].setInitialCondition(mouseX,mouseY,vx, vy, vz);

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