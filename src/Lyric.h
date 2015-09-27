#pragma once
#include "ofMain.h"
#include "Parser.h"

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
    map<string, string> textWithSeconds;
    map<string,string>::iterator lyricIterator;
    int lyricsBoxHeight;
    ofVec2f center;
    ofColor colorTextToType;
    ofColor colorTextTyped;
    
private:
    void loadFile(string filename);
    ofTrueTypeFont	font;
};
