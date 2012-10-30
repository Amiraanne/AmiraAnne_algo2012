/*
 *  rectangle.cpp
 *  emptyExample
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "rectangle.h"

rectangle:rectangle(){
	
	catchUpSpeed = 0.03f
	
}

//------------------------------------------------------------------

void rectangle::draw(){
	ofNoFill();
	ofSetRectMode(OF_RECTMODE_CENTER);//center around the position
	ofSetColor(255, 165, 0);
	ofRect(pos.x, pos.y, 10, 10);
	
}

//------------------------------------------------------------------

void rectangle::xenoToPoint(float cathX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed)*pos.x;
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed)*pos.y;
	
} 