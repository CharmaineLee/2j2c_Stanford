#pragma once

#include "ofMain.h"
#include "ofxGui.h"
#include "ofxTimeline.h"
#include "ofxPowerMate.h"
#include "ofxTLEmptyKeyframes.h"


class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
    
    ofLight light;
    
    ofxTimeline timeline;
    ofxTLEmptyKeyframe keyframe;
    ofSpherePrimitive faithBall;
    ofImage faithImage;
    ofEasyCam easyCam;
    ofVideoPlayer final;
    
    ofxXmlSettings settings;
//    //    ofFile imageSaveLocation;
//    
//    ofImage screenGrab;
//    //LIVE VIDEO CAMERA
//    ofVideoGrabber cameraLive;
//    int camWidth;
//    int camHeight;
//    
//    //OFX GUI
//    ofxPanel primePanel;
//    ofxIntSlider rortatePushPop;
//    ofxIntSlider xShift;
//    ofxIntSlider yShift;
//    
//    ofxIntSlider anotherRotation;
//    ofxIntSlider xShift2;
//    ofxIntSlider yShift2;
//    
//    ofxIntSlider brillo;
//    ofxButton clear;
//    ofxButton save;
//    //DRAWING TOOL
//    ofImage slit;
//    
//    //DRAWING SURFACE
//    ofFbo fullScan;
//    
    //POWER-MATE
    void onPowerMateData(powerData& d);
    ofxPowerMate powerMate;
    
    
    int slitHistoryI;
    int globalSpinVol;
    int globalClick;

		
};
