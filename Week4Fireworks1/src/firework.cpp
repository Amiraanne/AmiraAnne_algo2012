/*
 *  firework.cpp
 *  Week4
 *
 *  Created by Amira Pettus on 10/28/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
//rely on distance and not on time ( predefine target pos and subtract)
#include "firework.h"

void firework::setup(int x, int y){
	targetPos = ofPoint(x,y);
	currentPos.x = ofRandom(ofGetWidth());
	currentPos.y = ofGetHeight();
	
	exploded = false;
}

//-----------------------------------------------------//

void firework::update(){
	
	if (!exploded){
		cout << "NOT EXPLOTE YET" << endl;
		if ( targetPos.distance(currentPos) < 5  ){
			particles.clear();
			
			for (int i = 0; i < 1000; i++){
				particle newParticle;
				float vx = ofRandom(-4,4);
				float vy = ofRandom(-4,4);
				newParticle.setInitialCondition(currentPos.x,currentPos.y,vx, vy);
				particles.push_back(newParticle);
			}
			
			exploded = true;
		
		} else {
			currentPos.x = ofLerp(currentPos.x, targetPos.x, 0.1);
			currentPos.y = ofLerp(currentPos.y, targetPos.y, 0.1);
		}
	} else {
		cout << "EXPLOTE" << endl;
	}


	for (int i = 0; i < particles.size(); i++){
		//particles[i].addDampingForce();
		particles[i].addForce(0,0.000098);//gravityyyy
		particles[i].update();
	}
}


//-----------------------------------------------------//

void firework::draw(){

	if (!exploded) {
		ofSetColor(255, 255, 255);
		ofCircle(currentPos, 6);// a single white particle is supposed to float to target pos before firework is triggered
												//how do I do this when the mouse is pressed?	
	}

	for (int i = 0; i < particles.size(); i++){
		ofSetColor(255,23,0);
		particles[i].draw();
	}
	
}