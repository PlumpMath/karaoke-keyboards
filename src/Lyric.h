#pragma once
#include "ofMain.h"
#include "Parser.h"
#include "Letter.h"
#include "penner.h"

class Lyric{
public:
    Lyric();
    void setup(string filename, ofColor colorTextToType, ofColor colorTextTyped);
    void update(int time);
    void draw();
    bool letterCatched(int key);
    
    string currentSentence;
    string sentenceToType;
    stringstream typedSentenceCorrect;
    
    int positionReachedInCurrentSentence;
    ofVec2f witdhCurrentSentence;
    map<string, string> textWithSeconds;
    map<string,string>::iterator lyricIterator;
    
    vector<Letter> wrongTyped;
    
    int lyricsBoxHeight;
    
    ofVec2f center;
    ofColor colorTextToType;
    ofColor colorTextTyped;
    
private:
    void drawErrors(int posX, int posY);
    void loadFile(string filename);
    ofTrueTypeFont	font;
};
