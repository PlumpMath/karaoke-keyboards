#pragma once

#include "ofMain.h"
#include "Parser.h"

class Score{
public:
    Score();
    void setup(map<string, string> textWithSeconds);
    void onePointMore();
    void draw();
    
    int totPoints;
    int actualPoints;
    ofVec2f scorePositon;
    ofVec2f paddingRightTop;
    ofTrueTypeFont font;

};


