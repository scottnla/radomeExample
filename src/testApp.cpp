#include "testApp.h"

//--------------------------------------------------------------
void radomeExample::setup(){
  ofBackground(0,0,0);
  ofEnableSmoothing();
  ofSetFrameRate(30);
  ofFill();
  width = ofGetWidth();
  height = ofGetHeight();
  //configure our objects
  for(int i = 0; i < numRings; i++) {
    rings[i].index = i;
    rings[i].freq = (20.0 + i) / 30.0;
    rings[i].maxRadius = width/2 - 100*i;
    rings[i].radius = 0;
  }
  startTime = ofGetElapsedTimeMillis();
  startTime *= 0.001;

  	syphonOutput.setName("radome output");
    
	syphonClient.setup();
    
	syphonClient.setApplicationName("Arena");
	syphonClient.setServerName("Composition");
}

//--------------------------------------------------------------
void radomeExample::update(){
  float sec = ofGetElapsedTimeMillis();
  sec *= 0.001;
  sec -= startTime;
  for(int i = 0; i < numRings; i++) {
    rings[i].radius = rings[i].maxRadius*sin(rings[i].freq*sec);
  }
  
}

//--------------------------------------------------------------
void radomeExample::draw(){
  ofPushMatrix();
  ofTranslate(width/2, height/2);
  for(int i = 0; i < numRings; i++) {
    ofNoFill();
    ofCircle(0, 0, rings[i].radius);
  }
  ofPopMatrix();
  syphonOutput.publishScreen();
}

//--------------------------------------------------------------
void radomeExample::keyPressed(int key){

}

//--------------------------------------------------------------
void radomeExample::keyReleased(int key){

}

//--------------------------------------------------------------
void radomeExample::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void radomeExample::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void radomeExample::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void radomeExample::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void radomeExample::windowResized(int w, int h){

}

//--------------------------------------------------------------
void radomeExample::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void radomeExample::dragEvent(ofDragInfo dragInfo){ 

}
