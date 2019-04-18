#include <gtk/gtk.h>
#include "ajouter.h"
#include "recherche.h"
#include "supprimer.h"
#include<stdio.h>
#include<stdlib.h>


void about(void){

    GtkWidget *about,*Table,*Image;


    about=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(about),"ABOUT");
    gtk_window_set_default_size(GTK_WINDOW(about),799,500);
    gtk_window_set_position(GTK_WINDOW(about),GTK_WIN_POS_CENTER);
    gtk_window_set_icon_from_file(GTK_WINDOW(about),"D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\about.gif",NULL);
    Table=gtk_table_new(1,1,TRUE);
    gtk_container_add(GTK_CONTAINER(about),Table);
    Image=gtk_image_new_from_file("E:\\LES PROJETS\\Bibliotheque1.05.1\\IMGab.gif");
    gtk_table_attach(GTK_TABLE(Table), Image,0, 1, 0, 1,GTK_EXPAND | GTK_FILL, GTK_EXPAND,0, 0);

    gtk_widget_show_all(about);
    gtk_main();

    }

