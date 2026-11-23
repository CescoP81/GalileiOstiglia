#include <stdio.h>

int main(){
    int a;
    int b;
    int c;

    a=0;
    b=0;
    c=0;

    printf("Inserisci a: ");
    scanf("%d", &a);
    fflush(stdin);

    printf("Inserisci b: ");
    scanf("%d", &b);
    fflush(stdin);

    c = a + b;

    if(c >= 10){
        printf("C=%d valore maggiore o uguale a 10!\n",c);
    }
    else{
        printf("C=%d valore minore a 10!\n",c);
    }

    return 0;
}