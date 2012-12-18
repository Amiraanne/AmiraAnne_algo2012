/*
 *  particle.cpp
 *  emptyExample
 *
 *  Created by Amira Pettus on 11/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"
#include "ofMain.h"

//--------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.01f;
	
}
//---------------------------------------------------------

void particle::resetForce(){
	frc.set(0,0);
}
//---------------------------------------------------------

void particle::addDampingForce(){
	frc.x = frc.x - vel.x * damping;
	frc.y = frc.y - vel.y * damping;

}
//----------------------------------------------------------

void particle::setInitialCondition(float px,float py,float vx,float vy){

	pos.set(px,py);
	vel.set(vx,vy);

	radiusSize = 10;
	alpha = 255;
//	pos.x = 250;
//	pos.y = 250;
}
//------------------------------------------------------------

void particle::update(){
	vel = vel + frc;
	pos = pos + vel;
}
//--------------------------------------------------------------

void particle::draw(){
	
	
	
	
	ofPushMatrix();
	
	ofTranslate(pos.x, pos.y);
	float angle = atan2(vel.y,vel.x);
	ofRotateZ(angle = angle * RAD_TO_DEG);
	
	ofPushMatrix();
	
	//ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
	
	ofFill();
	ofSetColor(255,165,0,alpha);
	ofSetCircleResolution(6);
	ofCircle(0, 0, radiusSize);
	
	ofNoFill();
	ofSetColor(165,42,42,alpha);
	ofCircle(0, 0, radiusSize *2);
	
	
	ofFill();
	ofSetColor(255,165,0,alpha);
	ofSetCircleResolution(6);
	ofCircle(32, 19.5, radiusSize);
	
	ofNoFill();
	ofSetColor(165,42,42,alpha);
	ofCircle(32, 19.5, radiusSize *2);
	
	
	ofFill();
	ofSetColor(255,165,0,alpha);
	ofSetCircleResolution(6);
	ofCircle(0,38, radiusSize);
	
	ofNoFill();
	ofSetColor(165,42,42,alpha);
	ofCircle(0, 38, radiusSize *2);
	ofPopMatrix();	
	

	//string temp;
	ofPopMatrix();

}

