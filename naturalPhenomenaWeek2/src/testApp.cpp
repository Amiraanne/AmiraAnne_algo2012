#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){

	ofSetVerticalSync(true);
	ofBackground(23, 23, 8);
	
	for(int i = 0;i < 500; i++){
		myTriangles.push_back(triangle(i));
	}
}

//--------------------------------------------------------------
void testApp::update(){
	
	//radius = radius/3 + 0.1;
	for(int i = 0; i < myTriangles.size(); i++){
		myTriangles[i].update();
	}

}

//--------------------------------------------------------------
void testApp::draw(){
	
	for(int i = 0; i < myTriangles.size(); i++){
		myTriangles[i].draw();
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