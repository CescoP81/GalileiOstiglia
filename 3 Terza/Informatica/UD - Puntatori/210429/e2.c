#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 5
#define COLS 10

void initMatrix(int *_m, int _r, int _c);
void printMatrix(int *_m, int _r, int _c);
void orderMatrix(int *_m, int _r, int _c, int _mode);

int main(){
    int mat[ROWS][COLS];

    initMatrix((int*)mat, ROWS, COLS);
    printMatrix((int*)mat, ROWS, COLS);

    printf("\n\n");
    orderMatrix((int*)mat, ROWS, COLS, 1);
    printMatrix((int*)mat, ROWS, COLS);

    return(0);

}

void initMatrix(int *_m, int _r, int _c){
    srand(time(NULL));
    int i;
    for(i=0; i<(_r*_c); i++){
        *(_m+i) = rand()%100+1;
    }
}

void printMatrix(int *_m, int _r, int _c){
    int i;
    int cnt;

    for(i=0, cnt=0; i<(_r*_c); i++){
        printf("%4d",*(_m+i));
        cnt ++;
        if(cnt == _c){
            printf("\n");
            cnt = 0;
        }
    }
}

void orderMatrix(int *_m, int _r, int _c, int _mode){
    int i, j, tmp;
    for(i=0; i<(_r*_c); i++){
        for(j=i; j<(_r*_c); j++){
            if(_mode == 1){  // modo crescente
                if(*(_m+i) > *(_m+j)){
                    tmp = *(_m+i);
                    *(_m+i) = *(_m+j);
                    *(_m+j) = tmp;
                }
            }
            else{   // modo decrescente
                if(*(_m+i) < *(_m+j)){
                    tmp = *(_m+i);
                    *(_m+i) = *(_m+j);
                    *(_m+j) = tmp;
                }
            }
        }
    }
}