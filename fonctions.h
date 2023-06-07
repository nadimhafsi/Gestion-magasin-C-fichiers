#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

int code;
char nom[20],description[20],dateexpiration[20];
int quantite;
float prix;

int codecommande,qttecommande;


FILE* fp;
FILE* fc;



void ajouterproduit(void);
void afficherproduits(void);
void  modifierproduits(void);
void supprimerproduit(void);
void rechercherproduit(void);
void passercommande(void);
void affichercommandes(void);
void supprimercommande(void);
void modifiercommande(void);


void modifiercommande(){
    rewind(fc);
    int codec,tr=0;
    FILE* temp;


   fc=fopen("commandes.txt","rt");

        if(fc==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }

    temp=fopen("temp.txt","wt");

            if(temp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }



     printf("donner le code du commande a modifier : ") ;
     scanf("%d",&codec);
     while(fscanf(fc,"%d\n%d\n%d\n",&codecommande,&code,&qttecommande)==3)
     {
         if(codecommande==codec)
         {
             tr=1;
             printf("donner le nouveau code de produit : ");
             scanf("%d",&code);
             printf("donner la nouvelle quantite : ");
             scanf("%d",&qttecommande);

         }

     fprintf(temp,"%d\n%d\n%d\n",codecommande,code,qttecommande);
     }
     fclose(fc);
     fclose(temp);
      remove("commandes.txt");
      rename("temp.txt","commandes.txt");

     if(tr==0) printf("la commande n'existe pas !!!! \n");
     else printf("modification se faite avec succes\n");

}



void supprimercommande(){
    rewind(fc);
    int codec,tr=0;
    FILE* temp;


    fc=fopen("commandes.txt","rt");

        if(fc==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }

    temp=fopen("temp.txt","wt");

            if(temp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }



     printf("donner le code du commande a supprimer : ") ;
     scanf("%d",&codec);
     while(fscanf(fc,"%d\n%d\n%d\n",&codecommande,&code,&qttecommande)==3)
     {
         if(codecommande!=codec)
     fprintf(temp,"%d\n%d\n%d\n",codecommande,code,qttecommande);
         else
            tr=1;
     }
     fclose(fc);
     fclose(temp);
      remove("commandes.txt");
      rename("temp.txt","commandes.txt");

     if(tr==0) printf("la commande n'existe pas !!!! \n");
     else printf("suppression se faite avec succes\n");

}


void affichercommandes(){
    rewind(fc);
    fc=fopen("commandes.txt","r"); //mode lire
          if(fc==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }

     printf("voila la liste de commandes\n\n");
     rewind(fc);
     while(!feof(fc))
      {
          fscanf(fc,"%d\n%d\n%d\n",&codecommande,&code,&qttecommande);

          printf("commande n%d:%d pieces de produit n%d\n",codecommande,qttecommande,code);
      }
      printf("\n\n");
      fclose(fc);

}

void passercommande(){
    FILE* temp;
    int codep,quantitec,tr=0; //initialement etudiant n'exite pas
    int code1,code2,code3;
     fc=fopen("commandes.txt","a+"); //mode lire et ecrire

     if(fc==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }

            fp=fopen("stock.txt","rt");

        if(fp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }

            temp=fopen("temp.txt","wt");

        if(fp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }


      printf("donner code produit a commander : ");
      scanf("%d",&codep);

       while(fscanf(fp,"%d\n%s\n%s\n%d\n%f\n%s\n",&code,nom,description,&quantite,&prix,dateexpiration)==6)
     {

         if(code==codep)
         {
             printf("donner la quantite a commander : ");
             scanf("%d",&quantitec);
             if(quantitec>quantite)
                printf("stok insuffisant\n");
             else{
             printf("donner le code du commande : ");
             scanf("%d",&codecommande);
             while(!feof(fc))
             { fscanf(fc,"%d\n%d\n%d\n",&code1,&code2,&code3);
                 if(code1==codecommande)
                 {   printf("numero de commande deja utlise !!!!!!!!!!!\n");
                     goto fin;

                 }
             }
             quantite=quantite-quantitec;
             tr=1;
             fprintf(fc,"%d\n%d\n%d\n",codecommande,code,quantitec);
                }
         }
        fprintf(temp,"%d\n%s\n%s\n%d\n%f\n%s\n",code,nom,description,quantite,prix,dateexpiration);
     }

     fclose(fp);
     fclose(fc);
     fclose(temp);
      remove("stock.txt");
      rename("temp.txt","stock.txt");

    if(tr==0) printf("produit n'existe pas !!!!!!!!\n");
    else printf("commande se faite avec succees\n");

fin:  ;
}


void supprimerproduit(){
    int codep,tr=0;
    FILE* temp;

    afficherproduits();

    fp=fopen("stock.txt","rt");

        if(fp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }

    temp=fopen("temp.txt","wt");

            if(temp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }



     printf("donner le code de produit a supprimer : ") ;
     scanf("%d",&codep);
     while(fscanf(fp,"%d\n%s\n%s\n%d\n%f\n%s\n",&code,nom,description,&quantite,&prix,dateexpiration)==6)
     {
         if(code!=codep)
     fprintf(temp,"%d\n%s\n%s\n%d\n%f\n%s\n",code,nom,description,quantite,prix,dateexpiration);
         else
            tr=1;
     }
     fclose(fp);
     fclose(temp);
      remove("stock.txt");
      rename("temp.txt","stock.txt");

     if(tr==0) printf("le produit n'existe pas !!!! \n");
     else printf("suppression se faite avec succes\n");
}


