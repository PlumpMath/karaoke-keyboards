#include "Player.h"

Player::Player(){
    
}

void Player::play(){
    ofPlayer.play();
}

void Player::setup(string file){
    ofPlayer.load("song.mp3");
    ofPlayer.setVolume(0.75f);
    ofPlayer.setMultiPlay(false);
};

void Player::update(){
    ofSoundUpdate();
};

int Player::getTime(){
    return ofPlayer.getPositionMS();
};

void Player::draw(){
    ofSetColor(100, 200, 100);
    ofDrawRectangle(0,0,ofGetWidth(),100);
    ofSetColor(0, 0, 0);

    string tempStr = "click and drag\npct done: "+
        ofToString(ofPlayer.getPositionMS())+"\nspeed: "
        +ofToString(ofPlayer.getSpeed());
    ofDrawBitmapString(tempStr, 10,10);
    
};