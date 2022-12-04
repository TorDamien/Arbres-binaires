#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "arbre.h"
#include "file.h"
#include <stdbool.h>

type cherche_type(arbre a) {
   if (a == NULL) {
      return VIDE;
   } 
   else if (a->gauche == NULL && a->droit == NULL) {
      return FEUILLE;
   } 
   else {
      return NOEUD;
   }
}


void afficher_par_niveau(arbre racine, FILE* fout) {
   if (racine == NULL || cherche_type(racine) != NOEUD){
      return;
   }

   File f;
   arbre n;
   init_file(&f);
   enfiler(&f,racine);
   int cpt =0, max = 1, newmax = 0;
   while (!file_est_vide(&f)) {
      n = defiler(&f);
      fprintf(fout,"%d ",n->val);

      if(n->gauche != NULL) {
         if(cherche_type(n->gauche) == NOEUD){
            enfiler(&f,n->gauche);
            newmax++;

         }
      }

      if(n->droit != NULL) {
         if(cherche_type(n->droit) == NOEUD){
            enfiler(&f,n->droit);
            newmax++;
         } 
      }
     cpt++;
     if (cpt >= max){
      fprintf(fout,"\n");
      max = newmax;
      newmax = 0;
      cpt = 0;
     }
   }
}

void afficherParenthese(arbre a) {
    if (a==NULL) { return; }
    if (a->gauche!=NULL) {
        printf("(");
        afficherParenthese(a->gauche);
        printf(")");
    }
    printf(" %d ",a->val);
    if (a->droit!=NULL) {
        printf("(");
        afficherParenthese(a->droit);
        printf(")");
    }
}

arbre creer_feuille(int n) {
	arbre new = malloc(sizeof(arbre));
	assert (new != NULL );
	new->val = n;
	new->gauche = NULL;
	new->droit = NULL;
	return new; 
}


bool inserer_abr(arbre *a_p, int n) {

    arbre *noeud = a_p;
    arbre *pere_noeud;

    // Le noeud à ajouter : penser à le supprimer si n est déjà dans arbre
    arbre a_ajouter = malloc(sizeof(arbre));
    (*a_ajouter).val = n;
    (*a_ajouter).gauche = NULL;
    (*a_ajouter).droit = NULL;

    if (*noeud != NULL ) {

        while (*noeud != NULL ) {

            pere_noeud = noeud;

            if ((*noeud)->val == n) {

                free(a_ajouter);
                return false;
            }
            else if (n > (*noeud)->val) {

                noeud = &((*noeud)->droit);
                if (*noeud == NULL ) {
                    (*pere_noeud)->droit = a_ajouter;
                    return true; 
                }
            }
            else {
               
                noeud = &((*noeud)->gauche);
                if (*noeud == NULL ) {
                    (*pere_noeud)->gauche = a_ajouter;
                    return true; 
                }
            } 
        }
    }
    // Cas ou on ajoute un élément à un arbre vide
    else {

        *noeud = a_ajouter;
        return true;
    }

    // Impossible d'arriver ici. Pour enlever le warning
    return false;
}

void ajouter_noeud_ABR(arbre *a, int n) {
	
	if ((*a) == NULL) {
		(*a)=(arbre)malloc(sizeof(noeud));
        (*a)->val = n;
        (*a)->gauche=NULL;
        (*a)->droit=NULL;
		return;
	}

	if ((*a)->val == n) {
		printf("Valeur déjà présente dans l'arbre\n");
		return;
	}

	if (n < (*a)->val) {
		ajouter_noeud_ABR(&(*a)->gauche,n);
		return;
	}

	if (n > (*a)->val) {
		ajouter_noeud_ABR(&(*a)->droit,n);
		return;
	}

}