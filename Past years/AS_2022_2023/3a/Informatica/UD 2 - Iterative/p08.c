#include <stdio.h>

int main(){
    int righe;
    int cnt1, cnt2, cnt3;

    // iterativa di inserimento numero di righe desiderate.
    do{
        printf("Inserisci il nr. di righe: ");
        scanf("%d", &righe);
        fflush(stdin);
    }while(righe<1 || righe>10);

    // schema grafico 1
    cnt1 = 1;
    while(cnt1 <= righe){           // ciclo delle righe
        cnt2 = 1;
        while(cnt2 <= (cnt1-1)){    // ciclo degli spazi bianchi su ogni riga
            printf("   ");
            cnt2 = cnt2 + 1;
        }

        cnt2 = cnt1;
        while(cnt2 <= righe){       // ciclo dei numeri sulla riga.
            printf("%3d", cnt2);
            cnt2 = cnt2 + 1;
        }
        cnt1 = cnt1 + 1;
        printf("\n");
    }

    printf("\n\n");

    // schema grafico 2
    cnt1 = 1;
    while(cnt1 <= righe){               // ciclo per le righe
        cnt2 = 1;
        while(cnt2 <= righe-cnt1+1){    // ciclo per i numeri dispari/spazi sulle righe
            if(cnt2%2 != 0)
                printf("%3d", cnt2);
            else
                printf("  -");
            cnt2 = cnt2 + 1;
        }
        printf("\n");
        cnt1 = cnt1 + 1;
    }

    printf("\n\n");

    // schema grafico 3
    cnt1 = 1;
    while(cnt1 <= righe){               // ciclo per le righe
        cnt2 = 1;
        while(cnt2 <= righe){           // ciclo per gli spazi/numeri sulle righe.
            if(cnt2 >= righe-cnt1+1)
                printf("%3d", cnt2);
            else
                printf("  -");
            cnt2 = cnt2 + 1;
        }
        printf("\n");
        cnt1 = cnt1 + 1;
    }
    return(0);
}