/*
 *  triangles.cpp
 *  naturalPhenomenaWeek2
 *
 *  Created by Amira Pettus on 10/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "triangles.h"

triangle::triangle(int _index){ //_index is a parameter  that allows each 
							   //indv triangle in the vector to understand its placement within the array and results in them moving seperately.
	index = _index;
	xorig = ofRandom(ofGetWidth());
	yorig = ofRandom(ofGetHeight());
}

//------------------------------------------------------------------

void triangle::update(){
	radius = 60;
	
	float angle = ofGetElapsedTimef()*3.5;
	
	pos.x = xorig + radius * cos(angle + index);
	pos.y = yorig + radius * -sin(angle + index);
	
	

	
}

//------------------------------------------------------------------

void triangle::draw(){
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
	
	
	ofRect(pos.x, pos.y, 5, 5);
	//ofTriangle(pos.x, pos.y,pos2.x , pos2.y, pos3.x, pos3.y);// Why wont it work with triangles??
		
}
//------------------------------------------------------------------