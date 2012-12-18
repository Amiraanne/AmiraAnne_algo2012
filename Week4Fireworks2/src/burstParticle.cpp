/*
 *  burstParticle.cpp
 *  emptyExample
 *
 *  Created by Amira Pettus on 10/28/12.
 */

#include "burstParticle.h"



burstParticle::burstParticle() {
	setup(0, 0, 0, 0);
	damping = 0.01f;
}

void burstParticle::setup(float px, float py, float vx, float vy) {
    pos.set(px, py);
	vel.set(vx, vy);
	
}

void burstParticle::resetForce() {
    frc.set(0,0);
}


void burstParticle::addDampingForce() {
    //frc.x -= vel.x * damping;
	//frc.y -= vel.y * damping;
}

void burstParticle::update() {
	vel = vel + frc;
	
	pos.x += vel.x * cos(theta);
	pos.y += vel.y * sin(theta);
	
}

void burstParticle::draw() {
	
	ofPushMatrix();
	
	ofTranslate(pos.x, pos.y);
	
	ofCircle(2, 0, 2);
	
	ofPopMatrix();
	
}
