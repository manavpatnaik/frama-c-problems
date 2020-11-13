/*@
    requires n > 0;
    requires \valid_read(arr+(0..n-1));
    ensures \forall integer k; 0 <= k < n ==> arr[k] == (\at(arr[k], Pre) + c);
*/
void increment_array_by(int* arr, int n, int c) {
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] == \at(arr[k], Pre) + c;
        loop invariant \forall integer k; i <= k < n ==> arr[k] == \at(arr[k], Pre);
        loop assigns i, arr[0..n-1];
    */
    for (int  i = 0; i < n; i++) {
        arr[i] = arr[i] + c;
    }
}