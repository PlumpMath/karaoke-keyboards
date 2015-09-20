#include "ofMain.h"

class Player{

public:
    Player();
    void setup(string filename);
    void play();
    void update();
    void draw();
    int getTime();
    
    ofSoundPlayer ofPlayer;
    ofTrueTypeFont	font;
    
private:
};

