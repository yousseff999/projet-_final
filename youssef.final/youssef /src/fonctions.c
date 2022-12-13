#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif
#include "fonctions.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gtk/gtk.h>
enum { EID,
       EMUNI,
       EJOUR,
       EMOIS,
       EANNEE,
       ENBH,
       ENBCONS,
       ETOUR,
       COLUMNS};

void ajout_election(election e,int tour, int nb)
{ 
    FILE *f=NULL;
	if (tour ==1)
	strcpy(e.tour,"1er_tour");
	if(tour==2)
	strcpy(e.tour,"2eme_tour");
        if (nb==1)
        e.nbcons_e=10;
        if (nb==2)
        e.nbcons_e=12;
        if (nb==3)
        e.nbcons_e=14;
    f=fopen("election.txt","a");
    if(f!=NULL)
    { 
        
        fprintf(f,"%s %s %d %d %d %s %d %s\n",e.id_e,e.muni_e,e.date.jour,e.date.mois,e.date.annee,e.nbhab_e,e.nbcons_e,e.tour);
        fclose(f);
    }
    }
void modifier(election e ,int mod_tour , int mod_nb)
{
if (mod_tour ==1)
	strcpy(e.tour,"1er_tour");
	if(mod_tour==2)
	strcpy(e.tour,"2eme_tour");
        if (mod_nb==1)
        e.nbcons_e=10;
        if (mod_nb==2)
        e.nbcons_e=12;
        if (mod_nb==3)
        e.nbcons_e=14;
    char id[20];
    char muni[20];
    int jour;
    int mois;
    int annee;
    char nbhab[20];
    int nbcons;
    char tour1[20];
 
    FILE * f=fopen("election.txt", "r");
    FILE * f2=fopen("election2.txt", "w");
    if(f!=NULL)
    {
        while(fscanf(f,"%s %s %d %d %d %s %d %s\n",id,muni,&jour,&mois,&annee,nbhab,&nbcons,tour1)!=EOF)
        {
            if(strcmp(e.id_e,id)==0)
            {
                fprintf(f2,"%s %s %d %d %d %s %d %s\n",e.id_e,e.muni_e,e.date.jour,e.date.mois,e.date.annee,e.nbhab_e,e.nbcons_e,e.tour);
               
            }
            else
                fprintf(f2,"%s %s %d %d %d %s %d %s\n",id,muni,jour,mois,annee,nbhab,nbcons,tour1);

        }
    }
    fclose(f);
    fclose(f2);
    remove("election.txt");
    rename("election2.txt", "election.txt");
    

}


///////////////////////////////Fonction Supprimer ////////////////////////
void supprimerElection(char id []){
election e;
FILE *f1;
FILE *f2;

f1=fopen("election.txt","r");
f2=fopen("elecSup.txt","w");
while(fscanf(f1,"%s %s %d %d %d %s %d %s\n",e.id_e,e.muni_e,&e.date.jour,&e.date.mois,&e.date.annee,e.nbhab_e,&e.nbcons_e,e.tour)!=EOF)
{if (strcmp(id,e.id_e)!=0)
fprintf(f2,"%s %s %d %d %d %s %d %s\n",e.id_e,e.muni_e,e.date.jour,e.date.mois,e.date.annee,e.nbhab_e,e.nbcons_e,e.tour);
}
fclose(f1);
fclose(f2);
remove("election.txt");
rename("elecSup.txt","election.txt");
}

/////////////////fonction afficher////////////////////////
void afficher(GtkTreeView *liste)
{	

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
election e;
         char id_e[20];
         char muni_e[20];
         char jour[20];
         char mois[20];
         char annee[20];
         char nbhab_e[20];
         char nbcons_e[20];
         char tour[20];
         store=NULL;
         FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
	
renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id_e",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("muni_e",renderer,"text",EMUNI,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nbhab_e",renderer,"text",ENBH,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nbcons_e",renderer,"text",ENBCONS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("tour",renderer,"text",ETOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

store = gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
 f=fopen("election.txt", "a+");
    if(f==NULL)
    {  return;}
else { f=fopen("election.txt", "a+");
        while(fscanf(f,"%s %s %s %s %s %s %s %s \n",id_e,muni_e,jour,mois,annee,nbhab_e,nbcons_e,tour)!=EOF)

        { 
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,EID,id_e,EMUNI,muni_e,EJOUR,jour,EMOIS,mois,EANNEE,annee,ENBH,nbhab_e,ENBCONS,nbcons_e,ETOUR,tour,-1);

}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)) ;
g_object_unref (store);
}}
}


