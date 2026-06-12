#ifndef BLACKJACK_H
#define BLACKJACK_H


#include<bits/stdc++.h>
#include<random>

using namespace std;

class BlackJack{
    vector<int> player;
    vector<int> dealer;

    int player_points;
    int dealer_points;

    char choice;

public:
    int winner;
    BlackJack(){
        player_points=0;
        dealer_points=0;

        player.push_back(rand()%10+1);
        player.push_back(rand()%10+1);

        dealer.push_back(rand()%10+1);
        dealer.push_back(rand()%10+1);

    }

    void take_choice(){
        cout <<endl << "HIT (H)  or  STAND (S): ";
        cin >> choice;
        choice=toupper(choice);

        if(choice == 'H') draw_card();
        else if(choice == 'S') {
            display();
            dealer_turn();
        }

        else{
            cout << "Invalid Choice";
            take_choice();

        }
    }

    void draw_card(){
        int card= rand()%10+1;
        player.push_back(card);

        if(calculate_points()>21) 
        {
            display(); 
            cout << endl << "PLAYER BUSTED";
        }

        else {
            cout << "+" << card << endl << "Total=" << calculate_points();
            take_choice();
        }


    }

    int calculate_points(){

        player_points=0;

        for(auto it=player.begin(); it!=player.end(); it++){
            player_points+=*(it);
        }

        return player_points;
        
    }

    void display(){
        cout << endl << "Player: ";
        for(auto it=player.begin(); it!=player.end(); it++){
            cout << *(it) << " ";
        }
        cout << endl;

        cout << "Player Points= " << calculate_points();
        cout << endl;

       
    }

       int calculate_points_dealer(){
        dealer_points=0;

        for(auto it=dealer.begin(); it!=dealer.end(); it++){
            dealer_points+=*(it);
        }

        return dealer_points;
        
    }

    void dealer_turn(){

        while(calculate_points_dealer()<17){
            dealer.push_back(rand()%10+1);
        }
            cout << "Dealer Stands\n\n";
            compare();
    }
        
    void compare(){
        if(player_points > 21) cout << "PLAYER BUSTED";
        else if(dealer_points > 21) {
            cout << "DEALER BUSTED\nPLAYER WINS";
            winner=1;
        }
        else if(dealer_points > player_points) cout << "PLAYER LOSE!!";
        else if(dealer_points == player_points) cout <<"MATCH DRAW!!";
        else {
            cout << "PLAYER WINS!!"; 
            winner = 1;
        }

        cout << endl;

        cout << "Dealer: ";
        for(auto n:dealer){
            cout << n << " ";
        }
        cout << endl;
        cout << "Dealer Points= " << calculate_points_dealer() << endl;

    }


};

#endif