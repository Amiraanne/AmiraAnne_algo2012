#include "testApp.h"

static int pts[] = {257,219,257,258,259,274,263,325,266,345,266,352,269,369,276,387,286,415,291,425,302,451,308,462,316,472,321,480,328,488,333,495,339,501,345,505,350,507,365,515,370,519,377,522,382,525,388,527,405,534,426,538,439,539,452,539,468,540,485,540,496,541,607,541,618,539,625,537,641,530,666,513,682,500,710,476,723,463,727,457,729,453,732,450,734,447,738,440,746,423,756,404,772,363,779,343,781,339,784,327,789,301,792,278,794,267,794,257,795,250,795,232,796,222,796,197,797,195,797,188,796,188};
static int nPts  = 61*2;

//--------------------------------------------------------------
void testApp::setup() {
	ofSetVerticalSync(true);
	
	startscreen=TRUE;
	
	frontPage.loadImage("frontpage.png");
	back.loadImage("back001.png");
	back002.loadImage("back004.png");
	back003.loadImage("back002.png");
	back004.loadImage("back003.png");
	
	cbot01.loadImage("cbot01.png");
	//ofSetBackgroundAuto(true);
	//ofBackgroundHex(0xfdefc2);
	ofSetLogLevel(OF_LOG_NOTICE);
	
	font.loadFont("HelveticaCY.dfont", 12);
	
	bMouseForce = false;
	b02=false;
	b02svg=false;
	b03=false;
	b04=false;
	b05=false;
	
	//ofImage back;
	
	

	

	
	
	box2d.init();
	box2d.setGravity(0, 10);
	box2d.createGround();
	box2d.setFPS(30.0);
	box2d.registerGrabbing();
	
	// register the listener so that we get the events
	ofAddListener(box2d.contactStartEvents, this, &testApp::contactStart);
	ofAddListener(box2d.contactEndEvents, this, &testApp::contactEnd);
	
	// load the 8 sfx soundfile
	for (int i=0; i<N_SOUNDS; i++) {
		sound[i].loadSound("sfx/"+ofToString(i)+".mp3");
		sound[i].setMultiPlay(true);
		sound[i].setLoop(false);
	}
	
	backmusic.loadSound("backmusic.mp3");
	backmusic.play();
	backmusic.setLoop(true);
	
	
	
	//text
	
	bFirst  = true;
	typeStr = "Text Your Message";
	
	markPixels=false;
	openCircle=false;
	openArm=false;
	openBear=false;
	openGiraffe=false;
	openBird=false;
	openOwl=false;
	strLen=0;
	
	
	//------------svg01
    svg.load("bot01.svg");
	ofPath path;
     path = svg.getPathAt(0);
	
	ofPolyline line = path.getOutline()[0];
	polyLine.clear();
	
	cout << line.getVertices().size() << endl;
	for (int i = 0; i < line.getVertices().size(); i++){
		polyLine.addVertex(line.getVertices()[i]);
	}
	
	polyLine.setPhysics(0.0, 0.5, 0.5);
	polyLine.create(box2d.getWorld());	
	
	//------------scg02
	
		
	
	//shape
	
	
	
	//ofxSVG svg02;
	//svg02.load("bot02.svg");
	
	
	
	
	
	

}

//--------------------------------------------------------------
void testApp::contactStart(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		// if we collide with the ground we do not
		// want to play a sound. this is how you do that
		if(e.a->GetType() == b2Shape::e_circle && e.b->GetType() == b2Shape::e_circle) {
			
			SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
			SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
			
			if(aData) {
				aData->bHit = true;
				sound[aData->soundID].play();
			}
			
			if(bData) {
				bData->bHit = true;
				sound[bData->soundID].play();
			}
		}
	}
}

//--------------------------------------------------------------
void testApp::contactEnd(ofxBox2dContactArgs &e) {
	if(e.a != NULL && e.b != NULL) { 
		
		SoundData * aData = (SoundData*)e.a->GetBody()->GetUserData();
		SoundData * bData = (SoundData*)e.b->GetBody()->GetUserData();
		
		if(aData) {
			aData->bHit = false;
		}
		
		if(bData) {
			bData->bHit = false;
		}
	}
}


