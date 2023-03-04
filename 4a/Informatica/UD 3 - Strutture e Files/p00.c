#include <stdio.h>

typedef struct Strutto{
    int val;
    void (*pmod)(struct Strutto*, int);
};

void modifica(struct Strutto*, int);

int main(){
    struct Strutto s1;
    s1.pmod = modifica;
    s1.val = 10;

    printf("%d\n", s1.val);

    s1.pmod(&s1, 20);
    printf("%d\n", s1.val);
}

void modifica(struct Strutto *_s, int _v){
    (*_s).val = _v;
}