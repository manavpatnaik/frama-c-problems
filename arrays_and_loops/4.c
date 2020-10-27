#include<limits.h>
/*@
    requires x > 0 && x < INT_MAX;
    ensures \result == x;
    assigns \nothing;
*/
int test(int x) {
    int a = x;
    int y = 0;
    /*@ 
        loop invariant y + a == x;
        loop invariant a > -1 && a <= x;
        loop assigns a, y;
    */
    while(a != 0) {
        y = y + 1;
        a = a - 1;
    }
    return y;
}
    
int main() {
    int num = test(3);
    //@ assert num == 3;
    return 0;
}