/*@
    requires n > 0;
    requires \valid_read(a+(0..n-1));
    requires \forall integer k; 0 <= k < n ==> a[k] == k;
    ensures \forall integer k; 0 <= k < n ==> a[k] == 2*k;
*/
void arrayDouble(int *a, int n) {
    int p = 0;
    /*@
        loop invariant 0 <= p <= n;
        loop invariant \forall integer k; p <= k < n ==> a[k] == k;
        loop invariant \forall integer k; 0 <= k < p ==> a[k] == 2*k;
        loop assigns p, a[0..n-1];
    */
    while (p < n) {
        a[p] = a[p] * 2;
        p = p + 1;
    } 
}

int main() {
    int arr[] = {0,1,2,3,4,5};
    arrayDouble(arr, 6);
}