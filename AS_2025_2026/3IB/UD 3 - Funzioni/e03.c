#include <stdio.h>
#include "mialib.c"

int main(){
    srand(time(NULL));
    int num;
/*    
    vediDivisori(12);
    printf("\n");
    vediDivisori(28);
    printf("\n");

    num = getIntegerValue();
    printf("\n- %d -\n", num);

    num = getIntegerValueInterval(3, 30);
    printf("\n- %d -\n", num);
    
    num = getRandomValue();
    printf("\n- %d -\n", num);
    
    num = getRandomValueInterval(5, 100);
    printf("\n- %d -\n", num);
*/
    for(int i=1; i<=5; i++){
        num = getRandomValueInterval(5, 60);
        printf("%d -> ", num);
        vediDivisori(num);
        printf("\n");
    }
    printf("\n\n");
    for(int i=1; i<=7; i++){
        num = getRandomValueInterval(27, 88);
        printf("%d -> ", num);
        vediDivisori(num);
        printf("\n");
    }
    return(0);
}