#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "gamelib.h"  /*Include gamelib.h*/

#define LIFE 20; 


static struct Mago mago1; //player 1
static struct Mago mago2; //player 2
static struct Carta* fields1;
static struct Carta* fields2;


static struct Carta *hand1 = 0; //mano player 1 
static struct Carta *hand2 = 0; //mano player 2
static struct Carta *deck1 = 0; //mazzo player 1
static struct Carta *deck2 = 0; //mazzo player 2

int gioca=0;

int conta(Carta* testa){
	int i=0;
	while(testa != NULL){
		i++;
		testa = testa -> prossimaCarta;
	}
	return i;
}

int generaTypeOfCard() //funzione per generare tipo di carta
{

	int a=rand()%100;
	if(a>=0&&a<40)
		return 0;
	if(a>=40&&a<65)
			return 1;
	if(a>=65&&a<85)
			return 2;
	if(a>=85&&a<100)
			return 3;
	return 0;
}

int generateLifePointsOfCard(int n) //funzione per genreare punti vita di una carta
{
	int a=(rand()%10)+1;
		return a;
}

static struct Carta* aggiungi_in_testa_carta(Carta* testa,Carta* daAggiungere){  //per aggiungere carte in testa

	if(conta(testa)>5 )
	{
		printf("Mano piena");
		testa = (Carta*) malloc(sizeof(Carta));
		return testa;

	}
	else

	{
				Carta* nodoSuccessivo = testa;
				testa = (Carta*) malloc(sizeof(Carta));
				testa =daAggiungere;
								testa -> prossimaCarta = nodoSuccessivo;

			return testa;
	}

}

static struct Carta* aggiungi_in_testa(Carta* testa){ //per aggiungere carta in testa

	if(conta(testa)>5)
	{
		printf("Mano piena\n");
		return testa;
    

	}
  
	else

	{
		int num=conta(testa);
			if(testa != 0){
				Carta* nodoSuccessivo = testa;
				testa = (Carta*) malloc(sizeof(Carta));
				testa -> type = generaTypeOfCard();
								testa -> life_points = generateLifePointsOfCard(num);
								testa -> prossimaCarta = nodoSuccessivo;
			}
			else{
				testa = (Carta*) malloc(sizeof(Carta));
				testa -> type = 2;
						testa -> life_points=2 ;
						testa -> prossimaCarta = 0;
			}
			return testa;
	}
  

}

static struct Carta* aggiungi_in_coda(Carta* testa){ //per aggiungere carte in coda
	if(testa != 0){
		Carta* nodoSuccessivo = testa;
		while(nodoSuccessivo -> prossimaCarta != 0){
			nodoSuccessivo = nodoSuccessivo -> prossimaCarta;
		}
	    nodoSuccessivo -> prossimaCarta = aggiungi_in_testa(0);
	}
	else{
		testa = aggiungi_in_testa(testa);
	}
	return testa;
}

static struct Carta* aggiungi_in_posizione(int posizione, Carta* testa){ //per aggiungere le carte in posizione

	if(posizione == 0 || testa == 0){
		testa = aggiungi_in_testa(testa);
	}
	else if(posizione > 0){
		int i=1;
		Carta* nodoSuccessivo = testa;
		while(i < posizione && nodoSuccessivo -> prossimaCarta != 0){
			nodoSuccessivo = nodoSuccessivo -> prossimaCarta;
			i++;
		}
		nodoSuccessivo -> prossimaCarta = aggiungi_in_testa(nodoSuccessivo -> prossimaCarta);
	}
	return testa;
}

static struct Carta* rimuovi_in_testa(Carta* testa){   //per rimuovere carta dalla testa 
	if(testa != 0){
		Carta* daEliminare = testa;
		testa = testa -> prossimaCarta;
		free(daEliminare);
	}

	return testa;
}

static struct Carta* rimuovi_in_coda(Carta* testa){ //per rimuovere carta dalla coda
	if(testa != 0){
		if(testa -> prossimaCarta != 0){

			Carta* attuale = testa;
			Carta* daEliminare = testa -> prossimaCarta;

			while(daEliminare -> prossimaCarta != 0){
				attuale = daEliminare;
				daEliminare = daEliminare -> prossimaCarta;
			}
	    	attuale -> prossimaCarta = rimuovi_in_testa(daEliminare);
		}
		else{
			testa = rimuovi_in_testa(testa);
		}
	}

	return testa;
}

static struct Carta* rimuovi_in_posizione(int posizione, Carta* testa){ //per rimuovere posizione


	if(posizione == 0 || testa -> prossimaCarta == 0){
		testa = rimuovi_in_testa(testa);
	}
	else if(posizione > 0){
		int i=1;

		Carta* attuale = testa;
		Carta* daEliminare = testa -> prossimaCarta;

		while(i < posizione && daEliminare-> prossimaCarta != 0){
                        attuale = daEliminare;
			daEliminare = daEliminare -> prossimaCarta;
			i++;
		}
		attuale -> prossimaCarta = rimuovi_in_testa( daEliminare -> prossimaCarta);

	}
	return testa;
}

