#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void affichage_binaire (unsigned int a)
{
  if (a >= 2)
    {
      affichage_binaire(a / 2) ;
    }  

  unsigned int res ;

  res = a % 2;

  printf ("%u", res) ;
}

void test_affichage_binaire_param (unsigned int a)
{
  printf ("affichage_binaire (%u) = ", a) ;

  affichage_binaire (a) ;

  printf("\n") ;

}

void test_affichage_binaire ()
{
  test_affichage_binaire_param (45) ;
  test_affichage_binaire_param (145) ;
  test_affichage_binaire_param (255) ;
  test_affichage_binaire_param (2047) ;
  test_affichage_binaire_param (2048) ;
}

int main ()
{
  test_affichage_binaire () ;

  return EXIT_SUCCESS;
}
