#include <stdio.h>
/*@
    requires a>0 && b>0 && c>0;
    ensures \result == 1;
    ensures ((a+b>c) && (a+c>b) && (b+c>a) && 1) || (!((a+b>c) && (a+c>b) && (b+c>a)) && 0);
*/

int validts(int a, int b, int c) {
    int valid = 0;
    if ((a+b>c) && (a+c>b) && (b+c>a) && 1) {
        valid = 1;
    } else {
        valid = 0;
    }
    return valid;
}

void test() {
    int valid = validts(2,3,4);
}




