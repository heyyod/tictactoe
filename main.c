#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>

enum GameState
{
	NowPlaying,
	Tie,
	Won
};

enum GameState GetGameState(char *board)
{
	if ((board[0] == board[1] && board[1] == board[2] && board[0] != ' ') ||
		(board[0] == board[3] && board[3] == board[6] && board[0] != ' ') ||
		(board[0] == board[4] && board[4] == board[8] && board[0] != ' ') ||
		(board[1] == board[4] && board[4] == board[7] && board[1] != ' ') ||
		(board[2] == board[4] && board[4] == board[6] && board[2] != ' ') ||
		(board[2] == board[5] && board[5] == board[8] && board[2] != ' ') ||
		(board[3] == board[4] && board[4] == board[5] && board[3] != ' ') ||
		(board[6] == board[7] && board[7] == board[8] && board[6] != ' '))
		return Won;
	else
	{
		int i;
		for (i = 0; i < 9; i++)
			if (board[i] == ' ') return NowPlaying;
		return Tie;
	}
	return NowPlaying;
}

struct player
{
	char *name;
	char mark;
};

void WaitForKeyPress()
{
	Sleep(500);
	printf("\n\n\n\n                                   Press any key to continue...");
	if (getch()) system("cls");
}

//Printing Functions
void PrintStartingScreen()
{
	//Intro
	{
		printf("\n\n\t\t\t     WELCOME TO\n\n");
		char boardTop[] = "\t\t\t _________________\n\t\t\t|     |     |     |\n";
		char boardRow0[] = "\t\t\t|     |     |     |\n\t\t\t|_____|_____|_____|\n\t\t\t|     |     |     |\n";
		char boardRow1[] = "\t\t\t|     |     |     |\n\t\t\t|_____|_____|_____|\n\t\t\t|     |     |     |\n";
		char boardRow2[] = "\t\t\t|     |     |     |\n\t\t\t|_____|_____|_____|\n";
		printf("%s%s%s%s", boardTop, boardRow0, boardRow1, boardRow2);
		boardRow0[6] = 'X';
		Sleep(1000);
		system("cls");
		printf("\n\n\t\t\t     WELCOME TO\n\n");
		printf("%s%s%s%s", boardTop, boardRow0, boardRow1, boardRow2);
		boardRow1[12] = 'X';
		printf("\n\t\t\t  TIC   ");
		Sleep(1000);
		system("cls");
		printf("\n\n\t\t\t     WELCOME TO\n\n");
		printf("%s%s%s%s", boardTop, boardRow0, boardRow1, boardRow2);
		boardRow2[18] = 'X';
		printf("\n\t\t\t  TIC   ");
		printf("TAC   ");
		Sleep(1000);
		system("cls");
		printf("\n\n\t\t\t     WELCOME TO\n\n");
		printf("%s%s%s%s", boardTop, boardRow0, boardRow1, boardRow2);
		printf("\n\t\t\t  TIC   ");
		printf("TAC   ");
		printf("TOE");

		WaitForKeyPress();
	}

	//Rules
	{
		printf("\n  RULES:\n\n");
		printf(" 1. The game is played on a grid that's 3 cells by 3 cells.\n\n");
		printf(" 2. If you are X you play first and your friend or the computer\n");
		printf("    is O. Players take turns putting their marks in empty cells.\n\n");
		printf(" 3. The first player to get 3 marks in a row (up, down, across,\n");
		printf("    or diagonally) is the winner.\n\n");
		printf(" 4. When all 9 cells are full, the game is over. If no player has\n");
		printf("    3 marks in a row, the game ends in a tie.\n\n\n");
		WaitForKeyPress();
	}

	//Instructions
	{
		printf("\n HOW TO PLAY:\n\n");
		printf(" You can fill the board with your mark by entering the column\n");
		printf(" (A, B or C) and the row(1, 2 or 3) of a cell.\n\n");
		printf(" e.g. The top left cell is A1 and the bottom right cell is C3.");
		printf("\n\n\t\t            A     B     C   \n\t\t          _________________ \n\t\t         |     |     |     |\n");
		printf("\t\t      1  |     |     |     |\n\t\t         |_____|_____|_____|\n\t\t         |     |     |     |\n");
		printf("\t\t      2  |     |     |     |\n\t\t         |_____|_____|_____|\n\t\t         |     |     |     |\n");
		printf("\t\t      3  |     |     |     |\n\t\t         |_____|_____|_____|");
		WaitForKeyPress();
	}
}

