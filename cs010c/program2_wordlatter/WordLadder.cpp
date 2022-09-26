#include <iostream>
#include <list>
#include <fstream>
#include <ostream>
#include <stack>
#include <queue>
#include <deque>
#include <string>

#include "WordLadder.h"

using namespace std;

WordLadder::WordLadder(const string &inputFile) {
    ifstream fin;
    string dictWord;
    fin.open(inputFile);

    if (!fin.is_open()) {
        cout << "Error opening" << inputFile << "." << endl;
        return;
    }

    while(fin >> dictWord) {
        if (dictWord.length() == 5) {
            dict.push_back(dictWord);
        }
        else {
            cout << "Error: word is not five characters." << endl;
            return;
        }
    }

    fin.close();
    return;
}

void WordLadder::outputLadder(const string &start, const string &end, const string &outputFile) {
    ofstream fout;
    fout.open(outputFile);

    if (!fout.is_open()) {
        cout << "Error opening: " << outputFile << "." << endl;
        fout.close();
        return;
    }

    stack<string> wordStack;
    wordStack.push(start);

    queue<stack <string> > ladder;
    ladder.push(wordStack);

    if (start == end) {
        fout << start << endl;
        fout.close();
        return;
    }

    list<string>::iterator word;

    while (!ladder.empty() && !dict.empty()) {
        for (word = dict.begin(); word != dict.end(); word++) {
            if (wordDifference(*word, ladder.front().top())) {
                if (*word == end) {
                    stack<string> endStack;
                    endStack.push(*word);
                
                    while (ladder.front().empty() == false) {
                        endStack.push(ladder.front().top());
                        ladder.front().pop();
                    }

                    if (endStack.empty() == false) {
                        while (endStack.empty() == false) {
                            fout << endStack.top() << endl;
                            endStack.pop();
                        }
                        fout.close();
                    }
                    /*
                    else {
                        fout << "No Word Ladder Found." << endl;
                        fout.close();
                        return;
                    }
                    */
                    return;
                }
                else {
                    stack<string> newStack = ladder.front();
                    newStack.push(*word);
                    ladder.push(newStack);
                    word = dict.erase(word);
                    --word;
                }
            }
        }
    ladder.pop();
    }
    fout << "No Word Ladder Found." << endl;
    fout.close();
    return;
}

bool WordLadder::wordDifference(const string &dictWord, const string &stackWord) {
    int count = 0;
    for (unsigned int i = 0; i < stackWord.size(); i++) {
        if (dictWord.at(i) != stackWord.at(i)) {
            count = count + 1;
        }
    }

    if (count == 1) {
        return true;
    }
    else {
        return false;
    }
}