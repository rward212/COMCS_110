//Objective: Play a game of RPS between the user and the computer.
//Name: Roger Ward
//Course: COMSC-110-8215
//Compiler: MS Visual Studio 2010
//Editor: MS NotePad

//libraries
#include <iostream>
#include <cctype>
using namespace std;

#include <ctime>


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
  cout << "Objective: Play a game of RPS between the user and the computer.";
  cout << "Programmer: Roger Ward\n"; 
  cout << "Editor(s) used: Notepad\n"; 
  cout << "Compiler(s) used: VC++ 2010 Express\n"; 
  cout << "File: " << __FILE__ << endl; 
  cout << "Complied: " << __DATE__ << " at " << __TIME__ << endl << endl; 

  //variables
  int randomNumber; // a randomly generated 0, 1, or 2. Used to generate a r/R, p/P, or s/S. (int)
  char tempPlay; // temporary input holder
  char userPlay; // a user-chosen 0, 1, or 2. Used to generate a r/R, p/P, or s/S. (char)
  int userScore; // the number of times the user has won (int)
  int computerScore; // the number of times the computer has won (int)
  char response; // users input to repeat game or not (char)

  cout << "Welcome to Rock, Paper, Scissors!" << endl;

  while(true)
  {  
    //Generate a random choice for the computer
    int randomNumber = rand() % 3;

    //Obtain a valid input from the user
    while (true)
    {
      cout << "Please enter a choice [r = rock, p = paper, s = scissors, q = quit]" << endl;
      cin >> tempPlay;
      cin.ignore(1000, 10);
      userPlay = tolower(tempPlay);
      if (userPlay == 'r' || userPlay == 'p' || userPlay == 's' || userPlay == 'R' || userPlay == 'P' || userPlay == 'S' || userPlay == 'q' || userPlay == 'Q') break;
      cout << "I'm sorry, that's not a valid entry. Please try again." << endl;
     } //while
    
    // Output user choice
    if (userPlay == 'r')
      cout << "You chose rock." << endl;
    else if (userPlay == 'p')
      cout << "You chose paper." << endl;
    else if (userPlay == 's')
      cout << "You chose scissors." << endl;
    else
      break;


    // Output computer choice
    if (randomNumber == 0)
      cout << "Computer chose rock." << endl;
    else if (randomNumber == 1)
      cout << "Computer chose paper." << endl;
    else
      cout << "Computer chose scissors." << endl;

    //Compare the computer and user values and declare the winner
    if (userPlay == 'r' && randomNumber == 1)
    {
      cout << "Computer wins!" << endl;
      computerScore += 1;
    }
    else if (userPlay == 'r' && randomNumber == 2)
    {
      cout << "You win!" << endl;
      userScore += 1;
    }  
    else if (userPlay == 'p' && randomNumber == 0)
    {
      cout << "You win!" << endl;
      userScore += 1;
    }
    else if (userPlay == 'p' && randomNumber == 2)
    {  
      cout << "Computer wins!" << endl;
      computerScore += 1;
    }  
    else if (userPlay == 's' && randomNumber == 0)
    {  
      cout << "Computer wins!" << endl;
      computerScore += 1;
    }
    else if (userPlay == 's' && randomNumber == 1)
    {
      cout << "You win!" << endl;
      userScore += 1;
    }
    else if (userPlay == 'q' || userPlay == 'Q')
      break;
    else
      cout << "It's a tie!" << endl;


    //Repeat or exit game
    while (true)
    {
      cout << "Would you like to play again? [y = yes, n = no]" << endl;
      cin >> response;
      cin.ignore(1000, 10);
      if (tolower(response) == 'y' || tolower(response) == 'n') break;
      cout << "I'm sorry, that's not a valid choice. Please try again." << endl;
    }

    if (response == 'n') break;
  } // main game loop

  //Display Scores
  cout << "Your score: " << userScore << endl;
  cout << "Computer's score: " << computerScore << endl;

  // Output goodby message
  cout << "Thanks for playing RPS! Goodbye!" << endl;
} // main
