#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int RIGHE = 20;
const int LUNGHEZZA = 10;

char getCarMinuscolo();
char getCarMaiuscolo();
char getDigit();
char getJolly();

int main(){
    int nrPassword;
    int trash;
    char passwords[RIGHE][LUNGHEZZA+1];
    int i;
    srand(time(NULL));

    do{
    printf("Quante password generare: ");
    scanf("%d", &nrPassword);
    trash = getchar();
    }while((nrPassword > 20) || (nrPassword<=0));

    for(i=0; i<nrPassword; i++){
        // nnCcCn-ncJ
        passwords[i][0] = getDigit();
        passwords[i][1] = getDigit();
        passwords[i][2] = getCarMaiuscolo();
        passwords[i][3] = getCarMinuscolo();
        passwords[i][4] = getCarMaiuscolo();
        passwords[i][5] = getDigit();
        passwords[i][6] = '-';
        passwords[i][7] = getDigit();
        passwords[i][8] = getCarMinuscolo();
        passwords[i][9] = getJolly();
        passwords[i][10] = '\0';
    }

    printf("Password Generate:\n");
    for(i=0; i<nrPassword; i++){
        printf("[%d]: %s\n", i+1, passwords[i]);
    }

    return(0);
}

char getCarMinuscolo(){
    int random;
    random = rand()%26;

    return('a'+random);
}
char getCarMaiuscolo(){
    int random;
    random = rand()%26;

    return('A'+random);
}
char getDigit(){
    int random;
    random = rand()%10;

    return('0'+random);
}
char getJolly(){
    // indica un carattere Jolly tra i seguenti * ( ) $ # !
    int random;
    random = rand()%6;
    if(random == 0) return('*');
    if(random == 1) return('(');
    if(random == 2) return(')');
    if(random == 3) return('$');
    if(random == 4) return('#');
    if(random == 5) return('!');
}