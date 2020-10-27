/*@
    requires n > 0 && x > 0;
    requires \valid_read(a + (0..n-1));
    ensures \result >= 0 && \result <= n;
*/
int func(int *a, int n, int x, int *sum) {
    int p = 0;
    int count = 0;
    *sum = 0;
    /*@
        loop invariant 0 <= p <= n;
        loop invariant count <= p && *sum == count*x;
        loop assigns p, count, *sum;
    */
    while (p < n) {
        if (a[p] == x) {
            count = count + 1;
            *sum = *sum + x;
        }
        p = p + 1;
    }
    Label_a:
    *sum += 0;
    //@ assert \at(*sum, Label_a) == count*x;
    return count;
}

