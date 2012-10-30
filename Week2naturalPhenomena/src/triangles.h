/*
 *  triangles.h
 *  naturalPhenomenaWeek2
 *
 *  Created by Amira Pettus on 10/1/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

//x pos,y pos, r,g,b , rotation, sin wave, opacity

#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "ofMain.h"

class triangle{

	public:
	
		triangle(int _index);
	
		void  draw();
		void update();
		
		ofPoint pos, pos2,pos3;
		ofColor color;
	
		//float opacity;
		//float rotate;
	    float radius;
	    float xorig; 
	    float yorig; 
	    int   index;
	
};

#endif