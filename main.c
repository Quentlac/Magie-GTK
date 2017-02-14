#include <stdlib.h>
#include <gtk/gtk.h>
#include "main.h"



int main (int argc, char *argv[])
{
    Data data;
    gtk_init(&argc, &argv);

    //creation d'une fenetre
    GtkWidget* fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(fenetre),"Tour de magie!");

    //creation d'une boite vertical
    GtkWidget* vbox = NULL;
    vbox = gtk_vbox_new(FALSE,0);

    //insertion des explications
    GtkWidget* explication = NULL;
    explication = gtk_label_new("<b>Choisissez un nombre compris entre 1 et 64, puis séléctionner les grilles qui contiennet ce nombre.</b>");
    gtk_label_set_use_markup(GTK_LABEL(explication),TRUE);
    gtk_box_pack_start(GTK_BOX(vbox),explication,FALSE,FALSE,0);

    //insertion des image
    GtkWidget* image = NULL;
    image = gtk_image_new_from_file("./cartes.png");
    gtk_box_pack_start(GTK_BOX(vbox),image,FALSE,FALSE,0);


    //insertion d'une boite horizontal
    GtkWidget* hbox = NULL;
    hbox = gtk_hbox_new(TRUE,0);

    //creation des bouton selection
    data.grille1 = gtk_toggle_button_new_with_label("SELECT");
    gtk_box_pack_start(GTK_BOX(hbox),data.grille1,FALSE,FALSE,0);

    data.grille2 = gtk_toggle_button_new_with_label("SELECT");
    gtk_box_pack_start(GTK_BOX(hbox),data.grille2,FALSE,FALSE,0);

    data.grille3 = gtk_toggle_button_new_with_label("SELECT");
    gtk_box_pack_start(GTK_BOX(hbox),data.grille3,FALSE,FALSE,0);

    data.grille4 = gtk_toggle_button_new_with_label("SELECT");
    gtk_box_pack_start(GTK_BOX(hbox),data.grille4,FALSE,FALSE,0);

    data.grille5 = gtk_toggle_button_new_with_label("SELECT");
    gtk_box_pack_start(GTK_BOX(hbox),data.grille5,FALSE,FALSE,0);

    data.grille6 = gtk_toggle_button_new_with_label("SELECT");
    gtk_box_pack_start(GTK_BOX(hbox),data.grille6,FALSE,FALSE,0);

    gtk_box_pack_start(GTK_BOX(vbox),hbox,FALSE,FALSE,0);

    //ajout d'un bouton valider
    GtkWidget* bouton_valid = NULL;
    bouton_valid = gtk_button_new_with_label("Valider");
    gtk_box_pack_start(GTK_BOX(vbox),bouton_valid,FALSE,FALSE,0);
    g_signal_connect(G_OBJECT(bouton_valid),"clicked",G_CALLBACK(devine),(gpointer)&data);

    gtk_container_add(GTK_WINDOW(fenetre),GTK_BOX(vbox));
    gtk_widget_show_all(fenetre);
    g_signal_connect(G_OBJECT(fenetre),"destroy",G_CALLBACK(gtk_main_quit),NULL);
    gtk_main();


}

void devine(GtkWidget* widget, Data* data){
    int nombre = 0;
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->grille1))){
        nombre += 1;
    }
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->grille2))){
        nombre += 2;
    }
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->grille3))){
        nombre += 4;
    }
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->grille4))){
        nombre += 8;
    }
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->grille5))){
        nombre += 16;
    }
    if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(data->grille6))){
        nombre += 32;
    }

    //creation d'une fenetre
    GtkWidget* fenetre = NULL;
    fenetre = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(fenetre),"Votre nombre!!!");
    gtk_window_set_default_size(GTK_WINDOW(fenetre),300,100);

    //creation d'une boite vertical
    GtkWidget* vbox = NULL;
    vbox = gtk_vbox_new(TRUE,0);

    char nombre_trouve[50];
    sprintf(nombre_trouve,"<big>Le nombre est: <b>%d</b></big>",nombre);

    //ajout du label
    GtkWidget* label = NULL;
    label = gtk_label_new(nombre_trouve);
    gtk_label_set_use_markup(GTK_LABEL(label),TRUE);
    gtk_box_pack_start(GTK_BOX(vbox),label,FALSE,FALSE,0);

    //ajout d'une image
    GtkWidget* image = NULL;
    image = gtk_image_new_from_file("./chapeau.png");
    gtk_box_pack_start(GTK_BOX(vbox),image,FALSE,FALSE,0);

    gtk_container_add(GTK_WINDOW(fenetre),GTK_BOX(vbox));
    gtk_widget_show_all(fenetre);
    gtk_main();

}
