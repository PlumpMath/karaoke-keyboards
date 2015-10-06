#include "letter.h"

Letter::Letter(string _strLetter, ofVec2f _cursorPosition, ofColor _color){
    strLetter = _strLetter;
    startPosition = _cursorPosition;
    color = _color;
    endPosition = ofVec2f(startPosition.x, ofGetHeight());
    direction = startPosition - endPosition;
}

void Letter::setup(){
    
}

void Letter::update(float pct){
    currentPosition = endPosition + direction * pct;
}

void Letter::draw(){
    
}




