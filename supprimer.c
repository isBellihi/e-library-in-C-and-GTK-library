#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"ajouter.h"
#include"supprimer.h"
#include"recherche.h"




/********************************************************************************************/
/****                                 Suprimer Un Livre                                 *****/
/********************************************************************************************/

void Supprimer_Livre(void){
GtkWidget *Supp;
GdkColor color;
GtkWidget *titre;
GtkWidget *label;
const gchar* text;

    Supp=gtk_dialog_new_with_buttons("Supprimer Un Livre",GTK_WINDOW(pwindow),
        GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);
    gtk_window_set_icon_from_file(GTK_WINDOW(Supp),"D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\bib.gif",NULL);
                gtk_window_set_default_size(GTK_WINDOW(Supp),400,200);

        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
        gtk_widget_modify_bg(GTK_WIDGET(Supp),GTK_STATE_NORMAL,&color);

    text=g_locale_to_utf8("<span background=\"#cae29b\" foreground=\"#35a1F1\"size=\"x-large\"><b><u>    saisier le titre :   </u></b></span>",-1,NULL,NULL,NULL);
            label=gtk_label_new(text);
            gtk_label_set_use_markup(GTK_LABEL(label),TRUE);
            gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Supp)->vbox),label,TRUE,TRUE,0);

            titre=gtk_entry_new();
             gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Supp)->vbox),titre,TRUE,TRUE,0);
            gtk_widget_show_all(Supp);

            switch(gtk_dialog_run(GTK_DIALOG(Supp))){

            case GTK_RESPONSE_OK :{
                    text=gtk_entry_get_text(GTK_ENTRY(titre));
                    Supprimer(text);
                    gtk_widget_destroy(Supp);
                    break;
                    }
            default : gtk_widget_destroy(Supp);
            }
}

void Supprimer(const gchar* text){
    GtkWidget *msg,*alert ;
    gint i,j,trouve=0;
    GdkColor color;
    FILE *fbiblio;
    msg=gtk_message_dialog_new(GTK_WINDOW(pwindow),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,
                    GTK_BUTTONS_YES_NO,"voulez vous vraiment supprimer \n         ce Livre !!??");
    gtk_window_set_icon_from_file(GTK_WINDOW(msg),"D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\bib.gif",NULL);
    gtk_dialog_run(GTK_DIALOG(msg));

    switch(gtk_dialog_run(GTK_DIALOG(msg))){
        case GTK_RESPONSE_YES :

                for(i=0;i<bib.nbr_disp-1;i++){
                    if(strcmp(bib.TabLivre[i].titre,text)==0){
                        trouve=1;
                        for(j=i;j<bib.nbr_disp-1;j++){
                            bib.TabLivre[j].titre=bib.TabLivre[j+1].titre;
                            bib.TabLivre[j].auteur=bib.TabLivre[j+1].auteur;
                            bib.TabLivre[j].an_edition=bib.TabLivre[j+1].an_edition;
                        }
                    }
            }if(trouve) bib.nbr_disp--;
            if(strcmp(bib.TabLivre[bib.nbr_disp-1].titre,text)==0 && !trouve) { trouve=1; bib.nbr_disp--; }
            if(!trouve){
                alert=gtk_message_dialog_new(GTK_WINDOW(pwindow),GTK_DIALOG_MODAL,
                    GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"aucun Livre corespond a ce titre");
                gtk_window_set_title(GTK_WINDOW(alert),"INFO_LIVRE");
                gtk_window_set_icon_from_file(GTK_WINDOW(alert),"D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\bib.gif",NULL);

        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
            gtk_widget_modify_bg(GTK_WIDGET(alert),GTK_STATE_NORMAL,&color);

            gtk_dialog_run(GTK_DIALOG(alert));
            gtk_widget_destroy(alert);
            gtk_widget_show_all(pwindow);
            break;
                }

                bib.TabLivre=(livre*)realloc(bib.TabLivre,bib.nbr_disp*sizeof(livre));
                fbiblio=fopen("D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliothéque1.05.1\\biblio.txt","w+");
                for(i=0;i<bib.nbr_disp;i++){
                    fprintf(fbiblio,"%s#%s#%s",bib.TabLivre[i].titre,bib.TabLivre[i].auteur,bib.TabLivre[i].an_edition);
                    if(i<bib.nbr_disp-1 && bib.nbr_disp!=0) fprintf(fbiblio,"\n");
                }

                fclose(fbiblio);

            gtk_widget_destroy(msg);
            break;
        case GTK_RESPONSE_NO :
            gtk_widget_destroy(msg);
            break;
        default : gtk_widget_destroy(msg);
    }gtk_widget_destroy(msg);

}





