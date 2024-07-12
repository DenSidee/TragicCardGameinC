/*Dichiarazioni funzioni principali contenute nel main*/

#ifndef GAMELIB_
#define GAMELIB_
#define MAX 100
 
enum Classe_mago {darkness,life,light};
enum Type_card {creature,remove_creature,inflict_damage,heal_damage};

typedef struct Mago
{
char name[MAX];
int lifePoints;
enum Classe_mago class;
}Mago;

typedef struct Carta
{
enum Type_card type;
int life_points;
struct Carta* prossimaCarta;
}Carta;

void setGame(); 
//305 di gamelib.c

void fight(); 
//395 di gamelib.c

void end_game(); 
//543 di gamelib.c

#endif
