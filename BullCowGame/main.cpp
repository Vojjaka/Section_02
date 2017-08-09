#include <iostream>
#include <string>
#include "FBullCowGame.h"

void PrintIntro();
void PlayGame();
std:: string GetGuess();
bool AskToPlayAgain();
FBullCowGame BCGame; // instantiate a new game

//the entry point for our app
int main()
{
	bool bPlayAgain = false;
	do {
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);

	return 0;//exit the application
}


//introduce to the game
void PrintIntro() 
{
	constexpr int WORD_LENGTH = 9;

	std:: cout << "Welcome to Bulls and Cows" << std:: endl;
	std:: cout << "Can you guess the " << WORD_LENGTH;
	std:: cout << " letter isogram I'm thinking of?\n";
	std:: cout << std:: endl;

	return;
}


void PlayGame()
{

	
	int maxTries = BCGame.GetMaxTries();
	
	//loop for the number of turns asking for guesses
	
		for (int count = 1; count <= maxTries; count++){
		std:: string Guess = GetGuess();
		std:: cout << "Your guyes was: " << Guess << std:: endl;
		std:: cout << std:: endl;
	}
}


std:: string GetGuess() 
{

	int CurrentTry = BCGame.GetCurrentTry();

	//get a guess from the player		
	std:: cout << "Try " << CurrentTry << ". Enter your guess: ";
	std:: string Guess = "";
	std:: getline(std:: cin, Guess);
	return Guess;
}

bool AskToPlayAgain()
{
	std:: cout << "Do you want to play again (y/n)?";
	std:: string Response = "";
	getline(std:: cin, Response);
	return (Response[0] == 'y') || (Response[0] == 'Y');
}
