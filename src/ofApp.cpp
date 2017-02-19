#include "ofApp.h"
#include <vector>
#include "ofxTLKeyframes.h"

//--------------------------------------------------------------
void ofApp::setup(){
    //GUI
    GUI.setup();
    GUI.add(xRotation.setup("X Rotation: ", 0, 0, 360));
    GUI.add(yRotation.setup("Y Rotation: ", 0, 0, 360));
    GUI.add(zoomAmount.setup("Zoom: ", 0, -200,850));
    GUI.add(stop_and_PlayBack.setup("REPLAY", false));
    
    //    GUI.add(play.setup("Play Video"));
    //    GUI.add(pause.setup("Pause Video"));
    
    //OSC SETUP
    //--------------------
    //--------------------
    //--------------------
    //--------------------
    
    
    std::clock_t start;
    double duration;
    
    start = std::clock();
    
    
    ofSetFrameRate(60);
    ofSetVerticalSync(true);
    ofEnableSmoothing();
    
    
    final.load("Test_File.mp4");
    faithImage.update();
    
    ofDisableAlphaBlending();
    ofEnableDepthTest();
    //glEnable(GL_DEPTH_TEST);
    ofEnableLighting();
    
    light.setPosition(ofGetWidth()*.5, ofGetHeight()*.25, 0);
    light.enable();
    
    //Timeline setup and playback details
    ofxTimeline::removeCocoaMenusFromGlut("CurvesColorsDemo");
    
    timeline.setup();
    timeline.setFrameRate(60);
    timeline.setDurationInFrames(60*30);
    timeline.setLoopType(OF_LOOP_NORMAL);
    
    
    //defining global variables
    buttonClickTracker = 0;
    
    clock_t startTime = clock();
}

//--------------------------------------------------------------
void ofApp::update(){
    
    if (stop_and_PlayBack == true) {//loads XML file
        timeline.addCurves("Rotate X", ofRange(0, 360));
        timeline.addCurves("Rotate Y", ofRange(0, 360));
        timeline.addCurves("Zoom",     ofRange(-200,850));
        buttonClickTracker = 1;
    } else {
        timeline.clear();
    }
    
    //OSC RECIEVING LOOP
    //--------------------
    //--------------------
    //--------------------
    //--------------------
    
    ofxTLKeyframe* frames = new ofxTLKeyframe();
    frames->time = clock();
    frames->value = globalSpinVol;
    //    if (globalSpinVol == 0) {
    //        frames->value = globalSpinVol;
    //    } else {
    //        frames->value = (float) 1/globalSpinVol;
    //    }
    //
    keyframes.push_back(frames);
    
    
    ofxTLKeyframe apple;
    apple.time = 0;
    apple.value = 1.1;
    //
    ofxTLKeyframes ben;
    //    ben.time = 0;
    //    ben.value = 1.1;
    //    ben.addKeyframe();
    //    ben.save();
    ben.getXMLStringForKeyframes(keyframes);
    final.update();
    //    std::cout << "hello world";
    //std::cout << ben.getXMLStringForKeyframes(keyframes) << std::endl;
}

//--------------------------------------------------------------
void ofApp::draw(){
    
    //    for (int i = 0; i < stored.size(); i++) {
    //        std::cout << stored.at(i) << std::endl;
    //    }
    
    ofBackground(210,70,10);
    
    ofPushMatrix();
    ofPushStyle();
    {
        final.play();
        
        ofEnableDepthTest();
        glMatrixMode(GL_TEXTURE);
        glPushMatrix();
        
        ofScale(2560,1280);
        glMatrixMode(GL_MODELVIEW);
        
        ofPushMatrix();
        {
            //float zoomAmount = timeline.getValue("Zoom");
            
            //ZOOM VARIABLE, -200,850
            
            ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0, zoomAmount); // zoom amount
            
            //Read the values out of the timeline and use them to change the viewport rotation
            
            //X-ROTATION VARIABLE, 0,360
            ofRotate(xRotation, 1, 0, 0);
            
            //Y-ROTATION VARIABLE, 0,360
            ofRotate(yRotation, 0, 1, 0);
            
            ofSetColor(255,255,255);
            final.getTexture().bind();
            ofDrawSphere(200);
            final.getTexture().unbind();
        }
        ofPopMatrix();
        
        glMatrixMode(GL_TEXTURE);
        glPopMatrix();
    }
    
    ofPopMatrix();
    ofPopStyle();
    
    glMatrixMode(GL_MODELVIEW);
    timeline.draw();
    GUI.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    if (key == 'v'){
        timeline.toggleShow();
    }
    
    else if (key == 'p'){
        final.stop();
    }
}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
    
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
    
    
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
    
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){
    
}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){
    
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 
    
}
