#ifndef EELECTION_H_INCLUDED
#define EELECTION_H_INCLUDED
#endif
#include <stdio.h>
#include <string.h>
#include <gtk/gtk.h>
typedef struct  
{
int jour,mois,annee;
}date;
typedef struct 
{
date date;
char id_e[50];
char muni_e[20];
char nbhab_e[20];
int nbcons_e;
char tour[20];
}election;

typedef struct 
{
char nat[20];
int  cin;
char nom[20];
char prenom[20]; 
date date;
char genre[20];
char type[20]; 
int  numBV;
int  vote;
}stat;

void ajout_election(election e,int tour, int nb);
void afficher(GtkTreeView *liste);
void modifier(  election e , int mod_tour , int mod_nb );
void supprimerElection(char id []);
int chercherElection(char id[]);
void afficherRecherche(GtkTreeView *liste);
float agemoyen(char * filename);
float TPE( char * filename);
float TPN( char * filename);

