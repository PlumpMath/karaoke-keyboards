#include "Score.h"
#include "Poco/RegularExpression.h"
#include <regex>

Score::Score(){

}

void Score::setup(map<string,string> text_with_seconds){
    totPoints = 0;
    actualPoints = 0;
    for (map<string,string>::iterator it=text_with_seconds.begin(); it!=text_with_seconds.end(); it++) {
        string str = it->second;
        totPoints += Parser::stringWithValidChars(str, "[a-z_0-9]").length();
    }
    
    paddingRightTop = ofVec2f(30,30);
    scorePositon = ofVec2f(ofGetWidth(), 0);
    font.loadFont("BEBAS.ttf", 30);
};

void Score::onePointMore(){
    actualPoints ++;
};

void Score::draw(){
    ofPushMatrix();
        ofTranslate(scorePositon.x, scorePositon.y);
        string maxPoints = ofToString(totPoints);
        string pointsNow = ofToString(actualPoints);
        string score = pointsNow.append(" / ").append(maxPoints);
    
        ofSetColor(0,0,0);
        ofRectangle scoreBounds = font.getStringBoundingBox(score, 0, 0);
        font.drawString(
                        score,
                        -scoreBounds.width-paddingRightTop.x,
                        (scorePositon.y + paddingRightTop.y+ scoreBounds.height)
        );
    ofPopMatrix();
};

