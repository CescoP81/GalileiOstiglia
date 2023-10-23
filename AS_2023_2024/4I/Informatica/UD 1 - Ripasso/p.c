#include <stdio.h>

void doppio(int*);

int main(){
    int a=5;

    printf("Address: %d - Value: %d\n\n", &a, a);
    doppio(&a);

    printf("Address: %d - Value: %d\n\n", &a, a);
    return(0);

}

void doppio(int *x){
    printf("Address: %d - Value: %d\n\n", x, *x);
    *x = (*x) * 2;
}

/*
Address: 6422300 - Value: 5

Address: 6422300 - Value: 5

Address: 6422300 - Value: 10
*/