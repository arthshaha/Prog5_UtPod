//
// Created by arthshaha on 10/23/2018.
//

#ifndef UNTITLED4_UTPOD_H
#define UNTITLED4_UTPOD_H
//#ifndef UTPOD_H
//#define UTPOD_H
#include "Song.h"

//UtPod class declaration
class UtPod
{
private:
    static const int MAX_MEMORY = 512;
    static const int SUCCESS = 0;
    static const int NO_MEMORY = -1;
    static const int NOT_FOUND = -2;

    struct SongNode
    {
        Song s;
        SongNode *next;
    };

    SongNode *songs;  //the head pointer

    int memSize;

public:
    UtPod();
    UtPod(int size);

    int addSong(Song const &s);
    int removeSong(Song const &s);
    void shuffle();
    void showSongList();
    void sortSongList();

    int getTotalMemory() {
        return memSize;
    }

    int getRemainingMemory();
    void clearMemory();
    ~UtPod();

};

#endif //UNTITLED4_UTPOD_H
