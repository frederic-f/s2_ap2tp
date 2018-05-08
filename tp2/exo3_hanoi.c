#include <stdlib.h>
#include <stdio.h>

typedef unsigned int uint ;

unsigned int autre_pilier (unsigned int x, unsigned int y) {
    if ( (x != y) && (x + y < 6)) {
        return 6 - x - y ;
    }
}


void hanoi_aux (uint n, uint d, uint a) {
    if (n == 1) {
        printf ("Déplacer un disque du pilier %d au pilier %d\n", d, a) ;
    } else {
        hanoi_aux (n -1, d, autre_pilier(d, a)) ;

        hanoi_aux (1, d, a) ;

        hanoi_aux (n - 1, autre_pilier(d, a), a) ;
    }
}


void hanoi (uint n) {
    hanoi_aux (n, 1, 3) ;
}


void test_hanoi_param (uint n) {
    printf ("Appel hanoi pour n = %d\n", n) ;
    hanoi (n);
    printf ("\n") ;
}

void test_hanoi () {
    test_hanoi_param (1) ;

    test_hanoi_param (2) ;

    test_hanoi_param (3) ;

    test_hanoi_param (4) ;

    test_hanoi_param (5) ;
}



int main () {
    //printf ("%d", autre_pilier(2, 3)) ;

    test_hanoi () ;

    return 0 ;
}