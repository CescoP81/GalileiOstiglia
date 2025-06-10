#include <stdio.h>

const int NRBIT = 8;
const int NRBYTE = 4;

int main(){
    int subnetByte[NRBYTE];
    int subnetBit[NRBYTE][NRBIT];

    int IpUnoByte[NRBYTE];
    int IpUnoBit[NRBYTE][NRBIT];
    int ipUnoAndMask[NRBYTE][NRBIT];

    int IpDueByte[NRBYTE];
    int IpDueBit[NRBYTE][NRBIT];
    int ipDueAndMask[NRBYTE][NRBIT];

    int i, j;
    int byteTmp;
    int match;
    char junk;
    int ris;

    do{
        /* ####################### 
        # SEZIONE SUBNET MASK #
        #######################
        */
        for(i=0; i<NRBYTE; i++){
            printf("Inserisci il %d byte: ", i+1);
            scanf("%d", &subnetByte[i]);
            junk = getchar(); // equivalente della fflush che non funziona su Codespace
        }
        printf("Subnet impostata: %d.%d.%d.%d\n", subnetByte[0], subnetByte[1], subnetByte[2], subnetByte[3]);
        // Converto la subnet in bit
        for(i=0; i<NRBYTE; i++){
            byteTmp = subnetByte[i];
            for(j=0; j<NRBIT; j++){
                subnetBit[i][j] = byteTmp % 2;
                byteTmp = byteTmp / 2;
            }
        }
        /*
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                printf("%d", subnetBit[i][j]);
            }
            if(i<3){
                printf(".");
            }
        }*/

        /* ####################### 
        #    SEZIONE IP 1     #
        #######################
        */
        printf("\n-- Inserimento del primo IP --\n");
        for(i=0; i<NRBYTE; i++){
            printf("Inserisci il %d byte: ", i+1);
            scanf("%d", &IpUnoByte[i]);
            junk = getchar(); // equivalente della fflush che non funziona su Codespace
        }
        printf("IP1 Inserito: %d.%d.%d.%d\n", IpUnoByte[0], IpUnoByte[1], IpUnoByte[2], IpUnoByte[3]);
        for(i=0; i<NRBYTE; i++){
            byteTmp = IpUnoByte[i];
            for(j=0; j<NRBIT; j++){
                IpUnoBit[i][j] = byteTmp % 2;
                byteTmp = byteTmp / 2;
            }
        }
        // eseguo AND logico tra IP1 e Subnet
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                if(IpUnoBit[i][j] == 1 && subnetBit[i][j] == 1)
                    ipUnoAndMask[i][j] = 1;
                else
                    ipUnoAndMask[i][j] = 0;
            }
        }
        /*
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                printf("%d", IpUnoBit[i][j]);
            }
            if(i<3){
                printf(".");
            }
        }*/
        

        /* ####################### 
        #    SEZIONE IP 2     #
        #######################
        */
        printf("\n-- Inserimento del Secondo IP --\n");
        for(i=0; i<NRBYTE; i++){
            printf("Inserisci il %d byte: ", i+1);
            scanf("%d", &IpDueByte[i]);
            junk = getchar(); // equivalente della fflush che non funziona su Codespace
        }
        printf("IP2 Inserito: %d.%d.%d.%d\n", IpDueByte[0], IpDueByte[1], IpDueByte[2], IpDueByte[3]);
        for(i=0; i<NRBYTE; i++){
            byteTmp = IpDueByte[i];
            for(j=0; j<NRBIT; j++){
                IpDueBit[i][j] = byteTmp % 2;
                byteTmp = byteTmp / 2;
            }
        }
        // eseguo AND logico tra IP2 e Subnet
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                if(IpDueBit[i][j] == 1 && subnetBit[i][j] == 1)
                    ipDueAndMask[i][j] = 1;
                else
                    ipDueAndMask[i][j] = 0;
            }
        }
        /*
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                printf("%d", IpDueBit[i][j]);
            }
            if(i<3){
                printf(".");
            }
        }*/
        
        /*  ####################### 
            # STAMPE IP e AND     #
            #######################
        */
        printf("\n\tIP1 su 32bit:\n");
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                printf("%d", IpUnoBit[i][j]);
            }
            if(i<3){
                printf(".");
            }
        }
        printf("\n\tIP2 su 32bit:\n");
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                printf("%d", IpDueBit[i][j]);
            }
            if(i<3){
                printf(".");
            }
        }
        // Visualizzo gli AND logici
        printf("\n\n\tIP1 and Subnet Mask:\n");
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                printf("%d", ipUnoAndMask[i][j]);
            }
            if(i<3){
                printf(".");
            }
        }
        printf("\n\tIP2 and Subnet Mask:\n");
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                printf("%d", ipDueAndMask[i][j]);
            }
            if(i<3){
                printf(".");
            }
        }

        /*  ####################### 
            # CHECK AND LOGICI    #
            #######################
        */
        match = 1;
        for(i=0; i<NRBYTE; i++){
            for(j=NRBIT-1; j>=0; j--){
                if(ipUnoAndMask[i][j] != ipDueAndMask[i][j])
                    match = 0;
            }
        }
        printf("\n\nRISULTATO del CONTROLLO:\n");
        if(match == 1)
            printf("-- I due IP comunicano tra loro, esegui un ping e verifica! --");
        else
            printf("-- I due IP non comunicano tra loro con questa Subnet Mask! --");
        
        printf("\n\n--> Altro match da verificare?(1->si, 0->no): ");
        scanf("%d", &ris);
        junk = getchar();
    }while(ris!=0);
    return(0);
}
