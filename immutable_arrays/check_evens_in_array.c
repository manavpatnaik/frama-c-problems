// Program to find if the array consists of even elements only

/*@
    requires n > 0;
    requires \valid_read(a+(0..(n-1)));
    assigns \nothing;

    behavior all_even:
        assumes \forall integer k; 0 <= k < n ==> a[k]%2 == 0;
        ensures \result == 1;

    behavior all_not_even:
        assumes \exists  integer k; 0 <= k < n ==> a[k]%2 != 0;
        ensures \result == 0;

    disjoint behaviors;
    complete behaviors;
*/
int areElementsEven(int *a, int n) {
    int p = 0;
    /*@
        loop invariant 0 <= p <= n;
        loop invariant \forall integer k; 0 <= k < p ==> a[k]%2 == 0;
        loop assigns p; 
    */
    while (p < n) {
        if (a[p]%2 != 0) {
            return 0;
        }
        p = p + 1;
    }
    return 1;
}

void main() {
    int arr[] = {2,4,6,8,10};
    int res = areElementsEven(arr, 5);
    //@ assert res == 1;
}
