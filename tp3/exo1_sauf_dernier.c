#include <stdio.h>
#include <stdlib.h>

#include "liste_entiers.c"

liste sauf_dernier (liste L) ;
void test_sauf_dernier_param (liste L) ;
void test_sauf_dernier () ;


liste sauf_dernier_recu (liste L) {
	
	if (est_vide (L)) 
		return L ;
	
	if (est_vide (reste (L))) {
		return l_vide() ;
	}
	
	return cons (prem(L), sauf_dernier_recu (reste(L))) ; 
}

liste sauf_dernier_iter (liste L) {
	
	liste M, N ;
	M = L ;
	N = l_vide () ;
	
	if (est_vide (L)) 
		return L ;
	
	while (! est_vide (reste(M))) {
		N = cons (prem (M), N) ; 
		M = reste (M) ;
	}
	
	return renverser (N) ; 
}

void test_sauf_dernier_param (liste L) {

	liste M, N ;
	
	printf ("sauf_dernier_recu ( ") ;
	afficher_liste (L) ;
	printf (" ) = ") ;
	M = sauf_dernier_recu (L) ;
	
	afficher_liste (M) ;
	
	printf ("\n") ;
	
	printf ("sauf_dernier_iter( ") ;
	afficher_liste (L) ;
	printf (" ) = ") ;
	N = sauf_dernier_iter (L) ;
	
	afficher_liste (N) ;
	
	printf ("\n\n") ;
}

void test_sauf_dernier () {
	
	printf ("\n") ;
	
	liste M, L ;
	
	M = l_vide () ;
	
	test_sauf_dernier_param (M) ;
	
	L = cons (3, cons(4, cons(5, cons(17, M)))) ;
	
	test_sauf_dernier_param (L) ;
	
	
}

int main() {
	
	test_sauf_dernier () ;

	return EXIT_SUCCESS ;

}