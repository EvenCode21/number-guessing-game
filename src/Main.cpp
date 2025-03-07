#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <fstream>

void gameplay(int chances);
int attempts = 0;
bool keepPlaying = true;

int main()
{
	printf("Welcome to the number guessing game!!\n\n");
	printf("I'm thinking of a number between 1 and 100\n");
	printf("The number of chances you'll have depends on the difficulty you choose\n\n");
	
	do
	{
		int difficulty = 0;
		attempts = 0;
		printf("\n");
		printf("Please select the difficulty level: \n");
		printf("1. Easy (10 chances)\n");
		printf("2. Medium (5 chances)\n");
		printf("3. Hard (3 chances)\n\n");

		do
		{
			printf("Enter your choice: ");
			std::cin >> difficulty;

		} while (difficulty < 1 || difficulty > 3);

		printf("\n\n");

		switch (difficulty)
		{
			case 1:
				printf("Great! You have selected the Easy difficulty level.\n");
				gameplay(10);
			break;
			case 2:
				printf("Great! You have selected the Medium difficulty level.\n");
				gameplay(5);
				break;
			case 3:
				printf("Great! You have selected the Hard difficulty level.\n");
				gameplay(3);
				break;
		}

	} while (keepPlaying);
}

void gameplay(int chances)
{
	printf("Let's start the game!!\n\n");

	int cpuChoice = (rand() % 100) + 1;

	attempts = 0;

	int playerChoice = 0;

	for (int i = 0; i < chances; i++)
	{
		printf("Enter your guess: ");
		std::cin >> playerChoice;

		if (playerChoice < cpuChoice)
		{
			printf("Incorrect! the number is greater than %i\n\n", playerChoice);
			attempts++;
		}
		else if (playerChoice > cpuChoice)
		{
			printf("Incorrect! the number is less than %i\n\n", playerChoice);
			attempts++;
		}
		else
		{
			printf("Congratulations! You guessed the correct number in %i attempts.\n\n", attempts);
			
			break;
		}
	}
	
	int input;

	do
	{
		printf("Do you wanna play again? (1 = yes/ 2 = no): ");
		scanf_s("%i", &input);

	} while (input != 2 && input !=1);

	if (input == 2)
	{
		keepPlaying = false;
	}

}