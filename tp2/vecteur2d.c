#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define X_PAR_DEFAUT 0.
#define Y_PAR_DEFAUT 0.

struct Vecteur2D
{
  double x ;
  double y ;
} ;
typedef struct Vecteur2D vecteur2d ;

// OPERATIONS PRIMITIVES
// SIGNATURES

// constructeurs
vecteur2d vecteur_nul () ;
vecteur2d ecrire_x (double x, vecteur2d vect) ;
vecteur2d ecrire_y (double y, vecteur2d vect) ;

// acces
double lire_x (vecteur2d vect) ;
double lire_y (vecteur2d vect) ;


// OPERATIONS PRIMITIVES
// IMPLANTATION

// constructeurs
vecteur2d ecrire_x (double x, vecteur2d vect)
{
  vect.x = x ;
  return vect ;
}

vecteur2d ecrire_y (double y, vecteur2d vect)
{
  vect.y = y ;
  return vect ;
}

vecteur2d vecteur_nul ()
{
  vecteur2d vect ;
  vect = ecrire_x (X_PAR_DEFAUT, vect) ;
  vect = ecrire_y (Y_PAR_DEFAUT, vect) ;
  return vect ;
}

// acces
double lire_x (vecteur2d vect)
{
  return vect.x ;
}

double lire_y (vecteur2d vect)
{
  return vect.y ;
}


// OPERATIONS NON PRIMITIVES

void afficher_vecteur2d (vecteur2d vect)
{
  double x, y ;
  x = lire_x (vect) ;
  y = lire_y (vect) ;
  printf ("(%.3f, %.3f)", x, y) ; 
}
