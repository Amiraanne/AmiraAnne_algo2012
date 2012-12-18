/*
 *  burst.h
 *  emptyExample
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef __week4_fireworks__firework__
#define __week4_fireworks__firework__

#include "ofMain.h"
#include "burstParticle.h"

class burst {
	
public:
	
	float lifetime;
	float ascendTime;
	
	float born;
	float elapsed;
	
	bool exploded;
	
	ofColor c;
	int particleCount;
	
	ofPoint currentPos;
	ofPoint targetPos;
	
	void setup(int x, int y);
	void update();
	void draw();
	void explode();
	
	vector <burstParticle> particles;
	
};

#endif 