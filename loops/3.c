#include <stdio.h>
/*@
    requires c > 0;
    ensures \result == c;
    assigns \nothing;
*/
int func(int c) {
    int x = c;
    int y = 0;
    /*@
        loop invariant c == x + y && x >= 0;
        loop assigns x, y;
    */
    while(x > 0) {
        x = x - 1;
        y = y + 1;
    }
    return y;
}