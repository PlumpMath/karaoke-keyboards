#include "Lyric.h"

Lyric::Lyric(){
    
};

void Lyric::setup(string filename){
    textWithSeconds = {
        {"00:01","Is this the real life -"},
        {"00:03","Is this just fantasy -"},
        {"00:07","Caught in a landslide -"},
        {"00:10","No escape from reality -"},
        {"00:14","Open your eyes"},
        {"00:17","Look up to the skies and see -"},
        {"00:24","I'm just a poor boy, I need no sympathy -"},
        {"00:31","Because I'm easy come, easy go,"},
        {"00:35","A little high, little low,"},
        {"00:38","Anyway the wind blows, doesn't really matter to me,"},
        {"00:47","                                             - to me -,"},
        {"00:55","Mama, just killed a man,"},
        {"01:01","Put a gun against his head,"},
        {"01:04","Pulled my trigger, now he's dead,"},
        {"01:08","Mama, life had just begun,"},
        {"01:15","But now I've gone and thrown it all away -"},
        {"01:22","Mama, ooo,"},
        {"01:29","Didn't mean to make you cry -"},
        {"01:32","If I'm not back again this time tomorrow -"},
        {"01:37","Carry on, carry on, as if nothing really matters -"},
        {"01:54","Too late, my time has come,"},
        {"02:01","Sends shivers down my spine,"},
        {"02:04","Body's aching all the time,"},
        {"02:08","Goodbye everybody - I've got to go -"},
        {"02:14","Gotta leave you all behind and face the truth -"},
        {"02:21","Mama, ooo -"},
        {"02:28","I don't want to die,"},
        {"02:32","I sometimes wish I'd never been born at all -"},
        {"03:05","I see a little silhouetto of a man,"},
        {"03:08","Scaramouche, scaramouche will you do the Fandango -"},
        {"03:12","Thunderbolt and lightning - very very frightening me -"},
        {"03:15","Galileo, Galileo,"},
        {"03:17","Galileo, Galileo"},
        {"03:19","Galileo figaro - Magnifico -"},
        {"03:22","But I'm just a poor boy and nobody loves me -"},
        {"03:25","He's just a poor boy from a poor family -"},
        {"03:28","Spare him his life from this monstrosity -"},
        {"03:33","Easy come easy go -, will you let me go -"},
        {"03:36","Bismillah! No -, we will not let you go - let him go -"},
        {"03:40","Bismillah! We will not let you go - let him go"},
        {"03:43","Bismillah! We will not let you go - let me go"},
        {"03:46","           Will not let you go - let me go"},
        {"03:48","           Will not let you go - let me go"},
        {"03:51","No, no, no, no, no, no, no -"},
        {"03:53","Mama mia, mama mia, mama mia let me go -"},
        {"03:57","Beelzebub has a devil put aside for me, for me -"},
        {"04:03","                                                 for me -"},
        {"04:15","So you think you can stone me and spit in my eye -"},
        {"04:21","So you think you can love me and leave me to die -"},
        {"04:26","Oh Baby - Can't do this to me baby -"},
        {"04:33","Just gotta get out - just gotta get right outta here -"},
        {"05:11","Nothing really matters,"},
        {"05:15","Anyone can see,"},
        {"05:18","Nothing really matters -, nothing really matters to me"},
        {"05:43","Any way the wind blows..."}
    };
    lyricIterator = textWithSeconds.begin();
    currentSentence = "";
    lyricsBoxHeight = ofGetHeight()/5;
    font.loadFont("BEBAS.ttf", lyricsBoxHeight/8);
    bottomCenter = ofVec2f(ofGetWidth()/2, ofGetHeight()-lyricsBoxHeight);
};

void Lyric::getLetter(int key){
    //cout << key << endl;
    typedSentence.push_back(key);
    comparedCurrentSentenceAndReceivedSentence(key);
}

void Lyric::update(int timeInMS){
    timeInMS -= 1000;
    int songMinutes = (timeInMS/60000)%60;
    int songSeconds = (timeInMS/1000)%60;

    string lyricMinutes = lyricIterator->first.substr(0,2);
    string lyricSeconds = lyricIterator->first.substr(3,2);
    //updateScore();
    if (songMinutes >= ofToInt(lyricMinutes) && songSeconds >= ofToInt(lyricSeconds)) {
        currentSentence = lyricIterator->second;
        vector<char> containerCurrentSentence(currentSentence.begin(), currentSentence.end());
        typedSentence.clear();
        ++lyricIterator;

        //containerCurrentSentence = buildContainerCurrentSentence(currentSentence);
    }
};

void Lyric::draw(){
    ofPushMatrix();
        ofTranslate(bottomCenter.x, bottomCenter.y);
        
        ofSetColor(243, 239, 111);
        ofDrawRectangle(-bottomCenter.x, 0, ofGetWidth(),lyricsBoxHeight);
        
        string toRead = currentSentence;
        ofSetColor(0,0,0);
        ofRectangle readBounds = font.getStringBoundingBox(toRead, 0, 0);
        font.drawString(currentSentence, -readBounds.width/2, (lyricsBoxHeight/3)+readBounds.height );
        
        string keyPressed;
        ofSetColor(100, 200, 200);
        for (auto const& s : typedSentence) { keyPressed += s; }
        ofRectangle keyPressedBounds = font.getStringBoundingBox(keyPressed, 0, 0);
        font.drawString(keyPressed, -keyPressedBounds.width/2, (lyricsBoxHeight/2)+readBounds.height);
    ofPopMatrix();
};



int Lyric::letterCatched(){
    return 1;
}

vector<char> buildContainerCurrentSentence(string _sentence){
    //string str = Parser::stringWithValidChars(_sentence);
    vector<char> data(_sentence.begin(), _sentence.end());
}

void Lyric::comparedCurrentSentenceAndReceivedSentence(int key){
    for (auto typed : typedSentence) {
        cout << "asdas" << endl;
        char test = 'a';
        if (char(typed) == test){
            cout << "casa" << endl;
            //cout << containerCurrentSentence.first << endl;
        }
        cout << typed << endl;
    }
    //typedSentence itera tra le lettere typed, se e' giusta incrementa il puntatore su vectorCurrentSentence e aumenta lo scora
    // se e' sbagliata lascia il puntatore dove e' e non far nulla.
    // finito questo verifica se ti serve tutto
    //vector<char> vectorCurrentSentence(currentSentence.begin(), currentSentence.end());
    
    
}
