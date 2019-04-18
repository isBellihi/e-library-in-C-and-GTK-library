#include <stdlib.h>
#include <gtk/gtk.h>
#include "ajouter.h"
#include<string.h>



/***************************************************************************************************/
/****     La fonction Lancer la boite de dialog pour Ajouter des Livres a la bibliotheque      *****/
/***************************************************************************************************/

void Lancer_Boite_Ajouter(void){

        GtkWidget *pdialog,*msg,*nbrLivre,*nLivre;
        GtkWidget *labelL;
        GtkWidget* label[3];
        GtkWidget *pTitre,*pAnne,*pAuteur;
        GdkColor color;
        FILE *fbiblio=NULL;
        gint i,nbr=0;
        gchar* text;

        const gchar* titre;
        const gchar* auteur;
        const gchar* an_edition;


         /*** cree une boite de dialoge pour saissier les informations d'un livre ***/

        nbrLivre=gtk_dialog_new_with_buttons("Nombre des Livres",GTK_WINDOW(pwindow),
            GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

        gtk_window_set_default_size(GTK_WINDOW(nbrLivre),90,120);

        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
        gtk_widget_modify_bg(GTK_WIDGET(nbrLivre),GTK_STATE_NORMAL,&color);

        labelL=gtk_label_new("Entrer le nombre des livre qui vous souhaiter ajouter :\n");
        nLivre=gtk_entry_new();
        gtk_box_pack_start(GTK_BOX(GTK_DIALOG(nbrLivre)->vbox),labelL,TRUE,FALSE,0);
        gtk_box_pack_start(GTK_BOX(GTK_DIALOG(nbrLivre)->vbox),nLivre,TRUE,FALSE,0);
        gtk_widget_show_all(nbrLivre);

        /** les test sur les reponse **/

        switch(gtk_dialog_run(GTK_DIALOG(nbrLivre))){
        case GTK_RESPONSE_OK :{
        nbr=atoi(gtk_entry_get_text(GTK_ENTRY(nLivre)));
        gtk_widget_destroy(nbrLivre);
        }default: gtk_widget_destroy(nbrLivre);
        }


	int b=0;

    /** une boucle pour cree la boite de dialog de chaque Livre **/
    for(i=0;i<nbr;i++){
	b=0;

            // while pour recrée la boite de saissier les infos de Livre si en laisse l'un des champs vide


            pdialog=gtk_dialog_new_with_buttons("AjoutLivre",GTK_WINDOW(pwindow),
                            GTK_DIALOG_MODAL,GTK_STOCK_OK,GTK_RESPONSE_OK,GTK_STOCK_CANCEL,GTK_RESPONSE_CANCEL,NULL);

            gtk_window_set_default_size(GTK_WINDOW(pdialog),500,250);

        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
        gtk_widget_modify_bg(GTK_WIDGET(pdialog),GTK_STATE_NORMAL,&color);

            //pour l'input de Titre

    text=g_locale_to_utf8("<span  foreground=\"black\"size=\"x-large\"><b><u>    Saisier le Titre :    </u></b></span>",-1,NULL,NULL,NULL);
            label[0]=gtk_label_new(text);
            gtk_label_set_use_markup(GTK_LABEL(label[0]),TRUE);
            gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pdialog)->vbox),label[0],TRUE,TRUE,0);


            pTitre=gtk_entry_new();
		            gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pdialog)->vbox),pTitre,TRUE,TRUE,0);



            //pour l'input de l'auteur

    text=g_locale_to_utf8("<span  foreground=\"black\" size=\"x-large\"><b><u>    Saisier l'auteur :    </u></b></span>",-1,NULL,NULL,NULL);
            label[2]=gtk_label_new(text);
            gtk_label_set_use_markup(GTK_LABEL(label[2]),TRUE);
            gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pdialog)->vbox),label[2],TRUE,TRUE,0);

            pAuteur=gtk_entry_new();
            gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pdialog)->vbox),pAuteur,TRUE,TRUE,0);

            //pour l'input d'anne d'eddition

    text=g_locale_to_utf8("<span  foreground=\"black\"size=\"x-large\"><b><u>    Saisier l'anne d'eddition :   </u></b></span>",-1,NULL,NULL,NULL);
            label[1]=gtk_label_new(text);
            gtk_label_set_use_markup(GTK_LABEL(label[1]),TRUE);
            gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pdialog)->vbox),label[1],TRUE,TRUE,0);

            pAnne=gtk_entry_new();
            gtk_box_pack_start(GTK_BOX(GTK_DIALOG(pdialog)->vbox),pAnne,TRUE,TRUE,0);


            gtk_widget_show_all(pdialog);

        // Enregester le livre dans le fichier biblio.txt qui represente la bibliotheque

        switch(gtk_dialog_run(GTK_DIALOG(pdialog))){
            case GTK_RESPONSE_OK :{
                titre=gtk_entry_get_text(GTK_ENTRY(pTitre));
                auteur=gtk_entry_get_text(GTK_ENTRY(pAuteur));
                an_edition=gtk_entry_get_text(GTK_ENTRY(pAnne));
                //les tests pour les inputs de saisier
                if(titre[0]=='\0' || auteur[0]=='\0' || an_edition[0]=='\0' ) {

                     // le cas de l'un des champs est vide en lance un msg d erreur
                  msg=gtk_message_dialog_new(GTK_WINDOW(pdialog),GTK_DIALOG_MODAL,GTK_MESSAGE_ERROR,
                    GTK_BUTTONS_OK,"l'un des champs est vide !!! \n slvp rempli touts les champs !!");
                    gtk_window_set_icon_from_file(GTK_WINDOW(msg),"E:\\LES PROJETS\\Bibliotheque1.05.1\\bib.gif",NULL);

        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
        gtk_widget_modify_bg(GTK_WIDGET(msg),GTK_STATE_NORMAL,&color);

                    gtk_dialog_run(GTK_DIALOG(msg));
                    gtk_widget_destroy(msg);
                    gtk_widget_show_all(pdialog);
                    i--;
                    break;
                }

                    fbiblio=fopen("E:\\LES PROJETS\\Bibliotheque1.05.1\\biblio.txt","a+");
                   if(b==1 || bib.nbr_disp!=0) fprintf(fbiblio,"\n");
                    fprintf(fbiblio,"%s#%s#%s",titre,auteur,an_edition); b=1;
                    fclose(fbiblio);
                    break;
            }default: gtk_widget_destroy(pdialog); i=nbr;
        }


        gtk_widget_destroy(pdialog);


    }


        Charg_Livre();
}

