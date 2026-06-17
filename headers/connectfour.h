#ifndef CONNECTFOUR_H
#define CONNECTFOUR_H

#include <bits/stdc++.h>
using namespace std;
class ConnectFour{
public:
    int col1;
    int col2;
    int moves;
    int winner;
    vector<vector<char>> board;

    ConnectFour(){
        moves=0;
        board= vector<vector<char>> (6, vector<char> (7,' '));
    }

    void player1(){
        for(int i=5; i>=0; i--){
            if(board[i][col1]==' ')  {
                board[i][col1] = 'O';
                moves++;
                break;
            }
        }
     }

     void player2(){
        for(int i=5; i>=0; i--){
            if(board[i][col2]==' ')  {
                board[i][col2] = 'X';
                moves++;
                break;
            }
        }
    }

    bool draw(){
        if(moves == 42){
            cout << "IT'S A DRAW!";
            return true;
        }
        return false;
    }
    

    void input_player1(){
        cout << "Enter the position of O: ";
        cin >> col1;  
         while(true){
            if(col1<0 || col1>6) 
            {
                cout << "INVALID POSITION! TRY AGAIN\n"; 
                cin >> col1;
            }
            else if(board[0][col1]!=' ') {
                cout << "COLUMN FULL! TRY AGAIN\n";
                cin >> col1;
            }
            else break;
        } 
    }

    void input_player2(){
        cout << "Enter the position of X: ";
        cin >> col2; 
        while(true){
            if(col2<0 || col2>6) 
            {
                cout << "INVALID POSITION! TRY AGAIN \n"; 
                cin >> col2;
            }
            else if(board[0][col2]!=' ') {
                cout << "COLUMN FULL! TRY AGAIN \n";
                cin >> col2;
            }
            else break;
        } 
    }

    void print(){
        cout << " 0 1 2 3 4 5 6" << endl;
        for(int i=0; i<6; i++){
            for(int j=0; j<7; j++){
                cout << "|" << board[i][j];
            }
            cout << "|";
            cout << endl;
        }

        
    }

    bool win(){
        // FOR HORIZONTAL 
        for(int i=0; i<6; i++){
            for(int j=0; j<=3; j++){
                if(board[i][j]=='O' || board[i][j]=='X' ){
                if(board[i][j]==board[i][j+1] &&
                   board[i][j]==board[i][j+2] &&
                   board[i][j]==board[i][j+3] ){
                         if (board[i][j]=='O') {
                            cout << "O WON!!\n";
                            winner = 0;
                        }
                        else {
                            cout << "X WON!!\n";
                            winner = 1;

                        }
                        return true;
                   }
                }
            }
        }

        //FOR VERTICAL
         for(int i=0; i<=2; i++){
            for(int j=0; j<7; j++){
                if(board[i][j]=='O' || board[i][j]=='X' ){
                if(board[i][j]==board[i+1][j] &&
                   board[i][j]==board[i+2][j] &&
                   board[i][j]==board[i+3][j] ){
                       if (board[i][j]=='O') {
                            cout << "O WON!!\n";
                            winner = 0;
                        }
                        else {
                            cout << "X WON!!\n";
                            winner = 1;

                        }
                        return true;
                   }
                }
            }
        }
// FOR DIAGONALS
        // Bottom-left to top-right
        for(int i=0; i<=2; i++){
            for(int j=0; j<=3; j++){
                if(board[i][j]!=' ' && board[i][j]==board[i+1][j+1]
                    && board[i][j]==board[i+2][j+2]
                    && board[i][j]==board[i+3][j+3]){
                        if (board[i][j]=='O') {
                            cout << "O WON!!\n";
                            winner = 0;
                        }
                        else {
                            cout << "X WON!!\n";
                            winner = 1;

                        }
                        return true;
                    }
                }
            }

        // Top-left to bottom-right
        for(int i=3; i<6; i++){
            for(int j=0; j<=3; j++){
                if(board[i][j]!=' ' && board[i][j]==board[i-1][j+1]
                    && board[i][j]==board[i-2][j+2]
                    && board[i][j]==board[i-3][j+3]){
                        if (board[i][j]=='O') {
                            cout << "O WON!!\n";
                            winner = 0;
                        }
                        else {
                            cout << "X WON!!\n";
                            winner = 1;

                        }
                        return true;
                    }
            }
        }
    
     return false;

    }

};

#endif