#include "testApp.h"

static int pts[] = {257,219,257,258,259,274,263,325,266,345,266,352,269,369,276,387,286,415,291,425,302,451,308,462,316,472,321,480,328,488,333,495,339,501,345,505,350,507,365,515,370,519,377,522,382,525,388,527,405,534,426,538,439,539,452,539,468,540,485,540,496,541,607,541,618,539,625,537,641,530,666,513,682,500,710,476,723,463,727,457,729,453,732,450,734,447,738,440,746,423,756,404,772,363,779,343,781,339,784,327,789,301,792,278,794,267,794,257,795,250,795,232,796,222,796,197,797,195,797,188,796,188};
static int nPts  = 61*2;

//--------------------------------------------------------------
void testApp::setup() {
	ofSetVerticalSync(true);
	ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	bMouseForce = false;
	
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(30.0);
	box2d.registerGrabbing();
	
		//text
	
	bFirst  = true;
	typeStr = "ABCDEFGHIJKLMNOPQRSTUVWXYZ\nabcdefghijklmnopqrstuvwxyz\n0123456789,:&!?";
	
	markPixels=false;
	openCircle=false;
	
	//T=255;
	//H=0;
	strLen=0;
	
	
	
	//shape
	ofxSVG svg;
	svg.load("shape5.svg");
	
	ofPath path;
	path = svg.getPathAt(0);
	
	
	
	ofPolyline line = path.getOutline()[0];
		
	cout << line.getVertices().size() << endl;
	for (int i = 0; i < line.getVertices().size(); i++){
		polyLine.addVertex(line.getVertices()[i]);
	}
	
	//shape
	/*ofxSVG svg;
	svg.load("shape6.svg");
	
	ofPath path02;
	path02 = svg02.getPathAt(0);
	
	
	
	ofPolyline line02 = path02.getOutline()[0];
	
	cout << line02.getVertices().size() << endl;
	for (int i = 0; i < line02.getVertices().size(); i++){
		polyLine.addVertex(line02.getVertices()[i]);
	}*/
	
	

	
	// make the shape
	polyLine.setPhysics(0.0, 0.5, 0.5);
	polyLine.create(box2d.getWorld());		
	
	
	
	
	
	//path.getOutline();
	
	//poli = path.getOutline()[0];*/
	
}

//float step;

//--------------------------------------------------------------
void testApp::update() {
	
	
	
	box2d.update();
	
	
	if(bMouseForce) {
		float strength = 8.0f;
		float damping  = 0.7f;
		float minDis   = 100;
		for(int i=0; i<circles.size(); i++) {
			circles[i].addAttractionPoint(mouseX, mouseY, strength);
			circles[i].setDamping(damping, damping);
		}
		for(int i=0; i<customParticles.size(); i++) {
			customParticles[i].addAttractionPoint(mouseX, mouseY, strength);
			customParticles[i].setDamping(damping, damping);
		}
		
	}
	
	// add some circles every so often
	if((int)ofRandom(0, 10) == 0 && openCircle==true) {
		ofxBox2dCircle circle;
		circle.setPhysics(0.3, 0.5, 0.1);
		circle.setup(box2d.getWorld(), (ofGetWidth()/2)+ofRandom(-20, 20), -20, ofRandom(10, 20));
		circles.push_back(circle);		
	}

	
	/*step += 0.001;
	if (step > 1) {
        
		step -= 1;
	}*/
	

	
}


