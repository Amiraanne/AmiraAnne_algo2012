/*
 *  firework.h
 *  Week4
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

//here will just be the bool explosion at the target ( middle of screen)
//using a key pressed 

#ifndef week4
#define week4

#include "ofMain.h"
#include "particle.h"

class firework {
	
public:
	
	float lifetime;
	float ascendTime;
	
	float born;
	float elapsed;
	
	bool exploded;
	int particleCount;
	
	ofPoint currentPos;
	ofPoint targetPos;
	
	void setup(int x, int y);
	void update();
	void draw();
	void explode();
	
	vector <particle> particles;
	
};

#endif 