void modifierproduit(){
    int codep,tr=0;
    FILE* temp;
         afficherproduits();

    fp=fopen("stock.txt","rt");

        if(fp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }

    temp=fopen("temp.txt","wt");

            if(temp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }



     printf("donner le code de produit a modifier : ") ;
     scanf("%d",&codep);
    rewind(fp);
     while(fscanf(fp,"%d\n%s\n%s\n%d\n%f\n%s\n",&code,nom,description,&quantite,&prix,dateexpiration)==6)
     {
         if(code==codep)
         {
             tr=1;
             printf("donner le nouveau nom : ");
             scanf("%s",nom);
             printf("donner la nouvelle description : ");
             scanf("%s",description);
             printf("donner la nouvelle quantite : ");
             scanf("%d",&quantite);
             printf("donner le nouveau prix : ");
             scanf("%f",&prix);
         }

     fprintf(temp,"%d\n%s\n%s\n%d\n%f\n%s\n",code,nom,description,quantite,prix,dateexpiration);
     }
     fclose(fp);
     fclose(temp);
      remove("stock.txt");
      rename("temp.txt","stock.txt");

     if(tr==0) printf("le produit n'existe pas !!!! \n");
     else printf("modification se faite avec succes\n");
}


void rechercherproduit(){
    int codep,tr=0,ch;
    char nomp[20];
    fp=fopen("stock.txt","r");
    rewind(fp);
    if(fp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }


              printf("\n1 : recherche par code produit\n");
              printf("2 : recherche par nom produit\n\n");
              printf("choisir votre critere de recherche: ");
              scanf("%d",&ch);
              printf("\n");

    if(ch==1)
    {

        printf("donner code produit : ");
        scanf("%d",&codep);
        printf("\n\n");

        while(!feof(fp))
        {
          fscanf(fp,"%d\n%s\n%s\n%d\n%f\n%s\n",&code,nom,description,&quantite,&prix,dateexpiration);
          if(code==codep)
          {
              tr=1;
              printf("Code : %d \n",code);
              printf("nom : %s \n",nom);
              printf("description : %s \n",description);
              printf("Quantite : %d \n",quantite);
              printf("Prix : %f TND \n",prix);
              printf("date expiration : %s \n",dateexpiration);

          }
        }

        if(tr==0) printf("produit n'existe pas !!! \n");

    }

    else if(ch==2)
        {

        printf("donner nom produit : ");
        scanf("%s",nomp);
        printf("\n\n");

        while(!feof(fp))
        {
          fscanf(fp,"%d\n%s\n%s\n%d\n%f\n%s\n",&code,nom,description,&quantite,&prix,dateexpiration);
          if(strcmp(nom,nomp) == 0)
          {
              tr=1;
              printf("Code : %d \n",code);
              printf("nom : %s \n",nom);
              printf("description : %s \n",description);
              printf("Quantite : %d \n",quantite);
              printf("Prix : %f TND \n",prix);
              printf("date expiration : %s \n",dateexpiration);

          }
        }

        if(tr==0) printf("produit n'existe pas !!! \n");

    }
    fclose(fp);
}


void afficherproduits(){
    rewind(fp);
    fp=fopen("stock.txt","r"); //mode lire et ecrire
          if(fp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }

     printf("voila la liste de produis\n\n");
     while(!feof(fp))
      {
          fscanf(fp,"%d\n%s\n%s\n%d\n%f\n%s\n",&code,nom,description,&quantite,&prix,dateexpiration);

          printf("%d-->%s \n",code,nom);
      }
      printf("\n\n");
      fclose(fp);
}


void ajouterproduit(){
    int codep,tr=0; //initialement etudiant n'exite pas
     fp=fopen("stock.txt","a+"); //mode lire et ecrire

     if(fp==NULL)
        {printf("impossible d'ouvrir le fichier\n");
        exit(1);
        }
      printf("donner code produit: ");
      scanf("%d",&codep);

      while(!feof(fp))
      {
          fscanf(fp,"%d\n%s\n%s\n%d\n%f\n%s\n",&code,nom,description,&quantite,&prix,dateexpiration);
          if(code==codep)
          {
              tr=1;
              break;
          }
      }
      if(tr==1)
        printf("produit exite deja!!!!!\n");
      else
      {
          printf("donner le nom : ");
          scanf("%s",nom);
          printf("donner la description : ");
          scanf("%s",description);
          printf("donner la quantite : ");
          scanf("%d",&quantite);
          printf("donner le prix: ");
          scanf("%f",&prix);
          printf("donner la date d'expiration: ");
          scanf("%s",dateexpiration);

           fprintf(fp,"%d\n%s\n%s\n%d\n%f\n%s\n",codep,nom,description,quantite,prix,dateexpiration);
      }
    fclose(fp);

}

#endif // FONCTIONS_H_INCLUDED
