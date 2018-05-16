/*	Fichier cree par Frederic FRANCOIS 
	Exo 2
*/

#include "liste_entiers.c"

/* *****************************************************************************
 * Q1. Fonction qui a une liste associe la liste obtenue en ne gardant que les elements PAIRS
 * ***************************************************************************** */

liste pair (liste L) {
	
	if (est_vide (L))
		return l_vide () ;
	
	/* si le premier element est pair on le garde, sinon non */
	if (prem (L) % 2 == 0) {
		return cons (prem (L), pair (reste (L))) ;
	} else {
		return pair (reste (L)) ;
	}
	
}


void test_pair_param (liste L) {
	printf ("pair ( ") ;
	afficher_liste (L) ;
	printf (" ) = ") ;
	afficher_liste (pair (L)) ;
	printf (" \n") ;
}


void test_pair () {
	
	liste L = cons (0, cons (1, cons (2, cons (3, cons (4, cons (5, cons (6, l_vide ()))))))) ;
	test_pair_param (L) ;
	
	L = cons (0, cons (4, cons (1, cons (3, cons (2, cons (5, cons (6, l_vide ()))))))) ;
	test_pair_param (L) ;

	L = cons (0, cons (14, cons (31, cons (33, cons (28, cons (588, cons (677, l_vide ()))))))) ;
	test_pair_param (L) ;
	
}

/* *****************************************************************************
 * Q2. Fonction qui a une liste associe la liste obtenue en ne gardant que les elements IMPAIRS
 * ***************************************************************************** */

liste impair (liste L) {
	
	if (est_vide (L))
		return l_vide () ;
	
	/* si le premier element est pair on le garde, sinon non */
	if (prem (L) % 2 != 0) {
		return cons (prem (L), impair (reste (L))) ;
	} else {
		return impair (reste (L)) ;
	}
	
}


void test_impair_param (liste L) {
	printf ("impair ( ") ;
	afficher_liste (L) ;
	printf (" ) = ") ;
	afficher_liste (impair (L)) ;
	printf (" \n") ;
}


void test_impair () {
	
	liste L = cons(0, cons (1, cons (2, cons (3, cons (4, cons (5, cons (6, l_vide ()))))))) ;
	test_impair_param (L) ;
	
	L = cons (0, cons (4, cons (1, cons (3, cons (2, cons (5, cons (6, l_vide ()))))))) ;
	test_impair_param (L) ;

	L = cons (0, cons (14, cons (31, cons (33, cons (28, cons (588, cons (677, l_vide ()))))))) ;
	test_impair_param (L) ;
	
}


int main () {
	
	test_pair () ;
	
	printf ("\n") ;
	
	test_impair () ;
	
	printf ("\n") ;
	
	return 0 ;
}

/* Resultats 
 
$ ./ex2
pair ( (0 1 2 3 4 5 6) ) = (0 2 4 6) 
pair ( (0 4 1 3 2 5 6) ) = (0 4 2 6) 
pair ( (0 14 31 33 28 588 677) ) = (0 14 28 588) 

impair ( (0 1 2 3 4 5 6) ) = (1 3 5) 
impair ( (0 4 1 3 2 5 6) ) = (1 3 5) 
impair ( (0 14 31 33 28 588 677) ) = (31 33 677) 
 
 */ 