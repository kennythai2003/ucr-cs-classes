#include "Playlist.h"
#include <iostream>
#include <string>
using namespace std;

void PrintMenu(string);



int main() {
    string playlistTitle;
    cout << "Enter playlist's title:" << endl;
    getline(cin, playlistTitle);
    cout << endl;
    PrintMenu(playlistTitle);

    return 0;
}

void PrintMenu(string plName) {
    // PlaylistNode playlist;
    string uniqueID;
    string songName;
    string artistName;
    int songLength;

    PlaylistNode* head = nullptr;
    PlaylistNode* tail = nullptr; 
    PlaylistNode* newSong = nullptr;
    
    cout << plName << " PLAYLIST MENU" << endl;

    cout << "a - Add song" << endl;
    cout << "d - Remove song" << endl;
    cout << "c - Change position of song" << endl;
    cout << "s - Output songs by specific artist" << endl;
    cout << "t - Output total time of playlist (in seconds)" << endl;
    cout << "o - Output full playlist" << endl;
    cout << "q - Quit" << endl << endl;

    cout << "Choose an option:" << endl;    

    char menuOption;
    cin >> menuOption;
    cin.ignore();

    while (menuOption != 'a' && menuOption != 'd' && menuOption != 'c' 
        && menuOption != 's' && menuOption != 't' && menuOption != 'o'&& menuOption != 'q') {
            cin >> menuOption;
    }
    
    while (menuOption != 'q') {
     if (menuOption == 'a') {
        cout << "ADD SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        getline(cin, uniqueID);
        cout << "Enter song's name:" << endl;
        getline(cin, songName);
        cout << "Enter artist's name:" << endl;
        getline(cin, artistName);
        cout << "Enter song's length (in seconds):" << endl;     
        cin >> songLength; 
        cout << endl;

        newSong = new PlaylistNode(uniqueID, songName, artistName, songLength);

        if (head == nullptr) {
            // cout << "empty" << endl;
            head = newSong;
            tail = newSong;
        }
        else {
            // cout << "works" << endl;
            PlaylistNode* temp = tail;
            tail = newSong;
            temp -> SetNext(newSong);
        }    
        // PrintMenu(plName);
    }
    else if (menuOption == 'd') {
        cout << "REMOVE SONG" << endl;
        cout << "Enter song's unique ID:" << endl;
        getline(cin, uniqueID);

        if (head->GetID() == uniqueID) {
            songName = head->GetSongName();

            PlaylistNode* temp = head;
            head = temp->GetNext();
            delete temp;
        }
        else {
            PlaylistNode* prevSong = nullptr;
            PlaylistNode* currSong = head;

            while(currSong->GetNext() != nullptr && currSong->GetID() != uniqueID){
                prevSong = currSong;
                currSong = currSong->GetNext();
            }
            
            if(currSong == tail){
                tail = prevSong;
                prevSong->SetNext(nullptr);

                songName = currSong->GetSongName();
                delete currSong;
            }
            else{
                prevSong->SetNext(currSong->GetNext());

                songName = currSong->GetSongName();
                delete currSong;
             }
           }
        cout << "\"" << songName << "\"" << " removed." << endl << endl;
        // PrintMenu(plName);
    }
    else if (menuOption == 'c') {
        int currPos;
        int newPos;
        cout << "CHANGE POSITION OF SONG" << endl;
        cout << "Enter song's current position:" << endl; 
        cin >> currPos;
        cout << "Enter new position for song:" << endl;
        cin >> newPos;

        PlaylistNode* prevSong = nullptr;
        PlaylistNode* currSong = head;

        int numNodes = 0;
        //count num of nodes
        for(PlaylistNode* i = head; i != nullptr; i = i->GetNext()){
            numNodes = numNodes + 1;
        }

        //search for the song in the current pos
        for(int i = 0; i < currPos - 1; ++i){
            prevSong = currSong; //maintains where our currSong is
            currSong = currSong->GetNext(); //finds what the currSong next song is
        }

        //case where we are moving the head (pos 1)
        if(head == currSong) {
            //keeps track of the second song
            head = currSong->GetNext();
        }
        else {
            prevSong->SetNext(currSong->GetNext());
            //previous song's next song is set to currsongs next song
        }

        //if the user enters a new position that is less than 1, move the node to the head
        if(newPos <= 1){
            currSong->SetNext(head); //makes currsong next song the head
            head = currSong; // head is now the second song whlist currsong is the head
            cout << "\"" << currSong->GetSongName() << "\"" << " moved to position 1" << endl;
        }
        //if the user enters a new position greater than n, move the node to position of the tail
        else if(newPos >= numNodes){
            tail->SetNext(currSong); //makes the last song next song be currSong
            currSong->SetNext(nullptr); //makes currSong's next song is now set to nullptr
            tail = currSong; //tail is now second to last, and currsong is moved to the last position
            cout << "\"" << currSong->GetSongName() << "\"" << " moved to position " << numNodes << endl;
        }
        else {
            prevSong = head; 
            for(int i = 1; i < newPos - 1; ++i){
               prevSong = prevSong->GetNext();
               //for loop used to find the newpositions song next song (holds this val)
            }
            currSong->SetNext(prevSong->GetNext());
            //currSong's next song is now the new positions next song
            prevSong->SetNext(currSong);
            //
            cout << "\"" << currSong->GetSongName() << "\"" << " moved to position " << newPos << endl;
            cout << endl;
        }

        // PrintMenu(plName);
    }
    else if (menuOption == 's') {
        cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
        cout << "Enter artist's name:" << endl << endl;
        getline(cin, artistName);

        PlaylistNode *currSong = head;
        int songPos = 1;
            
        while (currSong != nullptr) {
            if (currSong->GetArtistName() == artistName) {
                cout << songPos << "." << endl;
                currSong->PrintPlaylistNode();
                cout << endl;
            }
            currSong = currSong->GetNext();
            songPos = songPos + 1;
        }
        // PrintMenu(plName);
    }            
    else if (menuOption == 't') {
        cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

        int totalTime = 0;
        PlaylistNode* currSong = head;
        while (currSong != nullptr) {
            totalTime = totalTime + currSong->GetSongLength();
            currSong = currSong->GetNext();
        }
        cout << "Total time: " << totalTime << " seconds" << endl << endl;
        // PrintMenu(plName);
    }
    else if (menuOption == 'o') {
        cout << plName << " - OUTPUT FULL PLAYLIST" << endl;
        if (head != nullptr) {
            // cout << "oituputs" << endl;      
            int songPos = 1;
            PlaylistNode *currSong = head;
            while (currSong != nullptr) {
                cout << songPos << "." << endl ;
                currSong->PrintPlaylistNode();
                cout << endl;

                songPos = songPos + 1;
                currSong = currSong->GetNext();
            }
            // PrintMenu(plName);
        }    
        else {
            cout << "Playlist is empty" << endl << endl;
            // PrintMenu(plName);
        }       
    }
        cout << plName << " PLAYLIST MENU" << endl;

        cout << "a - Add song" << endl;
        cout << "d - Remove song" << endl;
        cout << "c - Change position of song" << endl;
        cout << "s - Output songs by specific artist" << endl;
        cout << "t - Output total time of playlist (in seconds)" << endl;
        cout << "o - Output full playlist" << endl;
        cout << "q - Quit" << endl << endl;

        cout << "Choose an option:" << endl;    

        cin >> menuOption; 
        cin.ignore();

        while (menuOption != 'a' && menuOption != 'd' && menuOption != 'c' 
        && menuOption != 's' && menuOption != 't' && menuOption != 'o'&& menuOption != 'q') {
            cin >> menuOption;
        } 
    }
}
