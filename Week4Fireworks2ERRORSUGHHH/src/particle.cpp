/*
 *  particle.cpp
 *  emptyExample
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"

fireworkParticle::fireworkParticle() {
	setup(0, 0, 0, 0);
	damping = 5.0f;
}
//--------------------------------------------------------------
void fireworkParticle::setup(float px, float py, float vx, float vy) {
    pos.set(px, py);
	vel.set(vx, vy);
	
}
//--------------------------------------------------------------
void fireworkParticle::resetForce() {
    frc.set(0,0);
}
//--------------------------------------------------------------

void fireworkParticle::addDampingForce() {
    frc.x -= vel.x * damping;
	frc.y -= vel.y * damping;
}
//--------------------------------------------------------------
void fireworkParticle::update() {
	vel = vel + frc;
	
	pos.x += vel.x * cos();
	pos.y += vel.y * sin();
	
}
//--------------------------------------------------------------
void fireworkParticle::draw() {
	
	ofSetColor(r, g, b, a);
    ofCircle(initPos.x, initPos.y, vel.x*.2 + vel.y*.2);
	
	ofBeginShape();
	ofNoFill();
	
	ofBeginShape();
	for (int i = 0; i < particles.size(); i++){
		ofVertex(particles[i].x, particles[i].y);
	}
	ofEndShape();
	
	
}
