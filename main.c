#include <stdlib.h>
#include <gtk/gtk.h>
#include "ajouter.h"
#include "recherche.h"
#include "supprimer.h"
#include "trie.h"
#include "about.h"





int main(int argc,char* argv[]){


    GtkWidget *Vbox=NULL;
    gtk_init(&argc,&argv);

    pwindow=gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(pwindow),"Bibliotheque");
    gtk_window_set_default_size(GTK_WINDOW(pwindow),550,500);
    gtk_window_set_position(GTK_WINDOW(pwindow),GTK_WIN_POS_CENTER);

        GtkWidget* *button;
        GdkColor color;
        gchar *text=NULL;

        // chargement des livres dans la memoir
        Charg_Livre();


        // modifier l'arrier plan de la fenetre principale
        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
        gtk_widget_modify_bg(GTK_WIDGET(pwindow),GTK_STATE_NORMAL,&color);
        // maitre un icon a la fenetre
        gtk_window_set_icon_from_file(GTK_WINDOW(pwindow),"D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\bib.gif",NULL);
        button=(GtkWidget**)malloc(4*sizeof(GtkWidget*));
        // cree un Vbox
        Vbox=gtk_vbox_new(FALSE,6);
        gtk_container_add(GTK_CONTAINER(pwindow),Vbox);







        GtkWidget *pMenu=NULL;
        GtkWidget *pMenuBar=NULL;
        GtkWidget *pMenuItem=NULL;


        /**** Creation du menu ****/
        /* ETAPE 1 */
        pMenuBar = gtk_menu_bar_new();

        /** quitter le programe **/

                pMenu = gtk_menu_new();

        pMenuItem = gtk_menu_item_new_with_label("Quitter    ");
        g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(Quitter), (GtkWidget*)pwindow);
        gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);

        pMenuItem = gtk_menu_item_new_with_label("File");
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);

        gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
        gtk_box_pack_start(GTK_BOX(Vbox), pMenuBar, FALSE, FALSE, 0);

        /** Premier sous−menu **/
        /* ETAPE 2 */
        pMenu = gtk_menu_new();

        pMenuItem = gtk_menu_item_new_with_label("Trier par nom ");
        g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(trie_nom), (GtkWidget*)pwindow);
        gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);

        pMenuItem = gtk_menu_item_new_with_label("Trier par date ");
        g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(trie_date), (GtkWidget*)pwindow);
        gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);


        pMenuItem = gtk_menu_item_new_with_label("Edit");
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);

        gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
        gtk_box_pack_start(GTK_BOX(Vbox), pMenuBar, FALSE, FALSE, 0);




                /** Deuxieme sous−menu **/
        /* ETAPE 2 */
        pMenu = gtk_menu_new();

        pMenuItem = gtk_menu_item_new_with_label("A propose    ");
        g_signal_connect(G_OBJECT(pMenuItem), "activate", G_CALLBACK(about), (GtkWidget*)pwindow);
        gtk_menu_shell_append(GTK_MENU_SHELL(pMenu), pMenuItem);

        pMenuItem = gtk_menu_item_new_with_label("?");
        gtk_menu_item_set_submenu(GTK_MENU_ITEM(pMenuItem), pMenu);

        gtk_menu_shell_append(GTK_MENU_SHELL(pMenuBar), pMenuItem);
        gtk_box_pack_start(GTK_BOX(Vbox), pMenuBar, FALSE, FALSE, 0);










        text=g_locale_to_utf8("<span background=\"#ece10a\" foreground=\"black\" size=\"xx-large\"><b><u> GESTION DE BIBLIOTHEQUE </u></b></span>",-1,NULL,NULL,NULL);
        button[0]=gtk_label_new(text);
        gtk_label_set_use_markup(GTK_LABEL(button[0]),TRUE);

        button[1]=gtk_button_new_with_label("AJOUTE LIVRE");



        button[2]=gtk_button_new_with_label("AFFICHE");
        button[3]=gtk_button_new_with_label("SUPPRESSION");



        gtk_box_pack_start(GTK_BOX(Vbox),button[0],TRUE,TRUE,10);
        gtk_box_pack_start(GTK_BOX(Vbox),button[1],TRUE,TRUE,10);
        gtk_box_pack_start(GTK_BOX(Vbox),button[2],TRUE,TRUE,10);
        gtk_box_pack_start(GTK_BOX(Vbox),button[3],TRUE,TRUE,10);



        g_signal_connect(G_OBJECT(button[1]),"clicked",G_CALLBACK(Lancer_Boite_Ajouter),NULL);
        g_signal_connect(G_OBJECT(button[2]),"clicked",G_CALLBACK(recherche),NULL);
        g_signal_connect(G_OBJECT(button[3]),"clicked",G_CALLBACK(Supprimer_Livre),NULL);


        gtk_widget_show_all(pwindow);
gtk_main();
return EXIT_SUCCESS;

}
