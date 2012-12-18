#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	
	ofSetVerticalSync(true);
	ofSetFrameRate(60);
	ofBackground(0,0,0);
	ofEnableAlphaBlending();
	
	pdfRendering = false;
}

//--------------------------------------------------------------
void testApp::update(){
	
	for (int i = 0; i < particles.size(); i++) {
		particles[i].resetForce();
		//particles[i].addForce(0,0.04);//gravity
		particles[i].addDampingForce();
		particles[i].update();
		
		particles[i].alpha = ofMap(i, 0, particles.size(), 0, 255, true);
	}
}
	
			

//--------------------------------------------------------------
void testApp::draw(){
	ofSetColor(0x000000);
	
	if( !pdfRendering ){
		ofDrawBitmapString("press r to start pdf multipage rendering", 32, 50);
	}
    
	for (int i = 0; i < particles.size(); i++){
		
		particles[i].draw();
	}
	
//-------------------	
	//
//	ofBeginShape();
//	//ofPushMatrix();
//	ofSetCircleResolution(8);
//	ofCircle(pos.x * 2, pos.y* 2, radiusSize);
//	ofSetLineWidth(2);
//	ofLine(pos.x *2,pos.y *2,(pos.x *2)+ 10,(pos.y *2)+10);
//	ofLine(pos.x *2,pos.y *2,(pos.x *2)-10,(pos.y *2)-10);
//	//ofPopMatrix();	
//	ofEndShape();
	
////--------------------
//	
//	ofBeginShape();
//	ofPushMatrix();
//	ofSetColor(0, 0, 223);
//	ofLine(pos.x*3, pos.y*3, (pos.x*3)+24,(pos.y*3)+24);
//	ofPopMatrix();
//	ofEndShape();
//
}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
	
	switch (key){
			
				
        case'r':
            
            pdfRendering = !pdfRendering;
            if( pdfRendering ){
                ofSetFrameRate(12);  // so it doesn't generate tons of pages
                ofBeginSaveScreenAsPDF("recording-"+ofGetTimestampString()+".pdf", true);
            }else{
                ofSetFrameRate(60);
                ofEndSaveScreenAsPDF();		
            }
            break;
	}
	

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
	
	if (particles.size()>100) {
		particles.erase(particles.begin());
	}
	
	float vx = ofRandom(-4,4);
    float vy = ofRandom(-4,4);
    particle temp;
    temp.setInitialCondition(x,y,vx, vy);	
    particles.push_back(temp);

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
