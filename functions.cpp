#include "header.h"



int randomNumberGenerator()
{

//Declare

	int x;
	int choice;

	bool invalid = true;

//Generate

	x = rand() % 13 + 2;

	if (x > 10 && x < 14)
	{
		x = 10;
	}
	else if (x == 14)
	{
		cout << "You got an Ace!" << endl;

		do
		{
			cout << "Do you want '1' or '11'? (type '1' or '11'): ";
			cin  >> choice;
			cout << endl;

			invalid = !(choice == 1 || choice == 11);

			if (invalid)
			{
				cout << "*** Please enter a '1' or '11' ***";
			}

		}while (invalid);

		x = choice;

	}


	return x;
}

int dealerTurn()
{

//Declare

	int x;
	int dealerTotal = 0;

//Generate

	while (dealerTotal < 17)
	{
		x = rand() % 13 + 2;

		if (x < 10)
		{
			dealerTotal += x;
		}
		else if (x > 10 && x < 14)
		{
			x = 10;

			dealerTotal += x;
		}
		else
		{
			x = 11;

			if (dealerTotal <= 10)
			{
				dealerTotal += x;
			}
			else if (dealerTotal > 10 || dealerTotal < 21)
			{
				dealerTotal++;
			}
		}
	}

	return dealerTotal;
}

