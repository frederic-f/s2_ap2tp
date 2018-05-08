#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> // permet d'utiliser le type bool

bool est_trie(double T[], size_t n) {
  int i = 0;

  while ( (i < n-1) && (T[i] <= T[i+1] ))
    {
      i++;
    } 

    return(i>=n-1);

}


// procedure de test - affichage

void test_est_trie_param(double T[], int n){

  printf("Le tableau est-il trie?\n");
  if(est_trie(T, n)) 
    { 
      printf("oui"); 
    } 
  else 
    {
      printf("non");
    }

}

// procedure de test - utilisation de variables pour tester

void test_est_trie(){

  double tableau[5] = {1.0, 1.0, 3.0, 4.0, 5.0};

  test_est_trie_param(tableau, 5);
}

int main(void) {

  test_est_trie();

}
