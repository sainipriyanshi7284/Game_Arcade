#ifndef SCORE_H
#define SCORE_H

#include<iostream>
#include<fstream>
#include<bits/stdc++.h>

using namespace std;

class Score{
     map<string,int> scores;

public:

    void load(){
        scores.clear();
        ifstream file( "scores.txt");

        string player;
        string game;
        int score;

         while(file >> player >> game >> score){
            string key =  player + " " + game;
            scores[key]=score;
        }

        file.close();
    }

    void update( string player, string game, int score){
        load();
        string key = player + " " + game;
        scores[key]+=score;
        save();
    }


    void show(){ 
        load();
        cout << endl << "======= LEADERBOARD =======" << endl << endl;
        for(auto x:scores){
            cout << x.first << " : " << x.second << endl;
         }
        cout << endl;
    }


    void save(){
        ofstream file( "scores.txt");
          for(auto x:scores){
            file << x.first << " " << x.second << endl;
        }

         file.close();

    }

};

#endif