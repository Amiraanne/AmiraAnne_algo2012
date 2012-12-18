/*
 *  firework.cpp
 *  emptyExample
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "firework.h"
#include "ofMain.h" 

void firework::firework(){}

void firework::setup(int x,int y){
	
	currentPos.x = x;
	targetPos = ofPoint(x,y);
	
	exploded = false;
	
	lifetime = 3;
	ascendTime = 1.5;
	born = ofGetElapsedTimef();
	
	particleCount = 50;
}

void firework::update(){


	elapsed = ofGetElapsedTimef() - born;
	
	if (elapsed > ascendTime && !exploded) {
		exploded = true;
		explode();
	} //else {
//		float pct = elapsed / ascendTime;
//		pct = powf(pct, 0.8);
//		currentPos.y = ofGetHeight() * (1-pct) + pct * targetPos.y;
//	}
	

	for ( int i = 0;i < particles.size();i++){
		particles[i].addDampingForce();
		particles[i].update();
	
	}
	
}

void firework::draw(){
	if ( !exploded){
		ofSetColor(0, 250, 154);
		ofCircle(currentPos.x, currentPos.y, 6);
	
	}else {
		
		float pct = elapsed / lifetime;
		pct = 2;
		
		for (int i = 0; i < particles.size(); i++){
			ofSetColor(0,255,127);
			particles[i].draw();
		}
		
	}

}
void firework::explode() {
	
	for (int i = 0; i < particleCount; i++){
		fireworkParticle particle;
		float vx = ofRandom(-2,5);
		float vy = ofRandom(-2,5);
		particle.setup(currentPos.x, currentPos.y, vx, vy);
	    particles.push_back(particle);
	}
	
}
};