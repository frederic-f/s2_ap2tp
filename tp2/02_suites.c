#include <stdio.h>

typedef unsigned int uint ;

/* *******************************************************************
 * Q.1 - Implémentation de Un et Vn
 ****************************************************************** */

double v (uint n) ;

double u (uint n) {
    if (n == 0)
        return 5 ;

    return (1./5.) * (u (n-1) + 4 * v (n - 1)) ;
}

double v (uint n) {
    if (n == 0)
        return 1 ;

    return (1./5.) * (3 * u (n -1) + 2 * v (n - 1)) ;
}


/* *******************************************************************
 * Q.2 - Procédures de test
 ****************************************************************** */

void test_suite_u_param (uint n) {
    printf ("u(%d) = %f\n", n, u (n)) ;
}

void test_suite_v_param (uint n) {
    printf ("v(%d) = %f\n", n, v (n)) ;
}


void test_suites () {
    /* u */
    test_suite_u_param (10) ;

    printf ("Limite u(n) = 19 / 7\n") ;

    printf ("u(10) - lim u(n) = %f\n", u(10) - (19./7.)) ;

    printf ("\n") ;

    /* v */
    test_suite_v_param (10) ;

    printf ("Limite v(n) = 19 / 7\n") ;

    printf ("v(10) - lim v(n) = %f\n", v(10) - (19./7.)) ;

}



/*
int main () {

    test_suites () ;

    return 0 ;
}*/
