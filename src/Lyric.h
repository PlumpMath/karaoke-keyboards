#pragma once
#include "ofMain.h"
#include "Parser.h"

class Lyric{
public:
    Lyric();
    void setup(string filename);
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
    ofVec2f bottomCenter;
    
private:
    void updateScore();
    void getSentence();
    void comparedCurrentSentenceAndReceivedSentence(int key);
    ofTrueTypeFont	font;
};
