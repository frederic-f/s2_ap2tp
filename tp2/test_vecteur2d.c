#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vecteur2d.c"


void test_afficher_vecteur2d_param (vecteur2d vect)
{
  printf ("vecteur = ") ;
  afficher_vecteur2d (vect) ;
  printf ("\n") ;
}


void test_afficher_vecteur2d ()
{
  test_afficher_vecteur2d_param (vecteur_nul ());
  test_afficher_vecteur2d_param (ecrire_x (2., vecteur_nul())) ;
  test_afficher_vecteur2d_param (ecrire_y (-4., vecteur_nul())) ;
  test_afficher_vecteur2d_param (ecrire_x (2., ecrire_y (-4., vecteur_nul ()))) ;
  test_afficher_vecteur2d_param (ecrire_x (-2., ecrire_y (4., vecteur_nul ()))) ;
}


int main()
{
  test_afficher_vecteur2d () ;
  return EXIT_SUCCESS ;
}
