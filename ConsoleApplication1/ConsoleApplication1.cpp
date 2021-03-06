// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

/*
Firstly we need to introduce the game = TRUE
Secondly we need to explain the rules of the game = TRUE
Next we will allow user input
Lastly we will check the player's guess against the random number and print back to them
whether or not their guess is correct, lower or higher than the generated number.
The game will be controlled within a loop with a condition against the maximum guess count

Thirdly generate a random number using the rand() function and print the number to the screen 
^^(this will be changed)
*/
#include "stdafx.h"
#include <string.h>
#include <iostream>

int guessCount;
int randNum =10;
int playerGuess;
const int maxGuessCount = 4;
void intro();
void Reset();
bool gameWon;
void PlayerInput();
void GuessCheck();

int main()
{
	Reset();
	do 
	{
		PlayerInput();
	} while ((guessCount <= maxGuessCount) && (gameWon == false));
	
	system("Pause");
    return 0;
}


void intro()
{
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl;
	std::cout << "Hello and welcome to the infamous guessing game!" << std::endl;
	std::cout << "-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-" << std::endl<<std::endl;
	std::cout << "The rules are simple: " << std::endl << "1: You have 5 attempts at guessing my number" << std::endl;
	std::cout << "2: I will tell you if you are higher, lower or than my number and of course," << std::endl;
	std::cout << "   if you are correct." << std::endl<<std::endl;
}

void Reset() 
{
	gameWon = false;
	guessCount = 0;
	intro();
}

void PlayerInput() 
{
	std::cout << "What is your guess?" << std::endl<<std::endl;
	std::cin >> playerGuess;
	std::cout << "Your guess was: " << playerGuess << std::endl;
	std::cout << "This means that you are: " << std::endl;
	GuessCheck();
}

void GuessCheck() 
{
	if (playerGuess < randNum)
	{
		std::cout << "Higher!"<<std::endl;
		guessCount++;
		std::cout << guessCount;
	}

	else 
	
		if (playerGuess > randNum) 
		{
		std::cout << "Lower!" << std::endl;
		guessCount++;
		std::cout << guessCount;
		}

	else

		if (playerGuess == randNum)
		{
			std::cout << "Well done! You guessed correctly!" <<"in only " <<guessCount<<" guesses!"<<std::endl;
			gameWon = true;
		}
}