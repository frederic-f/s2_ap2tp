/* 	Fichier cree par Frederic FRANCOIS 
	Exo 1
*/

#include <math.h>
#include <stdio.h>

/* *****************************************************************************
 * Q1. Implantation de la suite S
 * ***************************************************************************** */

double S (unsigned int n, double a) {
	if (n == 0) 
		return 0 ;
	
	return (S (n - 1, a) + (pow (-a, n - 1) / (n))) ;
	
}

void test_S_param (unsigned int n, double a) {
	printf ("S (%d, %f) = ", n, a) ;
	printf ("%f", S (n, a));
	printf ("\n");
}

void test_S () {
	test_S_param (0, 1) ;
	test_S_param (1, 1) ;
	test_S_param (2, 1) ;
	test_S_param (3, 1) ;
	test_S_param (4, 1) ;
	test_S_param (5, 1) ;
}

/* *****************************************************************************
 * Q2. Approximation de ln
 * ***************************************************************************** */

/* Fonction auxiliaire recursive */
double ln_approche_FA (double a, double eps, unsigned int p) {
	
	double S_2p_plus_1 ;
	double S_2p ;
	
	S_2p_plus_1 = S (2*p + 1, a) ;
	S_2p = S (2*p, a) ;
	
	/* si l'expression est verifiee on arrete la recursivite ici */
	if ((S_2p_plus_1 - S_2p) <= (2 * eps)) {
		return ((S_2p + S_2p_plus_1) / 2) ;
	} 
	/* sinon on augmente la precision */
	else {
		return ln_approche_FA (a, eps, p+1) ;
	}
	
}


double ln_approche (double x, double eps) {
	/* Contraintes pour les valeurs : (1. < x < 2.) et (eps > 0) */

	/* on fait appel a une fonction auxiliaire recursive pour pouvoir tester des valeurs croissantes de p */
	
	/* on fait ici la soustraction (a = x - 1) */

	return ln_approche_FA (x-1, eps, 0) ;
	
}

void test_ln_approche_param (double x, double eps) {
	
	printf ("ln_approche (%f, %f) = ", x, eps) ;
	printf ("%.5f", ln_approche (x, eps)) ;
	printf ("\n") ;
}


void test_ln_approche () {

	test_ln_approche_param (1.1, 1.) ;

	test_ln_approche_param (1.1, 0.1) ;
	
	test_ln_approche_param (1.1, 0.01) ;
	
	test_ln_approche_param (1.1, 0.001) ;
	
	test_ln_approche_param (2., 0.001) ;
}

int main () {
		
	test_S () ;
	
	printf ("\n");
	
	test_ln_approche () ;
	
	return 0 ;
}

/* Resultats */

/* 

S (0, 1.000000) = 0.000000
S (1, 1.000000) = 1.000000
S (2, 1.000000) = 0.500000
S (3, 1.000000) = 0.833333
S (4, 1.000000) = 0.583333
S (5, 1.000000) = 0.783333

ln_approche (1.100000, 1.000000) = 0.50000
ln_approche (1.100000, 0.100000) = 0.95167
ln_approche (1.100000, 0.010000) = 0.95167
ln_approche (1.100000, 0.001000) = 0.95309
ln_approche (2.000000, 0.001000) = 0.69315


*/