/**************************************************************************************************/
/****                   La fonction Quitter() pour confirmer le Quitter                       *****/
/**************************************************************************************************/

void Quitter(void){
    GtkWidget *msg;

    msg=gtk_message_dialog_new(GTK_WINDOW(pwindow),GTK_DIALOG_MODAL,GTK_MESSAGE_QUESTION,
                               GTK_BUTTONS_YES_NO,"voulez vous vraiment quitter ce programe !!??");

    gtk_dialog_run(GTK_DIALOG(msg));

    switch(gtk_dialog_run(GTK_DIALOG(msg))){
        case GTK_RESPONSE_YES :
            gtk_widget_destroy(pwindow);

        default :
            gtk_widget_destroy(msg);
            break;
    }
}


/***************************************************************************************************/
/****         La fonction AffichLivre permet d'afficher un Livre connaissant sont Titre        *****/
/***************************************************************************************************/

void AffichLivre(livre Livre,gint b){
    GtkWidget *InfoLivre;
    GdkColor color;

    if(b==1){

    InfoLivre=gtk_message_dialog_new(GTK_WINDOW(pwindow),GTK_DIALOG_MODAL,GTK_MESSAGE_INFO,
      GTK_BUTTONS_OK,"Les Info sur Livre :\n\n    - le Titre : %s\n\n    - L'auteur :%s\n\n    - L'anne d'edition : %s",
                    Livre.titre,Livre.auteur,Livre.an_edition);
    gtk_window_set_icon_from_file(GTK_WINDOW(InfoLivre),"E:\\LES PROJETS\\Bibliotheque1.05.1\\bib.gif",NULL);

        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
        gtk_widget_modify_bg(GTK_WIDGET(InfoLivre),GTK_STATE_NORMAL,&color);

    gtk_window_set_title(GTK_WINDOW(InfoLivre),"INFO_LIVRE");
    gtk_dialog_run(GTK_DIALOG(InfoLivre));
    gtk_widget_destroy(InfoLivre);
    gtk_widget_show_all(pwindow);
    }else{
        InfoLivre=gtk_message_dialog_new(GTK_WINDOW(pwindow),GTK_DIALOG_MODAL,
                        GTK_MESSAGE_INFO,GTK_BUTTONS_OK,"aucun Livre corespond a ce titre");
        gtk_window_set_title(GTK_WINDOW(InfoLivre),"INFO_LIVRE");
        gtk_window_set_icon_from_file(GTK_WINDOW(InfoLivre),"E:\\LES PROJETS\\Bibliotheque1.05.1\\bib.gif",NULL);

        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
        gtk_widget_modify_bg(GTK_WIDGET(InfoLivre),GTK_STATE_NORMAL,&color);

        gtk_dialog_run(GTK_DIALOG(InfoLivre));
        gtk_widget_destroy(InfoLivre);
        gtk_widget_show_all(pwindow);
    }
}