static struct Carta* ritronaCarta_in_posizione(int posizione, Carta* testa){ //per far ritornare la carta in posizione


	if(posizione == 0 || testa -> prossimaCarta == 0){
		return testa;
	}
	else if(posizione > 0)
	{
		int i=1;

		Carta* attuale = testa;
		Carta* daTornare = testa -> prossimaCarta;

		while(i < posizione && daTornare-> prossimaCarta != 0){
                        attuale = daTornare;
                        daTornare = daTornare -> prossimaCarta;
			i++;
		}
		attuale -> prossimaCarta = rimuovi_in_testa( daTornare -> prossimaCarta);

	}
	return testa;
}


void stampa_lista(Carta * testa){ //funzione per stampare la lista delle carte 
	if(testa != 0){
		printf("TESTA -> ");
		while(testa != 0){
			printf("%d -> ",testa->type);
			printf("%d -> ",testa->life_points);
			testa = testa -> prossimaCarta;
		}
	    printf("NULL \n");
	}
	else {
		printf("LISTA VUOTA \n");
	}
}




void print_hand(Carta * testa)  //funzione per stampare la mano dei giocatori
{
		if(testa != 0){

			while(testa != 0){
				printf("\t||\t");
				switch(testa->type)
				{
				case 0:
					printf("Creatura-->");
					break;
				case 1 :
					printf("Rimozione Creatura -->"); //carta remove creature
					break;
				case 2 :
					printf("Attacco -->" ); //carta inflict damage
					break;
				case 3:
					printf("Guarisci Danno -->");//carta heal damage
					break;
				}

				printf("%d ",testa->life_points);
				testa = testa -> prossimaCarta;
			}
		    printf("\n");
		}
		else {
			printf("LISTA VUOTA \n");
		}
}

void print_field(Carta * testa,int lunghezzaField)   //funzione per stampare il campo dei giocatori
{
		if(testa != 0){

			for(int i=0;i<lunghezzaField;i++){
				printf("||");
				switch(testa->type)
								{
								case 0:
									printf("Creatura ->");
									break;
								case 1 :
									printf("Rimozione creatura ->");
									break;
								case 2 :
									printf("Attacco ->");
									break;
								case 3:
									printf("Guarisci Danno ->");
									break;
								}
								printf("%d ",testa->life_points);
								printf("||");
								testa = testa -> prossimaCarta;
			}
		    printf("\n");
		}
		else {
			printf("LISTA VUOTA \n");
		}
}

Carta* draw(Carta* testa,Carta* deck)       //funzione per pescare la carta 
{
	testa=aggiungi_in_testa_carta(testa,deck);
	deck=rimuovi_in_testa(deck);

	return testa;
}

void setGame()   //funzione per impostare il gioco 
{
	int choose=0;

	printf("BENVENUTO!\n\t\tSelezionare Nome del primo mago:\n");
	scanf("%s",mago1.name);   //rileva il nome del primo mago
	do
			{
			printf("\n\n\n\t\t\tSelezionare classe del primo mago\n"         //selezione della classe del primo mago
					   " \t\t\t_________________ \n"
             "\t\t\t|                 |\n"
					   "\t\t\t|  1) Darkness    |\n"    
					   "\t\t\t|                 |\n"
				     "\t\t\t|  2) Life        |\n"
             "\t\t\t|                 |\n"
					   "\t\t\t|  3) Light       |\n"
					   "\t\t\t|                 |\n"
					   "\t\t\t|_________________|\n\n\n->");
			scanf("%d",&choose);
			if(choose<1||choose>3)
				printf("ERRORE DI INSERIMENTO\n");
			}
	while(choose<1||choose>3);

	mago1.class=choose;
	mago1.lifePoints=LIFE;


	printf("\t\tSelezionare nome del secondo mago:\n");
		scanf("%s",mago2.name);    //rileva il nome del secondo mago
		do
				{
				printf("\n\n\n\t\t\tSelezionare classe del secondo mago\n"  //selezione della classe del secondo mago
						 " \t\t\t_________________ \n"
             "\t\t\t|                 |\n"
					   "\t\t\t|  1) Darkness    |\n"    
					   "\t\t\t|                 |\n"
				     "\t\t\t|  2) Life        |\n"
             "\t\t\t|                 |\n"
					   "\t\t\t|  3) Light       |\n"
					   "\t\t\t|                 |\n"
					   "\t\t\t|_________________|\n\n\n->");
				scanf("%d",&choose);
				if(choose<1||choose>3)
					printf("ERRORE DI INSERIMENTO\n");
				}
				while(choose<1||choose>3);
		mago2.class=choose;
		mago2.lifePoints=LIFE;


		static unsigned short numCarteDeck=0;

		printf("\nNumero di carte per ogni deck:\n");
				scanf("%hu",&numCarteDeck);

				for(int i=0;i<numCarteDeck;i++)
						{
							deck1 = aggiungi_in_testa(deck1);
						}

				for(int i=0;i<numCarteDeck;i++)
						{
							deck2 = aggiungi_in_testa(deck2);
						}


		for(int i=0;i<5;i++)
		{
			hand1 = aggiungi_in_testa(hand1);
		}

		printf("\n\n\t\tMano %s:\n",mago1.name);
		print_hand(hand1);

		for(int i=0;i<5;i++)
				{
					hand2 = aggiungi_in_testa(hand2);
				}

		printf("\n\n\t\tMano %s:\n",mago2.name);
		print_hand(hand2);
}

