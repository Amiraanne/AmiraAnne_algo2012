/*
 *  ellipse.cpp
 *  CreatureBaby
 *
 *  Created by Amira Pettus on 10/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "ellipse.h"
//-------------------------------------------------------

ellipse::ellipse(){
	xorig = ofRandom(ofGetWidth());
	yorig = ofRandom(ofGetHeight());


}
//------------------------------------------------------------------

void ellipse::update(){
	
	//radius = 50;
	
	float angle = ofGetElapsedTimef() * 3.5;
	
	pos.x = xorig + radius * cos(angle);
	pos.y = yorig + radius * -sin(angle);


}


//------------------------------------------------------------------

void ellipse::draw(){
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER);// center around the position
	ofSetColor(255, 23, 18);
	ofEllipse(pos.x, pos.y,ofRandom(ofGetWidth()),ofRandom(ofGetHeight()));	
}

//------------------------------------------------------------------

void ellipse::xenoToPoint(float catchX,float catchY){	pos.x = catchUpSpeed * catchX + (1 - catchUpSpeed) * pos.x;
	pos.y = catchUpSpeed * catchY + (1 - catchUpSpeed) * pos.y; 

}