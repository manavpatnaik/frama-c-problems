// Program to find index of an element in an array
// Behaviors not used in this program

/*@
    requires n >= 0;
    requires \valid_read(arr+(0..n-1));
    assigns \nothing;

    ensures -1 <= \result < n;

    ensures 0 <= \result < n ==> arr[\result] == x;
    ensures (\result == -1) ==> (\forall integer i; 0 <= i < n ==> arr[i] != x);
    assigns \nothing;
*/
int array_find(int* arr, int n, int x) {
    int i = 0;
    /*@
        loop invariant 0 <= i <= n;
        loop invariant \forall integer k; 0 <= k < i ==> arr[k] != x;
        loop assigns i;
        loop variant n-i;
    */
    for (i = 0; i < n; i++) {
        if (arr[i] == x) {
            return i;
        }
    }
    return -1;
}

// from this directory run: frama-c-gui -wp array_find.c