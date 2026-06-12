#ifndef MINISWEEPER_H
#define MINISWEEPER_H


#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

class Minisweeper{
    int row,col;
    char arr[10][10];
    char visible[10][10];
public:
    int mines;
    Minisweeper(){
        srand(time(0));
        
        row=col=0;
        for(int i=0; i<4;i++){
            for(int j=0; j<4; j++){
                arr[i][j] = 'o';
                visible[i][j]= '#';
            }
        }
         mines = rand()%3+2;
        int count = 0;

        while(count < mines){
            int r = rand()%4;
            int c = rand()%4;
            if(arr[r][c] != 'x'){
                arr[r][c] = 'x';
                count++;
            }
        }


    }

    void printHiddenGrid(){
        for(int i=0; i<4;i++){
            for(int j=0; j<4; j++){
               cout << "[" << visible[i][j] << "]";
            }
           cout <<  endl;
        }


    }   

    void printGrid(){
          for(int i=0; i<4;i++){
            for(int j=0; j<4; j++){
                cout << "[" << arr[i][j] <<"]";
            }
           cout <<  endl;
        }

    }


    void userInput(){
        cout << endl << "Enter the guess location of the cell " << endl << "Row: ";
        cin >> row ;
        cout << "Column: ";
        cin >> col;
        while(row<0 || row>=4 ||col<0 ||col>=4)  {
            cout << "Invalid Position. Try Again"  << endl << "Row: ";
            cin >> row;
            cout << "Column: ";
            cin >> col;
        }

        
    }
    int countCells(){
        int count=0;
        for(int i=0; i<4;i++){
            for(int j=0; j<4; j++){
               if(visible[i][j]=='o') count+=1;
            }
        }
       return count;
        
    }

    void checkCell(){
       if(visible[row][col] != '#') {
            cout << "Cell already revealed" << endl;
            return;
        }

        if(arr[row][col] == 'x'){
            printGrid();
            cout << endl << "BOOM!! Stepped on mine";
        }

        else{
            visible[row][col] = 'o';
            printHiddenGrid();
            cout << "Safe Cell" << endl << endl;
        }
    }


    bool gameOver(){
        if (arr[row][col] =='x') return true;
        if(countCells() == 16-mines){
            cout << "WINNER!! Congratulations u revealed all the safe cells ";
            return true;
        }
        else return false;
    }

};
#endif

