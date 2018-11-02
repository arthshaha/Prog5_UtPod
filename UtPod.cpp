//
// Created by arthshaha on 10/30/2018.
//
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <utility>
#include "UtPod.h"


using namespace std;

UtPod::UtPod() {
    memSize = MAX_MEMORY ;
    songs = NULL ;
}
UtPod::UtPod(int size)
{
    if(size < 0 || size > MAX_MEMORY)
        memSize = MAX_MEMORY;
    else
        memSize = size;
    songs = NULL;
}
int UtPod::addSong(const Song &s) {
    if(getRemainingMemory()<s.getSize()){
        return NO_MEMORY;
    }
    SongNode *newSong=new SongNode;
    newSong->s=s;
    newSong->next=songs;
    songs=newSong;
    return SUCCESS;
}
int UtPod::removeSong(Song const &s){
    SongNode *current=songs;
    SongNode *behind=NULL;
    if(current != NULL && current->s == s){
        behind = current->next;
        delete current;		//delete first node
        songs = behind;		//make head/songs equal to second node (ptr->nxt)
        return SUCCESS;
    }
    while(current!=NULL){
       /* if(current==songs&&current->s==s){
            delete current;
            return SUCCESS;
        }*/
        if(current->s==s){
            behind->next=current->next;
            delete current;
            return SUCCESS;
        }
        behind=current;
        current=current->next;
    }
    /*if(behind==NULL)
        songs=songs->next;
    else
        behind->next=current->next;*/
    return NOT_FOUND;

}
void UtPod::shuffle(){
    SongNode *ptr1=songs;
    SongNode *ptr2=songs;
    srand(time(0));
    int numSongs=0;
    while(ptr1!=NULL){
        numSongs++;
        ptr1=ptr1->next;
    }
    ptr1=songs;
    for(int i=0;i<2*numSongs;i++){
        for(int j=0;j<rand()%numSongs;j++){
            ptr1=ptr1->next;
        }
        for(int k=0;k<rand()%numSongs;k++){
            ptr2=ptr2->next;
        }
        swap(ptr1->s,ptr2->s);
        ptr1=songs;
        ptr2=songs;
    }

}
void UtPod::showSongList(){
    SongNode *ptr=songs;
    while(ptr!=NULL){
        cout << ptr->s.getArtist() << ", " << ptr->s.getTitle() << ", " << ptr->s.getSize() << "MB" << endl;
        ptr=ptr->next;
    }
}
void UtPod::sortSongList(){
    if(songs==NULL)
        return;
    SongNode *ptr1;
    SongNode *ptr2;
    Song tempSong;
    for(ptr2=songs;ptr2!=NULL;ptr2=ptr2->next){
        for(ptr1=ptr2->next;ptr1!=NULL;ptr1=ptr1->next){
            if(ptr2->s > ptr1->s){
                swap(ptr1->s,ptr2->s);
            }
        }
    }
}
int UtPod::getRemainingMemory(){
    int total=0;
    SongNode *ptr=songs;
    while(ptr!=NULL){
        total=total+ptr->s.getSize();
        ptr=ptr->next;
    }
    return memSize-total;
}
void UtPod::clearMemory(){
    SongNode *ptr = songs;
    while(ptr !=  NULL){
        SongNode *nextNode = ptr->next;
        delete(ptr);
        ptr = nextNode;
    }
    songs = NULL;
}

UtPod::~UtPod(){
    clearMemory();
}