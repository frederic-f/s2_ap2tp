#include <stdio.h>
#include <stdlib.h>

#include "liste_entiers.c"

#define base 10


	
	
void afficher_grand_entier (liste L) {
	liste M ;
	M = renverser (L) ;
	
	while (prem (M) == 0) {
		M = reste (M) ;
	}
	
	printf("Grand entier : ");
	
	while (! est_vide (M)) {
		printf("%d", prem (M));
		M = reste (M) ;
	}
	
	printf("\n") ;
}

liste succ_grand_entier_FA (liste L, unsigned int n) {
		
	if (est_vide (L))
		return L ;
	
	if ((prem(L) == 9) && (n == 1)) {
		return cons(0, succ_grand_entier_FA (reste (L), 1)) ;	
	}
	
	return cons (prem (L) + n, reste (L)) ;
}

void succ_grand_entier (liste L) {
		
	
	afficher_grand_entier (succ_grand_entier_FA (L, 1)) ;
}

int main() {
	
	liste L ;
	
	L = cons (5, cons (9, cons (6, cons (8, cons (0, cons (8, cons(0, l_vide ()))))))) ;
	
	afficher_grand_entier (L) ;
	
	printf("Successeur : \n");
	succ_grand_entier (L) ;

	return EXIT_SUCCESS ;

}