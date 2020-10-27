/*@
    requires n > 0;
    assigns \nothing;
    ensures \valid_read(a + (0..n-1));

behavior present:
    assumes \exists integer k; 0 <= k < n && x == a[k];
    ensures \result == 1;

behavior not_present:
    assumes  \exists integer k; 0 <= k < n && x != a[k];
    ensures \result == 0;
*/
int arraySearch(int *a, int x, int n) {
    int p = 0;
    /*@
        loop invariant  0 <= p <= n;
        loop invariant \forall integer k; 0 <= k < p ==> x != a[k];
        loop assigns p;
    */
    while (p < n) {
        if (a[p] == x) {
            return 1;
        }
        p++;
    }
    return 0;
}