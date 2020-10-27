/*@
    requires -10 <= x <= 0 ;
    requires 0 <= y <= 5 ;
    ensures -10 <= \result <= 10 ;
*/
int function(int x, int y) {
    int res ;
    y += 10 ;
    x -= 5 ;
    res = x + y ;
    //@ assert -15 <= res <= 5;
    return res ;
}