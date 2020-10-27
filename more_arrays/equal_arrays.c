/*@ 
    requires n > 0;
    requires \valid_read (a + (0..n-1));
    requires \valid_read (b + (0..n-1));
    assigns \nothing;

    behavior equal:
        assumes \forall integer k;  0 <= k < n ==> b[k] == a[k];
        ensures \result == 1;

    behavior not_equal:
        assumes \exists integer k;  0 <= k < n && b[k] != a[k];
        ensures \result == 0;
*/
int check(int *a, int *b, int n) {
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i ==> a[k] == b[k];
        loop assigns i;
    */
    for (int i = 0; i < n; i++) {
        if (a[i] != b[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int a[] = {1,2,3,4,5};
    int b[] = {1,2,3,4,5};
    check(a, b, 5);
}