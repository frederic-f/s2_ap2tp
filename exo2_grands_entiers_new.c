#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "liste_entiers.c"

#define BASE 10


void afficher_grand_entier (liste L) {
	liste M = renverser(L) ;

	while (prem (M) == 0) {
	    M = reste (M) ;
	}

	while (!est_vide(M)) {
	    printf ("%d", prem (M)) ;

	    M = reste (M) ;
	}
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



/* *******************************************************************************************
 * Entier naturel -> Grand Entier
 * version Iterative
 * ********************************************************************************************/
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


/* *******************************************************************************************
 * Grand entier -> Entier naturel
 * version Recursive
 * ********************************************************************************************/

int toEntierNaturel_FA (liste L, unsigned int n) {

    if (est_vide (L)) {
        return 0 ;
    }

    return prem (L) * pow (BASE, n) + toEntierNaturel_FA (reste (L), n + 1) ;

}


int toEntierNaturel (liste L) {

    return toEntierNaturel_FA (L, 0) ;
}


/* *******************************************************************************************
 * Somme de Grands Entiers
 *
 * version iterative
 * ********************************************************************************************/

liste sommeGrandsEntiers (liste L, liste M) {

    liste S ;
    int indice, retenue, num ;

    indice = 0 ;
    retenue = 0 ;

    S = l_vide() ;

    while ( ((!est_vide(L)) && (!est_vide(M))) ||  (retenue != 0)) {

        num = retenue ;

        if (!est_vide(L)) {
            num += prem (L) ;
            L = reste(L) ;
        }

        if (!est_vide(M)) {
            num += prem (M) ;
            M = reste (M) ;
        }

        S = cons (num % BASE, S) ;

        retenue = num / BASE ;
    }

    return renverser (S) ;
}

/* *******************************************************************************************
 * main
 * ********************************************************************************************/
int main() {
	
	liste L, M, N ;
	
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

    printf("Grand entier -> Entier naturel : %d\n", toEntierNaturel (L)) ;
    printf("\n") ;

    M = cons (9, cons (3, cons (6, cons (8, l_vide ())))) ;
    N = cons (0, cons (9, cons (7, cons (4, l_vide ())))) ;
    printf ("Somme de grands entier %d + %d = %d\n", toEntierNaturel(N), toEntierNaturel(M) ,toEntierNaturel (sommeGrandsEntiers (N, M))) ;
    printf ("\n") ;

	return EXIT_SUCCESS ;

}