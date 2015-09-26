#pragma once

#include "ofMain.h"
#include "Parser.h"

class Score{
public:
    Score();
    void setup(map<string, string> textWithSeconds);
    void update(int rightKey);
    void draw();
    
    int totPoints;
    ofVec2f scorePositon;
    ofVec2f paddingRightTop;
    ofTrueTypeFont font;

};


