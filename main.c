#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "gamelib.h"

int main(void)
{
	srand(time(0));
	int choose; //variabile scelta giocatore menù
	int ended=1;
	int isSetted=0;
	do
	{
		do
		{
		printf( "\n"

"▄▄▄█████▓██▀███  ▄▄▄       ▄████ ██▓▄████▄        ▄▄▄█████▓██░ ██▓█████     ▄████▄  ▄▄▄      ██▀███ ▓█████▄      ▄████ ▄▄▄      ███▄ ▄███▓█████ \n"
"▓  ██▒ ▓▓██ ▒ ██▒████▄    ██▒ ▀█▓██▒██▀ ▀█        ▓  ██▒ ▓▓██░ ██▓█   ▀    ▒██▀ ▀█ ▒████▄   ▓██ ▒ ██▒██▀ ██▌    ██▒ ▀█▒████▄   ▓██▒▀█▀ ██▓█   ▀ \n"
"▒ ▓██░ ▒▓██ ░▄█ ▒██  ▀█▄ ▒██░▄▄▄▒██▒▓█    ▄       ▒ ▓██░ ▒▒██▀▀██▒███      ▒▓█    ▄▒██  ▀█▄ ▓██ ░▄█ ░██   █▌   ▒██░▄▄▄▒██  ▀█▄ ▓██    ▓██▒███   \n"
"░ ▓██▓ ░▒██▀▀█▄ ░██▄▄▄▄██░▓█  ██░██▒▓▓▄ ▄██▒      ░ ▓██▓ ░░▓█ ░██▒▓█  ▄    ▒▓▓▄ ▄██░██▄▄▄▄██▒██▀▀█▄ ░▓█▄   ▌   ░▓█  ██░██▄▄▄▄██▒██    ▒██▒▓█  ▄ \n"
"  ▒██▒ ░░██▓ ▒██▒▓█   ▓██░▒▓███▀░██▒ ▓███▀ ░        ▒██▒ ░░▓█▒░██░▒████▒   ▒ ▓███▀ ░▓█   ▓██░██▓ ▒██░▒████▓    ░▒▓███▀▒▓█   ▓██▒██▒   ░██░▒████▒\n"
"  ▒ ░░  ░ ▒▓ ░▒▓░▒▒   ▓▒█░░▒   ▒░▓ ░ ░▒ ▒  ░        ▒ ░░   ▒ ░░▒░░░ ▒░ ░   ░ ░▒ ▒  ░▒▒   ▓▒█░ ▒▓ ░▒▓░▒▒▓  ▒     ░▒   ▒ ▒▒   ▓▒█░ ▒░   ░  ░░ ▒░ ░\n"
"    ░     ░▒ ░ ▒░ ▒   ▒▒ ░ ░   ░ ▒ ░ ░  ▒             ░    ▒ ░▒░ ░░ ░  ░     ░  ▒    ▒   ▒▒ ░ ░▒ ░ ▒░░ ▒  ▒      ░   ░  ▒   ▒▒ ░  ░      ░░ ░  ░\n"
"  ░       ░░   ░  ░   ▒  ░ ░   ░ ▒ ░                ░      ░  ░░ ░  ░      ░         ░   ▒    ░░   ░ ░ ░  ░    ░ ░   ░  ░   ▒  ░      ░     ░   \n"
"           ░          ░  ░     ░ ░ ░ ░                     ░  ░  ░  ░  ░   ░ ░           ░  ░  ░       ░             ░      ░  ░      ░     ░  ░\n"
"                                   ░                                       ░                         ░                                          \n"                  
    "\n"           
"                     ____                                 \t\t\tTragic The Card Game:\n"
"                   .'* *.'\n"
"                __/_*_*(_                       \tInserisci il comando dalla lista sottostante!\n"
"               / _______ \\ \n"
"              _\\_)/___\\(_/_                              \t\t\t _________________\n"
"             / _((\\- -/))_ \\                             \t\t\t|                 |\n"
"             \\ \\())(-)(()/ /                             \t\t\t| 1) Set Game     |\n"
"              ' \\(((()))/ '                               \t\t\t|                 |\n"
"             / ' \\)).))/ ' \\                             \t\t\t| 2) Fight!       |\n"
"            / _ \\ -|| - /_  \\                            \t\t\t|                 |\n"
"           (   ( .;''';. .'  )                             \t\t\t| 3) Finish       |\n"
"            _\\""__ /    )\\ __""/_                           \t\t\t|_________________|\n"
"             \\/  \\   ' /  \\/                            \t\t\t                   \n"
"              .'  '...' ' )\n"
"              / /  |  \\ \\\n"
"             / .   .   . \\ \n"
"            /   .     .   \\ \n  "        
"          /   /   |   \\   \\ \n "        
"        .'   /    b    '.  '.  \n "     
"    _.-'    /     Bb     '-. '-._\n  "  
"_.-'       |      BBb       '-.  '-.\n "
"(________mrf\\____.dBBBb.________)____) \n       "     );         
		scanf("%d",&choose);
		if(choose<1||choose>3)  //in caso l'opzione scelta non corrispondesse con le opzioni date 
			printf("ERRORE! L'opzione inserita non è inclusa nella lista!\n");
		}
		while(choose<1||choose>3);

		switch(choose) //switch per il menù
		{
		case 1:
			setGame();
			isSetted=1;
			break;
		case 2:
			if(isSetted)

				fight();
			else
				printf("Gioco Non Settato\n");
			break;
		case 3:
			end_game();
			ended=0;
			break;
		}
	}
	while(ended);


	return(0);

}
