#include <gtk/gtk.h>


void
on_addo_clicked                        (GtkWidget       *button,
                                        gpointer         user_data);

void
on_r_male_toggled                      (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_r_fmale_toggled                     (GtkToggleButton *togglebutton,
                                        gpointer         user_data);



void
on_treeview1_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview2_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_treeview3_row_activated             (GtkTreeView     *treeview,
                                        GtkTreePath     *path,
                                        GtkTreeViewColumn *column,
                                        gpointer         user_data);

void
on_modifyo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);//

void
on_searcho_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_deleteo_clicked                     (GtkWidget       *button,
                                        gpointer         user_data);

void
on_searcho2_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton1_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_checkbutton2_toggled                (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_refresho1_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_save_clicked                 	(GtkWidget       *objet_graphique,
                                        gpointer         user_data);//

void
on_entrynommo_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data);

void
on_rbhommemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_rbfemmemo_toggled                   (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_entry_cino_grab_focus               (GtkWidget       *widget,
                                        gpointer         user_data);


void
on_refresho3_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton4o_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);

void
on_refresho2_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);

void
on_checkbutton3o_toggled               (GtkToggleButton *togglebutton,
                                        gpointer         user_data);


void
on_searcho4_clicked                    (GtkWidget       *button,
                                        gpointer         user_data);

void
on_refresho4_clicked                   (GtkWidget       *button,
                                        gpointer         user_data);
