/*
 *  ellipse.h
 *  CreatureBaby
 *
 *  Created by Amira Pettus on 10/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "ofMain.h"

class ellipse{
	
	public:
	
		ellipse();
		
		void update();
		void draw();
		void xenoToPoint(float catchX, float catchY);
	
		ofPoint pos;
		float catchUpSpeed; // take this pct of where I want to be, and 1-catchUpSpeed of my pos
		float opacity;
		float rotate;
		float xorig;
		float yorig;
		float radius;
};

#endif // ELLIPSE_H
