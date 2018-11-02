//
// Created by arthshaha on 10/30/2018.
//

#include <cstdlib>
#include <string>
#include "Song.h"
using namespace std;
Song::Song(){
    artist = "";
    title = "";
    size = 0;
}
Song::Song(string artist, string title, int size){
    this->artist = artist;
    this->title = title;
    this->size = size;
}
string Song::getTitle() const{
    return title;
}
void Song::setTitle(string title){
    this->title = title;
}
string Song::getArtist() const{
    return artist;
}
void Song::setArtist(string artist){
    this->artist = artist;
}
int Song::getSize() const{
    return size;
}
void Song::setSize(int size){
    this->size = size;
}
void Song::printSong(){
    cout << "Artist: " << artist;
    cout << ", Title: " << title;
    cout << ", Size: " << size << endl;
}
bool Song::operator >(Song const &s) {
    if (artist>s.artist)
        return true;
    else if(artist==s.artist){
        if(title>s.title)
            return true;
        else if(title==s.title){
            if(size>s.size)
                return true;
            else
                return false;
        }
    }
    return false;
}
bool Song::operator <(Song const &s) {
    if (artist<s.artist)
        return true;
    else if(artist==s.artist){
        if(title<s.title)
            return true;
        else if(title==s.title){
            if(size<s.size)
                return true;
            else
                return false;
        }
    }
    return false;
}
bool Song::operator ==(Song const &s)
{
    return (title == s.title &&
            artist == s.artist &&
            size == s.size);
}