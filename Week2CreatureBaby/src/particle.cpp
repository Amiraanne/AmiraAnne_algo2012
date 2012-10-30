/*
 *  particle.cpp
 *  CreatureBaby
 *
 *  Created by Amira Pettus on 9/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#include "particle.h"

//-------------------------------------------------------------

particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.05f;
	
	//leaf1.loadImage("leaf1.png")
	//leaf1.loadImage("leaf1.png")
	//leaf1.loadImage("leaf1.png")

}

//-------------------------------------------------------------

void particle::resetForce(){
	// reset forces every frame
	
	frc.set(0,0);

}

//-------------------------------------------------------------


void particle:: addForce(float x,float y){
	// add in a force in x and y for this frame.
	
	frc.x = frc.x + x;
	frc.y = frc.y + y;

}

//--------------------------------------------------------------

void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector

	frc.x = frc.x - vel.x * damping;
	frc.y = frc.y - vel.y * damping;

}

//--------------------------------------------------------------

void particle::setInitialCondition(float px,float py,float vx,float vy){
	pos.set(px,py);
	vel.set(vx,vy);

}

//--------------------------------------------------------------

void particle::update(){
	vel = vel +frc;
	pos = pos + vel;


}

//--------------------------------------------------------------

void particle::bounceOfWalls(){

	bool bDampedOnCollision = true;
	boolbDidICollide = false;
	
	//what are the walls
	float minX  = 0;
	float minY  = 0;
	float maxX  = ofGetWidth();
	float maxXY = ofGetHeight();
	
	if(pos.x > maxX){
		pos.x = maxX;// move to the edge
		vel.x *= -1;
		bDidICollide = true;
	
	}else if (pos.x <minX) {
		pos.x = minX; // move to the edge
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxY) {
		pos.y = maxY;// move to the edge
		vel.y *= -1;
		bDidICollide = true;
		
	}else if (pos.y < minY){
		pos.y = miny;// move to the edge
		vel.y *= -1;
		bDidICollide = true;
	
	}
	
	if (bDidICollide == true && bDidICollide == true) {
		vel *= 0.3;
	}
	

}































