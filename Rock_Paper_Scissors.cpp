#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

//Function Declarations
string getPlayersChoice();
string getComputersChoice();
void decideWhoWins(string computerChoice, string playerChoice);

//Main
int main()
{
	//Declaring Variables
	srand(time(0)); //Seeds the random variable
	string playerChoice;
	string computerChoice;
	bool appIsOn = true; //Determines if the program is looping

	//Game Loop
	while (appIsOn)
	{
		//Assigning Data to Vars
		playerChoice = getPlayersChoice();
		if (playerChoice == "end") //Ensures that if player wants to end, the appIsOn bool gets changed to false
		{
			appIsOn = false;
		}
		computerChoice = getComputersChoice();

		//Decide who wins
		decideWhoWins(computerChoice, playerChoice);
	}
	return 0;
}

//FUNCTION CREATION
string getPlayersChoice()
{
	int decision; //Number value chosen by user for which item they want

	cout << endl <<"Rock (1), Paper (2), or Scissors(3) | End Game (4): ";
	cin >> decision;

	switch (decision) //Returns the choice based off the number chosen
	{
		case 1: return "rock";
		case 2: return "paper";
		case 3: return "scissors";
		default: return "end";
	}
}

string getComputersChoice()
{
	int decision; //Computer's Decision

	decision = rand() % 3;

	switch (decision) //Returns the choice based off the number generated
	{
		case 0: return "rock";
		case 1: return "paper";
		case 2: return "scissors";
	}
}

void decideWhoWins(string computerChoice, string playerChoice)
{
	//Checks first to see whether or not player wants to play
	if (playerChoice == "end") //Player decides to stop playing
	{
		cout << "Thank you for playing Rock, Paper, Scissors!";
	}
	else //Player decides to keep playing
	{
		cout << "Player Chose: " << playerChoice << " | Computer Chose: " << computerChoice << endl;

		//Tie
		if (computerChoice == playerChoice)
		{
			cout << "Tie!" << endl;
		}
		//Computer Wins
		else if (computerChoice == "rock" && playerChoice == "scissors" ||
			computerChoice == "scissors" && playerChoice == "paper" ||
			computerChoice == "paper" && playerChoice == "rock")
		{
			cout << "Computer Wins" << endl;
		}
		//Player Wins | If none of previous conditions true, the player wins
		else 
		{
			cout << "Player Wins" << endl;
		}
	}
}
