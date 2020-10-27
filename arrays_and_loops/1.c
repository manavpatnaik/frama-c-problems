/*@
    requires base >= 0 && height >= 0;
    ensures \result == (base * height)/2;
*/
int area(int base, int height){
    int res = (base *  height)/2;
    return res;
}

int main() {
    int a = area(4, 5);
    //@ assert a == 10;
}