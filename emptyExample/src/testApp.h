#pragma once

#include "ofMain.h"

class testApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed  (int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
<<<<<<< HEAD
				
		vector< rectangle > rectangles
	
};
=======
		
		ofPoint pos;
		float radiusSize;
	
		vector <particle> particles;
		bool	pdfRendering;
		
	};
>>>>>>> 78879bf... commit
#endif