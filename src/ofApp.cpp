#include "ofApp.h"
#include "ofxTLEmptyKeyframes.h"

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
    
    //each call to "add keyframes" add's another track to the timeline
    timeline.addCurves("Rotate X", ofRange(0, 360));
    timeline.addCurves("Rotate Y", ofRange(0, 360));
    timeline.addCurves("Zoom",     ofRange(-200,850));

    //POWER-MATE
    powerMate.conecta();
    ofAddListener(powerMate.tengoInfo, this, &ofApp::onPowerMateData);
}

//--------------------------------------------------------------
void ofApp::update(){
    final.update();
}

void ofApp::onPowerMateData(powerData& d){ // Big thanks to Aman Tiwari for helping me decode ofxPowerMate
    // button click
//    if (d.presionado == 1) {
//        slitHistoryI = slitHistoryI + 1;
//    }
//    
    globalSpinVol = globalSpinVol + d.rollVar;
   // globalClick = d.presionado;
}



//--------------------------------------------------------------
void ofApp::draw(){
    
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
