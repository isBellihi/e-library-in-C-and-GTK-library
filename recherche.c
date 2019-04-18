#include <stdlib.h>
#include <gtk/gtk.h>
#include "ajouter.h"
#include "recherche.h"
#include "supprimer.h"
#include<string.h>



GtkWidget *input,*Rwindow;


void recherche(void)
{
	GtkWidget *Rtext,*btnr[5],*hbox;
	GdkColor color;
	const gchar *rtxt,*recu=NULL;

	//creation d'une boite

					Rwindow=gtk_dialog_new_with_buttons("l'affichage",GTK_WINDOW(pwindow),
            GTK_DIALOG_MODAL,NULL);


//modification sur théme de boite
        color.pixel=0;
        color.red=89*89;
        color.green=248*248;
        color.blue=240*240;
				gtk_window_set_icon_from_file(GTK_WINDOW(Rwindow),"bib.gif",NULL);
					gtk_widget_modify_bg(GTK_WIDGET(Rwindow),GTK_STATE_NORMAL,&color);
					gtk_window_set_default_size(GTK_WINDOW(Rwindow),300,150);

					gtk_window_set_icon_from_file(GTK_WINDOW(Rwindow),"bib.gif",NULL);

	gtk_window_set_default_size(GTK_WINDOW(Rwindow),200,200);
	gtk_window_set_position(GTK_WINDOW(Rwindow),GTK_WIN_POS_CENTER);

//  msg  "recherher livre par"


		rtxt=g_locale_from_utf8("<span font_desc=\"Times new roman italic 15\" ><u> RECHERCHE LIVRE PAR:</u></span>",-1,NULL,NULL,NULL);
		Rtext=gtk_label_new(rtxt);
		gtk_label_set_use_markup(GTK_LABEL(Rtext),TRUE);

		gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Rwindow)->vbox),Rtext,FALSE,FALSE,0); //met dans la boite*/



//creation des buttons radio

hbox=gtk_hbox_new(TRUE,2);





        input=gtk_entry_new();
        gtk_entry_set_text(GTK_ENTRY(input),recu);

		btnr[0]=gtk_radio_button_new_with_label(NULL,"--TITRE");
		btnr[1]=gtk_radio_button_new_with_label_from_widget(GTK_RADIO_BUTTON(btnr[0]),"--DATE D'EDITION");
		btnr[3]=gtk_button_new_with_label("_AFFICHER");






//met dans la boite
GtkWidget *hbx=NULL;



                    hbx=gtk_hbox_new(TRUE,0);

					gtk_box_pack_start(GTK_BOX(hbox),btnr[0],TRUE,FALSE,3);
					gtk_box_pack_start(GTK_BOX(hbox),btnr[1],TRUE,FALSE,3);

					gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Rwindow)->vbox),hbox,TRUE,FALSE,0);
					gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Rwindow)->vbox),input,FALSE,FALSE,0);

					gtk_box_pack_start(GTK_BOX(hbx),btnr[3],FALSE,FALSE,0);


					gtk_box_pack_start(GTK_BOX(GTK_DIALOG(Rwindow)->vbox),hbx,FALSE,FALSE,7);


					gtk_widget_show_all(Rwindow); // Affichage de la boite

					g_signal_connect(G_OBJECT(btnr[3]),"clicked",G_CALLBACK(valider),btnr[0]);




}


int  valider(GtkWidget *Rbtn,gpointer data)
{

	GSList *Rlist;
	const gchar *btn_clicked;
	const	gchar *recu=NULL;
	gint i;


recu=gtk_entry_get_text(GTK_ENTRY(input));


	btn_clicked=(char*)malloc(30);

			Rlist=gtk_radio_button_get_group(GTK_RADIO_BUTTON(data));   //recupértion le contenu button
						while(Rlist)
							{
								if(gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(Rlist->data)))
								{

									btn_clicked=gtk_button_get_label(GTK_BUTTON(Rlist->data));
									Rlist=NULL;

								}else  Rlist=g_slist_next(Rlist);


							}



                int trouve;
				if(strcmp(btn_clicked,"--TITRE")==0)
				{       trouve=0;
                        for(i=0;i<bib.nbr_disp;i++){
                            if(strcmp(recu,bib.TabLivre[i].titre)==0){
                                    trouve=1;
                                    break;
                            }
                        }
                        AffichLivre(bib.TabLivre[i],trouve);
                        gtk_widget_destroy(Rwindow);

				}else if(strcmp(btn_clicked,"--DATE D'EDITION")==0) Affich_ts(recu);
                gtk_widget_destroy(Rwindow);


return 0;
}

