/*@
    requires num > 0;
    ensures sum = 
*/
int func(int num) {
    int i = 0;
    int sum = 0;
    /*@
        loop invariant sum == (sum + i);
        loop assigns num, i, sum;
    */
    while(num>0) {
        i = num%10;
        sum += i;
        num /= 10;
    }
    return sum;
}