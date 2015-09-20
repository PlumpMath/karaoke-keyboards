#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    
    // on OSX: if you want to use ofSoundPlayer together with ofSoundStream you need to synchronize buffersizes.
    // use ofFmodSetBuffersize(bufferSize) to set the buffersize in fmodx prior to loading a file.
    player.setup("song.mp3");
    lyric.setup("lyrics.txt");
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255,255,255);
    player.update();
    lyric.update(player.getTime());
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw();
    lyric.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    lyric.getLetter(key);
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
    player.play();
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
