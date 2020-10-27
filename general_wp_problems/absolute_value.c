#include <limits.h>
/*@
    requires val > INT_MIN;
    ensures positive_value: \result >= 0;
    ensures (val >= 0 ==> \result == val) && 
            (val < 0 ==> \result == -val);
*/
int abs(int val) {
    if(val < 0) return -val;
    return val;
}

void foo(int a) {
    int b = abs(-42);
    int c = abs(42);
    int d = abs(a);
    int e = abs(INT_MIN);
}