void PrintMenu()
{
	printf("%c", 201);
	char i;
	for (i = 0; i < 63; i++) printf("%c", 205);
	printf("%c\n", 187);
	printf("%c  Make a choice (1-4):                                         %c\n", 186, 186);
	printf("%c  1. Play against the comptuter                                %c\n", 186, 186);
	printf("%c  2. Play against a friend                                     %c\n", 186, 186);
	printf("%c  3. View game log                                             %c\n", 186, 186);
	printf("%c  4. Quit                                                      %c\n", 186, 186);
	printf("%c", 200);
	for (i = 0; i < 63; i++) printf("%c", 205);
	printf("%c\n", 188);
}

void PrintBoard(char *board)
{
	system("cls");
	char boardABC[] = "\n       A     B     C   \n     _________________ \n    |     |     |     |\n";
	char boardRow0[] = " 1  |     |     |     |\n    |_____|_____|_____|\n    |     |     |     |\n";
	boardRow0[7] = board[0];
	boardRow0[13] = board[1];
	boardRow0[19] = board[2];
	char boardRow1[] = " 2  |     |     |     |\n    |_____|_____|_____|\n    |     |     |     |\n";
	boardRow1[7] = board[3];
	boardRow1[13] = board[4];
	boardRow1[19] = board[5];
	char boardRow2[] = " 3  |     |     |     |\n    |_____|_____|_____|\n";
	boardRow2[7] = board[6];
	boardRow2[13] = board[7];
	boardRow2[19] = board[8];
	printf("%s%s%s%s", boardABC, boardRow0, boardRow1, boardRow2);
}

//Board Functions
int GetCellIndexOnBoard(char column, char row)
{
	int i = 0, j = 0;
	i = (int)column - 65;
	j = (int)row - 49;
	return (j * 3 + i);
}

int IsCellEmpty(int cellIndex, char *board)
{
	return (board[cellIndex] != 'X' && board[cellIndex] != 'O');
}

//Player
char GetChoice()
{
	char c;
	printf(" > Your choice [1-4]: ");
	do c = getch();
	while (c < '1' || c > '4');
	printf("%c\n", c);
	return c;
}

char *GetPlayerName()
{
	printf("\n > Enter a name: ");
	char str[256], *pt;
	scanf("%s", str);
	pt = (char *)calloc(strlen(str) + 1, sizeof(char));
	strcpy(pt, str);
	return pt;
}

char GetPlayerMark(char *name)
{
	printf("\n > %s Choose your mark [X or O]: ", name);
	char playerMark;
	do playerMark = getch();
	while (playerMark != 'X' && playerMark != 'O' && playerMark != 'x' && playerMark != 'o');
	if (playerMark == 'X' || playerMark == 'x')
		playerMark = 'X';
	else
		playerMark = 'O';
	printf("%c", playerMark);
	Sleep(500);
	return playerMark;
}

int ChooseDifficulty()
{
	char dif;
	printf("\n Choose the difficulty level.\n 1 - EASY | 2 - MEDIUM | 3 - IMPOSSIBLE: ");
	do dif = getch();
	while (dif < '1' || dif > '3');
	printf("%c\n", dif);

	//This determines the level of accuracy of the minimax function.
	if (dif == '1')	return 2;
	else if (dif == '2') return 6;
	else return 20;
}

