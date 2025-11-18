#include <stdio.h>

int main(){
    int anno;
    int mese;
    int bisestile;
    char junk;

    // step 1: acquisizione valori iniziali
    printf("Inserisci un anno: ");
    scanf("%d", &anno);
    junk = getchar();

    printf("Inserisci un mese(da 1 a 12): ");
    scanf("%d", &mese);
    junk = getchar();

    // step 2: determino se l'anno è bisestile oppure no.
    if(anno%100 == 0){
        // anno secolare
        if(anno%400 == 0){
            bisestile = 1;
        }
        else{
            bisestile = 0;
        }
    }
    else{
        if(anno%4 == 0){
            bisestile = 1;
        }
        else{
            bisestile = 0;
        }
    }
    
    // step 3: determino e comunico i giorni del mese inserito
        switch(mese){
            case 1:{
                printf("Giorni mese: 31");
                break;
            }
            case 2:{
                if(bisestile == 1)
                    printf("Giorni mese: 29");
                else
                    printf("Giorni mese: 28");
                
                /*  oppure 
                    printf("Giorni mese: %d", (28 + bisestile));
                */
                break;
            }
            case 3:{
                printf("Giorni mese: 31");
                break;
            }
            case 4:{
                printf("Giorni mese: 30");
                break;
            }
            case 5:{
                printf("Giorni mese: 31");
                break;
            }
            case 6:{
                printf("Giorni mese: 30");
                break;
            }
            case 7:{
                printf("Giorni mese: 31");
                break;
            }
            case 8:{
                printf("Giorni mese: 31");
                break;
            }
            case 9:{
                printf("Giorni mese: 30");
                break;
            }
            case 10:{
                printf("Giorni mese: 31");
                break;
            }
            case 11:{
                printf("Giorni mese: 30");
                break;
            }
            case 12:{
                printf("Giorni mese: 31");
                break;
            }
            default:{
                printf("Attenzione numero del mese non valido...\n");
            }
        }
    
    // soluzione alternativa allo switch case
    printf("\n\n");
    if((mese==1) || (mese==3) || (mese==5) || (mese==7) || (mese == 8) || (mese==10) || (mese==12))
        printf("Giorni mese: 31");
    if((mese==4) || (mese==6) || (mese==9) || (mese==11))
        printf("Giorni mese: 30");
    if(mese == 2)
        printf("Giorni mese: %d", (28+bisestile));
    
    return(0);
}