#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<unistd.h>
#define NBL 6
#define NBC 7
int player;
char token[] = "ox";
char player_1[20];
char player_2[20];
char tab[NBL][NBC];
bool end = false;             //Défini les valeurs du tableau.


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
void update_tab(int player_choose, int player) {
  for(int y=NBL;y>=0;y--) {
      if (tab[y][player_choose] == '.') {
	tab[y][player_choose] = token[player];
	break;
      }
  }
}

void winVert(void)
{
	for(int x=0; x<NBL-3; x++)
	 {for(int y=0; y<NBC; y++)
	{if (tab[x][y] == token [player] && tab[x+1][y] == token[player] && tab [x+2][y] == token [player] && tab [x+3][y] == token [player]){
	end=true;
}
}
}
}
void winHorz(void)
{	for(int x=0; x<NBL; x++)
{	for(int y=0; y<NBC-3; y++)
{	if (tab[x][y] == token [player] && tab[x][y+1] == token[player] && tab [x][y+2] == token [player] && tab [x][y+3] == token [player])
{	end=true;
}
}
}
}
void winDiag(void)
{	for(int x=0; x<NBL; x++)
{	for(int y=0; y<NBC; y++)
{	if (tab [x][y] == token [player] && tab [x+1][y+1] == token [player] && tab [x+2][y+2] == token [player] && tab [x+3][y+3] == token[player])
{	end=true;
}
}
}
}
void main(void){
  game();
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
  do{
    print_tab();
    int player_choose;
    
    printf("[%c] Où voulez placer votre jeton ?", token[player]);
    scanf("%d", &player_choose);
    player_choose--;
    
    update_tab(player_choose, player);
    winVert();
    winHorz();
    winDiag();
   
    player = !player;
  }while(!end);
}

