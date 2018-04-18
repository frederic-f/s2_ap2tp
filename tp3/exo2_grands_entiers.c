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


/* *******************************************************************************************
 * Grand entier -> Entier naturel
 * version Recursive
 * (iterative plus haut)
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

liste sommeGrandsEntiers_iter (liste L, liste M) {

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
 * Somme de Grands Entiers
 *
 * version recursive
 * ********************************************************************************************/

liste som_FA (liste L, liste M, unsigned int retenue) {
	
	if ((est_vide (L)) && (est_vide (M))) { // L et M sont vides, uniquement la retenue a traiter
		
		return cons (retenue, l_vide ()) ;
	}
	
	else if (est_vide (L)) { // M n'est pas vide
		return cons ((prem (M) + retenue) % BASE, som_FA (l_vide (), reste (M), (prem (M) + retenue) > BASE)) ;
	}
	
	else if (est_vide (M)) { // L n'est pas vide
		return cons ((prem (L) + retenue) % BASE, som_FA (reste (L), l_vide (), (prem (L) + retenue) > BASE));
	}
	
	else { // ni L ni M sont vides
		return cons ((prem (L) + prem (M) + retenue) % BASE, som_FA (reste (L), reste (M), (prem (L) + retenue + prem (M)) > BASE )) ;
	}
}


liste sommeGrandsEntiers (liste L, liste M) {
	
	return (som_FA (L, M, 0)) ;
}


/* *******************************************************************************************
 * Difference de Grands Entiers
 *
 * version recursive
 * ********************************************************************************************/

liste dif_FA (liste L, liste M, unsigned int retenue) {
	
	if (est_vide (M)) { // plus rien a soustraire
		
		if (est_vide (L)) { // operation terminee
			return l_vide () ;
		}
		else { // on finit de vider L
			return cons (prem (L) - retenue, dif_FA (reste (L), l_vide(), 0)) ;
		}
	}
	
	
	if ((prem(L) - retenue) >= (prem(M))) { //pas de retenue a passer
		return cons (prem (L) - retenue - prem (M), dif_FA (reste (L), reste (M), 0)) ;
	}
	else { // prem (L) - retenue < prem (M) => retenue a passer
		return cons (BASE + prem (L) - retenue - prem(M), dif_FA (reste (L), reste (M), 1)) ;
	}
}


liste differenceGrandsEntiers (liste L, liste M) {

	return dif_FA (L, M, 0) ;
}


/* *******************************************************************************************
 * Produits de Grands Entiers
 *
 * version recursive
 * une fonction recursive pour calculer une ligne
 * une fonctin iterative qui ajoute les lignes
 * 
 * 3 facons de faire - recursive, iteratif, recursif - iteratif
 * ********************************************************************************************/

liste prod_FA (liste L, liste M, unsigned int retenue) {
	
	if ((est_vide (L)) && (est_vide (M))) { // L et M sont vides, uniquement la retenue a traiter
		
		return cons (retenue, l_vide ()) ;
	}
	
	else if (est_vide (L)) { // M n'est pas vide
		return cons ((prem (M) + retenue) % BASE, som_FA (l_vide (), reste (M), (prem (M) + retenue) > BASE)) ;
	}
	
	else if (est_vide (M)) { // L n'est pas vide
		return cons ((prem (L) + retenue) % BASE, som_FA (reste (L), l_vide (), (prem (L) + retenue) > BASE));
	}
	
	else { // ni L ni M sont vides
		return cons ((prem (L) + prem (M) + retenue) % BASE, som_FA (reste (L), reste (M), (prem (L) + retenue + prem (M)) > BASE )) ;
	}
}


liste produitGrandsEntiers (liste L, liste M) {
	
	return (prod_FA (L, M, 0)) ;
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

    M = cons (9, cons (3, cons (0, cons (8, l_vide ())))) ;
    N = cons (0, cons (9, cons (7, cons (4, l_vide ())))) ;
    printf ("Somme de grands entier %d + %d = %d\n", toEntierNaturel(N), toEntierNaturel(M) ,toEntierNaturel (sommeGrandsEntiers (N, M))) ;
    printf ("\n") ;

    printf ("Différence de grands entier %d - %d = %d\n", toEntierNaturel(M), toEntierNaturel(N) ,toEntierNaturel (differenceGrandsEntiers (M, N))) ;
    printf ("\n") ;

    printf ("Produit de grands entier %d x %d = %d\n", toEntierNaturel(M), toEntierNaturel(N) ,toEntierNaturel (produitGrandsEntiers (M, N))) ;
    printf ("\n") ;
    
    return EXIT_SUCCESS ;

}