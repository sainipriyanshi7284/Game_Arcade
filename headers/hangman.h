#ifndef HANGMAN_H
#define HANGMAN_H

#include<iostream>
#include<cctype>
#include<ctime>
#include<cstdlib> 
using namespace std;

class Hangman{
    string word;
    string secret_word;
    char guess;
public:
    int lives;
    string hint;
    Hangman(){
        lives=6;
    }

    void draw_hangman(){
        if(lives==6) 
            cout <<  "_________" << endl <<"|" << endl << "|" <<  endl << "|" << endl << "|" << endl;
        if(lives==5) 
            cout <<  "_________" << endl <<"|   O" << endl << "|" <<  endl << "|" << endl << "|" << endl << "|" << endl;
        if(lives==4)
            cout <<  "_________" << endl <<"|   O" << endl << "|   |" <<  endl << "|" << endl << "|" << endl << "|" << endl;
        if(lives==3)
            cout <<  "_________" << endl <<"|   O" << endl << "|  /|" <<  endl << "|" << endl << "|" << endl << "|" << endl;
         if(lives==2)
            cout <<  "_________" << endl <<"|   O" << endl << "|  /|\\ " <<  endl << "|" << endl << "|" << endl << "|" << endl;
         if(lives==1)
            cout <<  "_________" << endl <<"|   O" << endl << "|  /|\\ " <<  endl << "|  /" << endl << "|" << endl << "|" << endl;
        if(lives==0)
            cout <<  "_________" << endl <<"|   O" << endl << "|  /|\\ " <<  endl << "|  / \\ " << endl << "|" << endl << "|" << endl;
    }

    void choose_word(){
        int index = rand()%10;

        string words[]={"MONKEY","CHERRY","CRICKET","MUSKMELON","MACHINE","TELEVISION","CROCODILE","SPECTACLES","AUSTRALIA","ZIMBABWE"};
        string hints[]={"Animal","Fruit","Sports","Fruit","Electronic Item","Electronic Item","Animal","Object","Country","Country"};

        word=words[index];
        secret_word= string(words[index].length(), '_');
        hint=hints[index];

    }



    void input_guess(){
        cout << "Enter guess character: ";
        cin >> guess;
        guess=toupper(guess);
         while(!isalpha(guess)){
            cout << "Invalid input. Enter a letter: ";
            cin >> guess;
            guess = toupper(guess);
        }
    }

    void check_guess(){
        for(int i=0; i<word.length(); i++){
            if(secret_word[i]==guess){
                cout << "Letter already revealed" << endl;
                return;
             }
            if(word[i]==guess) 
                secret_word[i]=guess;
        }
        if(wrong_guess()) {
            cout << "Wrong Guess" << endl;
            lives--;
            cout << "Remaining Lives= " << lives << endl;
        }
    }

    bool wrong_guess(){
        int count=0;
        for(int i=0; i<word.length(); i++){
            if(word[i]!=guess) count++;
            }
        if (count==word.length()) return true;
        else return false;
    }

    void reveal(){
        for(int i=0; i<secret_word.length(); i++){
        cout << secret_word[i] << " ";
        }
    }

    void reveal_word(){
        for(int i=0; i<word.length(); i++){
        cout << word[i] << " ";
        }

    }

    bool win(){
        if(lives==0) {
            cout << "U lose" << endl;
            reveal_word();
            return true;
        }
        if(secret_word==word) {
            cout << "Congraluations!! U won";
            return true;
        }
        else return false;
    }

    bool winner(){
        if(lives==0)  return false;
        if(secret_word==word) return true;
        else return false;

    }
};

#endif
