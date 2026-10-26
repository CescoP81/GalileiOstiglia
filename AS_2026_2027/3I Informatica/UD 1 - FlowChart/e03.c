/* Programma fa la media di tre valori richiesti in input e comunica se bocciato o promosso.*/
#include <stdio.h>

int main()
{
    // variabili per memorizzare i voti in input.
    float voto_1;
    float voto_2;
    float voto_3;

    float media_voti;   // variabile per calcola la media dei voti acquisiti.
    char junk;

    // Step 1: acquisisco i voti
    printf("Inserisci il primo voto: ");
    scanf("%f", &voto_1);
    junk = getchar();

    printf("Inserisci il secondo voto: ");
    scanf("%f", &voto_2);
    junk = getchar();

    printf("Inserisci il terzo voto: ");
    scanf("%f", &voto_3);
    junk = getchar();

    // Step 2: calcolo della media dei voti
    media_voti = (voto_1 + voto_2 + voto_3) / 3;

    // stampo la media come feedback
    // printf("Somma dei voti: %.2f, media dei voti: %.2f\n\n", (voto_1+voto_2+voto_3), media_voti);

    // Step 3: determino se sono promosso o debito.
    if(media_voti < 6.0){
        printf("Spiacente, ti cucchi il debito!\n");
    }
    else{
        printf("Incredibile, passi al next level!\n");
    }

    return 0;
}