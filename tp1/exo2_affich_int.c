#include <stdio.h>
#include <stdlib.h>


void afficher_entiers_intervalle(unsigned int a, unsigned int b)
{
  
  if (a > b) { return; }

  printf("%d\n", a);
  afficher_entiers_intervalle(a+1, b);

}


void afficher_entiers_jusqu_a(unsigned int n) 
{
  
  afficher_entiers_intervalle(0, n);

}


// procedure qui affiche les resultats
void test_afficher_entiers_jusqu_a_param(unsigned int n) 
{
  // attention ! 
  
  // first: message de ce qu on va faire
  printf("Affichage des entiers jusqu'a %d\n", n);
  
  // ensuite on appelle procedure
  afficher_entiers_intervalle(0,n);
}

// procedure qui teste avec differentes valeurs
void test_afficher_entiers_jusqu_a(){

  test_afficher_entiers_jusqu_a_param(8);
  test_afficher_entiers_jusqu_a_param(16);

}

int main(void){
    test_afficher_entiers_jusqu_a();
}



