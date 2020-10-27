#include <stdio.h>
/*@
    requires n > 0;
    ensures \result == (n-4)/3.0;
    assigns \nothing;
*/
int fun(int n) {
    int i = 7;
    int x = 1;
    /*@
        loop invariant i == 4 + 3*x;
        loop assigns x, i;
    */
    while(i <= n) {
        x += 1;
        i += 3;
    }
    return x;
}

int main() {
    int a = fun(20);
    printf("%d\n", a);
}