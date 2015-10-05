#pragma once
#include "ofMain.h"

class Letter{
public:
    Letter();
    void setup(string strLetter, ofColor color);
    void update(float point);
    void draw();
    
    string strLetter;
    ofColor color;
    ofVec2f startPostion;
    ofVec2f endPostion;
    ofVec2f currentPostion;
    
    int alpha = 255;
};