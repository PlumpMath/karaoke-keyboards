#include "ofMain.h"

class Lyric{
public:
    Lyric();
    void setup(string filename);
    void update(int time);
    void draw();
    void getLetter(int key);
    
    string currentSentence;
    vector<int> typedSentence;

    map<string, string> example;
    map<string,string>::iterator myIterator;

    int lyricsBoxHeight;
    ofVec2f bottomCenter;
    

    
private:
    void updateScore();
    void getSentence();
    ofTrueTypeFont	font;
};
