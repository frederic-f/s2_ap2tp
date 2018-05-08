#include <stdio.h>
#include <stdlib.h>

unsigned int fibo(unsigned int x) 
{
  // tracage
  printf("fibo(%d)\n", x);
  
  if (x == 0) 
    {
      return(1);
    } 
  else if (x == 1) 
    {
      return(1);
    } 
  else 
    {
      return(fibo(x-2) + fibo(x-1));
    }
}


void test_fibo_param(unsigned int x) 
{
  printf("fibo(%d) = %d\n", x, fibo(x));
  fibo(x);
}

void test_fibo() 
{
  /* test_fibo_param(0);
  test_fibo_param(1);
  test_fibo_param(2);
  test_fibo_param(3);
  test_fibo_param(4);
  */
  test_fibo_param(2);
}

int main() {
  test_fibo();
  return EXIT_SUCCESS;
}
