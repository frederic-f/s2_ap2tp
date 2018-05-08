#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "vecteur2d.c"

// Q5
// implantation de f
vecteur2d f (vecteur2d vect_a)
{
  vecteur2d vect_b ;
  vect_b = vecteur_nul () ;

  vect_b = ecrire_x (.2 * (lire_x (vect_a) + 4 * (lire_y (vect_a))), vect_b) ;
  vect_b = ecrire_y (.2 * (3 * lire_x (vect_a) + 2 * lire_y (vect_a)), vect_b) ;

  return vect_b ;
}

// fonctions pour tester f
void test_f_param (vecteur2d vect)
{
  printf ("vecteur = ") ;
  afficher_vecteur2d (vect) ;
  printf ("\n") ;
}

void test_afficher_f ()
{
  vecteur2d vect_a, vect_b ;
  vect_a = vecteur_nul () ;
  test_f_param (vect_a) ;
  vect_b = f (vect_a) ;
  test_f_param (vect_b) ;
}

// Q6
// implantation de la suite a(n)
vecteur2d a (unsigned int n)
{
  if (n == 0)
    {
      // return vecteur (5,1)
      vecteur2d vect_a0 ;
      vect_a0 = ecrire_x (5, vecteur_nul () ) ;
      vect_a0 = ecrire_y (1, vect_a0) ;

      return vect_a0 ;
    }
  else 
    {
      vecteur2d vect_n ;
      vect_n = a (n - 1) ;
      return f (vect_n) ;
    }
 }

// Q7
// 

double v (unsigned int n) ;

double u (unsigned int n) 
{
  if (n == 0)
    {
      return 5 ;
    }
  else
    {
      return (0.2 * (u (n-1) + 4 * v (n-1))) ;
    }
}


double v (unsigned int n) 
{
  if (n == 0)
    {
      return 1 ;
    }
  else
    {
      return (0.2 * (3* u (n -1) + 2 * v (n - 1))) ;
    }
}

void test_uv_param (unsigned int n)
{

  double lim = 19. / 7. ;
  printf ("Lim = %f\n\n", lim) ;

  // calcul u(n)
  double res_u ;
  res_u = u (n) ;

  printf ("u(%u) = ", n) ;
  printf ("%f\n", res_u) ;

  double diff_u ;

  diff_u = lim - res_u ;

  printf ("diff_u = %f\n\n", diff_u) ;



  // calcul v(n)
  double res_v ;
  res_v = v (n) ;

  printf ("v(%u) = ", n) ;
  printf ("%f\n", res_v) ;

  double diff_v ;
  diff_v = lim - res_v ;

  printf ("diff_v = %f\n", diff_v) ;

  printf ("\n") ;


}

void test_uv ()
{
  test_uv_param (10) ;

}


int main ()
{
  test_uv () ;  

  test_afficher_f () ;

  return EXIT_SUCCESS;
}
