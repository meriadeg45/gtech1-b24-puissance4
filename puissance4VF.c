#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#define NBL 6
#define NBC 7
int player;
int player_choose;
int player_col;
char token[] = "ox";
char player_1[20];
char player_2[20];
char tab[NBL][NBC];
bool isThereAWinner = false;             //Défini les valeurs du tableau.

void flushstdin() {
  int c;
  while((c = getchar()) != '\n' && c != EOF);
}

void tab_init(void) {           //Mise en forme du tableau.
  for(int y=0;y<NBL;y++)
    for(int x=0;x<NBC;x++)
      tab[y][x] = '.';
}

void print_tab(void) {          //Appel du tableau.
  printf("-------------\n");    //Haut du tableau.
  for(int y=0;y<NBL;y++) {
    for(int x=0;x<NBC;x++) {
      char case_tab = tab[y][x];
      printf("%c", case_tab);
      printf("%c", &tab); //Afficher une variable en tant que caractère.
      printf(" ");
    }
    printf("\n");               //Retour à la ligne.
  }
  printf("-------------\n");    //Bas du tableau.
  printf("1 2 3 4 5 6 7\n");
}
int update_tab(int player_choose, int player) {
  int verif = 0;
  if(tab[0][player_choose] != '.') {
    for(int x=NBC;x>=0;x--){
      if(tab[0][x] != '.'){
        verif++;
      }
      if(verif == NBC) return 2;
    }
    return 1;
  }
  for(int y=NBL;y>=0;y--) {
      if (tab[y][player_choose] == '.') {
	tab[y][player_choose] = token[player];
	print_tab();
	return 0;
	break;
      }
  }
}

void winVert(int player)
{
	for(int x=0; x<NBL-3; x++)
	 {for(int y=0; y<NBC; y++)
	{if (tab[x][y] == token [player] && tab[x+1][y] == token[player] && tab [x+2][y] == token [player] && tab [x+3][y] == token [player]){
	isThereAWinner=true;
}
}
}
}
void winHorz(int player)
{	for(int x=0; x<NBL; x++)
{	for(int y=0; y<NBC-3; y++)
{	if (tab[x][y] == token [player] && tab[x][y+1] == token[player] && tab [x][y+2] == token [player] && tab [x][y+3] == token [player])
{	isThereAWinner=true;
}
}
}
}
void winDiag(int player)
{	for(int x=0; x<NBL-3; x++)
{	for(int y=0; y<NBC-3; y++)
{	if (tab [x][y] == token [player] && tab [x+1][y+1] == token [player] && tab [x+2][y+2] == token [player] && tab [x+3][y+3] == token[player])
{	isThereAWinner=true;}
{	
}
}
}
}
void winDiag1(int player)
{	for(int x=0; x<NBL; x++)
{	for(int y=0; y<NBC; y++)
{	if(tab [x][y] == token [player] &&  tab [x+1][y-1] == token[player] && tab [x+2][y-2] == token[player] && tab[x+3][y-3] == token[player])
{	isThereAWinner=true;
}
}
}
}
void victorytest(int player){
winVert(player);
winHorz(player);
winDiag(player);
winDiag1(player);
}


void game(void) {
    
  printf("Bonjour joueur 1, quel est votre nom ?: ");
  scanf("%s", &player_1);
  printf("Bienvenu %s.\n", &player_1);
  printf("Bonjour joueur 2, quel est votre nom ?: ");
  scanf("%s", &player_2);
  printf("Bienvenu %s.\n", &player_2);
  printf("La partie va bientôt commencer.\n", &player_1 , &player_2);

  tab_init();
 
  int player = 0;

print_tab();

  while(!isThereAWinner) {

    printf("[%c] Où voulez placer votre jeton ?", token[player]);
 	int isError = scanf("%d", &player_choose);
	if(isError > 0) {
		if(player_choose < 1 || player_choose > NBC)
		{
			printf("Cette colonne n'existe pas.\n");
			continue;
		}
		
		player_choose--;

		int check_tab = update_tab(player_choose, player);
		
		if(check_tab == 1) {
			printf("Cette colonne est pleine.");
			continue;
		}
		else if(check_tab == 2) {
			printf("Le tableau est plein, match nul.");
			break;
		}
		else {
			victorytest(player);
			player = !player;
		}
	}
	else
	{
		printf("Mauvaise colonne");
		flushstdin();
		continue;
	}
  }


  if(isThereAWinner){
    if(player == 1){
      printf("%s gagne\n", player_1);
    }else{
      printf("%s gagne\n", player_2);
    }
  }
  else{
    printf("Match nul\n");
  }
}

void main(void){
  game();
}
