#include "liste_entiers.c"

/* *********************************************************************************************
 * Q.1 - Recursive
 * ********************************************************************************************/
liste sauf_dernier_Recu (liste L) {
    if (est_vide(L))
        return l_vide() ;

    if (est_vide(reste(L)))
        return l_vide() ;

    return cons (prem (L), sauf_dernier_Recu(reste(L))) ;

}

/* *********************************************************************************************
 * Q.2 - Iterative
 * ********************************************************************************************/
liste sauf_dernier_Iter (liste L) {
    liste M = l_vide() ;
    liste N = L ;

    while ((N != l_vide()) && (reste(N) != l_vide())) {
        M = cons (prem(N), M) ;
        N = reste (N) ;
    }

    return renverser(M) ;
}


void test_sauf_dernier_param (liste L) {
    liste M, N ;

    M = sauf_dernier_Recu (L) ;

    printf ("sauf_dernier_Recu ( ");
    afficher_liste(L);
    printf (" ) = ") ;
    afficher_liste(M) ;
    printf ("\n") ;

    N = sauf_dernier_Iter (L) ;

    printf ("sauf_dernier_Iter ( ");
    afficher_liste(L);
    printf (" ) = ") ;
    afficher_liste(N) ;
    printf ("\n") ;
}


void test_sauf_dernier () {

    liste L = l_vide() ;

    test_sauf_dernier_param (L) ;

    L = cons (10, L) ;

    test_sauf_dernier_param (L) ;

    L = cons (20, cons (30, L)) ;

    test_sauf_dernier_param (L) ;
}

/* */
int main () {

    test_sauf_dernier();

    return 0 ;

}