#include "rectangle.h"
#include "testApp.h"


//------------------------------------------------------------------
rectangle::rectangle(){
	catchUpSpeed = 0.03f;
}

//------------------------------------------------------------------
void rectangle::draw() {
	ofFill();
	ofSetRectMode(OF_RECTMODE_CENTER); // center around the position
    ofSetColor(198,246,55);
    ofRect(pos.x, pos.y, radiusSize,radiusSize);
}

//------------------------------------------------------------------
void rectangle::xenoToPoint(float catchX, float catchY){
	pos.x = catchUpSpeed * catchX + (1-catchUpSpeed) * pos.x; 
	pos.y = catchUpSpeed * catchY + (1-catchUpSpeed) * pos.y; 
}
