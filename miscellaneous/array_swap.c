// Program to swap 2 elements of an array at the givem indices n1, n2

/*@
    requires n >= 0;
    requires 0 <= n1 < n && 0 <= n2 < n;
    requires \valid_read(arr+(0..n-1));
    ensures (arr[n2] == \old(arr[n1])) && (arr[n2] == \old(arr[n1]));
*/
void array_swap(int* arr, int n, int n1, int n2) {
    int temp = arr[n1];
    arr[n1] = arr[n2];
    arr[n2] = temp;
}

// from this directory run: frama-c-gui -wp array_swap.c