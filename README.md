# Two-Player Yahtzee Game in C

## Overview
This is a simplified two-player version of the classic dice game **Yahtzee** implemented in **C**.  
The human player competes against the computer, which uses an optimal strategy to maximize its score. The game consists of 13 rounds with five dice rolls per round.

## Features
- Full implementation of Yahtzee scoring categories:
  - Ones, Twos, Threes, Fours, Fives, Sixes
  - Three of a Kind, Four of a Kind
  - Full House
  - Small Straight, Large Straight
  - Yahtzee, Chance
- Human player input with clear prompts
- Computer AI chooses optimal dice and scoring categories
- Tracks scores over 13 rounds and determines the winner

## How to Run
1. Compile the program:
   ```bash
   gcc src/yahtzee.c -o yahtzee
2. Run the executable:
    ```bash
   ./yahtzee
3. Follow the prompts to play against the computer.
