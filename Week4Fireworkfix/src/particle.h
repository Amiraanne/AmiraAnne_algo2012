/*
 *  particle.h
 *  emptyExample
 *
 *  Created by Amira Pettus on 11/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
public:
	ofVec2f pos;
	ofVec2f vel;
	ofVec2f frc;   // frc is also know as acceleration (newton says "f=ma")
	
	particle();
	virtual ~particle(){};
	
	void resetForce();
	void addForce(float x, float y);
	void addDampingForce();
	void setInitialCondition(float px, float py, float vx, float vy);
	void update();
	void draw();
	void setup();
	
	float damping;
	
protected:
private:
};

#endif // PARTICLE_H