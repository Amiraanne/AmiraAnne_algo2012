/*
 *  burstParticle.h
 *  emptyExample
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */


#ifndef __week4_fireworks__fireworkParticle__
#define __week4_fireworks__fireworkParticle__

#include "ofMain.h"

class burstParticle {
	
public:
	
	ofPoint pos;
	ofPoint	vel;
	ofPoint frc;
	
	float theta;
	float subTheta;
	float subThetaSpeed;
	float damping;
	
	burstParticle();
	
	void setup(float px, float py, float vx, float vy);
	void resetForce();
	void addForce(float x, float y);
	void addDampingForce();
	void update();
	void draw();
	
};
#endif


