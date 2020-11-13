#include <stdlib.h>
/*@
    requires n >= 0 && n <= 100;
    ensures \result >= 0;
    ensures \result == (int)((n+1)*(n)/2);
    assigns \nothing;
*/
int sum(char n) {
    int s = 0;
    char k = 0;
    /*@
        loop invariant 0 <= k <= n+1;
        loop invariant s == (k-1)*(k)/2;
        loop assigns k, s;
        loop variant n - k;
    */
    while(k <= n) {    
        s = s + (int)k;
        k = k + 1;
    }
    return (int)s;
}

int main() {
    int s = sum(5);
    //@ assert s == 15;
}