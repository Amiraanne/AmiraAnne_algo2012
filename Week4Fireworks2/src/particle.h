/*
 *  particle.h
 *  emptyExample
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __week4_fireworks__Particle__
#define __week4_fireworks__Particle__

#include "ofMain.h"

class Particle {
	
public:

	Particle();
	
	void setup(float px, float py, float vx, float vy);
	void draw();
	void update();
	
	void resetForce();
	void addForce(float x, float y);
	void addDampingForce();
	
	ofPoint pos;
	ofPoint	vel;
	ofPoint frc;
	
	float damping;
	
	fireworkParticle();
	
};
#endif