/*
 *  firework.h
 *  emptyExample
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef PARTICLES_H
#define PARTICLES_H
#include "ofMain.h"

class firework{

public:
	
	void setup(int x, int y);
	void draw();
	void update();
	void explode();
	
	float lifetime;
	float ascendTime;
	float born;
	float elapsed;
	
	bool exploded;
	int particleCount;
	
	ofPoint currentPos;
	ofPoint targetPos;
	
	vector <fireworkParticle> particles;
		
};

#endif // PARTICLES_H