void attack(Carta * hand1 ,Carta * hand2 )  //funzione per attaccare 
{
	print_hand(hand1);
	print_hand(hand2);

	printf("\nDigita il numero di una delle carte partendo da 0\n");
											int number=0;
											scanf("%d",&number);

	hand2=rimuovi_in_posizione(number,hand2);

	printf("\nAttacco effettutato!\n");
}

void fight() //funzione fight
{
	int choose=0;
	int end=1;int finish=0;
	gioca=rand()%2;
	if(gioca==0)
	{
		printf("Inizia %s\n",mago1.name);
	}
	else
	{
		printf("Inizia %s\n",mago2.name);
	}

	do
	{

		switch(gioca)
		{
		case 0:
			finish=0;
			do
			{
				do
												{
												printf("\n\n\t\t\t%s fai la tua mossa!:\n"  //stampa azioni effettuabili da mago 1
														   "\t\t\t ________________________\n"
                               "\t\t\t|                        |\n"
                               "\t\t\t| 1) Stampa carte in mano|\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 2) Stampa campo        |\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 3) Pesca carta         |\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 4) Gioca carta         |\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 5) Attacca             |\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 6) Passa               |\n"
														   "\t\t\t|________________________|\n->",mago1.name);
												scanf("%d",&choose);
												if(choose<1||choose>6)
													printf("ERRORE DI INSERIMENTO\n");
												}
								while(choose<1||choose>6);
						switch(choose) //switch per le azioni effettuabili dal mago 1 
						{
						case 1:
							print_hand(hand1); 
							break;
						case 2:
							print_field(fields1,conta(fields1));
							break;
						case 3:
							hand1=draw(hand1,deck1);
							finish=1;
							break;
						case 4 :
							if(conta(fields1)>3)
																{
																	printf("Campo pieno!\n");
																}
																else
																{
																	print_hand(hand1);
																	printf("Digita il numero di una delle carte partendo da 0\n");
																	int number=0;
																	scanf("%d",&number);

																	fields1=ritronaCarta_in_posizione(number,hand1);
																	hand1=rimuovi_in_posizione(number,hand1);
																	finish=1;
																}
							finish=1;
							break;
						case 5:
							attack(hand1,hand2);
							finish=1;
							break;
						case 6:
							finish=1;
							break;
						}
			}while(finish==0);

			gioca=1;
			break;
		case 1:
					finish=0;
					do
					{
						do
														{
														printf("\n\n\t\t\t%s fai la tua mossa!:\n"    //stampa le azioni effettuabili dal mago 2
															 " \t\t\t________________________\n"
                               "\t\t\t|                        |\n"
                               "\t\t\t| 1) Stampa carte in mano|\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 2) Stampa campo        |\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 3) Pesca carta         |\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 4) Gioca carta         |\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 5) Attacca             |\n"
                               "\t\t\t|                        |\n"
														   "\t\t\t| 6) Passa               |\n"
														   "\t\t\t|________________________|\n->",mago2.name);
														scanf("%d",&choose);
														if(choose<1||choose>6)
															printf("ERRORE DI INSERIMENTO\n");
														}
										while(choose<1||choose>6);
								switch(choose)   //switch per le azioni effettuabili dal mago 2 
								{
								case 1:
									print_hand(hand2);
									break;
								case 2:
									print_field(fields2,conta(fields2));
									break;
								case 3:
									hand2=draw(hand2,deck2);
									finish=1;
									break;
								case 4 :
									if(conta(fields2)>3)
									{
										printf("Campo pieno\n");
									}
									else
									{
										print_hand(hand2);
										printf("Digita il numero di una delle carte partendo da 0\n");
										int number=0;
										scanf("%d",&number);

										fields2=ritronaCarta_in_posizione(number,hand2);
										hand2=rimuovi_in_posizione(number,hand2);
										finish=1;
									}

									break;
								case 5:
									finish=1;
									break;
								case 6:
									attack(hand2,hand1);
									finish=1;
									break;
								}
					}while(finish==0);

					gioca=0;
			break;
		}
	}
	while(end==1);
}

void end_game()   //funzione per la fine del gioco 
{
	printf("Grazie per aver giocato\n");
}



