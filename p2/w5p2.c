/*
	==================================================
	Workshop #5 (Part-2):
	==================================================
	Name   : Harsh Patel
	ID     : 146315205
	Email  : hpatel262@myseneca.ca
	Section: IPC144NJJ
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_length 70
#define MIN_length 10

struct PlayerInfo
{
	int no_of_lives;
	char ch_symbol;
	int found_treasure;
	int history[MAX_length];
};

struct Gameinfo
{
	int path_length;
	int no_of_moves;
	int bomb[MAX_length];
	int treasure[MAX_length];
};

int main()
{
	int a = 1, lives, path_len, moves, i, j, n = 0;
	const int multiple = 5;
	const int  MAX_LIVES = 10;
	const int MIN_LIVES = 1;
	int move[MAX_length] = { 0 };
	int symbol[MAX_length] = { 0 };
	int var = 0;
	struct PlayerInfo p = { 0 };
	struct Gameinfo g = { 0 };

	printf("================================\n");
	printf("         Treasure Hunt!         \n");
	printf("================================\n\n");
	/*
		start PLAYER Configuration
	*/
	printf("PLAYER Configuration\n");
	printf("--------------------\n");
	printf("Enter a single character to represent the player: ");
	scanf(" %c", &p.ch_symbol);

	while (a > 0)
	{
		printf("Set the number of lives: "); // taking number of lives.
		scanf("%d", &lives);
		if (lives > MIN_LIVES && lives < MAX_LIVES)
		{
			p.no_of_lives = lives;
			break;
		}
		else if (lives < MIN_LIVES || lives > MAX_LIVES)
		{
			printf("     Must be between 1 and 10!\n");
		}
	}
	printf("Player configuration set-up is complete\n");
	/*
		PLAYER Configuration ends
		start of GAME Configuration
	*/
	printf("\nGAME Configuration\n");
	printf("------------------\n");
	while (a > 0)
	{

		printf("Set the path length (a multiple of %d between %d-%d): ", multiple, MIN_length, MAX_length); // setting path length
		scanf("%d", &path_len);
		if (path_len > MIN_length && path_len < MAX_length)
		{
			if (path_len % multiple == 0)
			{
				g.path_length = path_len;
				break;
			}
			else
			{
				printf("     Must be a multiple of %d and between %d-%d!!!\n", multiple, MIN_length, MAX_length);
			}
		}
		else if (path_len < MIN_length || path_len > MAX_length)
		{
			printf("     Must be a multiple of %d and between %d-%d!!!\n", multiple, MIN_length, MAX_length);
		}
	}
	while (a > 0)
	{
		int max_moves = 0.75 * path_len;

		printf("Set the limit for number of moves allowed: ");          //setting number of moves allowed
		scanf("%d", &moves);
		if (moves > lives && moves < max_moves)
		{
			g.no_of_moves = moves;
			break;
		}
		else if (moves < lives || moves > max_moves)
		{
			printf("    Value must be between %d and %d\n", lives, max_moves);
		}
	}
	printf("\nBOMB Placement\n");                                                 //configuring bomb placement
	printf("--------------\n");
	printf("Enter the bomb positions in sets of %d where a value\n", multiple);
	printf("of 1=BOMB, and 0=NO BOMB. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", path_len);
	int pos = path_len / multiple;

	for (i = 0; i < 1; i++)
	{
		printf("   Positions [ 1- 5]: ");

		for (j = 0; j < multiple; j++)
		{
			scanf("%d", &g.bomb[var + j]);
		}
	}
	var = multiple;

	for (i = 1; i < 2; i++)
	{
		printf("   Positions [ 6-10]: ");

		for (j = 0; j < multiple; j++)
		{
			scanf("%d", &g.bomb[var + j]);
		}
	}
	var = 2 * multiple;

	for (i = 2; i < pos; i++)
	{
		printf("   Positions [%d-%d]: ", (var + 1), (i + 1) * multiple);

		for (j = 0; j < multiple; j++)
		{
			scanf("%d", &g.bomb[var + j]);
		}
		var = (i + 1) * multiple;
	}
	printf("BOMB placement set\n\n");


	printf("TREASURE Placement\n------------------\n");                             //configurung treasure placement
	printf("Enter the treasure placements in sets of %d where a value\n", multiple);
	printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
	printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", path_len);

	var = 0;

	for (i = 0; i < 1; i++)
	{
		printf("   Positions [ 1- 5]: ");

		for (j = 0; j < multiple; j++)
		{
			scanf("%d", &g.treasure[var + j]);
		}
	}

	var = multiple;

	for (i = 1; i < 2; i++)
	{
		printf("   Positions [ 6-10]: ");

		for (j = 0; j < multiple; j++)
		{
			scanf("%d", &g.treasure[var + j]);
		}
	}
	var = 2 * multiple;

	for (i = 2; i < pos; i++)
	{
		printf("   Positions [%d-%d]: ", (var + 1), (i + 1) * multiple);

		for (j = 0; j < multiple; j++)
		{
			scanf("%d", &g.treasure[var + j]);
		}
		var = (i + 1) * multiple;
	}
	var = 0;
	printf("TREASURE placement set\n\n");
	printf("GAME configuration set-up is complete...\n\n");
	/*
	   GAME Configuration ends
		start TREASURE HUNT Configuration Settings
	*/
	printf("------------------------------------\n");
	printf("TREASURE HUNT Configuration Settings\n");
	printf("------------------------------------");
	printf("\nPlayer:");
	printf("\n   Symbol     : %c", p.ch_symbol);
	printf("\n   Lives      : %d", p.no_of_lives);
	printf("\n   Treasure   : [ready for gameplay]");
	printf("\n   History    : [ready for gameplay]\n");

	printf("\nGame:");
	printf("\n   Path Length: %d", g.path_length);
	printf("\n   Bombs      : ");


	for (i = 0; i < pos; i++)
	{

		for (j = 0; j < multiple; j++)
		{
			printf("%d", g.bomb[var + j]);

		}
		var = (i + 1) * multiple;
	}
	var = 0;
	printf("\n   Treasure   : ");

	for (i = 0; i < pos; i++)
	{
		for (j = 0; j < multiple; j++)
		{
			printf("%d", g.treasure[var + j]);

		}
		var = (i + 1) * multiple;
	}
	/*
		TREASURE HUNT Configuration Settings ends
	*/
	printf("\n\n====================================");
	printf("\n~ Get ready to play TREASURE HUNT! ~");
	printf("\n====================================\n");

	while (p.no_of_lives != 0 && g.no_of_moves != 0)
	{
		printf("\n  ");
		for (i = 0; i < g.path_length; i++)     // showing were is bomb,treasure, bomb and treasure together
												// and nothing found at places we visited
		{
			if (symbol[i] == 0)
			{
				printf("-");
			}
			else if (symbol[i] == 1)
			{
				printf(".");
			}
			else if (symbol[i] == 2)
			{
				printf("&");
			}
			else if (symbol[i] == 3)
			{
				printf("!");
			}
			else if (symbol[i] == 4)
			{
				printf("$");
			}
		}
		printf("\n  ");                     // loop for major ruler
		for (i = 1, j = 1; i < g.path_length + 1; i++)
		{
			if (i % 10 == 0)
			{
				printf("%d", j);
				j++;
			}
			else
			{
				printf("|");
			}
		}
		printf("\n  ");
		for (i = 0; i < g.path_length / 10; i++)        // loop for minor ruler
		{
			for (j = 1; j < 11; j++)
			{
				if (j % 10 == 0)
				{
					printf("0");
				}
				else
				{
					printf("%d", j);
				}
			}
		}
		printf("\n");
		printf("+---------------------------------------------------+\n");
		printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", p.no_of_lives, p.found_treasure, g.no_of_moves);
		printf("+---------------------------------------------------+\n");
		while (move[n] < 1 || move[n] > g.path_length)          // move setup
		{
			printf("Next Move [1-%d]: ", g.path_length);
			scanf("%d", &move[n]);
			if (move[n] < 1 || move[n] > g.path_length)
			{
				printf("  Out of Range!!!\n");
			}

		}

		if (p.history[move[n] - 1] == 1)
		{
			printf("\n===============> Dope! You've been here before!\n\n");
		}
		else if (g.bomb[move[n] - 1] == 0 && g.treasure[move[n] - 1] == 0)
		{
			printf("\n===============> [.] ...Nothing found here... [.]\n\n");
			symbol[move[n] - 1] = 1;
			p.history[move[n] - 1] = 1;
			g.no_of_moves--;
		}
		else if (g.bomb[move[n] - 1] == 1 && g.treasure[move[n] - 1] == 1)
		{
			printf("\n===============> [&] !!! BOOOOOM !!! [&]\n");
			printf("===============> [&] $$$ Life Insurance Payout!!! [&]\n\n");
			symbol[move[n] - 1] = 2;
			p.history[move[n] - 1] = 1;
			g.no_of_moves--;
			p.no_of_lives--;
			p.found_treasure++;
		}
		else if (g.bomb[move[n] - 1] == 1)
		{
			printf("\n===============> [!] !!! BOOOOOM !!! [!]\n\n");
			symbol[move[n] - 1] = 3;
			p.history[move[n] - 1] = 1;
			g.no_of_moves--;
			p.no_of_lives--;
		}
		else if (g.treasure[move[n] - 1] == 1)
		{
			printf("\n===============> [$] $$$ Found Treasure! $$$ [$]\n\n");
			symbol[move[n] - 1] = 4;
			p.history[move[n] - 1] = 1;
			g.no_of_moves--;
			p.found_treasure++;
		}

		if (p.no_of_lives == 0 && g.no_of_moves == 0)
		{
			printf("No more LIVES and MOVES remaining!\n\n");
		}
		else if (p.no_of_lives == 0)
		{
			printf("No more LIVES remaining!\n\n");
		}
		else if (g.no_of_moves == 0)
		{
			printf("No more MOVES remaining!\n\n");
		}
		printf("  ");
		for (i = 0; i < g.path_length; i++)         // loop for printing current postion using character symbol
		{
			if (i == (move[n] - 1))
			{
				printf("%c", p.ch_symbol);
			}
			else
			{
				printf(" ");
			}
		}

		n++;

	}
	printf("\n  ");
	for (i = 0; i < g.path_length; i++)
	{
		if (symbol[i] == 0)
		{
			printf("-");
		}
		else if (symbol[i] == 1)
		{
			printf(".");
		}
		else if (symbol[i] == 2)
		{
			printf("&");
		}
		else if (symbol[i] == 3)
		{
			printf("!");
		}
		else if (symbol[i] == 4)
		{
			printf("$");
		}
	}
	printf("\n  ");
	for (i = 1, j = 1; i < g.path_length + 1; i++)
	{
		if (i % 10 == 0)
		{
			printf("%d", j);
			j++;
		}
		else
		{
			printf("|");
		}
	}
	printf("\n  ");
	for (i = 0; i < g.path_length / 10; i++)
	{
		for (j = 1; j < 11; j++)
		{
			if (j % 10 == 0)
			{
				printf("0");
			}
			else
			{
				printf("%d", j);
			}
		}
	}
	printf("\n");
	printf("+---------------------------------------------------+\n");
	printf("  Lives: %2d  | Treasures: %2d  |  Moves Remaining: %2d\n", p.no_of_lives, p.found_treasure, g.no_of_moves);
	printf("+---------------------------------------------------+\n");

	printf("\n##################\n");
	printf("#   Game over!   #\n");
	printf("##################\n\n");
	printf("You should play again and try to beat your score!");
	return 0;
}