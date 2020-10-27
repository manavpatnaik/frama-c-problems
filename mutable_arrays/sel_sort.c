#include <stdio.h>
/*@ 
    requires \valid(a+(0..n-1));
    requires n > 0;
    ensures \forall integer i,j; 0<=i<=j<n-1 ==> a[i]<=a[j];
*/
void selectionSort(int a[], int n) {
    int i, j, min;
    /*@
        loop invariant \forall integer p,q; 0<=p<q<=i ==> a[p]<=a[q];
        loop invariant \forall integer p,q; 0<=p<i+1==q<=n-1 ==> a[p]<=a[q];
        loop invariant 0<=i<n;
        loop assigns i,j,a[0..n-1];
        loop variant i;
    */
    for (i = 0; i < n-1; i++) {
        // Find the minimum element in unsorted array
        min = i;
        /*@ 
            loop invariant 0<=i<j<n;
            loop invariant \forall integer k; 0<=k<=i ==> a[k] <= a[i];
            loop invariant \forall integer k; i+1 <= k <= j ==> a[min] <= a[k];
            loop invariant \exists integer k; i+1 <= k <= j && a[min] == a[k];
            loop assigns j,min,a[i+1..n-1];
            loop variant i-j;
        */
        for (j = i+1; j < n; j++) {
            if (a[j] < a[min]){
                min = j;
            }
        }
        // Swap the minimum element with the first element
        int temp = a[min];
        a[min] = a[i];
        a[i] = temp;
    }
}
int main() {
    int arr[] = {64, 45, 10, 23, 11, 33};
    int n = 6;
    selectionSort(arr, n);
    return 0;
}