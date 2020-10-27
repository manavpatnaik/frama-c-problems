#include <limits.h>
/*@
requires INT_MIN<x && INT_MIN<y;
ensures \result>=x && \result>=y;
ensures \result==x || \result==y; 
*/
int max ( int x, int y ) {
    if ( x >=y ) 
        return x ;
    return y ;
}

 

void foo()
{
    int s = max(34,45);
    int t = max(-43,34);
    
}