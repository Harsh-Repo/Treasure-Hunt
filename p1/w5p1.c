/*
    ==================================================
    Workshop #5 (Part-1):
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

} p = { 0 };

struct Gameinfo
{
    int path_length;
    int no_of_moves;
    int bomb[MAX_length];
    int treasure[MAX_length];
};

int main()
{
    int a = 1, lives, path_len, moves;
    const int multiple = 5;


    int var = 0;
    struct Gameinfo g = { 0 };

    printf("================================\n");
    printf("         Treasure Hunt!         \n");
    printf("================================\n\n");
    printf("PLAYER Configuration\n");
    printf("--------------------\n");
    printf("Enter a single character to represent the player: ");
    scanf(" %c", &p.ch_symbol);

    while (a > 0)
    {
        printf("Set the number of lives: "); // taking number of lives.
        scanf("%d", &lives);
        if (lives > 1 && lives < 10)
        {
            p.no_of_lives = lives;
            break;
        }
        else if (lives < 1 || lives > 10)
        {
            printf("     Must be between 1 and 10!\n");
        }
    }
    printf("Player configuration set-up is complete\n");
    printf("\nGAME Configuration\n");
    printf("------------------\n");
    while (a > 0)
    {

        printf("Set the path length (a multiple of 5 between 10-70): ");        // setting path lenght
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
    int i = 0;
    for (; i < 1; i++)
    {
        printf("   Positions [ 1- 5]: ");
        int j = 0;
        for (; j < multiple; j++)
        {
            scanf("%d", &g.bomb[var + j]);
        }
    }
    var = multiple;
    int k = 1;
    for (; k < 2; k++)
    {
        printf("   Positions [ 6-10]: ");
        int l = 0;
        for (; l < multiple; l++)
        {
            scanf("%d", &g.bomb[var + l]);
        }
    }
    var = 2 * multiple;
    int m = 2;
    for (; m < pos; m++)
    {
        printf("   Positions [%d-%d]: ", (var + 1), (m + 1) * multiple);
        int n = 0;
        for (; n < multiple; n++)
        {
            scanf("%d", &g.bomb[var + n]);
        }
        var = (m + 1) * multiple;
    }
    printf("BOMB placement set\n\n");


    printf("TREASURE Placement\n------------------\n");                             //configurung treasure placement
    printf("Enter the treasure placements in sets of %d where a value\n", multiple);
    printf("of 1=TREASURE, and 0=NO TREASURE. Space-delimit your input.\n");
    printf("(Example: 1 0 0 1 1) NOTE: there are %d to set!\n", path_len);

    var = 0;
    int v = 0;
    for (; v < 1; v++)
    {
        printf("   Positions [ 1- 5]: ");
        int q = 0;
        for (; q < multiple; q++)
        {
            scanf("%d", &g.treasure[var + q]);
        }
    }

    var = multiple;
    int r = 1;
    for (; r < 2; r++)
    {
        printf("   Positions [ 6-10]: ");
        int s = 0;
        for (; s < multiple; s++)
        {
            scanf("%d", &g.treasure[var + s]);
        }
    }
    var = 2 * multiple;
    int t = 2;
    for (; t < pos; t++)
    {
        printf("   Positions [%d-%d]: ", (var + 1), (t + 1) * multiple);
        int u = 0;
        for (; u < multiple; u++)
        {
            scanf("%d", &g.treasure[var + u]);
        }
        var = (t + 1) * multiple;
    }
    var = 0;
    printf("TREASURE placement set\n\n");
    printf("GAME configuration set-up is complete...\n\n");
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

    int w = 0;
    for (; w < pos; w++)
    {
        int x = 0;
        for (; x < multiple; x++)
        {
            printf("%d", g.bomb[var + x]);

        }
        var = (w + 1) * multiple;
    }
    var = 0;
    printf("\n   Treasure   : ");
    int y = 0;
    for (; y < pos; y++)
    {
        int z = 0;
        for (; z < multiple; z++)
        {
            printf("%d", g.treasure[var + z]);

        }
        var = (y + 1) * multiple;
    }
    printf("\n\n====================================");
    printf("\n~ Get ready to play TREASURE HUNT! ~");
    printf("\n====================================");
    return 0;
}