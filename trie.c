#include <gtk/gtk.h>
#include "ajouter.h"
#include "supprimer.h"
#include "recherche.h"
#include "trie.h"



void trie_nom(void){

    int i,k,echange=1;
    livre tmp;
    k=bib.nbr_disp;
    FILE *fbiblio;

    /*** triage de tableau par programation  ***/
 while(echange){
    echange=0;
     for(i=0;i<k-1;i++){
        if(strcmp(bib.TabLivre[i].auteur,bib.TabLivre[i+1].auteur)>0){

            tmp=bib.TabLivre[i];
            bib.TabLivre[i]=bib.TabLivre[i+1];
            bib.TabLivre[i+1]=tmp;
            echange=1;
        }
    }
    k--;
 }

 /*** remetre le tableau apres le trie dans le fichier ***/

                 fbiblio=fopen("D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\biblio.txt","w+");
                for(i=0;i<bib.nbr_disp;i++){
                    fprintf(fbiblio,"%s#%s#%s",bib.TabLivre[i].titre,bib.TabLivre[i].auteur,bib.TabLivre[i].an_edition);
                    if(i<bib.nbr_disp-1 && bib.nbr_disp!=0) fprintf(fbiblio,"\n");
                }

                fclose(fbiblio);



}


void trie_date(void){

    int i,j,k,echange=1;
    livre tmp;
    k=bib.nbr_disp;
    FILE *fbiblio;

    /*** triage de tableau par programation  ***/
 while(echange){
    echange=0;
     for(i=0;i<k-1;i++){
        if(strcmp(bib.TabLivre[i].an_edition,bib.TabLivre[i+1].an_edition)>0){

            tmp=bib.TabLivre[i];
            bib.TabLivre[i]=bib.TabLivre[i+1];
            bib.TabLivre[i+1]=tmp;
            echange=1;
        }
    }
    k--;
 }

 /*** remetre le tableau apres le trie dans le fichier ***/

                 fbiblio=fopen("D:\\INFORMATIQUE\\SMI4\\Projet\\Bibliotheque1.05.1\\biblio.txt","w+");
                for(i=0;i<bib.nbr_disp;i++){
                    fprintf(fbiblio,"%s#%s#%s",bib.TabLivre[i].titre,bib.TabLivre[i].auteur,bib.TabLivre[i].an_edition);
                    if(i<bib.nbr_disp-1 && bib.nbr_disp!=0) fprintf(fbiblio,"\n");
                }

                fclose(fbiblio);



}

