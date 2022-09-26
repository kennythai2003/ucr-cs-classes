#include "Playlist.h"

    PlaylistNode::PlaylistNode() {
        uniqueID = "none";
        songName = "none";
        artistName = "none";
        songLength = 0;
        nextNodePtr = nullptr;
    }
    PlaylistNode::PlaylistNode(string uID, string sN, string aN, int sL) {
        uniqueID = uID;
        songName = sN;
        artistName = aN;
        songLength = sL;
        nextNodePtr = nullptr;
    }
    void PlaylistNode::InsertAfter(PlaylistNode *newSong){
        PlaylistNode *temp = this->nextNodePtr;
        this->nextNodePtr = newSong;
        newSong->nextNodePtr = temp;  
    } 
   
    void PlaylistNode::SetNext(PlaylistNode *newSong){
       this->nextNodePtr = newSong;
    } 

    string PlaylistNode::GetID() {
        return uniqueID;
    } 

    string PlaylistNode::GetSongName() {
        return songName;
    } 

    string PlaylistNode::GetArtistName() {
        return artistName;
    }

    int PlaylistNode::GetSongLength() {
        return songLength;
    } 

    PlaylistNode* PlaylistNode::GetNext(){
        return this->nextNodePtr;
    } 

    void PlaylistNode::PrintPlaylistNode() {
            cout << "Unique ID: " << this->uniqueID << endl;
            cout << "Song Name: " << this->songName << endl;
            cout << "Artist Name: " << this->artistName << endl;
            cout << "Song Length (in seconds): " << this->songLength<< endl;
    }