//--------------------------------------------------------------
void testApp::update() {
	
	//back.resize(ofGetWidth(),ofGetHeight());
	box2d.update();
  
	
	if (backmusic.getIsPlaying() == false)		backmusic.play();
	
	if(bMouseForce) {
		float strength = 8.0f;
		float damping  = 0.7f;
		float minDis   = 100;
		for(int i=0; i<circles.size(); i++) {
			circles[i].addAttractionPoint(mouseX, mouseY, strength);
			circles[i].setDamping(damping, damping);
		}
		/*for(int i=0; i<customParticles.size(); i++) {
			customParticles[i].addAttractionPoint(mouseX, mouseY, strength);
			customParticles[i].setDamping(damping, damping);
		}*/
		
	}
	
}


//--------------------------------------------------------------
void testApp::draw() {
	
	    ofBackground(255, 255, 255);
		
		back.draw(0,0,ofGetWidth(),ofGetHeight());
	    
		
		//cbot01.draw(0, 0);
		
		
		if (b02==true) {
			back002.draw(0,0, ofGetWidth(),ofGetHeight());
			
			
			svg02.load("bot04.svg");
			
			ofPath path02;
			path02 = svg02.getPathAt(0);
			
			ofPolyline line02 = path02.getOutline()[0];
			polyLine.clear();
			
			cout << line02.getVertices().size() << endl;
			for (int i = 0; i < line02.getVertices().size(); i++){
				polyLine.addVertex(line02.getVertices()[i]);
			}
			
			polyLine.setPhysics(0.0, 0.5, 0.5);
			polyLine.create(box2d.getWorld());
			
			
		}
		
		if (b03==true) {
			back003.draw(0,0, ofGetWidth(),ofGetHeight());
			
			
			svg03.load("bot02.svg");
			
			
			ofPath path03;
			path03 = svg03.getPathAt(0);
			
			ofPolyline line03 = path03.getOutline()[0];
			polyLine.clear();
			
			cout << line03.getVertices().size() << endl;
			for (int i = 0; i < line03.getVertices().size(); i++){
				polyLine.addVertex(line03.getVertices()[i]);
			}
			
			polyLine.setPhysics(0.0, 0.5, 0.5);
			polyLine.create(box2d.getWorld());
			
			
		}
		
		if (b04==true) {
			back004.draw(0,0, ofGetWidth(),ofGetHeight());
			
			
			svg04.load("bot03.svg");
			
			
			ofPath path04;
			path04 = svg04.getPathAt(0);
			
			ofPolyline line04 = path04.getOutline()[0];
			polyLine.clear();
			
			cout << line04.getVertices().size() << endl;
			for (int i = 0; i < line04.getVertices().size(); i++){
				polyLine.addVertex(line04.getVertices()[i]);
			}
			
			polyLine.setPhysics(0.0, 0.5, 0.5);
			polyLine.create(box2d.getWorld());
			
			
		} 
		
		if (b05==true) {
			ofSetColor(255);
			back.draw(0,0, ofGetWidth(),ofGetHeight());
			
			
			svg.load("bot01.svg");
			
			
			ofPath path;
			path = svg.getPathAt(0);
			
			ofPolyline line = path.getOutline()[0];
			polyLine.clear();
			
			cout << line.getVertices().size() << endl;
			for (int i = 0; i < line.getVertices().size(); i++){
				polyLine.addVertex(line.getVertices()[i]);
			}
			
			polyLine.setPhysics(0.0, 0.5, 0.5);
			polyLine.create(box2d.getWorld());
			
			
		} 
		
		
		
		
		
		
		// circle with animals
		for(int i=0; i<circles.size(); i++) {
			ofNoFill();
			circles[i].draw(); 
			
		}
		
		
		// testing boxes
		
		/*for(int i=0; i<boxes.size(); i++) {
		 ofFill();
		 
		 SoundData * data = (SoundData*)boxes[i].getData();
		 if(data && data->bHit) ofSetHexColor(0xff0000);
		 else ofSetHexColor(0x4ccae9);
		 //ofEnableAlphaBlending();
		 //ofSetColor(255,0,0,0);
		 //ofSetHexColor(0xe63b8b);
		 //	boxes[i].draw();
		 
		 }*/
		
		
		// animal boxes
		/*for(int i=0; i<boxes.size(); i++) {
		 //ofFill();
		 SoundData * data = (SoundData*)boxes[i].getData();
		 //ofEnableAlphaBlending();
		 //ofSetColor(R,G,B);
		 //ofSetHexColor(0xe63b8b);
		 //	boxes[i].draw();
		 
		 }*/
		
		
		for(int i=0; i<images.size(); i++) {
			
		    
			ofSetColor(circles[i].color.r, circles[i].color.g, circles[i].color.b);
			ofSetRectMode(OF_RECTMODE_CENTER);
			
		    ofPushMatrix();
	        
			ofTranslate(circles[i].getPosition().x, circles[i].getPosition().y);
			ofRotateZ(circles[i].getRotation());
		    images[i].draw(0,0);
			
		    ofSetRectMode(OF_RECTMODE_CORNER);
		    
		    ofPopMatrix();
			
			
		}
		
		
		
		/*for(int i=0; i<circles.size(); i++) {
		 ofFill();
		 SoundData * data = (SoundData*)circles[i].getData();
		 
		 if(data && data->bHit) ofSetHexColor(0xff0000);
		 else ofSetHexColor(0x4ccae9);
		 
		 
		 circles[i].draw();
		 }*/
		
		//ofSetColor(255,255,130);
		//	
		//	ofDrawBitmapString("drawing mode: inward", 50, 90);
		//		
		//	ofDrawBitmapString("drawing mode: outward", 50, 120);
		//	
		//	ofDrawBitmapString("drawing mode: clockwise", 50, 150);
		//	
		//	ofDrawBitmapString("drawing mode: counter-clockwise", 50, 170);
		//		
		//		
		//			
		//			
		//	
		//	string info = "";
		//	info += "FPS: "+ofToString(ofGetFrameRate(), 1)+"\n";
		//	info += "FPS: "+ofToString(R, 1)+"\n";
		//	info += "FPS: "+ofToString(G, 1)+"\n";
		//	info += "FPS: "+ofToString(B, 1)+"\n";
		//	ofSetHexColor(0x444342);
		//	ofDrawBitmapString(info, 30, 30);
		//		
		
		
		/*for(int i=0; i<customParticles.size(); i++) {
		 customParticles[i].draw();
		 }*/
		
		ofNoFill();
		//ofSetHexColor(0x444342);
		ofEnableAlphaBlending();
		ofSetColor(255, 0, 255,0);
		ofEnableAlphaBlending();
		//if(drawing.size()==0) 
		polyLine.draw();
		//else drawing.draw();
		
		
		
		//text
		//ofSetColor(80);
		
		//ofRect(20,20, 300, 800);
		
		
		
		ofSetColor(0, 0, 0);
	ofPushMatrix();
	ofTranslate(1005,550);
	ofRotateZ(-12);
	//font.drawString(typeStr, 0,0);
	
	ofDrawBitmapString(typeStr, 0,0);
	ofPopMatrix();	
		
		
		
	
	ofSetColor(255, 255, 255);//****important
		
	
		
	if (startscreen) {
		frontPage.draw(0, 0, ofGetWidth(),ofGetHeight());
	}
	
	
	
	
}

