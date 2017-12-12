#include "header.h"



int main()
{
//Initialize

	srand (time(NULL));

//Declarations

	int newRandomNum;
	char hitChoice;
	char roundChoice;
	int userTotal = 0;
	int dealerTotal = 0;

	bool userLost = false;
	bool gameOver = false;

//Main

	cout << "**********************************\n";
	cout << "*** Welcome to CS1A BLACKJACK! ***\n";
	cout << "**********************************\n\n";


	bool invalid = true;

	do
	{
		cout << "Would you like to play? ('y' for yes and 'n' for no): ";
		cin  >> roundChoice;
		cout << endl;

		invalid = !(roundChoice == 'y' || roundChoice == 'n');

	}while(invalid);

	while(roundChoice == 'y')
	{

		newRandomNum = randomNumberGenerator();

		cout << "Your first card is: " << newRandomNum
			 << endl << endl;

		userTotal += newRandomNum;

		do
		{
			cout << "Would you like another card? ('y' for yes and 'n' for no): ";
			cin  >> hitChoice;
			cout << endl;

			invalid = !(hitChoice == 'y' || hitChoice == 'n');

		}while(invalid);

		while(hitChoice == 'y')
		{
			newRandomNum = randomNumberGenerator();

			cout << "Your next card is: " << newRandomNum
				 << endl << endl;

			userTotal += newRandomNum;

			if(userTotal < 21)
			{
				cout << "Your total is " << userTotal
					 << endl;

				do
				{
					cout << endl;
					cout << "Would you like another card? ('y' for yes and 'n' for no): ";
					cin  >> hitChoice;
					cout << endl;

					invalid = !(hitChoice == 'y' || hitChoice == 'n');

				}while(invalid);

			}

			else if(userTotal == 21)
			{
				cout << "Your total is 21, You win!!"
					 << endl << endl;

				userLost = false;

				gameOver = true;

			}

			else
			{
				cout << "Your total is " << userTotal << "\n\nYou lose!!"
					 << endl << endl;

				userLost = true;

				gameOver = true;

			}

		}

// DEALER'S TURN

		if (!userLost && !gameOver)
		{

			dealerTotal = dealerTurn();

			cout << "The dealer's total is: " << dealerTotal
				 << endl << endl;

			if (dealerTotal > userTotal)
			{
				cout << "You Lose!!\n\n";
			}
			else if ((dealerTotal > 21) || (dealerTotal < userTotal) || (dealerTotal == userTotal))
			{
				cout << "You Win!!\n";
			}
		}

//Restart Game

		userTotal = 0;
		dealerTotal = 0;

//Prompt User

		do
		{
			cout << "Would you like to play again? ('y' for yes and 'n' for no): ";
			cin  >> roundChoice;
			cout << endl;

			invalid = !(roundChoice == 'y' || roundChoice == 'n');

		}while(invalid);

	}

	return 0;
}
