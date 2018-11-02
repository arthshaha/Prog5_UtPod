/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "UtPod.h"

using namespace std;

int main(int argc, char *argv[])
{
    UtPod t;

    Song s1("Arctic Monkeys", "poop", 1);
    int result = t.addSong(s1);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s2("Brockhampton", "asdf", 100);
    result = t.addSong(s2);
    cout << "result = " << result << endl;

    t.showSongList();

    Song s3("Kendrick Lamar", "skirt", 6);
    result = t.addSong(s3);
    cout << "result = " << result << endl;

    Song s4("Frank Ocean", "hahaha", 7);
    result = t.addSong(s4);
    cout << "result = " << result << endl;

    Song s5("Arth Shah", "wow", 241);
    result = t.addSong(s5);
    cout << endl <<"add result = " << result << endl;

    cout << endl << "memory = " << t.getRemainingMemory() << endl;

    t.showSongList();

    t.shuffle();
    cout << endl << "List has been shuffled" << endl << endl;

    cout << endl;
    t.showSongList();

    t.sortSongList();
    cout <<endl << endl <<"List has been sorted" << endl << endl;

    t.showSongList();

    result = t.removeSong(s4);
    cout << endl <<"delete result = " << result << endl;

    result = t.removeSong(s3);
    cout << endl <<"delete result = " << result << endl;

    t.showSongList();

    result = t.removeSong(s1);
    cout << endl <<"delete result = " << result << endl;

    t.showSongList();

    cout << endl <<"memory = " << t.getRemainingMemory() << endl;

    result = t.removeSong(s2);
    cout << endl <<"delete result = " << result << endl;

    result = t.removeSong(s4);
    cout << endl <<"delete result = " << result << endl;


    t.showSongList();

    result = t.addSong(s5);
    cout << endl <<"add result = " << result << endl;

    t.showSongList();
    cout << endl <<"memory = " << t.getRemainingMemory() << endl;


}