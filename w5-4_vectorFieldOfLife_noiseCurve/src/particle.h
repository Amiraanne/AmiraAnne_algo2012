#ifndef PARTICLE_H
#define PARTICLE_H

#include "ofMain.h"

class particle
{
    public:
        ofVec2f pos;
        ofVec2f currentPos;
        ofVec2f prevPos;
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
	
		void bounceOffWalls();
        void cleartail();
    
    
        float hue,sat,bri,ang,dist;
	
		float damping;
        float angle;
        int shape;
        int size;
    
        int boundWidth;
        int boundHeight;
        ofColor particleColor;
    
        vector <ofPoint> points;

    protected:
    private:
};

#endif // PARTICLE_H
