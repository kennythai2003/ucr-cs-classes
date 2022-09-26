#ifndef PLAYLIST_H
#define PLAYLIST_H

#include <iostream>
using namespace std;

class PlaylistNode {
 public:
    PlaylistNode();
    PlaylistNode(string, string, string, int);
    void InsertAfter(PlaylistNode*); //(1 pt)
    void SetNext(PlaylistNode*); // Mutator (1 pt)
    string GetID();
    string GetSongName();
    string GetArtistName();
    int GetSongLength();
    PlaylistNode* GetNext(); 
    void PrintPlaylistNode();
 private:
    string uniqueID; // Initialized to "none" in default constructor
    string songName; // Initialized to "none" in default constructor
    string artistName; // Initialized to "none" in default constructor
    int songLength; // Initialized to 0 in default constructor
    PlaylistNode* nextNodePtr; // Initialized to 0 in default constructor
};

#endif