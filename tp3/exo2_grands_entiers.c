#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "liste_entiers.c"

#define BASE 10


void afficher_grand_entier (liste L) {
	int e, cpt ; /* grand entier */

    cpt = 0 ;
    e = 0 ;

	while (! est_vide (L)) {
		e = e + prem (L) * pow (BASE, cpt) ;

		cpt += 1 ;
	    L = reste (L) ;
	}
	
	printf("%d\n", e) ;
}




liste succ_grand_entier_FA (liste L, unsigned int n) {
		
	if (est_vide (L))
		return L ;

	/* if the digit is the last of the base - eg 9 in base 10
	 * AND there is a carry
	 * we put 0 in the list and add a carry */
	if ((prem(L) == (BASE - 1)) && (n == 1)) {

		return cons (0, succ_grand_entier_FA (reste (L), 1)) ;
	}
	/* else we add the carry (if there is one)
	 * and keep going with the rest of the list */
	else {
        return cons (prem (L) + n, succ_grand_entier_FA (reste (L), 0)) ;
    }
}

liste succ_grand_entier (liste L) {
		
	/* we add 1
	 * similar to having a carry for the first digit */
	return succ_grand_entier_FA (L, 1) ;
}


liste toGrandEntier (int n) {

    liste L ;
    L = l_vide() ;

    while (n / BASE > 0) {
        L = cons (n % BASE, L) ;
        n = n / BASE ;
    }

    L = cons (n, L) ;

    return renverser (L) ;



}

int toEntierNaturel (liste L) {

    return 4 ;
}

int main() {
	
	liste L ;
	
	L = cons (9, cons (9, cons (6, cons (8, cons (0, cons (8, cons(0, l_vide ()))))))) ;

    printf("Grand entier : ") ;
	afficher_grand_entier (L) ;
    printf("\n") ;

	printf("Successeur : ") ;
	afficher_grand_entier (succ_grand_entier (L) ) ;
    printf("\n") ;

    printf("Entier naturel 3456789 -> Grand Entier : ") ;
    afficher_grand_entier (toGrandEntier (3456789)) ;
    printf("\n") ;

    printf("Entier naturel correspondant : %d\n", toEntierNaturel (L)) ;
    printf("\n") ;

	return EXIT_SUCCESS ;

}