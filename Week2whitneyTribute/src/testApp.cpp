#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofEnableAlphaBlending();
	ofBackground(0, 0, 0);
	ofSetCircleResolution(100);

	radius = 50;
}

//--------------------------------------------------------------
void testApp::update(){
	rotateShape= rotateShape + 1.0f;
	radius = radius + 0.1 ;
}

//--------------------------------------------------------------
void testApp::draw(){
	
	ofSetColor(255,255,255,ofRandom(0,50));
	ofFill();
	//ofSetStroke(228,115,18); how do you get a freakin stroke color?
	ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
	
	ofSetColor(0,0,255,ofRandom(0,50));
	ofFill();
	ofCircle(ofGetWidth()/2, ofGetHeight()/2, 100);
		
	float xorig = ofGetWidth()/2;
	float yorig = ofGetHeight()/2;
	float angle = ofGetElapsedTimef() * 3.5;
	
	
	//float x = xorig + radius * -sin(angle *5);
//	float y = yorig + radius * cos(angle);
	float x = 0 + radius * -sin(angle *5);
	float y = 0 + radius * cos(angle);
	
	ofPoint temp;
	temp.x = x;
	temp.y = y;	
	points.push_back(temp);
	
	if (points.size() > 1000) {
		points.erase(points.begin());
	}
	
	ofSetRectMode(OF_RECTMODE_CENTER);
	//ofSetColor(255,0,127);
	//ofFill();
	//ofCircle(x,y,10);
	
	ofSetColor(0,250,250);
	
	ofNoFill();
	ofPushMatrix();
	ofTranslate(xorig, yorig);
	ofRotate(rotateShape);
	ofBeginShape();
	
	
	for (int i = 0; i < points.size(); i++) {
		ofCurveVertex(points[i].x, points[i].y);
	
		}
	ofEndShape();

		
//----------------------------
	
	float x2orig = ofGetWidth()/2;
	float y2orig = ofGetHeight()/2;
	float angle2 = ofGetElapsedTimef() * 3.5;
	
	
	float x2 = x2orig + radius2 * cos(angle2);
	float y2 = y2orig + radius2 * -sin(angle2 * 5);
	
	ofPoint temp2;
	temp2.x = x2;
	temp2.y = y2;	
	points2.push_back(temp);
	
	if (points2.size() > 100) {
		points2.erase(points2.begin());//uses points from first shape
	}
	
   ofSetRectMode(OF_RECTMODE_CENTER);

	
	ofSetColor(255,250,0,80);
	
	ofNoFill();
	
	ofBeginShape();
	
	
	
	for (int j = 0; j < points2.size(); j++) {
	ofCurveVertex(points2[j].x, points2[j].y);
		
	}
	ofEndShape();
	ofPopMatrix();
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	ofToggleFullscreen();
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