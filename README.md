# Game Arcade (Console-Based C++ Project)

Game Arcade is a console-based C++ project containing a collection of classic games developed using Object-Oriented Programming (OOP), STL, file handling, modular header files, and persistent leaderboard storage.

## Overview

This project combines multiple games into a single application and maintains player scores across sessions using file handling.

## Included Games

### 1. MiniSweeper

Reveal safe cells while avoiding hidden mines.

### 2. Hangman

Guess letters to reveal the hidden word before running out of lives.

### 3. Connect Four

Two-player game where players connect four pieces horizontally, vertically, or diagonally.

### 4. Tic Tac Toe

Classic 3 × 3 board game for two players.

### 5. BlackJack

Card game where the objective is to achieve a score closest to 21 without exceeding it.

---

## Features

* Multiple games integrated into one application
* Persistent leaderboard using file handling
* Modular project organization using header files
* Randomized gameplay
* Input validation and replay functionality
* Single-player and multiplayer support

---

## Concepts Implemented

* Object-Oriented Programming (Classes and Encapsulation)
* STL (Vectors, Maps)
* File Handling
* Random Number Generation
* Header File Organization
* Game Loop Design
* Persistent Score Management

---

## Project Structure

Game_Arcade/ <br> <br>

├── headers/ <br>
│ ├── blackjack.h <br>
│ ├── connectfour.h <br>
│ ├── hangman.h <br>
│ ├── minisweeper.h <br>
│ ├── score.h <br>
│ └── tictactoe.h <br><br>

├── main.cpp <br>
├── README.md <br>
├── .gitignore <br>
└── scores.txt (generated locally)<br>

---

## Leaderboard

Player scores are stored locally and accumulate across multiple sessions.

Scoring System:

* MiniSweeper → Safe cells revealed
* Hangman → Based on remaining lives
* Connect Four → Winner receives points
* Tic Tac Toe → Winner receives points
* BlackJack → Win-based scoring

---

## Future Improvements

* GUI support
* Difficulty levels
* Enhanced leaderboard visualization
* Additional games
* Multiplayer improvements

---

Developed as a project to practice C++ concepts through game development.