void GetPlayerTurn(char *board, char *name, char mark)
{
	printf("\n __________________________\n");
	char col, row, isCellEmpty = 0;
	int cellPos;
	while (!isCellEmpty)
	{
		printf("\n > %s: enter a cell: ", name);
		//Read Column
		do col = getch();
		while (!(col >= 'A' && col <= 'C') && !( col >= 'a' && col <= 'c' ));
		if (col == 'a') col = 'A';
		else if (col == 'b') col = 'B';
		else if (col == 'c') col = 'C';
		printf("%c", col);
		//Read Row
		do row = getch();
		while (row < '1' || row > '3');
		printf("%c\n", row);

		cellPos = GetCellIndexOnBoard(col, row);
		if (!IsCellEmpty(cellPos, board))
			printf("\n Looks like this cell is full.\n");
		else
			isCellEmpty = 1;
	}
	board[cellPos] = mark;
}

//Computer
int minimax(char *board, char depth, char isComputerTurn, char currentMark, char difficulty)
{
    if (GetGameState(board) == Won && isComputerTurn)
        return (difficulty - depth);
    if (GetGameState(board) == Won && !isComputerTurn)
        return (depth - difficulty);
    if (GetGameState(board) == Tie)
        return 0;

    isComputerTurn = (isComputerTurn == 1) ? 0 : 1;
    currentMark = (currentMark == 'X') ? 'O' : 'X';
    if (!isComputerTurn)
    {
        //Player looks for the move that returns the smallest value
        int minimum = 100;
        int i;
        for (i = 0; i < 9; i++)
            if (board[i] == ' ')
            {
                board[i] = currentMark;
                int minimaxValue = minimax(board, ++depth, isComputerTurn, currentMark, difficulty);
                minimum = min(minimum, minimaxValue);
                board[i] = ' ';
            }
        return minimum;
    }
    else
    {
        //Computer looks for the move that returns the greatest value
        int maximum = -100;
        int i;
        for (i = 0; i < 9; i++)
            if (board[i] == ' ')
            {
                board[i] = currentMark;
                int minimaxValue = minimax(board, ++depth, isComputerTurn, currentMark, difficulty);
                maximum = max(maximum, minimaxValue);
                board[i] = ' ';
            }
        return maximum;
    }
}

int FindBestCell(char *board, char computerMark, char difficulty)
{
    int bestMoveScore = -100, bestCell, i;
    for (i = 0; i < 9; i++)
        if (board[i] == ' ')
        {
            board[i] = computerMark;
            int moveScore = minimax(board, 0, 1, computerMark, difficulty);
            board[i] = ' ';
            if (moveScore > bestMoveScore)
            {
                bestMoveScore = moveScore;
                bestCell = i;
            }

        }
    return bestCell;
}

void GetComputerTurn(char *board, char computerMark, char playerMark, char difficulty)
{
    printf("\n __________________________\n");
    printf("\n < COMPUTER THINKING");
    int i;
    for (i = 0; i < 3; i++)
    {
        Sleep(300);
        printf(" .");
    }
    int bestCell;
    bestCell = FindBestCell(board, computerMark, difficulty);
    board[bestCell] = computerMark;
}

//File IO
int GetLogedNumber(char *line)
{
	char str[256] = { '\0' };
	int i = 10; // starting position of number
	int j = 0;
	int n;
	while (line[i] != '\n')
	{
		//Save the number to seperate string
		str[j] = line[i];
		j++;
		i++;
	}
	n = atoi(str);
	return n;
}

