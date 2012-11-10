#include "rectangle.h"
#include "testApp.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.03f;
}

//------------------------------------------------------------------
void rectangle::draw() {
	
	
	ofPushMatrix();
	
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    

    

	ofLine(pos.x, pos.y, pos.x +20, pos.y +20);
	//ofLine(200, 200, 220, 220);
	ofLine(pos.x , pos.y, pos.x-20,pos.y +20);
	//ofLine(200, 200, 190, 220);
	ofSetColor(255,165,0);
	
	ofRect(pos.x, pos.y, radiusSize,radiusSize);
	//ofRect(200, 200, 10,10);
	ofFill();
	ofSetColor(165,42,42);//how does color work. I tried to make the body red and legs orange but got hte opposite instead how does placement of the code work for color
	
	
	ofPopMatrix();
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}
