#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	//ofSetCircleResolution(10);
	//ofEnableAlphaBlending();
}

//--------------------------------------------------------------
void testApp::update(){
	
	if (ofGetFrameNum() % 20 == 0) {
		float x = ofMap(sin(ofGetElapsedTimef()*3), -1, 1, 100, ofGetWidth() - 100);
		
		burst bst;
		bst.setup(x, ofRandom(100, 350));
		bursts.push_back(bst);
	}
	
	
	for (int i = 0; i < bursts.size(); i++){
		
		if (bursts[i].elapsed > bursts[i].lifetime)
			bursts.erase(bursts.begin()+i);
		else
			bursts[i].update();
	}
	

}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofBackground(0);
	
	for (int i = 0; i < bursts.size(); i++){
		bursts[i].draw();
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
	
	burst bst;
	bst.setup(x, y);
	bursts.push_back(bst);

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