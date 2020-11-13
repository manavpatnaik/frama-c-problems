// This program used an advanced ACSL clause: \max()
// Note: Some versions of 'wp' plugin may not support the \lambda clause.
//       The program may not verify in every machine.

/*@
    requires n > 0;
    requires \valid_read(arr+(0..n-1));
    ensures \result == \max(0, n-1, \lambda integer i; arr[i]);
    assigns \nothing;
*/
int array_max_advanced(int* arr, int n) {
    int max = arr[0];
    for (int i = 0; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}