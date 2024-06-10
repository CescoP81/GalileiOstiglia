#include <stdio.h>

int main(){
    int l1;
    int l2;
    int l3;

    printf("Inserisci lato 1: ");
    scanf("%d", &l1);
    fflush(stdin);

    printf("Inserisci lato 2: ");
    scanf("%d", &l2);
    fflush(stdin);

    printf("Inserisci lato 3: ");
    scanf("%d", &l3);
    fflush(stdin);

    // soluzione con if-else innestati e senza operatori logici
    if(l1 == l2){
        if(l2 == l3){
            printf("Trinagolo equilatero");
        }
        else{
            printf("Triangolo isoscele");
        }
    }
    else{
        if(l1 == l3){
            printf("Triangolo isoscele");
        }
        else{
            if(l2 == l3){
                printf("Triangolo isoscele.");
            }
            else{
                printf("Triangolo scaleno.");
            }
        }
    }
    printf("\n\n");

    // soluzione con if-else ed operatori logici
    if((l1 == l2) && (l2 == l3)){
        printf("Triangolo equilatero");
    }
    else{
        if((l1!=l2) && (l2!=l3) && (l1!=l3)){
            printf("Triangolo scaleno");
        }
        else{
            printf("Triangolo isoscele");
        }
    }
    return(0);
}