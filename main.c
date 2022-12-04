#include <stdio.h>
#include <stdlib.h>
#include "file.h"
#include "arbre.h"
#include <stdbool.h>

int main(){


	FILE *f = fopen("Affichage-par-niveau.txt","w");
	arbre a = NULL;
	int flag = 1;
	int n;

	afficherParenthese(a);
	printf("\n");
	while (flag) {
		printf("Entrer valeur à ajouter à l'arbre (-1 pour arrêter) : ");
		scanf("%d",&n);
		if( n >= 0 && n <= 500) {
			inserer_abr(&a,n);
			afficherParenthese(a);
			printf("\n");
		} 
		else if (n == -1) {
			flag = 0;
		} else {
			printf("Entrer un nb entree 0 et 500 ou -1 pour terminer\n");
		}
		
	}

	printf("Thierry\n");
	afficher_par_niveau(a,f);

	return 1;
}