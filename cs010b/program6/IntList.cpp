#include "IntList.h"
using namespace std;

//CHECK FOR CASES: empty list; when next goes towards an empty list; head & tail

IntList::~IntList() {
    while (head != nullptr) {
        IntNode *temp; 
        temp = head->next;
        delete head;
        head = temp;
    }
}

IntList::IntList() {
    head = nullptr;
    tail = nullptr;
}

void IntList::push_front(int val) {
    IntNode *temp = new IntNode(val);
    temp->next = head; 
    head = temp;
    
    if (tail == nullptr) {
        tail = head;
    }       
}

void IntList::pop_front() {
    if (!empty()) {
        IntNode *temp = head->next;
        delete head;
        head = temp;
    }

    if (head == nullptr) {
        tail = nullptr;
    }
}

bool IntList::empty() const {
    bool empty = false;
    if (head == nullptr && tail == nullptr) {
        empty = true;
    }
    return empty;
}

const int & IntList::front() const {
    return head->value;
}

const int & IntList::back() const {
    return tail->value;
}

ostream & operator<<(ostream & out, const IntList & list) {
    IntNode *curr = list.head;
    while (curr != nullptr) {
        if(curr->next != nullptr) {
            //takes all values before the tail
            out << curr-> value << " ";
            curr = curr -> next;
        }
        else {
            //outputs tail value
            out << curr-> value; 
            curr = curr -> next;           
        }
    }
    return out;
}

IntList::IntList(const IntList &cpy) {
    head = nullptr;
    tail = nullptr;
    IntNode *curr = cpy.head;
    while (curr != nullptr) {
        push_back(curr->value);
        curr = curr->next; 
    }
}

IntList & IntList::operator=(const IntList &rhs) {
    if (this != &rhs) {
        clear();
        IntNode *curr = rhs.head;
        while (curr != nullptr) {
            push_back(curr->value);
            curr = curr->next; 
        }
    }
    return *this;
}

void IntList::push_back(int value){
    IntNode *temp = new IntNode(value);
    if (empty()) {
        head = temp;
        tail = temp;
    }
    else if (head == tail) {
        tail = temp;
        head->next = tail;
    }
    else {
        tail->next = temp;
        tail = temp; 
    }
}

void IntList::clear() {
    IntNode *temp;
    if (empty()) {
        head = nullptr;
        tail = nullptr;
    }
    while (head != nullptr) {
        temp = head -> next;
        delete head;
        head = temp;
    }
    tail = nullptr; 
}

void IntList::selection_sort() {
    //algorithm derived from Selection Sort Video & 10.6 Code
    for (IntNode *i = head; i != nullptr; i = i-> next) {
        IntNode *min = i; 
        for (IntNode *j = i->next; j != nullptr; j = j-> next) {
            if (j->value < min->value) {
                swap (min->value, j->value);
            }
        }
    }
}

void IntList::insert_ordered(int value) {
    IntNode *temp = new IntNode (value);

    if (empty()) {
        head = temp;
        tail = temp;
    }
    else if (value <= head->value) {
        push_front(temp->value);
    }
    else if (value >= tail->value) {
        push_back(temp->value);
    }
    else {
        for (IntNode *prev = head; prev->value < value; prev = prev->next) {
            IntNode *curr = prev->next;
            if (curr->value >= value) {
                prev->next = temp;
                temp->next = curr;
            }
        }
    }
}

