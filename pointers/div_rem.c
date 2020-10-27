/*@
    requires \valid(q) && \valid(r);
    requires \separated(q, r);
    requires y != 0;
    assigns *q, *r;
    ensures x == *q * y + *r;
    ensures *r < y;
*/
void div_rem(unsigned x, unsigned y, unsigned* q, unsigned* r) {
    *q = x / y;
    *r = x % y;
}