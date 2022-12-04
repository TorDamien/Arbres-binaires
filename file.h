#ifndef _FILE_H
#define _FILE_H

#include "arbre.h"

typedef struct Element Element;

struct Element
{
    arbre arb;
    Element *suivant;
};

typedef struct File File;

struct File
{   
    Element *tete;
};

void init_file(File *f);

int file_est_vide(File *f);

void afficher_file(File *f);

void enfiler(File *f, arbre a);

arbre defiler(File *f);

#endif