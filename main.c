#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fonctions.h"



int main()
{   int choix;




    do
    {  system("cls");
      printf("\n\n \n########### Menu gestion stock magasin ###########\n\n\n");
      printf("\n1 : Ajouter nouvel produit\n");
      printf("\n2 : Modifer  produit\n");
      printf("\n3 : Supprimer produit\n");
      printf("\n4 : Afficher liste produits\n");
      printf("\n5: Recherche de produit\n");
      printf("\n6: passer une commande\n");
      printf("\n7: Afficher liste commandes\n");
      printf("\n8: Supprimer commande\n");
      printf("\n9: Modifier commande\n");
      printf("\n0 : Fin du programme\n");
      printf("\n\nVotre choix :");
      scanf("%d",&choix);

      switch(choix)
      {
          case 1 :  {      ajouterproduit();  ;break;}
          case 2 :  {      modifierproduit()  ;break;}
          case 3 :  {      supprimerproduit(); ;break;}
          case 4 :  {      afficherproduits()   ;break;}
          case 5 :  {      rechercherproduit();    ;break;}
          case 6 :  {      passercommande()   ;break;}
          case 7 :  {      affichercommandes()   ;break;}
          case 8 :  {      supprimercommande()   ;break;}
          case 9 :  {      modifiercommande()   ;break;}
          case 0 :  {      printf("\n\nfin du prgramme\n\n")   ;break;}
          default : printf("choix errone\n\n\n");
      }

    getch();
    }
    while(choix!=0);



    return 0;
}