int chercherElection(char id[])
{
election e;
FILE *f1;
FILE *f2;
int trv;
f1=fopen("election.txt","r");
f2=fopen("electionRech.txt","w");
while(fscanf(f1,"%s %s %d %d %d %s %d %s\n",e.id_e,e.muni_e,&e.date.jour,&e.date.mois,&e.date.annee,e.nbhab_e,&e.nbcons_e,e.tour)!=EOF)
{if (strcmp(e.id_e,id)!=0){
trv=0;}
else {
trv=1;
fprintf(f2,"%s %s %d %d %d %s %d %s\n",e.id_e,e.muni_e,e.date.jour,e.date.mois,e.date.annee,e.nbhab_e,e.nbcons_e,e.tour);}
}
fclose(f1);
fclose(f2);
return trv;
}


//////////////////////////////////Afficher Recherchee/////////////////
void afficherRecherche(GtkTreeView *liste)
{	

	GtkCellRenderer *renderer;
	GtkTreeViewColumn *column;
	GtkTreeIter iter;
	GtkListStore *store;
election e;
         char id_e[20];
         char muni_e[20];
         char jour[20];
         char mois[20];
         char annee[20];
         char nbhab_e[20];
         char nbcons_e[20];
         char tour[20];
         store=NULL;
         FILE *f;
store=gtk_tree_view_get_model(liste);
if (store==NULL){
	
renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("id_e",renderer,"text",EID,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("muni_e",renderer,"text",EMUNI,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("jour",renderer,"text",EJOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("mois",renderer,"text",EMOIS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("annee",renderer,"text",EANNEE,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nbhab_e",renderer,"text",ENBH,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste),column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("nbcons_e",renderer,"text",ENBCONS,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

renderer= gtk_cell_renderer_text_new ();
column = gtk_tree_view_column_new_with_attributes("tour",renderer,"text",ETOUR,NULL);
gtk_tree_view_append_column(GTK_TREE_VIEW (liste), column) ;

store = gtk_list_store_new (COLUMNS,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING,G_TYPE_STRING);
 f=fopen("electionRech.txt", "r");
    if(f==NULL)
    {  return;}
else { f=fopen("electionRech.txt", "r");
        while(fscanf(f,"%s %s %s %s %s %s %s %s \n",id_e,muni_e,jour,mois,annee,nbhab_e,nbcons_e,tour)!=EOF)

        { 
gtk_list_store_append (store,&iter);
gtk_list_store_set (store,&iter,EID,id_e,EMUNI,muni_e,EJOUR,jour,EMOIS,mois,EANNEE,annee,ENBH,nbhab_e,ENBCONS,nbcons_e,ETOUR,tour,-1);

}
fclose(f);
gtk_tree_view_set_model (GTK_TREE_VIEW (liste),GTK_TREE_MODEL (store)) ;
g_object_unref (store);
}}
}
////////////////stat agemoyen///////////////////
float agemoyen(char * filename )
{
  FILE * f = fopen ("user.txt", "r");
int nbelect =0;
int s = 0;
int age ;
stat u;


while (fscanf (f , "%s %d %s %s %d %d %d %s %s %d %d \n " ,u.nat, &u.cin , u.nom , u.prenom , &u.date.jour,  &u.date.mois, &u.date.annee , u.genre, u.type , &u.numBV , &u.vote)!=EOF)
{
if (strcmp(u.type, "electeur") == 0 ) {

	nbelect ++ ;
	age = 2022 - u.date.annee ;
	s  = s + age ;

 	}
}

float moyenage= (float)s/nbelect;

return moyenage ;
}

////////////////stat taux.o.n.e///////////////////
float TPE( char * filename)
{

        FILE *f = fopen ("user.txt", "r");
        stat u;
float e ;
        int tot=0,  nbe=0;
        if (f != NULL )
    {
        while (fscanf (f , "%s %d %s %s %d %d %d %s %s %d %d \n " ,u.nat, &u.cin , u.nom , u.prenom , &u.date.jour,  &u.date.mois, &u.date.annee , u.genre, u.type , &u.numBV , &u.vote)!=EOF)
{
            if (strcmp(u.type, "electeur") == 0)
            {
                tot ++ ;
                if (strcmp(u.nat, "etranger")==0)
                    nbe++ ;
                
            }

        }


    }
    e = (float)nbe / tot ;
return e;
}

float TPN( char * filename)
{

        FILE *f = fopen ("user.txt", "r");
        stat u;
float n ; 
        int tot=0, nbt=0;
        if (f != NULL )
    {
        while (fscanf (f , "%s %d %s %s %d %d %d %s %s %d %d \n " ,u.nat, &u.cin , u.nom , u.prenom , &u.date.jour,  &u.date.mois, &u.date.annee , u.genre, u.type , &u.numBV , &u.vote)!=EOF)
{
            if (strcmp(u.type, "electeur") == 0)
            {
                tot ++ ;
                if (strcmp(u.nat, "tunisien")==0)
                    nbt++ ;
            }
        }
    }
    n = (float)nbt / tot ;
return n;
}







