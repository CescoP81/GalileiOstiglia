#include <conio.h>
#include <stdio.h>
#define DIM 5

int vedi_mat(int [][DIM]);

int main(){
    int m[DIM][DIM];
    int i,j;
    int r;
    for(i=1; i<DIM; i++){
        for(j=1; j<DIM; j++){
            m[i][j] = i+j;
        }
    }
    r = vedi_mat(m);
    printf("Somma: %d", r);
    return(0);
}

int vedi_mat(int _m[][DIM]){
    int i, j;
    int x;
    x = 0;
    for(i=1; i<DIM; i++){
        for(j=1; j<DIM; j++){
            if(i%2 && j%2){
                printf("%d ", _m[i][j]);
                x = x + _m[i][j];
            }
            else{
                printf("# ");
            }
        }
        printf("\n");
    }
    return(x);
}