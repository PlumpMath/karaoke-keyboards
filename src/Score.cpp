#include "Score.h"
#include "Poco/RegularExpression.h"
#include <regex>

Score::Score(){

}

void Score::setup(map<string,string> text_with_seconds){
    totPoints = 0;
    for (map<string,string>::iterator it=text_with_seconds.begin(); it!=text_with_seconds.end(); it++) {
        string str = it->second;
        totPoints += Parser::stringWithValidChars(str).length();
    }
    
    paddingRightTop = ofVec2f(30,30);
    scorePositon = ofVec2f(ofGetWidth(), 0);
    font.loadFont("BEBAS.ttf", 30);
};

void Score::update(int rightKey){
    
};

void Score::draw(){
    ofPushMatrix();
        ofTranslate(scorePositon.x, scorePositon.y);
        string maxPoints = ofToString(totPoints);
        ofSetColor(0,0,0);
        ofRectangle maxPointsBounds = font.getStringBoundingBox(maxPoints, 0, 0);
        font.drawString(
                        maxPoints,
                        -maxPointsBounds.width-paddingRightTop.x,
                        (scorePositon.y + paddingRightTop.y+ maxPointsBounds.height)
        );
    ofPopMatrix();
};

