#include <stdio.h>
#include <stdlib.h>

/* programme qui calcule les puissances de 2 */

// fonction dpn qui renvoie deux puissance n
unsigned int dpn(unsigned int n)
{
  if(n==0) { return(1); }

  unsigned int d;
  d = dpn(n-1);

  return(d+d);
}

// procedure d'affichage
void test_dpn_param(unsigned int n)
{
  printf("dpn de %d = %d\n", n, dpn(n));
}

// procedure de test de dpn
void test_dpn()
{
  unsigned int i;

  for (i=0;i<6;i++){
    test_dpn_param(i);
  }

}



int main(void) 
{
  //test_dpn_param(4); // doit afficher 2 puissance 4 = 16
  //test_dpn_param(8); // doit afficher 2 puissance 8 = 

  test_dpn();
}
