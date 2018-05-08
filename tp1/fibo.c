#include <stdio.h>
#include <stdlib.h>

int fibo(int x) 
{
  if (x == 0) 
    {
      return(0);
    } 
  else if (x == 1) 
    {
      return(1);
    } 
  else 
    {
      //return(fibo(x-2) + fibo(x-1));
    }
}


void test_fibo_param(int x) {
  //printf("fibo(%d) = %d\n", x, fibo(x));
}

void test_fibo() {
  //test_fibo_param(5);
}

int main() {
  test_fibo();
  //return EXIT_SUCCESS;
}
