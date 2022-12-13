#ifdef HAVE_CONFIG_H
#  include <config.h>
#endif

#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "callbacks.h"
#include "interface.h"
#include "support.h"
#include "fonctions.h"

int tour=1;
int nb=0;
int mod_tour=1;
int mod_nb=0;
void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 nb=1;
}


void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
         
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 nb=2;

}


void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 nb=3;
}


void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
tour=1;
}


void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
tour=2;
}


void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
election e;
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_aff;
GtkTreeView *treeview1;

fenetre_ajout = lookup_widget(objet, "fenetre_ajout");
gtk_widget_hide(fenetre_ajout);
fenetre_aff=lookup_widget(objet,"fenetre_afficher");
fenetre_aff=create_fenetre_afficher();
gtk_widget_show(fenetre_aff);
treeview1=lookup_widget(fenetre_aff, "treeview1") ;
afficher(treeview1);
}


void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry_id,*combo_nb_h,*label,*muni,*jour,*mois,*annee;
election e ;
GtkWidget *fenetre_ajout , *pInfo;
fenetre_ajout = lookup_widget(objet,"fenetre_ajout");

entry_id= lookup_widget(objet,"entry_id_elec");
muni= lookup_widget(objet,"entry_muni_elec");
jour = lookup_widget(objet,"jour_elec");
mois = lookup_widget(objet,"mois_elec");
annee = lookup_widget(objet,"annee_elec");
combo_nb_h = lookup_widget(objet,"combo_nbh_elec");


strcpy(e.id_e,gtk_entry_get_text(GTK_ENTRY(entry_id)));
strcpy(e.muni_e,gtk_entry_get_text(GTK_ENTRY(muni)));
e.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
e.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
e.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(e.nbhab_e,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo_nb_h)));

ajout_election( e,tour ,nb);
//modifier(e,tour,nb);
gtk_label_set_text(GTK_LABEL(label),"election est bien ajouté .");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"election est bien ajouté");
switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(pInfo);
break;
}
}

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{
GtkTreeIter iter;
gchar* id;
gchar* jour;
gchar* mois;
gchar* annee;
gchar* muni;
gchar* nbh;
gchar* nbc;
gchar* tour;

election e;
GtkTreeModel *model= gtk_tree_view_get_model(treeview);
GtkWidget* windowmod,*windowaff,*tre,*idd,*jj,*mm,*aa,*mun,*nbbh,*nbbc,*tt;

if (gtk_tree_model_get_iter(model, &iter,path))
{


gtk_tree_model_get(GTK_LIST_STORE(model),&iter,0,&id,1,&muni,2,&jour,3,&mois,4,&annee,5,&nbh,6,&nbc,7,&tour,-1);

windowmod=create_fenetre_modif();
windowaff=create_fenetre_afficher();
gtk_widget_hide(windowaff);
gtk_widget_show(windowmod);

idd=lookup_widget(windowmod,"mod_entry_id");
gtk_entry_set_text(GTK_ENTRY(idd),id);

mun=lookup_widget(windowmod,"mod_muni");
gtk_entry_set_text(GTK_ENTRY(mun),muni);

jj=lookup_widget(windowmod,"mod_jour");
gtk_entry_set_text(GTK_ENTRY(jj),jour);

mm=lookup_widget(windowmod,"mod_mois");
gtk_entry_set_text(GTK_ENTRY(mm),mois);

aa=lookup_widget(windowmod,"mod_annee");
gtk_entry_set_text(GTK_ENTRY(aa),annee);





}
}

void
on_chercher_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_chercher;
GtkWidget *fenetre_afficher;
fenetre_afficher = lookup_widget(objet, "fenetre_afficher");
gtk_widget_hide(fenetre_afficher);
fenetre_chercher=lookup_widget(objet,"window_rech");
fenetre_chercher=create_window_rech();
gtk_widget_show(fenetre_chercher);

}


void
on_supprimer_clicked                   (GtkButton       *button,
                                        gpointer         user_data)
{
char idelet[20];
GtkWidget *windowreclamation,*tree, *iden,*output;
iden = lookup_widget(button,"entry_supp");
strcpy(idelet,gtk_entry_get_text(GTK_ENTRY(iden)));
supprimerElection(idelet);
windowreclamation=lookup_widget(button,"fenetre_afficher");
tree=lookup_widget(windowreclamation,"treeview1");
afficher(tree);
output=lookup_widget(button,"label20_msgSupp");
gtk_label_set_text(GTK_LABEL(output), "Supprimer avec Succes");
}


void
on_modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_modif;
GtkWidget *fenetre_afficher;
fenetre_afficher = lookup_widget(objet, "fenetre_afficher");
gtk_widget_hide(fenetre_afficher);
fenetre_modif=lookup_widget(objet,"fenetre_modif");
fenetre_modif=create_fenetre_modif();
gtk_widget_show(fenetre_modif);



}


void
on_ajouter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *fenetre_ajout;
GtkWidget *fenetre_aff;
GtkTreeView *treeview1;

fenetre_aff = lookup_widget(objet, "fenetre_afficher");
gtk_widget_hide(fenetre_aff);
fenetre_ajout=lookup_widget(objet,"fenetre_ajout");
fenetre_ajout=create_fenetre_ajout();
gtk_widget_show(fenetre_ajout);
}


void
on_mod_checkbutton1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 mod_nb=1;
}


void
on_mod_checkbutton2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 mod_nb=2;
}


void
on_mod_checkbutton3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
 mod_nb=3;
}


void
on_mod_radiobutton1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
mod_tour=1;
}


void
on_mod_radiobutton2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data)
{
if (gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(togglebutton)))
mod_tour=2;
}


