#ifndef MAIN_H_INCLUDED
#define MAIN_H_INCLUDED

typedef struct{
    GtkWidget* grille1;
    GtkWidget* grille2;
    GtkWidget* grille3;
    GtkWidget* grille4;
    GtkWidget* grille5;
    GtkWidget* grille6;

}Data;

void devine(GtkWidget* widget, Data* data);

#endif // MAIN_H_INCLUDED
