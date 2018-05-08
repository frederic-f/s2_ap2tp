#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int somme_cubes(int x) {
  
  // tracage
  // printf("appel a somme_cubes(%d)\n", x);

  // si x = 0 retourne 0
  if (x == 0) {
    
    // tracage
    // printf("somme_cubes(%d) retourne 0\n", x);
    
    return(0);
  }
  else { // x !=0

    int j = (x*x*x + somme_cubes(x-1));
    
    // tracage
    // printf("somme_cubes(%d) retourne %d\n", x, j);
    
    return(j);
  }
}

void test_somme_cubes_param(int n) {
  printf("execution de somme_cubes(%d)\n", n);
  printf("resultat = %d\n", somme_cubes(n));
}


void test_somme_cubes() { // utilise variable
  
  test_somme_cubes_param(3);
}

int main(void) {
  
  test_somme_cubes();

  return EXIT_SUCCESS;

}