void
on_mod_afficher_clicked                (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget *entry_id,*combo_nb_h,*label,*muni,*jour,*mois,*annee;
election e ;

GtkWidget *fenetre_aff, *fenetre_modif;
GtkTreeView *treeview1;

 entry_id= lookup_widget(objet,"mod_entry_id");
muni= lookup_widget(objet,"mod_muni");
jour = lookup_widget(objet,"mod_jour");
mois = lookup_widget(objet,"mod_mois");
annee = lookup_widget(objet,"mod_annee");
combo_nb_h = lookup_widget(objet,"mod_combobox");


strcpy(e.id_e,gtk_entry_get_text(GTK_ENTRY(entry_id)));
strcpy(e.muni_e,gtk_entry_get_text(GTK_ENTRY(muni)));
e.date.jour=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(jour));
e.date.mois=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(mois));
e.date.annee=gtk_spin_button_get_value_as_int(GTK_SPIN_BUTTON(annee));
strcpy(e.nbhab_e,gtk_combo_box_get_active_text(GTK_COMBO_BOX(combo_nb_h)));

modifier(e,mod_tour,mod_nb);



fenetre_modif = lookup_widget(objet, "fenetre_modif");
gtk_widget_hide(fenetre_modif);
fenetre_aff=lookup_widget(objet,"fenetre_afficher");
fenetre_aff=create_fenetre_afficher();
gtk_widget_show(fenetre_aff);
treeview1=lookup_widget(fenetre_aff, "treeview1") ;
afficher(treeview1);
}


void
on_mod_valider_clicked                 (GtkButton       *objet,
                                        gpointer         user_data)
{
GtkWidget  *pInfo;
GtkWidget *entry_id,*label;
char id[30];
int found = 0;
election e;
entry_id= lookup_widget(objet,"mod_entry_id");
strcpy(e.id_e,gtk_entry_get_text(GTK_ENTRY(entry_id)));
FILE * f=fopen("election.txt", "r");

    if(f!=NULL)
    {
        while(fscanf(f,"%s \n",id)!=EOF)
        {
            if(strcmp(e.id_e,id)==0)
            {
gtk_label_set_text(GTK_LABEL(label),"id verifié .");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"id verifié .");
switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(pInfo);
break;

}
found=1;
break;
}
}
               
           
            if(found==0)
{

                gtk_label_set_text(GTK_LABEL(label),"id non verifié .");
pInfo=gtk_message_dialog_new(GTK_WINDOW(user_data),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"id non verifié .");
switch(gtk_dialog_run(GTK_DIALOG(pInfo)))
{
case GTK_RESPONSE_OK:
gtk_widget_destroy(pInfo);
break;
}
}
}
fclose(f);
}

void
on_button4_retRech_clicked             (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *fenetre_chercher;
GtkWidget *fenetre_afficher;
fenetre_chercher = lookup_widget(button, "fenetre_chercher");
gtk_widget_destroy(fenetre_chercher);
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);


}


void
on_button4_affRch_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{

char idelet[20];
GtkWidget *id,*tree,*windowrechercher,*output,*fenetre_afficher;
int k;
windowrechercher=lookup_widget(button,"window_rech");
id = lookup_widget(button,"entry4_rechE");
strcpy(idelet,gtk_entry_get_text(GTK_ENTRY(id)));

k=chercherElection(idelet);

if (k==0)
	{

	output=lookup_widget(button,"label4_rechInt");
	gtk_label_set_text(GTK_LABEL(output), "Election Introuvable");
	}
if (k==1)	
	{	


}

gtk_widget_destroy(windowrechercher);
windowrechercher=create_window_rech();
gtk_widget_show(windowrechercher);
tree=lookup_widget(windowrechercher,"treeview2_affrech");
afficherRecherche(tree);
}


void
on_treeview2_affrech_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data)
{

}


void
on_button_affiEle_clicked              (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *tree, *windowelection;
windowelection=lookup_widget(button,"fenetre_afficher");
gtk_widget_destroy(windowelection);
windowelection=create_fenetre_afficher();
tree=lookup_widget(windowelection,"treeview1");
afficher(tree);
gtk_widget_hide(windowelection);
gtk_widget_show(windowelection);
}





void
on_button0_clicked                     (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output;
output = lookup_widget(button, "label0");
float t, agemoy;
char str[20];
t = agemoyen("user.txt");
sprintf(str,"%f",t);
gtk_label_set_text(GTK_LABEL(output),str);

}


void
on_button01_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *output,*output1;
output = lookup_widget(button, "label01");
float t,tpn;
char str[20];
char strr[20];
t = TPE("user.txt");
sprintf(str,"%f",t);
gtk_label_set_text(GTK_LABEL(output),str);
output1 = lookup_widget(button, "label02");
tpn = TPN("user.txt");
sprintf(strr,"%f",tpn);
gtk_label_set_text(GTK_LABEL(output1),strr);
}


void
on_stat_aff_clicked                    (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *stat;
GtkWidget *fenetre_afficher;
fenetre_afficher = lookup_widget(button, "fenetre_afficher");
gtk_widget_hide(fenetre_afficher);
stat=lookup_widget(button,"stat");
stat=create_stat();
gtk_widget_show(stat);

}


void
on_retourstat_clicked                  (GtkButton       *button,
                                        gpointer         user_data)
{
GtkWidget *stat;
GtkWidget *fenetre_afficher;
stat = lookup_widget(button, "stat");
gtk_widget_destroy(stat);
fenetre_afficher=lookup_widget(button,"fenetre_afficher");
fenetre_afficher=create_fenetre_afficher();
gtk_widget_show(fenetre_afficher);
}

