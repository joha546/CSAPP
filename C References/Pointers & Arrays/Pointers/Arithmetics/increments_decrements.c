#include<stdio.h>

int main(){
    //For integer values;
    int a = 52;
    int *p = &a;
    printf("p = %p\n", p);
    p++;
    printf("p++ = %p\n", p);
    p--;
    p--;
    printf("p-- = %p\n", p);

    // For Floating Points;
    float b = 25.5;
    float *q = &b;
    printf("q = %p\n", q);
    q++;
    printf("q++ = %p\n", q);
    q--;
    q--;
    printf("q-- = %p\n", q);

    // For character datatype;
    char c = 'a';
    char *r = &c;
    printf("r = %p\n", r);   
    r++;
    printf("r++ = %p\n", r); 
    r--;
    printf("r-- = %p\n", r);
    return 0;
}