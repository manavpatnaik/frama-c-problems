#include <stdio.h>
int pdt(int n) {
  int prod = 1;
  int i = 2;
  /*@
    loop invariant prod == powr(i/2)*fact(i/2);
    loop invariant 0 < i;
    loop invariant i <= n+1;
    loop assigns i, prod;  
  */
  while(i < n) {
    prod = power(i/2)*factorial(i/2);
    i = i+2;
  }
  return prod;
}

int main() {
    int p = pdt(10);
    printf("%d\n", p);
}