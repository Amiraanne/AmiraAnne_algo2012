/*
 *  particle.h
 *  CreatureBaby
 *
 *  Created by Amira Pettus on 9/29/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#Include"ofMain.h";

class particle {
	
	public:
	
	ofVec2f pos;
	ofVec2f vel;
	ofVec2f frc; // f = ma
	
	particle();
	virtual ~particle(){};
	
	void resetForce();
	void addForce(float x, float y);
	void addDampingForce();
	void setInitialCondition( float px,float py, float vx,float vy);
	void update();
	void draw();
	
	void bounceOffWalls();
	float damping;
	
};

#endif //PARTICLE_H