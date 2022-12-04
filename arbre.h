#ifndef _ARBRE_H_
#define _ARBRE_H_

#include <stdbool.h>

/* Structure d'un noeud d'arbre */
struct noeud_s;
typedef struct noeud_s noeud;

/* Un arbre binaire est défini comme une référence vers le noeud racine de l'arbre.
 * Un arbre binaire vide est représenté par une référence NULL.
 * Un arbre binaire est une structure de données récursive.
 * Si il n'est pas vide, ses fils sont des arbres.
 */
typedef noeud* arbre;

typedef struct noeud_s {
    int val;
    arbre gauche;
    arbre droit;
} noeud;

typedef enum {
    VIDE,
    FEUILLE,
    NOEUD
} type;


type cherche_type(arbre a);

void afficher_par_niveau(arbre racine, FILE* fout);

void afficherParenthese(arbre a);

arbre creer_feuille(int n);

void ajouter_noeud_ABR(arbre *a, int n);

bool inserer_abr(arbre *a_p, int n);

#endif