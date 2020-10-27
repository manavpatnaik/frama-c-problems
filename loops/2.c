/*@
    requires n >= 0;
    ensures \result == n*(n+1)/2;
    assigns \nothing;
*/

int sum(int n) {
    int s = 0;
    int k = 1;
    /*@
        loop invariant s == k*(k+1)/2;
        loop assigns k, s;
    */
    while(k != n+1) {    
        s = s+ k;
        k = k + 1;
    }
    return s;
}

int main() {
    int n1 = 5;
    int s = sum(5);
    //@ assert s == 15;
}