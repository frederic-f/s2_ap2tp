#include "02_vecteur2d.c"
#include "02_suites.c"

/* *******************************************************************
 * Q.4 - Fonction d'affichage d'un vecteur 2d
 ****************************************************************** */

void affiche_vecteur2d (vecteur2d v) {
    printf ("(%.3f, %.3f)", lire_x (v), lire_y (v)) ;
}


void test_affiche_vecteur2d () {
    affiche_vecteur2d (vecteur_nul()) ;
    printf ("\n") ;
    affiche_vecteur2d (ecrire_x(5, ecrire_y(5, vecteur_nul()))) ;
    printf ("\n") ;
}


/* *******************************************************************
 * Q.5 - Fonction qui associe un vecteur à un autre
 ****************************************************************** */

vecteur2d f (vecteur2d a) {
    vecteur2d b = vecteur_nul() ;
    b = ecrire_x ( ((lire_x (a) + 4 * lire_y (a)) / 5.), b) ;
    b = ecrire_y ( ((3 * lire_x (a) + 2 * lire_y (a)) / 5.), b) ;

    return b ;
}


void test_f_param (vecteur2d a) {
    printf ("f ( ") ;
    affiche_vecteur2d (a) ;
    printf (" ) = ") ;
    affiche_vecteur2d (f (a));
    printf ("\n") ;
}


void test_f () {
    vecteur2d a;
    a = vecteur_nul();
    test_f_param(a);

    test_f_param(ecrire_x(5, ecrire_y(5, vecteur_nul())));
    test_f_param(ecrire_x(3, ecrire_y(2, vecteur_nul())));
}


/* *******************************************************************
 * Q.6 - Suite a(n)
 ****************************************************************** */

vecteur2d a (uint n) {
    if (n == 0)
        return ecrire_x(5., ecrire_y (1., vecteur_nul ())) ;

    return f (a (n - 1)) ;
}


/* *******************************************************************
 * Q.7 - Test de a(n)
 ****************************************************************** */

void test_a_param (uint n) {
    printf ("a(%d) = ", n) ;
    affiche_vecteur2d (a (n)) ;
}


void test_a () {
    test_a_param (0) ;
    printf ("\n") ;
    test_suite_u_param (0) ;
    test_suite_v_param (0) ;

    printf ("\n") ;
    test_a_param (1) ;

    printf ("\n") ;
    test_suite_u_param (1) ;
    test_suite_v_param (1) ;

    printf ("\n") ;
    test_a_param (2) ;
    printf ("\n") ;

    printf ("\n") ;
    test_suite_u_param (2) ;
    test_suite_v_param (2) ;
}


/* *******************************************************************
 * Main
 ****************************************************************** */

int main () {
    printf ("Test vecteur 2d\n") ;
    test_affiche_vecteur2d () ;

    printf ("\n\n") ;

    printf ("Test f\n") ;
    test_f () ;

    printf ("\n\n") ;
    printf ("Test a\n") ;
    test_a () ;

    return 0 ;
}
