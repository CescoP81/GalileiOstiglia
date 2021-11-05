#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DIM_1 10
#define DIM_2 20
#define DIM_3 45

void initVettore(int [], int);
void initVettoreMinMax(int [], int, int, int);
void printVettore(int [], int);
void moltiplicaVettore(int [], int, int);

float mediaVettore(int [], int);


int main(){
   int v1[DIM_1];
   int v2[DIM_2];
   int v3[DIM_3];
   float media;

   initVettore(v1, DIM_1);
   printVettore(v1, DIM_1);
   printf("\n");

   initVettore(v2, DIM_2);
   printVettore(v2, DIM_2);
   printf("\n");

   initVettore(v3, 5);
   printVettore(v3, 5);
   printf("\n");

   initVettoreMinMax(v1, DIM_1, 10, 25);
   printVettore(v1, DIM_1);
   printf("\n");

   moltiplicaVettore(v1, DIM_1, 2);
   printVettore(v1, DIM_1);
   printf("\n");
   
   media = mediaVettore(v1, 7);
   printf("Media: %d", (int)media);
   printf("\n");

   return(0);
}

void initVettore(int _v[], int _dim){
   int i;
   srand(time(NULL));

   for(i=0; i<_dim; i++){
      _v[i] = rand()%20+1;
   }
}

void initVettoreMinMax(int _v[], int _dim, int _min, int _max){
   int i;
   srand(time(NULL));

   for(i=0; i<_dim; i++){
      _v[i] = _min + (rand()%(_max-_min)+1);
   }
}

void printVettore(int _v[], int _dim){
   int i;
   for(i=0; i<_dim; i++){
      printf("%4d", _v[i]);
   }
}

void moltiplicaVettore(int _v[], int _dim, int _moltiplicatore){
   int i;
   for(i=0; i<_dim; i++){
      _v[i] = _v[i] * _moltiplicatore;
   } 
}

float mediaVettore(int _v[], int _dim){
   int i;
   float media;

   for(i=0; i<_dim; i++){
      media = media + _v[i];
   }

   media = media / _dim;
   return(media);
}