void Affich_ts(const gchar* recu){

Charg_Livre();

GtkWidget *dialog=NULL;
GdkColor color;
printf("\n%s\n",recu);

dialog=gtk_dialog_new_with_buttons("l'affichage",GTK_WINDOW(pwindow),
            GTK_DIALOG_MODAL,NULL);
gtk_window_set_icon_from_file(GTK_WINDOW(dialog),"D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\bib.gif",NULL);
gtk_window_set_default_size(GTK_WINDOW(dialog),600,500);


        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
        gtk_widget_modify_bg(GTK_WIDGET(dialog),GTK_STATE_NORMAL,&color);

gtk_window_set_icon_from_file(GTK_WINDOW(dialog),"D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\bib.gif",NULL);


        GtkWidget *pListView;
GtkWidget *pScrollbar;
GtkListStore *pListStore;
GtkTreeViewColumn *pColumn;
GtkCellRenderer *pCellRenderer;
gint i;

pListStore=gtk_list_store_new(2,G_TYPE_STRING,G_TYPE_STRING);

/* Creation de la vue */
pListView = gtk_tree_view_new_with_model(GTK_TREE_MODEL(pListStore));
/* Creation de la premiere colonne */
pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Titre                                                                                     ",pCellRenderer,"text", 0,NULL);
/* Ajout de la colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);
/* Creation de la deuxieme colonne */
pCellRenderer = gtk_cell_renderer_text_new();
pColumn = gtk_tree_view_column_new_with_attributes("Auteur",pCellRenderer,"text",1,NULL);
/* Ajout de la colonne à la vue */
gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);
pScrollbar = gtk_scrolled_window_new(NULL, NULL);
gtk_scrolled_window_set_policy(GTK_SCROLLED_WINDOW(pScrollbar),GTK_POLICY_AUTOMATIC,GTK_POLICY_AUTOMATIC);
gtk_container_add(GTK_CONTAINER(pScrollbar), pListView);

GtkWidget *label;

label=gtk_label_new("\n les Livre qui portent la meme date que vous avez  saisie  :\n");

gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox),label,FALSE,FALSE,0);


gtk_box_pack_start(GTK_BOX(GTK_DIALOG(dialog)->vbox),pScrollbar,TRUE,TRUE,0);


GtkTreeIter pIter;
gtk_widget_show_all(dialog);



       int trouve=0;    gtk_widget_show_all(dialog);

        gtk_list_store_clear(pListStore);
        for(i = 0 ; i < bib.nbr_disp ; ++i)
            {
              if(strcmp(recu,bib.TabLivre[i].an_edition)==0){
            /* Creation de la nouvelle ligne*/ trouve=1;
            gtk_list_store_append(pListStore, &pIter);
            /* Mise a jour des donnees*/
            gtk_list_store_set(pListStore, &pIter,0,bib.TabLivre[i].titre,1,bib.TabLivre[i].auteur,-1);
              }
            }
        if(!trouve){
                gtk_list_store_append(pListStore, &pIter);
                gtk_list_store_set(pListStore, &pIter,0,"aucune",1,"aucune",-1);
        }

}