//--------------------------------------------------------------
void testApp::keyPressed(int key) {
	
	/*if(key == 'c') {
		float r = ofRandom(4, 20);		// a random radius 4px - 20px
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.1);
		circle.setup(box2d.getWorld(), mouseX, mouseY, r);
		
		circle.setData(new SoundData());
		SoundData * sd = (SoundData*)circle.getData();
		sd->soundID = ofRandom(0, N_SOUNDS);
		sd->bHit	= false;
		
		circles.push_back(circle);
	}*/
	
	
	if (typeStr.size() < 200){
		
        //typeStr += (char)key;
		
        int stringLength = typeStr.size();
		//cout << typeStr.size()%30 << endl;
		
        if (stringLength % 15 == 0 ){
            typeStr += "\n";
        }
		
    }
	
	
	
	if (key=='1') {
		
		b02=true;
		b03=false;
		b04=false;
		b05=false;
		
		//b02=!b02;
		//b02svg=!b02svg; 
	
	}
		
		
	if (key=='2') {
			
		b03=true;
		b02=false;
		b04=false;
		b05=false;
			
		//b03=!b03;
		//b03svg=!b03svg;
		
		}
	
	 if (key=='3') {
		
		b04=true;
		b02=false;
		b03=false;
		b05=false;
		//b04=!b04;
		//b03svg=!b03svg;
		
	}
	
	if (key=='4') {
		
		b05=true;
		b04=false;
		b02=false;
		b03=false;
		
		//b04=!b04;
		//b03svg=!b03svg;
		
	}
	if (key==OF_KEY_F1) {
		typeStr = " ";
		
	}
	
	
	if (key==OF_KEY_DOWN) {
		
		openArm=true;
		openBear=false;
		openGiraffe=false;
	}

	
	if (key==OF_KEY_RIGHT) {
		openBear=true;
		openArm=false;
		openGiraffe=false;
	}
	
	if (key==OF_KEY_LEFT) {
		openGiraffe=true;
		openBear=false;
		openArm=false;
	}
	
	if (key==OF_KEY_UP) {
		openBird=true;
		openGiraffe=false;
		openBear=false;
		openArm=false;
	}
	
	/*if (key=='o') {
		openOwl=true;
		openBird=false;
		openGiraffe=false;
		openBear=false;
		openArm=false;
	}*/
	
	
	//text
	
	if(key == OF_KEY_DEL || key == OF_KEY_BACKSPACE){
		typeStr = typeStr.substr(0, typeStr.length()-1);
		
	}
    
	
	
	else if(key == OF_KEY_RETURN ){
		typeStr += "\n";
	
		
	}
	
	
	
	
	else{
		if( bFirst ){
			typeStr.clear();
			bFirst = false;
		}
		typeStr.append(1, (char)key);
		markPixels=false;
	}
	if (key==OF_KEY_RETURN) {
		startscreen=false;
	}
	
	if(key == ' '){
		
		//pixelsLength =true;
		strLen = currentWord.length();
		wordLengths.push_back(strLen);
		currentWord.clear();
		w = strLen ;
	
		
		/*Circle c;
		 c.radius = strLen*5 ;
		 c.setup();
		 c.position.set(30, 100 + wordLengths.size() * 30);
		 
		 circles.push_back(c);*/
		
		//colorful rects
		
		
		ofxBox2dCircle circle;
		circle.setPhysics(3.0, 0.53, 0.1);
		circle.setup(box2d.getWorld(), ofGetWidth()/2, 100,10+w);
		circle.color.r = ofRandom(100,255); 
		circle.color.g = ofRandom(100,255); 
		circle.color.b = ofRandom(100,255); 
		
		circle.setData(new SoundData());
		SoundData * sd = (SoundData*)circle.getData();
		sd->soundID = ofRandom(0, N_SOUNDS);
		sd->bHit	= false;
		
		
		
	    circles.push_back(circle);
		
		
		
		
		/*float h = 20;	
		ofxBox2dRect rect;
		rect.setPhysics(3.0, 0.53, 0.1);
		rect.setup(box2d.getWorld(), mouseX, mouseY,10+w, 8+w);
		
		R=rect.color.r=ofRandom(100,255);
		G=rect.color.g=ofRandom(100,255);
		B=rect.color.b=ofRandom(100,255);

		boxes.push_back(rect);*/
		
	    
		//colorful animals
		
		ofImage temImg;
		
		
		if (openArm==true) {

			temImg.loadImage("armadillo.png");
			
		} 
		
		else if (openBear==true) {

			temImg.loadImage("bear.png");
		}
		
		else if (openGiraffe==true) {

			temImg.loadImage("giraffe.png");
			
		}else if (openBird==true) {
			
			temImg.loadImage("crane.png");
		
		}else if (openOwl==true) {
			
			temImg.loadImage("owl.png");
		}
		
		
		else {
			
		temImg.loadImage("crane.png");
		
		}
		
		temImg.resize(35+w*2, 30+w*2);
		images.push_back(temImg);
		
        
	}else {
		currentWord.append("key");
	}
	
}

//--------------------------------------------------------------
void testApp::keyReleased(int key) {
	
}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ) {
	
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button) {
	
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button) {
	


}

//--------------------------------------------------------------
void testApp::resized(int w, int h){
	
}

