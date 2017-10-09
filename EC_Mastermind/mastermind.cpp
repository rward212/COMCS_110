//Objective: Give the user the information he needs to guess the computer's randomly chosen set of colors within 6 guesses.
//Name: Roger Ward
//Course: COMSC-110-8215
//Compiler: MS Visual Studio 2010
//Editor: MS NotePad

//libraries
#include <iostream>
#include <string>
using namespace std;

#include <ctime>
#include <cstdlib>

//Programmer defined data types
//NONE

//Special compiler dependent definitions
//NONE

//global constants/variables
//NONE

//Programmer defined functions
//NONE

//main program
int main()
{
  srand(time(0));  

  // output my name and objective and program information
  cout << "Objective:";
  cout << "Programmer: Roger Ward\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: VC++ 2010 Express\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //Introduction and instructions
  cout << "Welcome to Mastermind!" << endl;
  cout << "by Roger Ward" << endl;
  cout << "(Computer choices output for the purposes of this demo.)" << endl;


  //random computer choice
  char solution1;
  char solution2;
  char solution3;
  char solution4;
  int solution = rand() % 4;
  if (solution == 0) solution1 = 'R';
  else if (solution == 1) solution1 = 'Y';
  else if (solution == 2) solution1 = 'B';
  else if (solution == 3) solution1 = 'G';
  solution = rand() % 4;
  if (solution == 0) solution2 = 'R';
  else if (solution == 1) solution2 = 'Y';
  else if (solution == 2) solution2 = 'B';
  else if (solution == 3) solution2 = 'G';
  solution = rand() % 4;
  if (solution == 0) solution3 = 'R';
  else if (solution == 1) solution3 = 'Y';
  else if (solution == 2) solution3 = 'B';
  else if (solution == 3) solution3 = 'G';
  solution = rand() % 4;
  if (solution == 0) solution4 = 'R';
  else if (solution == 1) solution4 = 'Y';
  else if (solution == 2) solution4 = 'B';
  else if (solution == 3) solution4 = 'G';

  //print out solutions (to make grading easier)
  cout << "solution1 = " << solution1 << endl;
  cout << "solution2 = " << solution2 << endl;
  cout << "solution3 = " << solution3 << endl;
  cout << "solution4 = " << solution4 << endl;

  //solution color count
  int solution_reds = 0;
  int solution_yellows = 0;
  int solution_greens = 0;
  int solution_blues = 0;

  if (solution1 == 'R') solution_reds += 1;
  if (solution2 == 'R') solution_reds += 1;
  if (solution3 == 'R') solution_reds += 1;
  if (solution4 == 'R') solution_reds += 1;
  if (solution1 == 'B') solution_blues += 1;
  if (solution2 == 'B') solution_blues += 1;
  if (solution3 == 'B') solution_blues += 1;
  if (solution4 == 'B') solution_blues += 1;
  if (solution1 == 'G') solution_greens += 1;
  if (solution2 == 'G') solution_greens += 1;
  if (solution3 == 'G') solution_greens += 1;
  if (solution4 == 'G') solution_greens += 1;
  if (solution1 == 'Y') solution_yellows += 1;
  if (solution2 == 'Y') solution_yellows += 1;
  if (solution3 == 'Y') solution_yellows += 1;
  if (solution4 == 'Y') solution_yellows += 1;

  int round_number = 0;

  while(true)
  {
    //set and display round number
    round_number += 1;
    cout << "Round number: " << round_number << endl;

    //user input validation loop
    string user_guess;
    while(true)
    {
    cout << "Please enter your four color choices in the following format: RYGB" << endl;
    getline(cin, user_guess);
    if ((user_guess[0] == 'R' || user_guess[0] == 'G' || user_guess[0] == 'B' || user_guess[0] == 'Y') && 
      (user_guess[1] == 'R' || user_guess[1] == 'G' || user_guess[1] == 'B' || user_guess[1] == 'Y') && 
      (user_guess[2] == 'R' || user_guess[2] == 'G' || user_guess[2] == 'B' || user_guess[2] == 'Y') && 
      (user_guess[3] == 'R' || user_guess[3] == 'G' || user_guess[3] == 'B' || user_guess[3] == 'Y')) break;
    cout << "I'm sorry, that isn't a valid entry. Please try again.\n";
    }
    
    // extracting individual chars from the input string
    char guess1 = user_guess[0];
    char guess2 = user_guess[1];
    char guess3 = user_guess[2];
    char guess4 = user_guess[3];

    // check for correct positions
    int correct_positions = 0;
    if (guess1 == solution1) correct_positions += 1;
    if (guess2 == solution2) correct_positions += 1;
    if (guess3 == solution3) correct_positions += 1;
    if (guess4 == solution4) correct_positions += 1;

    // check for correct colors
    int guess_reds = 0;
    int guess_yellows = 0;
    int guess_greens = 0;
    int guess_blues = 0;
    int correct_colors = 0;

    if (guess1 == 'R') guess_reds += 1;
    if (guess2 == 'R') guess_reds += 1;
    if (guess3 == 'R') guess_reds += 1;
    if (guess4 == 'R') guess_reds += 1;
    if (guess1 == 'B') guess_blues += 1;
    if (guess2 == 'B') guess_blues += 1;
    if (guess3 == 'B') guess_blues += 1;
    if (guess4 == 'B') guess_blues += 1;
    if (guess1 == 'G') guess_greens += 1;
    if (guess2 == 'G') guess_greens += 1;
    if (guess3 == 'G') guess_greens += 1;
    if (guess4 == 'G') guess_greens += 1;
    if (guess1 == 'Y') guess_yellows += 1;
    if (guess2 == 'Y') guess_yellows += 1;
    if (guess3 == 'Y') guess_yellows += 1;
    if (guess4 == 'Y') guess_yellows += 1;

    // assign correct color counts
    if (guess_reds <= solution_reds)
      correct_colors += guess_reds;
    else
      correct_colors += solution_reds;

    if (guess_blues <= solution_blues)
      correct_colors += guess_blues;
    else 
      correct_colors += solution_blues;

    if (guess_yellows <= solution_yellows)
      correct_colors += guess_yellows;
    else
      correct_colors += solution_yellows;

    if (guess_greens <= solution_greens)
      correct_colors += guess_greens;
    else
      correct_colors += solution_greens;


    // output guess results
    cout << "Correct colors: " << correct_colors << endl;
    cout << "Correct positions: " << correct_positions << endl;

    // break if user wins or max attempts have been reached
    if (correct_positions == 4 && round_number <= 10) 
    {
      cout << "You won! Congratualtions!" << endl;
      break;
    } else if (round_number > 10) {
      cout << "Nope. You lose." << endl;
      break;
    }

    // clear round-dependant variables
    guess_reds = 0;
    guess_greens = 0;
    guess_blues = 0;
    guess_yellows = 0;
    correct_colors = 0;
    correct_positions = 0;
    
  } // while
} // main






