/*
 *  particle.h
 *  emptyExample
 *
 *  Created by Amira Pettus on 11/12/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"
class particle{
	public:
	
		ofPoint pos;
		ofPoint vel;
		ofPoint frc;
	
		particle();
		virtual ~particle(){};
	
		void resetForce();
		void addForce(float x,float y);
		void addDampingForce();
		void setInitialCondition(float px,float py,float vx,float vy);
		void update();
		void draw();
	
		float damping;
	
		int alpha;
	
	protected:
	private:
	
	
	float radiusSize;
	
};

#endif // PARTICLE_H