void IntList::remove_duplicates() {
    for (IntNode *i = head; i != nullptr; i = i-> next) {
        IntNode *prev = i;
        IntNode *curr = prev->next;
        while (curr != nullptr) {
            if (curr->value == i->value) {
                if (curr == tail) {
                    prev->next = nullptr;
                    tail = prev;
                    delete curr; 
                    curr = prev->next;
                }
                else {
                    prev->next = curr->next;
                    delete curr; 
                    curr = prev-> next;
                }
            }
            else {
                curr = curr->next;
                prev = prev->next;
            }
        }
    }
}

  // while (menuOption != 'a' && menuOption != 'd' && menuOption != 'c' 
    //         && menuOption != 's' && menuOption != 't' && menuOption != 'o') {
    //         cin >> menuOption;
    // }
    //     if (menuOption == 'q') {
    //         cout << "done";
    //     }
    //     else if (menuOption == 'a') {
    //         cout << "ADD SONG" << endl;
    //         cout << "Enter song's unique ID:" << endl;
    //         cin >> uniqueID;
    //         cout << "Enter song's name:" << endl;
    //         cin.ignore(); 
    //         getline(cin, songName);
    //         cout << "Enter artist's name:" << endl;
    //         getline(cin, artistName);
    //         cout << "Enter song's length (in seconds)" << endl;     
    //         cin >> songLength; 

    //         PlaylistNode* newSong = new PlaylistNode(uniqueID, songName, artistName, songLength);
    //         if (head == nullptr) {
    //             head = newSong;
    //             tail = newSong;
    //         }
    //         else {
    //             playlist.InsertAfter(newSong);
    //         }
    //     }
    //     else if (menuOption == 'd') {
    //         cout << "REMOVE SONG" << endl;
    //         cout << "Enter song's unique ID:" << endl;

    //         //cout << ____________ < "removed" << endl;
    //     }
    //     else if (menuOption == 'c') {
    //         cout << "CHANGE POSITION OF SONG" << endl;
    //         cout << "Enter song's current position:" << endl;
    //         cout << "Enter new position for song:" << endl;
    //         //cout << ____ " moved to position " << ____ << endl;
    //     }
    //     else if (menuOption == 's') {
    //         cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
    //         cout << "Enter artist's name:" << endl;
    //         getline(cin, artistName);

    //         PlaylistNode *currSong = head;
    //         int songPos = 1;
            
    //         while (currSong != nullptr) {
    //             if (currSong->GetArtistName() == artistName) {
    //                 cout << songPos << "." << endl << endl;
    //                 currSong->PrintPlaylistNode();
    //                 cout << endl;
    //             }
    //             currSong = currSong->GetNext();
    //             songPos = songPos + 1;
    //         }
    //     }
    //     else if (menuOption == 't') {
    //         cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

    //         int totalTime = 0;
    //         PlaylistNode* currSong = head;
    //         while (currSong != nullptr) {
    //             totalTime = totalTime + currSong->GetSongLength();
    //             currSong = currSong->GetNext();
    //         }
    //         cout << "Total time: " << totalTime << " seconds" << endl << endl;
    //     }
    //     else if (menuOption == 'o') {
    //         if (head != nullptr) {
    //             cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;
                
    //             int songPos = 1;
    //             PlaylistNode *currSong = head;
    //             while (currSong != nullptr) {
    //                 cout << songPos << "." << endl;
    //                 currSong->PrintPlaylistNode();
    //                 cout << endl;
    //                 songPos = songPos + 1;
    //                 currSong = currSong->GetNext();
    //             }
    //         }
    //         else {
    //             cout << "Playlist is empty" << endl << endl;
    //         }
    //     }


    // PlaylistNode playlist;
    // string uniqueID;
    // string songName;
    // string artistName;
    // int songLength;

    // PlaylistNode* head = nullptr;
    // PlaylistNode* tail =nullptr;

// void PrintMenu(string plName) {
//     cout << plName << " PLAYLIST MENU" << endl;
//     cout << "a - Add song" << endl;
//     cout << "d - Remove song" << endl;
//     cout << "c - Change position of song" << endl;
//     cout << "s - Output songs by specific artist" << endl;
//     cout << "t - Output total time of playlist (in seconds)" << endl;
//     cout << "o - Output full playlist" << endl;
//     cout << "q - Quit" << endl << endl;

//     cout << "Choose an option:"; //endl;
// }
