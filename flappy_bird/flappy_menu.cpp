#include <iso646.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#include <conio.h>
#else
#include <ncurses.h>
#include "../extras/unix_support.h"
#endif

#include "flappygame.h"
#include "flappy_menu.h"
#include "highscore.h"
#include "../extras/extra.h"

#define keyUp 72 // arrow keys
#define keyDown 80
#define keyLeft 75
#define keyRight 77
#define keyEnter 13

int temp = 0;
void screenTitle(int *num)
{
	int titleScreen[10][94] = {{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
							   {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
							   {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
							   {1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
							   {1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
							   {1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0},
							   {1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
							   {1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0},
							   {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1},
							   {1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 1, 1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1}};

	clearScreen();
	setCursorPosition(0, 0);

	puts("");
	for (int i = 0; i < 10; i++)
	{
		printf("     ");
		for (int j = 0; j < 94; j++)
		{
			if (titleScreen[i][j])
			{
				int state = (j + *num + 3 * i) % 69;
				if ((0 <= state and state <= 9) or (60 <= state and state <= 69))
				{
					printf("%c", char(176));
				}
				else if ((10 <= state and state <= 19) or (50 <= state and state <= 59))
				{
					printf("%c", char(177));
				}

				else if ((20 <= state and state <= 29) or (40 <= state and state <= 49))
				{
					printf("%c", char(178));
				}
				else
				{
					printf("%c", char(219));
				}
			}
			else
				printf(" ");
		}
		puts("");
		hideCursor();
	}
}

// N4O: Renamed to avoid conflict.
int flappy_bird()
{
	char key;
	int x = 1;
	int num;
	int currPos = 0;
	char options[3][15] = {"Play", "Highscore", "Exit"};
	do
	{
		screenTitle(&num);
		num += 68;
		printf("                       ");
		for (int i = 0; i < 30; i++)
		{
			if (i == 0)
				printf("%c", char(201));
			else if (i == 29)
				printf("%c", char(187));
			else
				printf("%c", char(205));
		}
		puts("");
		printf("                       %c                            %c\n", char(186), char(186));
		for (int i = 0; i < 3; i++)
		{
			printf("                       %c   ", char(186));
			if (currPos == i)
				printf(">>   ");
			else
				printf("     ");

			printf("%s", options[i]);
			for (int j = strlen(options[i]); j < 12; j++)
				printf(" ");

			if (currPos == i)
				printf("   <<");
			else
				printf("     ");
			printf("   %c", char(186));
			puts("");
		}
		printf("                       %c                            %c\n", char(186), char(186));
		printf("                       ");
		for (int i = 0; i < 30; i++)
		{
			if (i == 0)
				printf("%c", char(200));
			else if (i == 29)
				printf("%c", char(188));
			else
				printf("%c", char(205));
		}
		if (kbhit())
		{
			key = getch();
			if ((key == keyUp or key == keyLeft) and currPos != 0)
				currPos--;
			else if ((key == keyDown or key == keyRight) and currPos != 6)
				currPos++;
			else if (key == keyEnter)
			{
				switch (currPos)
				{
				case 0:
				{
					FlappyTheBird birdy;
					clearScreen();
					birdy.startup_bird();
					while (1)
					{
						birdy.show_bird();
						temp = birdy.updateWithoutInput();
						birdy.updateWithInput();
						if (temp == 1)
						{
							int exit_code = 0;
							while (true) {
								int do_break = 0;
								char do_retry;
								clearScreen();
								printf("You died...\nRetry (y/n)? ");
								scanf("%c", &do_retry);
								to_lower(&do_retry);
								switch (do_retry)
								{
									case 'y':
										temp = 0;
										do_break = 1;
										clearScreen();
										birdy.startup_bird();
										break;
									case 'n':
										exit_code = 1;
										do_break = 1;
										break;
									default:
										break;
								}
								if (do_break) {
									inputUsername(birdy.score);
									break;
								}
							}
							if (exit_code) {
								break;
							}
						}
					}
					break;
				}
				case 1:
				{
					printLeaderboard();
					break;
				}
				case 2:
				{
					clearScreen();
					printf("You have clicked exit");
					return 0;
				}
				}
			}
		}

	} while (x != 0);

	return 0;
}
