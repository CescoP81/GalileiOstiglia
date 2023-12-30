#include <stdio.h>

void fibonacci(int);

int main(){
    fibonacci(10);
}

void fibonacci(int _x){
    int primo;
    int secondo;
    int terzo;
    if(_x>2){
        _x = _x - 2;
        primo = 1;
        secondo = 1;
        terzo = primo + secondo;

        printf("%d %d ", primo, secondo);
        while(_x > 0){
            printf("%d ", terzo);
            primo = secondo;
            secondo = terzo;
            terzo = primo + secondo;
            _x = _x - 1;
        }
    }
    else{
        printf("Serie non realizzabile...");
    }
}