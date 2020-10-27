#include <stdio.h>
 
/*@ 
 requires \valid(a+(0..n-1));
 requires n > 0;
 ensures \forall integer k; 0 <= k < n && k%2 ==0 ==> a[k] == 0;
*/
 
void replacedigits(int *a,int n){
 
 /*@
 loop invariant \forall integer k; 0 <= k < i && k%2 ==0 ==> a[k] == 0;
 loop invariant 0 <= i <= n;
 loop assigns i;
 */
 for(int i=0;i<n;i++){
 if(i%2==0){
 a[i] = 0;
 
 }
 }
 
 
}
 
int main(){
 int n = 5;
 int a[5]= {1,2,3,4,5};
 replacedigits(a,n);
 for(int i = 0;i<n;i++){
 printf("%d",a[i]);
 }
 
}