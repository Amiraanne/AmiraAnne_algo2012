/*
 *  burst.cpp
 *  Created by Amira Pettus on 10/28/12.
 */

#include "burst.h"

void burst::setup(int x, int y) {
	
	currentPos.x = x;
	targetPos = ofPoint(x, y);
	
	exploded = false;
	
	lifetime = 3.5;
	ascendTime = 1.5;
	born = ofGetElapsedTimef();
	
	c = ofColor(255, 165, 0);
	particleCount = 75;
	
}

void burst::update() {
	
	elapsed = ofGetElapsedTimef() - born;
	
	if (elapsed > ascendTime && !exploded) {
		exploded = true;
		explode();
	} else {
		
		float pct = elapsed / ascendTime;
		pct = powf(pct, 0.8);
		currentPos.y = ofGetHeight() * (1-pct) + pct * targetPos.y;
	}
	
	for (int i = 0; i < particles.size(); i++){
		particles[i].addDampingForce();
		particles[i].update();
	}
	
}

void burst::draw() {
	
	if (!exploded) {
		
		ofSetColor(255, 255, 255);
		ofCircle(currentPos.x, currentPos.y, 6);
		
	} else {
		
		float pct = elapsed / lifetime;
		pct = powf(pct, 2);
		
		for (int i = 0; i < particles.size(); i++){
			ofSetColor(c);
			particles[i].draw();
		}
		
	}
	
}

void burst::explode() {
	
	for (int i = 0; i < particleCount; i++){
		burstParticle particle;
		float vx = ofRandom(-2,2);
		float vy = ofRandom(-2,2);
		particle.setup(currentPos.x, currentPos.y, vx, vy);
	    particles.push_back(particle);
	}
	
};