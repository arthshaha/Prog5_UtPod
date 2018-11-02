//
// Created by arthshaha on 10/30/2018.
//

#ifndef UNTITLED4_SONG_H
#define UNTITLED4_SONG_H

#endif //UNTITLED4_SONG_H
#include <string>
#include <iostream>

using namespace std;

class Song{
private:
    string artist;
    string title;
    int size;

public:
    Song();
    Song(string artist, string title, int size);
    string getTitle() const;
    void setTitle(string title);
    string getArtist() const;
    void setArtist(string artist);
    int getSize() const;
    void setSize(int size);
    void printSong();
    bool operator ==(Song const &s);//Overloads the "==" operator
    bool operator <(Song const &s);//Overloads the "<" operator
    bool operator >(Song const &s);//Overloads the ">" operator

};


