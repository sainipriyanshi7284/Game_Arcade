#include<bits/stdc++.h>
#include "headers/minisweeper.h"
#include "headers/hangman.h"
#include "headers/connectfour.h"
#include "headers/tictactoe.h"
#include "headers/blackjack.h"
#include "headers/score.h"

using namespace std;

int main(){
    Score s;
    string player;
    string player1, player2;
    srand(time(0));
    
    int choice=0;
    while (choice!=7){
    cout << endl << endl;
    cout << "============= GAME ARCADE ============" << endl << endl;
   
    cout << "SCORE RULES: " << endl;  
    cout << "Scores accumulate across multiple plays." << endl;
    cout << "Leaderboard stores total score per player per game." << endl << endl;

    cout << "1. Miniweeper Game \n2. Hangman Game [Word Guess] \n3. Connect Four Game \n4. Tic Tac Toe \n5. BlackJack Game\n6. LeaderBoard\n7. EXIT" << endl << endl;

    cout << "Enter choice to play the game: ";
        cin >> choice;
        switch(choice){
            case 1:
            {
                 cout <<"Enter Player Name: ";
                 cin >> player;
                char c='y';
                while(c=='y'){
                    Minisweeper m;
                    cout << "========================= MINISWEEPER ============================" << endl;
                    cout << "============================(RULES)============================" << endl;
                    cout << endl << "You are provided with a 4 X 4 grid.";
                    cout << endl << "Mines placed on random cells all over the grid."<< endl;
                    cout << "Player must avoid stepping on the mine." << endl;
                    cout << "Goal is to reveal safe cells without hitting the mine." <<endl;
                    cout << "Player must write the position in 0 to 3 indexes"  <<endl << endl;

                    cout << "Score = Number of safe cells revealed" << endl;
                    cout << "Maximum = 16 - mines" << endl << endl;

                    m.printHiddenGrid();
                    cout << "HIDDEN MINES = " << m.mines;
                    while(true){
                        m.userInput();
                        m.checkCell();
                        if(m.gameOver()) break;
                    }  
                    cout << endl ;
                    auto count=m.countCells();
                    if(count>0){
                        s.update( player, "MiniSweeper", count);
                        cout << "Score = " << count << endl;
                    }
                cout << endl;
                cout << "Do you want to continue with this game (y/n)";
                cin >> c;
                c=tolower(c);
                }
            }
                break;

            case 2:
            {   
                 cout <<"Enter Player Name: ";
                 cin >> player;
                char c='y';
                while(c=='y'){
                    
                    Hangman h;
                    cout << "===================== HANGMAN [WORD GUESS] ============================" << endl;
                    cout << "============================(RULES)============================" << endl << endl;;
                    cout << "Guess one letter at a time to reveal the hidden word." << endl
                    << "If the guessed letter exists, all matching positions are revealed;"
                    << " otherwise you lose one life." << endl
                    <<"Reveal the complete word before all 6 lives are used to win the game." << endl << endl;
                    cout << "Win -> Score = 10 - remaining lives used" << endl;
                    cout << "Lose -> 0 points" << endl << endl;
                    h.choose_word();
                    cout << "HINT: " << h.hint << endl;
                    h.reveal();
                    cout << endl << endl;
                    h.draw_hangman();
                    while(!h.win()){
                        h.input_guess();
                        h.check_guess();
                        h.reveal();
                        cout << endl;
                        h.draw_hangman();
                        cout << endl << endl;
                    }

                    if(h.winner()) {
                        s.update( player, "Hangman", 10-h.lives );
                        cout << "Score = " << 10-h.lives << endl;
                    }
                    else {
                        s.update( player, "Hangman", 0 );
                        cout << "Score = " << 0 << endl;
                    }
                    cout << endl;
                cout << "Do you want to continue with this game (y/n)";
                cin >> c;
                c=tolower(c);
            }
            }
                break;

            case 3:
            {
                 cout <<"Enter Player1 Name: ";
                 cin >> player1;
                 cout << "Enter Player2 Name: ";
                 cin >> player2;

                char c='y';
                while(c=='y'){
                    
                    ConnectFour cf;
                    cout <<endl << endl;
                    cout << "========================= CONNECT FOUR ============================" << endl;
                    cout << "============================(RULES)============================" << endl;
                    cout << "Players take turns dropping pieces into a 7-column, 6-row grid." << endl
                    << "Player 1 uses O and Player 2 uses X." << endl
                    << "Enter a column number (0-6) to drop your piece; it falls to the lowest empty row." << endl
                    << "Connect 4 of your pieces horizontally, vertically, or diagonally to win." << endl
                    << "If all 42 cells are filled with no winner, the game ends in a draw." << endl << endl;
                     cout << "Winner -> +5 points" << endl;
                     cout << "Draw -> 0 points" << endl << endl;
                    cf.print();
                    while(true){
                        cf.input_player1();
                        cf.player1();
                        cf.print();
                        if(cf.win() || cf.draw() ) break;

                        cf.input_player2();
                        cf.player2();
                        cf.print();
                        if(cf.win() || cf.draw()) break;

                        cout << endl;
                    }
                    if(cf.winner==0){ 
                        s.update(player1, "ConnectFour",5); 
                        s.update(player2,"ConnectFour",0);
                        cout << "Score of Player 1 = " << 5 << endl;
                        cout << "Score of Player 2 = " << 0 << endl;
                    }
                    else if(cf.winner==1){
                        s.update(player2, "ConnectFour", 5 );
                        s.update(player1,"ConnectFour",0);
                        cout << "Score of Player 1 = " << 0 << endl;
                        cout << "Score of Player 2 = " << 5 << endl;
                        }
                    cout << "Do you want to continue with this game (y/n)";
                    cin >> c;
                    c=tolower(c);
                    }
               }
                break;
            
            case 4:
            {
                 cout <<"Enter Player1 Name: ";
                 cin >> player1;
                 cout << "Enter Player2 Name: ";
                 cin >> player2;

                char c='y';
                while(c=='y'){
                    
                    cout <<endl << endl;
                    cout << "========================= TIC TAC TOE ============================" << endl;
                    cout << "============================(RULES)============================" << endl;
                    cout << "The game is played on a 3 x 3 grid between two players (O and X)" << endl;
                    cout <<"Players take turns choosing an empty cell and placing their symbol." << endl;
                    cout << "First player to make 3 same symbols in a row, column, or diagonal wins.\n";
                    cout << "If all 9 cells are filled and nobody wins, the game ends in a draw.\n\n" ;

                    cout << "Winner -> +5 points" << endl;
                    cout << "Draw -> 0 points" << endl << endl;

                    TicTacToe t;
                    t.print();
                    while(true){
                        t.input_player1();
                        t.player1();
                        t.print();
                        if(t.win() || t.draw() ) break;

                        t.input_player2();
                        t.player2();
                        t.print();
                        if(t.win() || t.draw()) break;

                        cout << endl;
                }

                if(t.winner==0){ 
                        s.update(player1, "TicTacToe",5); 
                        s.update(player2,"TicTacToe",0);
                        cout << "Score of Player 1 = " << 5 << endl;
                        cout << "Score of Player 2 = " << 0 << endl;
                    }
                else if(t.winner==1){
                        s.update(player2, "TicTacToe", 5 );
                        s.update(player1,"TicTacToe",0);
                        cout << "Score of Player 1 = " << 0 << endl;
                        cout << "Score of Player 2 = " << 5 << endl;
                        }
                else {
                    s.update(player2, "TicTacToe", 0);
                    s.update(player1,"TicTacToe",0);

                }

               cout << "Do you want to continue with this game (y/n)";
                cin >> c;
                c=tolower(c);
             }
        }
            break;
    
    case 5:
        {  
            cout <<"Enter Player Name: ";
            cin >> player;

            char c='y';
            while(c=='y'){
                
                cout <<endl << endl;
                cout << "========================= BLACK JACK ============================" << endl;
                cout << "============================(RULES)============================" << endl;

                cout << "Player and dealer both start with 2 random cards." << endl;
                cout << "Player chooses:  Hit (H) -> draw one more card  and  Stand (S) -> stop drawing cards" << endl;
                cout << "If player's total becomes more than 21, player busts and loses." << endl;
                cout << "After player stands, dealer automatically draws cards until total is at least 17." << endl;
                cout << "Winner is decided as:" << endl;
                cout << "   Higher total -> wins" << endl;
                cout << "   Dealer > 21 -> Player wins" << endl;
                cout << "   Player > 21 -> Dealer wins" << endl;
                cout << "   Equal totals -> Draw" << endl <<endl;

                cout << "Win -> +5 points" << endl;
                cout << "Lose / Bust -> 0 points" << endl << endl;

                BlackJack b;
                b.display();
                b.take_choice();
                cout << endl;
                if(b.winner==1) {
                    s.update( player, "BlackJack", 5);
                    cout << "Score = " << 5 << endl;
                }
                else {
                    s.update( player, "BlackJack", 0);
                    cout << "Score = " << 0 << endl;
                }

                cout << "Do you want to continue with this game (y/n)";
                cin >> c;
                c=tolower(c);
            }
        }

        break;

    case 6:
        s.show();
        break;
    
    case 7:
        cout << "Exiting....";
        break;

    default:
        cout << "Invalid Choice";
        }
    }
}
