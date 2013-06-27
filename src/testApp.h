#pragma once

#include "ofMain.h"
#include "ofxSyphon.h"

class radomeExample : public ofBaseApp{
 public:
  void setup();
  void update();
  void draw();
		
  void keyPressed(int key);
  void keyReleased(int key);
  void mouseMoved(int x, int y);
  void mouseDragged(int x, int y, int button);
  void mousePressed(int x, int y, int button);
  void mouseReleased(int x, int y, int button);
  void windowResized(int w, int h);
  void dragEvent(ofDragInfo dragInfo);
  void gotMessage(ofMessage msg);

  struct Ring {
    int index;
    float freq;
    float maxRadius;
    float radius;
  };
  
  //visuals
  float width, height;
  static const int numRings = 6;
  Ring rings[numRings];
  float startTime;
  
  //audio
  ofxSyphonClient syphonClient;
    ofxSyphonServer syphonOutput;
};
