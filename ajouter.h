#include <stdlib.h>
#include <gtk/gtk.h>
#define taille_ligne 1000


     typedef struct liv{
        const gchar* titre;
        const gchar* auteur;
        const gchar* an_edition;
        }livre;

    typedef struct bibliotheque{
        livre *TabLivre;
        gint nbr_disp;
        }biblio;




 void Lancer_Boite_Ajouter(void);
 void RechLivre(void);
 void Charg_Livre(void);
 gchar** Decoupe_ligne(gchar*);
 void Quitter(void);
 GtkWidget *pwindow;
        biblio bib;
        void AffichLivre(livre,gint);


