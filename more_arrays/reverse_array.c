/*@
    requires n > 0;
    requires \valid_read(a + (0..n-1));

    ensures \forall integer k; 0 <= k < n/2 ==> a[k] == a[n-k-1];
*/
void reverse(int *a, int n) {
    int i = 0;
    int j = n-1;
    /*@
        loop invariant i <= n/2;
        loop invariant j >= n/2;
    */
    while (i < n/2) {
        int temp = a[i];
        a[i] = a[j];
        a[j] = temp;
        i++;
        j--;
    }
}