void LogResult(char *playerName, char result)
{
	FILE *gl_in, *gl_out;
	gl_in = fopen("gamelog.txt", "r");
	//This creates the initial gamelog.txt if it does not exist
	if (gl_in == NULL)
	{
		gl_out = fopen("gamelog.txt", "w");
		fclose(gl_out);
		gl_in = fopen("gamelog.txt", "r");
	}
	//This creates a file to save anything new and copy anything old
	gl_out = fopen("copy.txt", "a");

	int wins = 0, losses = 0, ties = 0;
	char playerExisted = 0;
	if (gl_in != NULL && gl_out != NULL)
	{
		char line[256] = { '\0' };
		while (fgets(line, sizeof(line), gl_in))
		{
			int i = 0;
			if (line[i] == '\n')
				continue; // for formatting purposes

			// We need to remove the \n to make a proper comparison with the playerName
			while (line[i] != '\n')
				i++;
			line[i] = '\0';
			//Checking if this player already has a log
			if (strcmp(line, playerName) == 0)
			{
				playerExisted = 1;
				fprintf(gl_out, "%s\n", line); //Print the name

				fgets(line, sizeof(line), gl_in);//Get wins line
				wins = GetLogedNumber(line);
				fgets(line, sizeof(line), gl_in);//Get losses line
				losses = GetLogedNumber(line);
				fgets(line, sizeof(line), gl_in);// Get ties line
				ties = GetLogedNumber(line);
				if (result == 'w')
					wins += 1;
				else if (result == 'l')
					losses += 1;
				else
					ties += 1;

				fprintf(gl_out, "WINS      %d\n", wins);
				fprintf(gl_out, "LOSSES    %d\n", losses);
				fprintf(gl_out, "TIES      %d\n\n", ties);
			}
			else
			{
				fprintf(gl_out, "%s\n", line);
				for (i = 0; i < 3; i++ )
				{
					fgets(line, sizeof(line), gl_in);
					fprintf(gl_out, "%s", line);
				}
				fprintf(gl_out, "\n");
			}
		}
	}

	if (!playerExisted)
	{
		if (result == 'w')
			wins += 1;
		else if (result == 'l')
			losses += 1;
		else
			ties += 1;
		fprintf(gl_out, "%s\n", playerName);
		fprintf(gl_out, "WINS      %d\n", wins);
		fprintf(gl_out, "LOSSES    %d\n", losses);
		fprintf(gl_out, "TIES      %d\n", ties);
	}

	fclose(gl_in);
	fclose(gl_out);

	//We delete the old file and rename copy.txt to gamelog.txt
	remove("gamelog.txt");
	rename("copy.txt", "gamelog.txt");
}

void PrintPlayerStats(char *playerName)
{
	FILE *gl_in = fopen("gamelog.txt", "r");
	char playerExisted = 0;
	if (gl_in != NULL)
	{
		char line[256] = { '\0' };
		while (fgets(line, sizeof(line), gl_in))
		{
			// We need to remove the \n to make a proper comparison with the playerName
			int i = 0;
			if (line[i] == '\n')
				continue;
			while (i < 256)
			{
				if (line[i] == '\n')
				{
					line[i] = '\0';
					break;
				}
				i++;
			}
			//Checking if this player already has a log
			if (strcmp(line, playerName) == 0)
			{
				playerExisted = 1;
				int j;
				for (j = 0; j < 3; j++)
				{
					fgets(line, sizeof(line), gl_in);
					printf("\t\t %s", line);
				}
				break;
			}
		}
		if (!playerExisted)
			printf("\n Player not found.");

		fclose(gl_in);
	}
	else
		printf("\n ERROR: No stats available yet.");
}

void PrintGameLog()
{
	FILE *gl_in = fopen("gamelog.txt", "r");
	if (gl_in == NULL)
		printf("\n ERROR: No stats available yet.");
	else
	{
		printf("\n");
		char line[256] = { "\0" };
		while (fgets(line, sizeof(line), gl_in))
		{
			if (line[0] == '\n')
				printf("===============================\n");
			else
				printf("  %s", line);
		}
		fclose(gl_in);
	}
}