/**************************************************************************************************/
/****                         Chargement des livres dans la memoire                           *****/
/**************************************************************************************************/


void Charg_Livre(void){

                /*** calculer le nbr des livres disponibles actuallement dans la biblio ***/
                gchar** str;
                int i=0,j;
                gchar ch[taille_ligne]= "";
                FILE *fbiblio;
                fbiblio=fopen("E:\\LES PROJETS\\Bibliotheque1.05.1\\biblio.txt","r");
                bib.nbr_disp=0;
                str=(gchar**)malloc(3*sizeof(gchar*));
                while(fgets(ch,taille_ligne,fbiblio) != NULL) bib.nbr_disp++;
                fclose(fbiblio);
                fbiblio=fopen("E:\\LES PROJETS\\Bibliotheque1.05.1\\biblio.txt","r");
                bib.TabLivre=(livre*)malloc(bib.nbr_disp*sizeof(livre));
                while(fgets(ch,taille_ligne,fbiblio) != NULL){
                    str=Decoupe_ligne(ch);
                    bib.TabLivre[i].titre=str[0];
                    bib.TabLivre[i].auteur=str[1];
                    for(j=0;j<strlen(str[2]);j++){
                        if(str[2][j]=='\n') { str[2][j]='\0'; break;}
                    }
                    bib.TabLivre[i].an_edition=str[2];


                    i++;

                }
                free(str);

                fclose(fbiblio);

}
/************************************************************************************************/
/*****      Decouper les ligne pour recuperer le Titre et l'auteur et l'an_eddition      ********/
/************************************************************************************************/

gchar** Decoupe_ligne(gchar *chaine)
{
int i,p=0,lg,nbr=0;
gchar Tmp[300],**tab_chaine=NULL;
 lg =strlen(chaine);

if(chaine[0]!='#')Tmp[p++]=chaine[0];

for(i=1;i<=lg;i++)
    {  if(chaine[i]!='#')Tmp[p++]=chaine[i];
       if((chaine[i]=='#' && chaine[i-1]!='#')||(i==lg&&p!=0)) // si c'est la fin du mot Tmp
       { Tmp[p]='\0';
         nbr++;       // Ajout de la ligne nbr pour le mot (char *)
         tab_chaine=(char**)realloc(tab_chaine,sizeof(char*)*nbr);
          if(tab_chaine!=NULL)
          {  // réservation de p caractères pour le mot Tmp
          tab_chaine[nbr-1]=(char*)malloc(sizeof(char)*(p));
          // copie du mot Tmp dans la ligne nbr-1 du tableau 2D des mots
          strcpy(tab_chaine[nbr-1],Tmp);
          p=0;
          }
       }
    }
return (tab_chaine);
}

