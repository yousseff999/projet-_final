#include <gtk/gtk.h>


void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton3_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_radiobutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_button1_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_button2_clicked                     (GtkWidget       *objet,
                                        gpointer         user_data);

void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_chercher_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_supprimer_clicked                   (GtkButton       *objet,
                                        gpointer         user_data);

void
on_modifier_clicked                    (GtkButton       *objet,
                                        gpointer         user_data);

void
on_ajouter_clicked                     (GtkButton       *objet,
                                        gpointer         user_data);

void
on_mod_checkbutton1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mod_checkbutton2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mod_checkbutton3_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mod_radiobutton1_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mod_radiobutton2_toggled            (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_mod_afficher_clicked                (GtkButton       *objet,
                                        gpointer         user_data);

void
on_mod_valider_clicked                 (GtkButton       *objet,
                                        gpointer         user_data);

void
on_button4_retRech_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button4_affRch_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_treeview2_affrech_row_activated     (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_button_affiEle_clicked              (GtkButton       *button,
                                        gpointer         user_data);

void
on_button5_affrech_clicked             (GtkButton       *button,
                                        gpointer         user_data);

void
on_button0_clicked                     (GtkButton       *button,
                                        gpointer         user_data);

void
on_button01_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_stat_aff_clicked                    (GtkButton       *button,
                                        gpointer         user_data);

void
on_retourstat_clicked                  (GtkButton       *button,
                                        gpointer         user_data);
