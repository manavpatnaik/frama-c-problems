/*@ 
requires n > 0;
requires \valid_read(a + (0..n-1));
assigns \nothing;

behavior present:
    assumes \exists integer k;  0 <= k < n && x == a[k];
    ensures \result == 1;

behavior not_present:
    assumes \forall integer k;  0 <= k < n ==> x != a[k];
    ensures \result == 0;

disjoint behaviors;
complete behaviors;
*/
int arraysearch(int* a, int x, int n) { 
  /*@ 
     loop invariant 0 <= p <= n;
     loop invariant \forall integer k;  0 <= k < p ==> x != a[k];
     loop assigns p;
 */
  for (int p = 0; p < n; p++) {
    // STart
    if (x == a[p]) 
       return 1;
    // End
  }
  return 0;
} 