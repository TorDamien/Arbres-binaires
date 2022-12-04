#include <stdlib.h>
#include <assert.h>
#include <stdio.h>
#include "file.h"

void init_file(File *f) { f->tete = NULL; }

int file_est_vide(File *f) { return (f->tete == NULL); }

void afficher_file(File *f) {


	Element *actuel = f->tete;
	while (actuel != NULL) {
		printf("%d->",actuel->arb->val);
		actuel = actuel->suivant;
	}
	printf("NULL\n");
}

void enfiler(File *f, arbre a)
{
    Element *new = malloc(sizeof(*new));
    
    assert(new);

    new->arb = a;
    new->suivant = NULL;

    if (f->tete != NULL) /* La file n'est pas vide */
    {
        /* On se positionne à la fin de la file */
        Element *actuel = f->tete;
        while(actuel->suivant != NULL)
        {
            actuel = actuel->suivant;
        }
        actuel->suivant = new;
    }
    else /* La file est vide, notre élément est le premier */
    {
        f->tete = new;
    }
}


arbre defiler(File *f)
{
	assert(f);

    Element *tete = f->tete;
    arbre res = tete->arb;
    f->tete = f->tete->suivant;
    free(tete);

    return res;
}