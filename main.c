#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct maillon_t
{
  int valeur;
  struct maillon_t* suivant;
}maillon_t;

//Fonction permettant de verifier si la chaine de caractere est une lettre/mot
int is_alpha(char *str)
{
  int i = -1;
  while (str[++i])
    if (isalpha(str[i]))
      return (1);
  return (0);
}

//Fonction permettant de verifier si la chaine de caractere est un chiffre/nombre
int is_num(char *str)
{
  int i = -1;
  while (str[++i])
    if (isdigit(str[i]))
      return (1);
  return (0);
}

// Methode permettant d'exit avec affichage d'erreur
void my_error()
{
    fprintf(stderr, "Erreur\n"); // Affichage sortie erreur
    exit(1);
}

// Fonction permettant la creation (et allocation de memoire) d'un seul maillon
maillon_t* create_maillon(int valeur, maillon_t* suivant)
{
    maillon_t* maillon = (maillon_t*)malloc(sizeof(maillon_t));
    if (maillon == NULL)
      my_error();
    maillon->valeur = valeur;
    maillon->suivant = suivant;
    return maillon;
}

// Methode permettant de liberer l'allocation de memoire pour le maillon
void free_maillon(maillon_t* maillon)
{
  if (maillon != NULL)
  {
    free_maillon(maillon->suivant);
    free(maillon);
  }
}

// Fonction permettant d'inserer un maillon
maillon_t* insert_maillon(maillon_t* maillon, maillon_t* element)
{
  if (maillon == NULL)
  {
    element->suivant = NULL;
    return element;
  }
  element->suivant = maillon;
  return element;
}

// Fonction permettant d'afficher la liste des maillons
void show_maillon(maillon_t* maillon)
{
  if (maillon != NULL)
    {

      show_maillon(maillon->suivant);
      printf("%d -> ", maillon->valeur);
    }
  else
    printf("\n");
  }

// Fonction permettant de verifier l'operateur
maillon_t* check_operateur(char *str, maillon_t* maillon)
{
  if (!strcmp(str, "ADD")) // addtionner
    printf("Il faut addtionner\n");
  else if (!strcmp(str, "SUB")) // soustaire
    printf("Il faut soustraire\n");
  else if (!strcmp(str, "MUL")) // multiplier
    printf("Il faut multiplier\n");
  else if (!strcmp(str, "DIV")) //diviser
    printf("Il faut diviser\n");
  else if (!strcmp(str, "MOD")) // modulo
    printf("Il faut modulo\n");
  else if (!strcmp(str, "POP")) // retirer le dernier element de la pile
    printf("Il faut enlever le dernier element de la pile\n");
  else if (!strcmp(str, "DUP")) // depliquer le dernier element de la pile
    printf("Il faut dupliquer le dernier element de la pile\n");
  else if (!strcmp(str, "SWP")) // echanger les deux derniers elements de la pile
    printf("Il faut echanger les deux derniers elements de la pile\n");
  else
    printf("Cet operateur n'existe pas\n");
  return (maillon);
}

// Fonction principale
int main()
{
    int N;
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        char instruction[11];
        scanf("%s", instruction);
    }
    printf("answer\n");
    return 0;
}
