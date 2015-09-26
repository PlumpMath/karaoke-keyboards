#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    // on OSX: if you want to use ofSoundPlayer together with ofSoundStream you need to synchronize buffersizes.
    // use ofFmodSetBuffersize(bufferSize) to set the buffersize in fmodx prior to loading a file.
    player.setup("qua.mp3");
    lyric.setup("lyrics.txt");
    score.setup(lyric.textWithSeconds);
}

//--------------------------------------------------------------
void ofApp::update(){
    ofBackground(255,255,255);

    lyric.update(player.getTime());
    player.update();
}

//--------------------------------------------------------------
void ofApp::draw(){
    player.draw();
    lyric.draw();
    score.draw();
}

void ofApp::startSongFromBeginning(){
    score.setup(lyric.textWithSeconds);
    lyric.setup("lyrics.txt");
    player.play();
}
//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    if(lyric.letterCatched(key)){
        score.onePointMore();
    }
    if (key == 13) { //press enter
        startSongFromBeginning();
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
    startSongFromBeginning();
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
    player.setup("song.mp3");
    lyric.setup("lyrics.txt");
    score.setup(lyric.textWithSeconds);
}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){
    
}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){
    
}
