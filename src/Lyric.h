#pragma once
#include "ofMain.h"
#include "Parser.h"

class Lyric{
public:
    Lyric();
    void setup(string filename);
    void update(int time);
    void draw();
    void getLetter(int key);
    
    string currentSentence;
    vector<int> typedSentence;
    vector<int> reachedSentence;
    vector<char> containerCurrentSentence;

    map<string, string> textWithSeconds;
    map<string,string>::iterator lyricIterator;

    int lyricsBoxHeight;
    int letterCatched();
    ofVec2f bottomCenter;
    

    
private:
    void updateScore();
    void getSentence();
    vector<char> buildContainerCurrentSentence(string str);
    void comparedCurrentSentenceAndReceivedSentence(int key);
    ofTrueTypeFont	font;
};
