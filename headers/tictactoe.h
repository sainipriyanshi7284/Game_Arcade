#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <bits/stdc++.h>
using namespace std;
class TicTacToe{
public:
    int col1;
    int row1;
    int row2;
    int col2;
    int moves;
    int winner;
    vector<vector<char>> board;

    TicTacToe(){
        moves=0;
        board= vector<vector<char>> (3, vector<char> (3,' '));
    }

    void player1(){
            if(board[row1][col1]==' ')  {
                board[row1][col1] = 'O';
                moves++;
            }
     }

     void player2(){
            if(board[row2][col2]==' ')  {
                board[row2][col2] = 'X';
                moves++;
            }
    }

    bool draw(){
        if(moves == 9){
            cout << "IT'S A DRAW!";
            return true;
        }
        return false;
    }


    void input_player1(){
        cout << "Enter the position of O: "<< endl;
        cout << "Column: ";
        cin >> col1;  
        cout <<"Row: ";
        cin >> row1;
         while(true){
            if(col1<0 || col1>2 || row1 <0 || row1>2) 
            {
                cout << "INVALID POSITION! TRY AGAIN\n"; 
                cin >> col1;
                cin >> row1;
            }
            else if(board[row1][col1]!=' ') {
                cout << "CELL FULL! TRY AGAIN\n";
                cin >> col1;
                cin >> row1;
            }
            else break;
        } 
    }

    void input_player2(){
        cout << "Enter the position of X: ";
        cout << "Column: ";
        cin >> col2;  
        cout <<"Row: ";
        cin >> row2;
        while(true){
            if(col2<0 || col2>2 || row2 <0 || row2>2) 
            {
                cout << "INVALID POSITION! TRY AGAIN \n"; 
                cin >> col2;
                cin >> row2;
            }
            else if(board[row2][col2]!=' ') {
                cout << "CELL FULL! TRY AGAIN \n";
                cin >> col2;
                cin >> row2;
            }
            else break;
        } 
    }

    void print(){
        cout << "   0 1 2 " << endl;
        for(int i=0; i<=2; i++){
            cout << i << " ";
            for(int j=0; j<=2; j++){
                cout << "|" << board[i][j];
            }
            cout << "|";
            cout << endl;
            }

        
    }

    bool win(){
        // FOR HORIZONTAL 
        for(int i=0; i<=2; i++){
                if( board[i][0]!=' '&& board[i][0]==board[i][1] &&
                   board[i][0]==board[i][2] ){
                        if (board[i][0]=='O') {
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

        //FOR VERTICAL
         for(int i=0; i<=2; i++){
                if(board[0][i]!=' ' && board[0][i]==board[1][i] &&
                   board[0][i]==board[2][i] ){
                        if (board[0][i]=='O') {
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
// FOR DIAGONALS
        // Bottom-left to top-right
            if(board[0][0]!=' ' && board[0][0]==board[1][1]
                && board[0][0]==board[2][2]){
                         if (board[0][0]=='O') {
                            cout << "O WON!!\n";
                            winner = 0;
                        }
                        else {
                            cout << "X WON!!\n";
                            winner = 1;

                        }
                        
                        return true;
                    }

        // Top-left to bottom-right
    
                if(board[1][1]!=' ' && board[1][1]==board[0][2]
                    && board[1][1]==board[2][0]){
                         if (board[1][1]=='O') {
                            cout << "O WON!!\n";
                            winner = 0;
                        }
                        else {
                            cout << "X WON!!\n";
                            winner = 1;

                        }
                        return true;
                    }
    
     return false;

    }

};


#endif