//Main Function
int main()
{
	// Setting the size of the console window
	SMALL_RECT WindowRect = { 0, 0, 65, 23};
	HANDLE WindowHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTitle("Tic Tac Toe");
	SetConsoleWindowInfo(WindowHandle, TRUE, &WindowRect);

	PrintStartingScreen();

	char choice;
	do
	{
		enum GameState gameState = NowPlaying;
		char board[9] = { ' ',' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };

		PrintMenu();
		choice = GetChoice();
		switch (choice)
		{
		case '1': // player vs computer
		{
			char difficulty = ChooseDifficulty();
			struct player player;
			player.name = GetPlayerName();
			player.mark = GetPlayerMark(player.name);
			char computerMark = (player.mark == 'X') ? 'O' : 'X';
			char playerWon = 0 , isPlayerTurn = 0;

			if (player.mark == 'X')
				isPlayerTurn = 1;
			PrintBoard(board);
			while (gameState == NowPlaying)
			{
				if( isPlayerTurn)
					GetPlayerTurn(board, player.name, player.mark);
				else
					GetComputerTurn(board, computerMark, player.mark, difficulty);
				PrintBoard(board);
				gameState = GetGameState(board);
				if (gameState == Won || gameState == Tie)
				{
					if (isPlayerTurn)
						playerWon = 1;
					break;
				}
				isPlayerTurn = (isPlayerTurn == 1) ? 0 : 1;
			}
			if (gameState == Tie)
			{
				LogResult(player.name, 't');
				printf("\n    The game is a Tie.\n");
			}
			else if (playerWon)
			{
				LogResult(player.name, 'w');
				printf("\n    Congratulations! YOU WON!\n");
			}
			else
			{
				LogResult(player.name, 'l');
				printf("\n    You lost. Better luck next time...");
			}
			free(player.name);
			WaitForKeyPress();
			break;
		}
		case '2': // player vs player
		{
			struct player players[2];
			printf("\nPLAYER 1: ");
			players[0].name = GetPlayerName();
			printf("\nPLAYER 2: ");
			char isNameDifferent;
			do
			{
				isNameDifferent = 1;
				players[1].name = GetPlayerName();
				if (strcmp(players[0].name, players[1].name) == 0)
				{
					isNameDifferent = 0;
					printf("\n Please enter a different name.");
				}
			} while (!isNameDifferent);
			players[0].mark = GetPlayerMark(players[0].name);
			players[1].mark = (players[0].mark == 'X') ? 'O' : 'X';

			int turn, winner = -1;
			turn = (players[0].mark == 'X') ? 0 : 1; //Determines who plays first
			PrintBoard(board);
			while (gameState == NowPlaying)
			{
				GetPlayerTurn(board, players[turn].name, players[turn].mark);
				PrintBoard(board);
				gameState = GetGameState(board);
				if (gameState == Won)
				{
					winner = turn;
					break;
				}
				else if (gameState == Tie)
					break;
				turn = (turn == 0) ? 1 : 0;
			}
			if (gameState != Tie)
			{
				int loser = (winner == 0) ? 1 : 0;
				printf("\n    %s WON!", players[winner].name);
				LogResult(players[winner].name, 'w');
				LogResult(players[loser].name, 'l');
			}
			else
			{
				printf("\n    This game is a TIE.");
				LogResult(players[0].name, 't');
				LogResult(players[1].name, 't');
			}
            free(players[0].name);
            free(players[1].name);
			WaitForKeyPress();
			break;
		}
		case '3': // view stats
		{
			printf("\n Show all available game log? [Y/N]: ");
			char answer;
			do answer = getch();
			while (answer != 'Y' && answer != 'N' && answer != 'y' && answer != 'n');
			printf("%c\n", answer);
			if (answer == 'Y' || answer == 'y')
				PrintGameLog();
			else
			{
				char *name = GetPlayerName();
				PrintPlayerStats(name);
				free(name);
			}
		}
		case '4': WaitForKeyPress();
		}
	} while (choice != '4');

	return 0;
}
