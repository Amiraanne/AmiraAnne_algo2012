#include "particle.h"
#include "ofMain.h"


//------------------------------------------------------------
particle::particle(){
	setInitialCondition(0,0,0,0);
	damping = 0.08f;
    size = 55;
    shape = 1;
    particleColor.set(200,100);
    prevPos.set(0, 0);
}

//------------------------------------------------------------
void particle::resetForce(){
    // we reset the forces every frame
    frc.set(0,0);
}

//------------------------------------------------------------
void particle::addForce(float x, float y){
    // add in a force in X and Y for this frame.
    frc.x = frc.x + x;
    frc.y = frc.y + y;
}

//------------------------------------------------------------
void particle::addDampingForce(){
	
	// the usual way to write this is  vel *= 0.99
	// basically, subtract some part of the velocity 
	// damping is a force operating in the oposite direction of the 
	// velocity vector
	
    frc.x = frc.x - vel.x * damping;
    frc.y = frc.y - vel.y * damping;
}

//------------------------------------------------------------
void particle::setInitialCondition(float px, float py, float vx, float vy){
    pos.set(px,py);
	vel.set(vx,vy);
 
    hue = pos.x/ofGetWidth()*30+10;
    sat = ofMap(pos.y,0,ofGetHeight()/2,100,255,true);
    bri = ofMap(pos.y,ofGetHeight()/2,ofGetHeight(),200,100,true);
    particleColor = ofColor::fromHsb(hue,sat,bri);
    
}


//------------------------------------------------------------
void particle::update(){	
	vel = vel + frc;
	pos = pos + vel;
}


//------------------------------------------------------------
void particle::draw(){


    // polygon > circle
    if (shape>3) {
        shape = 35;
    }
    
    ofSetColor(255,100);
	ofPoint temp;
	temp.x = pos.x;
	temp.y = pos.y;
	points.push_back(temp);
	if (points.size() > 20){
		points.erase(points.begin());
	}
    
	ofNoFill();
    
	
	for (int i = 0; i < particleColor.size(); i++){
		ofSetColor(abs(sin(i*10)*ofRandom(100,255)),abs(sin(i*20)*ofRandom(0,100)),abs( sin(i*10)*ofRandom(0,255)));
		particleColor[i].draw();
	}
	
	
   // particleColor.setHue(abs(pos.x/ofGetWidth()*50+100*sin(ofGetElapsedTimeMillis()*0.001)));
//    ofSetColor(particleColor,100);
//	ofBeginShape();
//	for (int i = 0; i < points.size(); i++){
//		ofVertex(points[i].x, points[i].y);
//	}
	ofEndShape();
   
    //get the angle by compare with previous position
    float dx = pos.x - prevPos.x;
    float dy = pos.y - prevPos.y;
    
    angle = atan2(dy, dx);
    
    prevPos.x = pos.x;
    prevPos.y = pos.y;
    
    
    ofFill();
    //change circle into triangle
    ofSetCircleResolution(shape);
    ofPushMatrix();
        ofTranslate(pos.x, pos.y);
        ofRotateZ(angle * RAD_TO_DEG);
        ofCircle(0, 0, size);
    ofPopMatrix();
    ofSetCircleResolution(100);
}


//------------------------------------------------------------
void particle::bounceOffWalls(){
	
	// sometimes it makes sense to damped, when we hit
	bool bDampedOnCollision = true;
	bool bDidICollide = false;
	
	// what are the walls
	float minx = 0;
	float miny = 0;
	float maxx = ofGetWidth();
	float maxy = ofGetHeight();
	
	if (pos.x > maxx){
		pos.x = maxx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	} else if (pos.x < minx){
		pos.x = minx; // move to the edge, (important!)
		vel.x *= -1;
		bDidICollide = true;
	}
	
	if (pos.y > maxy){
		pos.y = maxy; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	} else if (pos.y < miny){
		pos.y = miny; // move to the edge, (important!)
		vel.y *= -1;
		bDidICollide = true;
	}
	
	if (bDidICollide == true && bDampedOnCollision == true){
		vel *= 0.3;
	}
	
}

//------------------------------------------------------------
void particle::cleartail(){
    points.clear();
}
