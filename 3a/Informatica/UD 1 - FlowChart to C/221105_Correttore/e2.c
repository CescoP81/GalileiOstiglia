#include <stdio.h>

int main(){
    int A, B;
    int cnt;
    float media;
    
    // input dei valori iniziali
    printf("Inserisci A: ");
    scanf("%d", &A);
    fflush(stdin);

    printf("Inserisci B: ");
    scanf("%d", &B);
    fflush(stdin);

    if(A < B){   // condizione principale
        // caso vero, comunico valori dispari tra A e B e il valor medio.
        cnt = A;
        while(cnt <= B){
            if(cnt%2 == 1){
                printf("%d ", cnt);
            }
            cnt = cnt + 1;
        }
        media = (float)(A+B)/2;
        printf("\n\nMedio: %.2f\n", media);
    }
    else{
        if(A%2 == 1){
            printf("A: %d e' dispari\n", A);
        }
        if(B%2 == 1){
            printf("B: %d e' dispari\n", B);
        }
    }
    return(0);
}