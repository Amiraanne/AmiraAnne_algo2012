/*
 *  firework.cpp
 *  emptyExample
 *
 *  Created by Amira Pettus on 11/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "firework.h"



void firework::setup(int x, int y){
	
	currentPos.x = x;
	targetPos = ofPoint(x,y);
	
	exploded = false;
	lifetime = 3;
	ascendTime = 2;
	born = ofGetElapsedTimef();
}

//-----------------------------------------------------//

void firework::update(){
	
	elapsed = ofGetElapsedTimef()-born;
	
	if (elapsed > ascendTime && !exploded){
		exploded = true;
		explode();
		
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
}


//-----------------------------------------------------//

void firework::draw(){
	
	if (!exploded) {
		ofSetColor(255, 255, 255);
		ofCircle(currentPos.x, currentPos.y, 6);// a single white particle is supposed to float to target pos before firework is triggered
		//how do I do this when the mouse is pressed?	
	}
	
	//for (int i = 0; i < particles.size(); i++){
//		ofSetColor(255,23,0);
//		particles[i].draw();
//	}
	
}
//-----------------------------------------------------//

void firework::explode() {
	
	for (int i = 0; i < particleCount; i++){
		particle particle;
		float vx = ofRandom(-2,2);
		float vy = ofRandom(-2,2);
		//particles.setup(currentPos.x, currentPos.y, vx, vy);
	    particles.push_back(particle);
	}
	
	
};