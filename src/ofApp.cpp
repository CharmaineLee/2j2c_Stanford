#include "ofApp.h"
#include <vector>
#include "ofxTLKeyframes.h"

//--------------------------------------------------------------
void ofApp::setup(){
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
    timeline.setFrameRate(100);
    timeline.setDurationInFrames(20000);
    timeline.setLoopType(OF_LOOP_NORMAL);
    
    //POWER-MATE
    powerMate.conecta();
    ofAddListener(powerMate.tengoInfo, this, &ofApp::onPowerMateData);
    
    //defining global variables
    buttonClickTracker = 0;
}

//--------------------------------------------------------------
void ofApp::update(){
    ofxTLKeyframe* frames = new ofxTLKeyframe();
    
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
    std::cout << ben.getXMLStringForKeyframes(keyframes) << std::endl;
}

void ofApp::onPowerMateData(powerData& d){
    // button click
    if (d.presionado == 1) {
//        slitHistoryI = slitHistoryI + 1;
        //each call to "add keyframes" add's another track to the timeline
        if (buttonClickTracker == 0) {
            timeline.addCurves("Rotate X", ofRange(0, 360));  //loads XML file
            timeline.addCurves("Rotate Y", ofRange(0, 360));
            timeline.addCurves("Zoom",     ofRange(-200,850));
            buttonClickTracker = 1;
        }
        else {
            timeline.clear();
            buttonClickTracker = 0;
        }
        

    }
    else {
       globalSpinVol = globalSpinVol + d.rollVar;
    }
    
   // globalClick = d.presionado;
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
            float zoomAmount = timeline.getValue("Zoom");
            ofTranslate(ofGetWidth()/2.0, ofGetHeight()/2.0, globalSpinVol); // zoom amount 
            
            //Read the values out of the timeline and use them to change the viewport rotation
            ofRotate(globalSpinVol, 1, 0, 0);
            ofRotate(timeline.getValue("Rotate Y"), 0, 1, 0);
            
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
