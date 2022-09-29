#include <bits/stdc++.h>
using namespace std;
 
int letterToNum(char);
int main()
{
    int chessBoard[8][8];
    bool chessBoardBoolean[8][8];
    
    int boards = 1;
 
    int takenSpaces = 0; 
    char takenLetter = 'a';
    int takenX = 0, takenY = 0;
 
    char startLetter = 'a';    
    int startX = 0, startY = 0;
 
    char endLetter = 'a';
    int endX = 0, endY = 0;
 
    queue<pair<int, int>> bfsQueue;
    int a, b;
 
    cin >> takenSpaces;
    while (takenSpaces != -1)
    {
        //initialize board
        for (int i = 0; i < 8; ++i) 
        {
            for (int j = 0; j < 8; ++j) 
            {
                chessBoard[i][j] = 0;
                chessBoardBoolean[i][j] = true;
            }
        }      
 
        //take in marked spots
        for (int i = 0; i < takenSpaces; ++i) 
        {
            cin >> takenLetter >> takenY;
            takenX = letterToNum(takenLetter);
            takenY -= 1;
            cin.ignore();
            chessBoard[takenY][takenX] = -1;
            chessBoardBoolean[takenY][takenX] = false;
        }
 
        //grab starting position
        cin >> startLetter >> startY;
        startX = letterToNum(startLetter);
        startY -= 1;
        cin.ignore();
 
        chessBoard[startY][startX] = 0;
        chessBoardBoolean[startY][startX] = false;
        bfsQueue.push({startY, startX});
 
        cin >> endLetter >> endY;
        endX = letterToNum(endLetter);
        endY -= 1;
        cin.ignore();
 
        while (!bfsQueue.empty())
        {
            a = bfsQueue.front().first;
            b = bfsQueue.front().second;
 
            bfsQueue.pop();
            if (a + 2 < 8 && b + 1 < 8) 
            {
                if (chessBoard[a + 2][b + 1] != -1 && chessBoardBoolean[a + 2][b + 1] != false) 
                {
                    chessBoard[a + 2][b + 1] = chessBoard[a][b] + 1;
                    chessBoardBoolean[a + 2][b + 1] = false; 
                    if (a + 2 == endY && b + 1 == endX) 
                    {
                        cout << "Board " << boards << ": " << chessBoard[a + 2][b + 1] << " moves" << endl;
                        break;
                    }
                    bfsQueue.push({a + 2, b + 1});
                }
            }
        
            if (a + 2 < 8 && b - 1 >= 0) 
            {
                if (chessBoard[a + 2][b - 1] != -1 && chessBoardBoolean[a + 2][b - 1] != false) 
                {
                    chessBoard[a + 2][b - 1] = chessBoard[a][b] + 1;
                    chessBoardBoolean[a + 2][b - 1] = false;
                    if (a + 2 == endY && b - 1 == endX) 
                    {
                        cout << "Board " << boards << ": " << chessBoard[a + 2][b - 1] << " moves" << endl;
                        break;
                    }
                    bfsQueue.push({a + 2, b - 1});
                }
            }
            if (a - 2 >= 0 && b + 1 < 8) 
            {
                if (chessBoard[a - 2][b + 1] != -1 && chessBoardBoolean[a - 2][b + 1] != false) 
                {
                    chessBoard[a - 2][b + 1] = chessBoard[a][b] + 1;
                    chessBoardBoolean[a - 2][b + 1]= false;
                    if (a - 2 == endY && b + 1 == endX) 
                    {
                        cout << "Board " << boards << ": " << chessBoard[a - 2][b + 1] << " moves" << endl;
                        break;
                    }
                    bfsQueue.push({a - 2, b + 1});
                }
            }
            if (a - 2 >= 0 && b - 1 >= 0) 
            {
                if (chessBoard[a - 2][b - 1] != -1 && chessBoardBoolean[a - 2][b - 1] != false) 
                {
                    chessBoard[a - 2][b - 1] = chessBoard[a][b] + 1;;
                    chessBoardBoolean[a - 2][b - 1] = false;
                    if (a - 2 == endY && b - 1 == endX) 
                    {
                        cout << "Board " << boards << ": " << chessBoard[a - 2][b - 1] << " moves" << endl;
                        break;
                    }
                    bfsQueue.push({a - 2, b - 1});
                }
            }
 
            if (a + 1 < 8 && b + 2 < 8) 
            {
                if (chessBoard[a + 1][b + 2] != -1 && chessBoardBoolean[a + 1][b + 2] != false) 
                {
                    chessBoard[a + 1][b + 2] = chessBoard[a][b] + 1;;
                    chessBoardBoolean[a + 1][b + 2] = false;
                    if (a + 1 == endY && b + 2 == endX) 
                    {
                        cout << "Board " << boards << ": " << chessBoard[a + 1][b + 2] << " moves" << endl;
                        break;
                    }
                    bfsQueue.push({a + 1, b + 2});
                }
            }
            if (a - 1 >= 0 && b + 2 < 8) {
                if (chessBoard[a - 1][b + 2] != -1 && chessBoardBoolean[a - 1][b + 2] != false) 
                {
                    chessBoard[a - 1][b + 2] = chessBoard[a][b] + 1;;
                    chessBoardBoolean[a - 1][b + 2] = false;
                    if (a - 1 == endY && b + 2 == endX) 
                    {
                        cout << "Board " << boards << ": " << chessBoard[a - 1][b + 2] << " moves" << endl;
                        break;
                    }
                    bfsQueue.push({a - 1, b + 2});
                }
            }
            if (a + 1 < 8 && b - 2 >= 0) {
                if (chessBoard[a + 1][b - 2] != -1 && chessBoardBoolean[a + 1][b - 2] != false) 
                {
                    chessBoard[a+1][b-2] = chessBoard[a][b] + 1;
                    chessBoardBoolean[a + 1][b - 2] = false;
                    if (a + 1 == endY && b - 2 == endX) 
                    {
                        cout << "Board " << boards << ": " << chessBoard[a + 1][b - 2] << " moves" << endl;
                        break;
                    }
                    bfsQueue.push({a + 1, b - 2});
                }
            }
            if (a - 1 >= 0 && b - 2 >= 0) 
            {
                if (chessBoard[a - 1][b - 2] != -1 && chessBoardBoolean[a - 1][b - 2] !=false) 
                {
                    chessBoard[a - 1][b - 2] = chessBoard[a][b] + 1;;
                    chessBoardBoolean[a - 1][b - 2] = false;
                    if (a - 1 == endY && b - 2 == endX) 
                    {
                        cout << "Board " << boards << ": " << chessBoard[a - 1][b - 2] << " moves" << endl;
                        break;
                    }
                    bfsQueue.push({a - 1, b - 2});
                }
            } 
        }
        if (chessBoardBoolean[endY][endX] == true) 
        {
            cout << "Board " << boards << ": not reachable" << endl;
        }
        while (!bfsQueue.empty())
        {
            bfsQueue.pop();
        }
        cin >> takenSpaces;
        boards += 1;
    } 
 
    return 0;
}
 
int letterToNum(char chess) {
  int move;
  if (chess == 'a') {
    move = 0;
  }
  if (chess == 'b') {
    move = 1;
  }
  if (chess == 'c') {
    move = 2;
  }
  if (chess == 'd') {
    move = 3;
  }
  if (chess == 'e') {
    move = 4;
  }
  if (chess == 'f') {
    move = 5;
  }
  if (chess == 'g') {
    move = 6;
  }
  if (chess == 'h') {
    move = 7;
  }
  return move;
}