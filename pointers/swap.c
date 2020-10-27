/*@
requires \valid(a) && \valid(b);
assigns *a, *b;
ensures *a == \old(*b) && *b == \old(*a);
*/
void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int main(){
    int a = 37;
    int b = 91;
    swap(&a, &b);
}