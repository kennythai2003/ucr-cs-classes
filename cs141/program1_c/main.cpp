#include <bits/stdc++.h>
using namespace std;
 
int letterToNum(char);
int main()
{
    //add start position into the queue
    //enqueue knights potential moves
    //add new unvisited knight moves  
    int chessBoard[8][8];
 
    queue<pair<int, int>> bfsStack;
    //initalize board to 0 to represent empty spots
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < 8; ++j)
        {
            chessBoard[i][j] = 0;
        }
    }
 
    int takenSpaces = 0;
    cin >> takenSpaces;
    cin.ignore();
 
   
    char letter = 'a';
    int x = 0;
    int y = 0;
 
    for (int i = 0; i < takenSpaces; ++i)
    {
        cin >> letter;
        x = letterToNum(letter);
 
        cin >> y;
        y -= 1;
        cin.ignore();
       
        chessBoard[y][x] = 9;
 
        bfsStack.push({y, x});
        cout << "stack size: " << bfsStack.size() << endl;
    }
   
    char startLetter = 'a';
    cin >> startLetter;
    int startX = letterToNum(startLetter);
    int startY = 0;
    cin >> startY;
    startY -= 1;
    cin.ignore();
 
    chessBoard[startY][startX] = 1;
    //print chess board
    for (int i = 7; i >= 0; i--)
    {
        cout << i + 1 << ": ";
        for (int j = 0; j < 8; j++)
        {
        cout << chessBoard[i][j] << " ";
        }
        cout << endl;
    }  
    cout << "   a b c d e f g h" << endl;  
    return 0;  
}
 
 
int letterToNum(char chess)
{
    int move;
    if (chess == 'a')
    {
        move = 0;
    }
    if (chess == 'b')
    {
        move = 1;        
    }
    if (chess == 'c')
    {
        move = 2;        
    }
    if (chess == 'd')
    {
        move = 3;        
    }
    if (chess == 'e')
    {
        move = 4;        
    }
    if (chess == 'f')
    {
        move = 5;        
    }
    if (chess == 'g')
    {
        move = 6;        
    }
    if (chess == 'h')
    {
        move = 7;          
    }
    return move;
}
 