#ifndef _TEST_APP
#define _TEST_APP

#include "ofMain.h"
#include "rectangle.h"

class testApp : public ofSimpleApp{

	public:

		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased (int key);

		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased();


		rectangle myRectangle[25];// array name    stuff inside array   amount of the objects in the array
	
	
};

#endif
//NOTES: Why is my bug following my mouse so far away?
//How do I get them to follow each other more closely
//what is xeno to point really?
//sometimes I get bad access in ref ro my xeno to point line
