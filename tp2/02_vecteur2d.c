#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define X_DEFAUT 0.
#define Y_DEFAUT 0.

struct Vecteur2D
{
    double x ;
    double y ;
} ;
typedef struct Vecteur2D vecteur2d ;


/* OPERATIONS PRIMITIVES */

/* ecriture */

vecteur2d vecteur_nul () ;

vecteur2d ecrire_x (double x, vecteur2d v) ;

vecteur2d ecrire_y (double y, vecteur2d v) ;

/* lecture */

double lire_x (vecteur2d v) ;

double lire_y (vecteur2d v) ;

/* IMPLEMENTATION */

vecteur2d ecrire_x (double x, vecteur2d v) {
    v.x = x ;
    return v ;
}

vecteur2d ecrire_y (double y, vecteur2d v) {
    v.y = y ;
    return v ;
}

vecteur2d vecteur_nul () {
    vecteur2d v ;
    v = ecrire_x (X_DEFAUT, v) ;
    v = ecrire_y (Y_DEFAUT, v) ;
    return v ;
}


double lire_x (vecteur2d v) {
    return v.x ;
}

double lire_y (vecteur2d v) {
    return v.y ;
}