//--------------------------------------------------------------
void testApp::draw() {
	
    
		
	/*if (openCircle==true) {
		for(int i=0; i<circles.size(); i++) {
			ofFill();
			ofSetHexColor(0x90d4e3);
			circles[i].draw(); }
	} else if (openCircle==false) {
		circles[i].stop();
	}*/
	
	
	
	for(int i=0; i<circles.size(); i++) {
		ofFill();
		ofSetHexColor(0x90d4e3);
		 circles[i].draw(); 

		if (circles[i].getPosition().y > ofGetHeight()) {	
			openCircle=false;
		}
	}	
	
	
	
	
	
	
	for(int i=0; i<boxes.size(); i++) {
		ofFill();
		ofSetHexColor(0xe63b8b);
		boxes[i].draw();
	}
	
	for(int i=0; i<customParticles.size(); i++) {
		customParticles[i].draw();
	}
	
	ofNoFill();
	ofSetHexColor(0x444342);
	if(drawing.size()==0) polyLine.draw();
	else drawing.draw();
	
	
	string info = "";
	info += "Press [s] to draw a line strip ["+ofToString(bDrawLines)+"]\n"; 
	info += "Press [f] to toggle Mouse Force ["+ofToString(bMouseForce)+"]\n"; 
	info += "Press [c] for circles\n";
	info += "Press [b] for blocks\n";
	info += "Press [z] for custom particle\n";
	info += "Total circles: "+ofToString(circles.size())+"\n";
	info += "Total Bodies: "+ofToString(box2d.getBodyCount())+"\n";
	info += "Total Joints: "+ofToString(box2d.getJointCount())+"\n\n";
	info += "FPS: "+ofToString(ofGetFrameRate())+"\n";
	ofSetHexColor(0x444342);
	ofDrawBitmapString(info, 30, 30);
	
	ofSetColor(0, 0, 0);
	ofDrawBitmapString(typeStr, 900,20);
	
	
	
	//shape
	
	/*ofPushMatrix();
	//ofTranslate(ofGetWidth() / 2, ofGetHeight() / 2);
	//ofRotate(mouseX);
	
	poli.draw();

	
	ofPopMatrix();*/
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
	/*if(key == 'c') {
		float r = ofRandom(4, 20);		// a random radius 4px - 20px
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.1);
		circle.setup(box2d.getWorld(), mouseX, mouseY, r);
		circles.push_back(circle);
	}*/
	
	if (key==OF_KEY_DOWN) {
		openCircle=!openCircle;
	}

	
	if(key == 'b') {
		//float w = ofRandom(4, 20);	
		//int w;
		/*float h = 10;	
		ofxBox2dRect rect;
		rect.setPhysics(3.0, 0.53, 0.1);
		rect.setup(box2d.getWorld(), mouseX, mouseY, w, h);
		boxes.push_back(rect);*/
	}
	
	if(key == 'z') {
		float r = ofRandom(3, 10);		// a random radius 4px - 20px
		CustomParticle p;
		p.setPhysics(0.4, 0.53, 0.31);
		p.setup(box2d.getWorld(), mouseX, mouseY, r);
		p.color.r = ofRandom(20, 100);
		p.color.g = 0;
		p.color.b = ofRandom(150, 255);
		customParticles.push_back(p);
	}	
		
	//if(key == 'f') bMouseForce = !bMouseForce;
	//if(key == 't') ofToggleFullscreen();
	
	//text
	
	if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
		typeStr = typeStr.substr(0, typeStr.length()-1);
		
	}
    
	
	
	else if(key == OF_KEY_RETURN ){
		typeStr += "\n";
		//markPixels=true; 
		//H=10;
		
		//typeStr.clear();
		
	}
	
	
	
	
	else{
		if( bFirst ){
			typeStr.clear();
			bFirst = false;
		}
		typeStr.append(1, (char)key);
		markPixels=false;
	}
	
	if(key == ' '){
		
		//pixelsLength =true;
		strLen = currentWord.length();
		wordLengths.push_back(strLen);
		currentWord.clear();
        
		
		//Ball b;
		w = strLen*3 ;
		//b.setup();
		//b.position.set(30, ofRandomHeight()-20);	
		
		//b.color = randomColor;	// ZACH 
		
		//b.position.set(30, 100 + wordLengths.size() * 30);
		
		//balls.push_back(b);
		
		/*Circle c;
		 c.radius = strLen*5 ;
		 c.setup();
		 c.position.set(30, 100 + wordLengths.size() * 30);
		 
		 circles.push_back(c);*/
		
		float h = 10;	
		ofxBox2dRect rect;
		rect.setPhysics(3.0, 0.53, 0.1);
		rect.setup(box2d.getWorld(), mouseX, mouseY, w, h);
		boxes.push_back(rect);
		
		
        
        
	}else {
		currentWord.append("key");
	}
	
	
	//typeStr.resize(0, 5);
	//T=0;
	

	
	
	
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
	drawing.addVertex(x, y);
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {
	
	if(polyLine.isBody()) {
		drawing.clear();
		polyLine.destroy();	
	}
	
	drawing.addVertex(x, y);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
	
	drawing.setClosed(false);
	drawing.simplify();
	
	polyLine.addVertexes(drawing);
	polyLine.simplify();
	polyLine.setPhysics(0.0, 0.5, 0.5);
	polyLine.create(box2d.getWorld());
		
	drawing.clear();

}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
	
}

