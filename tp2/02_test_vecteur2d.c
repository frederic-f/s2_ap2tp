#include <time.h>

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
 * Q.8 - Temps de calcul
 ****************************************************************** */

/* Calcul de un selon Q1 */

void calcul_u_param (uint n) {
    long unsigned int dt;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    test_suite_u_param (n) ;
    clock_gettime(CLOCK_MONOTONIC_RAW, &stop);

    dt = (stop.tv_sec-start.tv_sec)*1000000000+(stop.tv_nsec-start.tv_nsec);
    printf("durée écoulée: %lu\n\n", dt);
}

void calcul_a_param (uint n) {
    long unsigned int dt;
    struct timespec start, stop;

    clock_gettime(CLOCK_MONOTONIC_RAW, &start);
    test_a_param (n) ;
    clock_gettime(CLOCK_MONOTONIC_RAW, &stop);

    dt = (stop.tv_sec-start.tv_sec)*1000000000+(stop.tv_nsec-start.tv_nsec);
    printf("\ndurée écoulée: %lu\n\n", dt);
}

void comparaison_temps_calcul () {
    calcul_u_param (10) ;
    calcul_a_param (10) ;

    calcul_u_param (20) ;
    calcul_a_param (20) ;
    calcul_u_param (30) ;
    calcul_a_param (30) ;
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



    printf ("\n\n") ;
    printf ("Temps de calcul \n\n") ;
    comparaison_temps_calcul () ;

    return 0 ;
}


/*
Test vecteur 2d
(0.000, 0.000)
(5.000, 5.000)


Test f
f ( (0.000, 0.000) ) = (0.000, 0.000)
f ( (5.000, 5.000) ) = (5.000, 5.000)
f ( (3.000, 2.000) ) = (2.200, 2.600)


Test a
a(0) =(5.000, 1.000)
u(0) = 5.000000
v(0) = 1.000000

a(1) =(1.800, 3.400)
u(1) = 1.800000
v(1) = 3.400000

a(2) =(3.080, 2.440)

u(2) = 3.080000
v(2) = 2.440000


Temps de calcul

u(10) = 2.714525
durée écoulée: 39506

a(10) =(2.715, 2.714)
durée écoulée: 7828

u(20) = 2.714286
durée écoulée: 11411582

a(20) =(2.714, 2.714)
durée écoulée: 3005

u(30) = 2.714286
durée écoulée: 5866137828

a(30) =(2.714, 2.714)
durée écoulée: 3537

*/

