#include <stdlib.h>
#include <stdio.h>
#include <malloc.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <time.h>
#include <Windows.h>

#define C 17			//DIMENSIONE ARENA
#define R 17

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void stampa(char _arena[C][R],int _punteggio, int _n_missili, int _tempo,int livello);

void stampa2(char _arena[C][R],int _n_missili); 

void stampa3(char _arena[C][R],int p1, int p2);

void stampa4(char __arena[C][R],int punti);

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

int main(void){
	
	int flaginizio = 0;				//FLAG DI CONTROLLO PER STAMPA AD AVVIO
	
	inizio:
	
	//VARIABILI DEL GIOCO PRINCIPALE 
	char arena[C][R] = {{' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' ',' '}};
	char P1 = 'S';					//SPRITE DEL GIOCATORE
	char mov;						//PER LA DIREZIONE
	int centrox = 7;				//SPAWN X
	int centroy = 7;				//SPAWN Y
	int flagmela = 0;				//FLAG DELL'OBBIETTIVO
	int flagostacolo = 0;			//FLAG SPAWN OSTACOLI
	int punteggio = 0;				//PUNTEGGIO
	int n_ostacoli = 1;				//NUMERO OSTACOLI
	int n_missili = 0;				//NUMERO MISSILI
	int togli_missili = 0;			//PER DIMINUIRE I MISSILI
	int tempo=60;					//TEMPO IN SECONDI
	int conta_missili = 0;			//FLAG SE I MISSILI VENGONO SPARATI
	int n_passi = 0;				//NUMERO PASSI DEL PLAYER PER SPAWN DEI NEMICI 
	int n_nemici1 = 0;				//NUMERO DEI NEMICI PER CALCOLO DI N_NEMICI 2
	int n_nemici2 = 0;				//NUMERO EFFETTIVO DI NEMICI
	int puntiminigame = 2000;		//PUNTI NECESSARI PER ACCEDERE AL MINIGAME
	int contapuntiminigame = 1;		//CNT PER AUMENTARE I PUNTI NECESSARI PER IL MINIGAME
	

	//VARIABILI DEL PRIMO MINIGIOCO	
	int flagboss = 0;				//FLAG DI CONTROLLO
	int attacco = 0;				//FLAG PER POSIZIONE DELL'ATTACCO
	int contax = 0;					//CALCOLO DEI PUNTI
		
	
	//VARIABILI DEL SECONDO MINIGIOCO
	int punti = 0;					//CONTA PUNTI
	int punti_avversario = 0;		//CONTA PUNTI AVVERSARIO
	char palla = 'O';				//SPRITE DELLA PALLA
	int su = 0;						//FLAG DELLA DIREZIONE
	int giu = 0;					//FLAG DELLA DIREZIONE
	int dx = 0;						//FLAG DELLA DIREZIONE
	int sx = 0;						//FLAG DELLA DIREZIONE
	int movimentox = 0;				//PER MUOVERE L'AVVERSARIO
	
	
	//VARIABILI DEL TERZO MINIGIOCO
	int punteggiosalto = 0;	
	int max = 0;
				
	srand(time(NULL));
	
	if(!flaginizio){
		
		arena[1][3] = 'B';
	arena[1][4] = 'E';									//STAMPA DELLE VARIE SCRITTE DI BENVENUTO E PRE-GAME
	arena[1][5] = 'N';
	arena[1][6] = 'V';
	arena[1][7] = 'E';
	arena[1][8] = 'N';
	arena[1][9] = 'U';
	arena[1][10] = 'T';
	arena[1][11] = 'O';
	arena[1][12] = '!';
		
	arena[5][4] = 'P';
	arena[5][5] = 'R';
	arena[5][6] = 'E';
	arena[5][7] = 'M';
	arena[5][8] = 'I';
	arena[5][10] = 'U';
	arena[5][11] = 'N';
	
	arena[7][3] = 'T';
	arena[7][4] = 'A';
	arena[7][5] = 'S';
	arena[7][6] = 'T';
	arena[7][7] = 'O';
	arena[7][9] = 'P';
	arena[7][10] = 'E';
	arena[7][11] = 'R';
	
	arena[9][3] = 'I';
	arena[9][4] = 'N';
	arena[9][5] = 'I';
	arena[9][6] = 'Z';
	arena[9][7] = 'I';
	arena[9][8] = 'A';
	arena[9][9] = 'R';
	arena[9][10] = 'E';
	arena[9][11] = '.';
	arena[9][12] = '.';
	arena[9][13] = '.';
	
	stampa(arena,punteggio,n_missili,tempo,n_ostacoli);	
	
	getch();
	
	flaginizio = 1;
	
	}
	
	
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	//INIZIO GIOCO PRINCIPALE

giocoprincipale:					//AVREI POTUTO FARE DELLE FUNZIONI CONTENENTI I VARI GIOCHI, MA MI SONO TROVATO MEGLIO NELL'USARE IL GOTO PER QUANTO SIA BLASFEMO
	
	system("CLS");
	
	for(int i = 0;i<17;i++){
		for(int j=0;j<17;j++){		//AZZERAMENTO ARENA
			arena[i][j] = ' ';
		}
	}
	
	arena[centroy][centrox] = P1;	//POSIZIONAMENTO PLAYER
	
	for(;;){
		
		system("CLS");
		stampa(arena,punteggio,n_missili,tempo,n_ostacoli);		//STAMPA ARENA 
		
		if(conta_missili == 0 && punteggio < 2000 && n_missili > 0 && flagmela == 0){
			punteggio = punteggio + 100;
		}
		else if(conta_missili == 0 && punteggio > 2000 && n_missili > 0 && flagmela == 0){		//AGGIUNTA DEI PUNTI CON "MOLTIPLICATORE"
			punteggio = punteggio + 200;
		}
		else if(conta_missili == 0 && punteggio > 5000 && n_missili > 0 && flagmela == 0){
			punteggio = punteggio + 300;
		}
		else if(conta_missili == 0 && punteggio > 10000 && n_missili > 0 && flagmela == 0){
			punteggio = punteggio + 500;
		}
		
		conta_missili = 0;		
		
		if(flagmela == 0){
			punteggio = punteggio + 20*n_nemici2;			//BONUS NEMICI PRESENTI
		}

		if(flagmela == 0 && punteggio > 2000){
			punteggio = punteggio + 10*(tempo/10);
			n_missili = punteggio/500 - togli_missili;		//CALCOLO DEI PUNTI BONUS DATI DAL TEMPO RIMASTO + ASSEGNAMENTO MISSILI
			tempo = 110;
			
		}
		else if(flagmela == 0 && punteggio<2000 && punteggio != 0){
			punteggio = punteggio + 5*(tempo/10);
			tempo = 60;
			n_missili = punteggio/250 - togli_missili;
		}
		else if(flagmela == 0 && punteggio > 5000){
			punteggio = punteggio + 5*(tempo/10);
			tempo = 160;
			n_missili = punteggio/750 - togli_missili;
		}
		
		Sleep(60);
		tempo--;										//DIMINUIZIONE DEL TEMPO
		
		if(tempo == 0 && flagmela == 1){
			goto fine1;									//GAME OVER PER FINE TEMPO
		}
		
		if(punteggio>puntiminigame){					//ACCESSO AI MINIGAME
			
			int random;
			
			contapuntiminigame++;
			puntiminigame = 2000 * contapuntiminigame;	//AUMENTO PUNTI NECESSARI PER ACCEDERVI
			random = 1 + rand()%4;
			
			for(int i = 0;i<17;i++){
				for(int j=0;j<17;j++){		//AZZERAMENTO ARENA
					arena[i][j] = ' ';
				}
			}
			
			arena[5][4] = 'M';
			arena[5][5] = 'I';
			arena[5][6] = 'N';
			arena[5][7] = 'I';				//STAMPA SCHERMATA MINIGAME
			arena[5][8] = 'G';
			arena[5][9] = 'A';
			arena[5][10] = 'M';
			arena[5][11] = 'E';
			arena[5][12] = '!';
		
			system("CLS");
			stampa(arena,punteggio,n_missili,tempo,n_ostacoli);	
			
			for(int i = 0;i<17;i++){
				for(int j=0;j<17;j++){		//AZZERAMENTO ARENA
					arena[i][j] = ' ';
				}
			}
			
			getch();
			
			if(random == 1){
				flagmela = 0;
				flagostacolo = 0;
				goto gioco1;
			}
			else if( random == 2){
				flagmela = 0;							//SCELTA CASUALE DEL MINIGAME
				flagostacolo = 0;
				goto gioco2;
			}
			else if( random == 3){
				flagmela = 0;
				flagostacolo = 0;
				goto gioco3;
			}
			else if( random == 4){
				flagmela = 0;
				flagostacolo = 0;
				goto gioco4;
			}		
		}
		
		if(flagostacolo == 0){							//CONTROLLO SPAWN OSTACOLI
			
			int randomx,randomy,flag = 0;
			
			for(int i=0;i<n_ostacoli;i++){
				do{
					
					flag = 0;
					randomx = rand()%16;
					randomy = rand()%16;
					if(arena[randomx][randomy] != ' ' && arena[randomx+1][randomy] != ' ' && arena[randomx-1][randomy] != ' ' && arena[randomx][randomy+1] != ' ' && arena[randomx][randomy-1] != ' '){
						flag = 1;
					}
					else if(arena[randomx][randomy] != 'S' && arena[randomx+1][randomy] != 'S' && arena[randomx-1][randomy] != 'S' && arena[randomx][randomy+1] != 'S' && arena[randomx][randomy-1] != 'S'){
						flag = 0;
					}
					else{
						flag = 1;				//CONTROLLI PER ASSICURARE IL MIGLIOR SPAWN, SENZA CHE VADA SUL GIOCATORE.
					}
				}while(flag == 1);
				
				arena[randomx][randomy] = '0';
				arena[randomx+1][randomy] = '0';
				arena[randomx-1][randomy] = '0';	//SPAWN DEGLI OSTACOLI
				arena[randomx][randomy+1] = '0';
				arena[randomx][randomy-1] = '0';
			}
			flagostacolo = 1;
		}
		
		if(flagmela == 0){
			
			int randomx,randomy;
			
			do{
				randomx = rand()%16;
				randomy = rand()%16;
			}while(arena[randomx][randomy] != ' ');
			
			arena[randomx][randomy] = 'Y';			//SPAWN OBBIETTIVO SECONDARIO CON OPPORTUNI CONTROLLI
		}
		
		if(flagmela == 0){
			
			int randomx,randomy;
			
			do{
				randomx = rand()%16;
				randomy = rand()%16;
			}while(arena[randomx][randomy] != ' ');	//SPAWN OBBIETTIVO PRINCIPALE CON OPPORTUNI CONTROLLI
			
			arena[randomx][randomy] = 'X';
			flagmela = 1;
		
		}
		
		if(kbhit()){								//INIZIO MOVIMENTO IN GAME
			
			int randomx,randomy,flagnemico = 0;
			
			if(n_passi%3 == 0){
				for(int i=0;i<n_nemici2;i++){
					
					do{
						randomx = rand()%16;		//SPAWN DEI NEMICI CON CONTROLLI
						randomy = rand()%16;
				}while(arena[randomx][randomy] != ' ' || arena[randomx][randomy] == '0' || arena[randomx][randomy] == 'X' || arena[randomx][randomy] == P1);
			
				arena[randomx][randomy] = 'x';
				}
			}
			mov = getch();
			fflush(stdin);
	
			if(mov == 'a'){
				n_passi++;
				arena[centroy][centrox] = ' ';		//MOVIMENTI NELLE VARIE DIREZIONI CON CONTROLLI PER VEDERE SE VENGONO SUPERATI I BORDI
				centrox--;
				if(centrox<0){
					goto fine1;
				}
			}
			else if(mov == 'd'){
				n_passi++;
				arena[centroy][centrox] = ' ';
				centrox++;
				if(centrox>16){
					goto fine1;
				}
			}	
			else if(mov == 'w'){
				n_passi++;
				arena[centroy][centrox] = ' ';
				centroy--;
				if(centroy<0){
					goto fine1;
				}
			}
			else if(mov == 's'){
				n_passi++;
				arena[centroy][centrox] = ' ';
				centroy++;
				if(centroy>16){
					goto fine1;
				}	
			}
		
			
			else if(mov == 'j'){					//MOVIMENTO DIREZIONE MISSILI
				if(n_missili>0){
					togli_missili++;
					conta_missili = 1;
					tempo--;
				
					for(int i = centrox-1;i>=0;i--){
						tempo--;
						if(arena[centroy][i] == '0'){
							punteggio = punteggio + 10;
							arena[centroy][i] = '+';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);			//CONTROLLO SE BECCA UN OSTACOLO
							arena[centroy][i] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
						}
						else if(arena[centroy][i] == 'x'){
							punteggio = punteggio + 30;
							arena[centroy][i] = '@';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);			//CONTROLLO SE BECCA UN NEMICO
							arena[centroy][i] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							break;
						}
						else if(arena[centroy][i] == 'X'){
							goto fine1;													//CONTROLLO SE BECCA L'OBBIETTIVO PRINCIPALE
						}
						else if(arena[centroy][i] == 'Y'){
							punteggio = punteggio - 100;
							arena[centroy][i] = 184;
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);			//CONTROLLO SE BECCA L'OBBIETTIVO SECONDARIO
							arena[centroy][i] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							break;
						}
						else{
							arena[centroy][i] = '-';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);			//OGNI INTERAZIONE DEL MISSILE CON UN OGGETTO CAUSA UN ANIMAZIONE SPECIFICA
							arena[centroy][i] = ' ';									//IL CODICE SI RIPETE PRATICAMENTE PER TUTTE LE 4 DIREZIONI MA IN MODO DIVERSO
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
						}
					}
				}
			}
			
			
			else if(mov == 'l'){
			
				if(n_missili > 0){
				
					togli_missili++;
					conta_missili = 1;
					tempo--;
				
					for(int i = centrox+1;i<=16;i++){
					
						tempo--;
					
						if(arena[centroy][i] == '0'){
						
							punteggio = punteggio + 10;
						
							arena[centroy][i] = '+';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[centroy][i] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
						}
						else if(arena[centroy][i] == 'x'){
						
							punteggio = punteggio + 30;
						
							arena[centroy][i] = '@';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[centroy][i] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							break;
						}
						else if(arena[centroy][i] == 'X'){
							goto fine1;
						}
						else if(arena[centroy][i] == 'Y'){
						
							punteggio = punteggio - 100;
						
							arena[centroy][i] = 184;
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[centroy][i] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							break;
						}
						else{
						
							arena[centroy][i] = '-';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[centroy][i] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
						}
					}
				}
			}
			
			else if(mov == 'i'){
			
				if(n_missili > 0){
				
					togli_missili++;
					conta_missili = 1;
					tempo--;
				
					for(int i = centroy-1;i>=0;i--){
					
						tempo--;
					
						if(arena[i][centrox] == '0'){
						
							punteggio = punteggio + 10;
						
							arena[i][centrox] = '+';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[i][centrox] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
						}
						else if(arena[i][centrox] == 'x'){
						
							punteggio = punteggio + 30;
						
							arena[i][centrox] = '@';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[i][centrox] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							break;
						}
						else if(arena[i][centrox] == 'X'){
						
							goto fine1;
						}	
						else if(arena[i][centrox] == 'Y'){
					
							punteggio = punteggio - 100;
						
							arena[i][centrox] = 184;
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[i][centrox] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							break;
						}
						else{
						
							arena[i][centrox] = 221;
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[i][centrox] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
						}
					}
				}
			}

			else if(mov == 'k'){
			
				if(n_missili > 0){
				
					togli_missili++;
					conta_missili = 1;
					tempo--;
				
					for(int i = centroy+1;i<=16;i++){
					
						tempo--;
					
						if(arena[i][centrox] == '0'){
						
							punteggio = punteggio + 10;
						
							arena[i][centrox] = '+';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[i][centrox] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
						}
						else if(arena[i][centrox] == 'x'){
						
							punteggio = punteggio + 30;
						
							arena[i][centrox] = '@';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[i][centrox]= ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							break;
						}
						else if(arena[i][centrox] == 'X'){
					
							goto fine1;
						}
						else if(arena[i][centrox] == 'Y'){
						
							punteggio = punteggio - 100;
						
							arena[i][centrox] = 184;
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[i][centrox] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							break;
						}
						else{
						
							arena[i][centrox] = 221;
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
							arena[i][centrox] = ' ';
							system("CLS");
							stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
						}
					}
				}
			}
		
			if(arena[centroy][centrox] == 'X'){				//INIZIO CONTROLLI SUL GIOCATORE E IL SUO CONTATTO CON GLI OGGETTI NELL'ARENA
			
				flagmela = 0;
				flagostacolo = 0;
				punteggio = punteggio + 150;				//SE GIOCATORE PRENDE X
			
				for(int i=0;i<C;i++){
				
					for(int j=0;j<R;j++){
						arena[i][j] = ' ';
					}
				}
			
				punteggio = punteggio + 15 * n_ostacoli;	//MOLTIPLICATORE PUNTI PER OSTACOLI E AUMENTO DI N_NEMICI PER IL CALCOLO POI DEI NEMICI EFFETTIVI
			
				n_ostacoli++;
				n_nemici1++;
				
				if(n_nemici1%5 == 0){
				
					n_nemici2++;
				}
			}
			if(arena[centroy][centrox] == 'Y'){
			
				punteggio = punteggio+100;					//SE GIOCATORE PRENDE Y 
			}
			else if(arena[centroy][centrox] == 'x'){		//SE GIOCATORE PRENDE IL NEMICO
				goto fine1;
			}
			else if(arena[centroy][centrox] == '0'){		//SE GIOCATORE PRENDE L'OSTACOLO
				goto fine1;
			}
			arena[centroy][centrox] = P1;					//MOVIMENTO DEL GIOCATORE
			}
	}
	
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
	
	fine1:													//GAME OVER
		
		for(;;){
			
			system("CLS");
				
			for(int i=0;i<C;i++){
				for(int j=0;j<R;j++){
					arena[i][j] = ' ';						//AZZERAMENTO
					
				}
			}
		
		arena[1][3] = 'G';
		arena[1][4] = 'A';									//STAMPA DELLE VARIE SCRITTE DI FINE GAME
		arena[1][5] = 'M';
		arena[1][6] = 'E';
		
		arena[1][8] = 'O';
		arena[1][9] = 'V';
		arena[1][10] = 'E';
		arena[1][11] = 'R';
		arena[1][12] = '!';
		
		arena[3][3] = 'P';
		arena[3][4] = 'U';
		arena[3][5] = 'N';
		arena[3][6] = 'T';
		arena[3][7] = 'E';
		arena[3][8] = 'G';
		arena[3][9] = 'G';
		arena[3][10] = 'I';
		arena[3][11] = 'O';
		arena[3][12] = ':';
		
		char displaypunteggio[6] = {' ',' ',' ',' ',' '};
		
		itoa(punteggio,displaypunteggio,10);				//CONVERSIONE PUNTEGGIO IN STRINGA PER STAMPA
		
		arena[5][6] = displaypunteggio[0];
		arena[5][7] = displaypunteggio[1];
		arena[5][8] = displaypunteggio[2];
		arena[5][9] = displaypunteggio[3];
		arena[5][10] = displaypunteggio[4];
		
		if(punteggio<2500){
			
			arena[7][4] = 'P';
			arena[7][5] = 'A';
			arena[7][6] = 'T';								//SCRITTE IN BASE AL PUNTEGGIO
			arena[7][7] = 'E';
			arena[7][8] = 'T';
			arena[7][9] = 'I';
			arena[7][10] = 'C';
			arena[7][11] = 'O';
		}
		else if(punteggio<5000){
			
			arena[7][5] = 'S';
			arena[7][6] = 'C';
			arena[7][7] = 'A';
			arena[7][8] = 'R';
			arena[7][9] = 'S';
			arena[7][10] = 'O';
		}
		else if(punteggio<7500){
			
			arena[7][5] = 'B';
			arena[7][6] = 'U';
			arena[7][7] = 'O';
			arena[7][8] = 'N';
			arena[7][9] = 'O';
		}
		else if(punteggio<10000){
			
			arena[7][5] = 'O';
			arena[7][6] = 'T';
			arena[7][7] = 'T';
			arena[7][8] = 'I';
			arena[7][9] = 'M';
			arena[7][10] = 'O';
		}
		else if(punteggio<20000){
			
			arena[7][5] = 'E';
			arena[7][6] = 'P';
			arena[7][7] = 'I';
			arena[7][8] = 'C';
			arena[7][9] = 'O';
		}
		else if(punteggio<20000){
			
			arena[7][4] = 'L';
			arena[7][5] = 'E';
			arena[7][6] = 'G';
			arena[7][7] = 'G';
			arena[7][8] = 'E';
			arena[7][9] = 'N';
			arena[7][10] = 'D';
			arena[7][11] = 'A';
		}
		
		arena[10][4] = 'A';
		arena[10][5] = 'N';
		arena[10][6] = 'C';
		arena[10][7] = 'O';
		arena[10][8] = 'R';
		arena[10][9] = 'A';
		
		arena[10][10] = '=';
		arena[10][11] = '1';
		
		arena[12][4] = 'U';
		arena[12][5] = 'S';
		arena[12][6] = 'C';
		arena[12][7] = 'I';
		arena[12][8] = 'T';
		arena[12][9] = 'A';
		
		arena[12][10] = '=';
		arena[12][11] = '0';
		
		stampa(arena,punteggio,n_missili,tempo,n_ostacoli);
		
		char scelta;
		
		scelta = getch();
		
		if(scelta == '1'){
			goto inizio;			//RICOMINCIA
		}
		else if(scelta == '0'){
			return 0;				//ESCI
		}
		
	}
	
//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
		
	gioco1: 						//INIZIO MINIGIOCO 1
	
		centrox = 7;				//RIMPOSTAZIONE DEL CENTRO
		centroy = 7;
		
		contax = 0;					
		
			for(;;){
				
				if(contax == 5){
					punteggio = punteggio + 1500;
					system("CLS");					//SE MINIGIOCO COMPLETATO TORNA A MAIN 
					goto giocoprincipale;
				}
				
				system("CLS");
				
				for(int i=0;i<C;i++){
					for(int j=0;j<R;j++){			//AZZERAMENTO
						arena[i][j] = ' ';
					}
				}
				arena[centroy][centrox] = P1;
				system("CLS");
				stampa2(arena,contax);
		
				Sleep(60);
				
				if(flagboss == 0){				//INIZIO FASE ATTACCO 
					attacco = 1+rand()%4;
				}
				
				if(flagboss == 0 && attacco == 1){							//DALL'ALTO
			
					int random;
			
					for(int i=0;i<10;i++){
						do{
							random = rand()%16; 
						}while(arena[0][random] != ' ' || arena[0][random] == 'o');				//CONTROLLI PER SPAWN DEGLI ATTACCHI E DELLA X
							arena[0][random] = 'o';												//SI RIPETONO ANCHE PER IL RESTO CON QUALCHE VARIAZIONE
					}
					do{
						random = rand()%16;
					}while(arena[0][random] != ' ' || arena[0][random] == 'o');
					
						arena[0][random] = 'X';													
						
					flagboss = 1;
				}

				else if(flagboss == 0 && attacco == 2){				//DA SINISTRA
			
					int random;
			
					for(int i=0;i<10;i++){
				
						do{
							random = rand()%16;
						}while(arena[random][0] != ' ' || arena[random][0] == 'o');  
				
							arena[random][0] = 'o';
					}
					
					do{
					
						random = rand()%16;
					
					}while(arena[random][0] != ' ' || arena[random][0] == 'o');
					
					arena[random][0] = 'X';
			
					flagboss = 1;
				}

				else if(flagboss == 0 && attacco == 3){				//DAL BASSO
			
					int random;
			
					for(int i=0;i<10;i++){
				
						do{
					
							random = rand()%16;
					
						}while(arena[16][random] != ' ' || arena[16][random] == 'o');
				
						arena[16][random] = 'o';
					}
					
					do{
					
						random = rand()%16;
					
					}while(arena[16][random] != ' ' || arena[16][random] == 'o');
					
					arena[16][random] = 'X';
			
					flagboss = 1;
				}

				else if(flagboss == 0 && attacco == 4){				//DA DESTRA
			
					int random;
			
					for(int i=0;i<10;i++){
				
						do{
					
							random = rand()%16;
					
						}while(arena[random][16] != ' ' || arena[random][16] == 'o');
				
							arena[random][16] = 'o';
					}
					
					do{
					
						random = rand()%16;
					
					}while(arena[random][16] != ' ' || arena[random][16] == 'o');
					
					arena[random][16] = 'X';
			
					flagboss = 1;
				}

				if(attacco == 1 && flagboss == 1){					//CONTROLLO PER MOVIMENTO DEGLI ATTACCHI PRATICAMENTE IDENTICO AL GIOCO PRINCIPALE
			
					for(int i=0;i<16;i++){
			
					Sleep(30);
					system("CLS");
					stampa2(arena,contax);
			
					for(int j=0;j<16;j++){
					
						if(arena[i][j] == 'X'){
							
							arena[i][j] = ' ';						//SPOSTAMENTO DELLA X E DELLE o
							arena[i+1][j] = 'X';
						}
				
						if(arena[i][j] == 'o'){
					
							arena[i][j] = ' ';
					
							arena[i+1][j] = 'o';
					
							if(kbhit()){
								mov = getch();
								fflush(stdin);
							
								if(mov == 'a'){						//PER MUOVERSI MENTRE GLI ATTACCHI SI SPOSTANO
			
									arena[centroy][centrox] = ' ';
									centrox--;
									if(centrox<0){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 'd'){
								
									arena[centroy][centrox] = ' ';
									centrox++;
									if(centrox>16){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 'w'){
									
									arena[centroy][centrox] = ' ';
									centroy--;
									if(centroy<0){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 's'){
									
									arena[centroy][centrox] = ' ';
									centroy++;
									
									if(centroy>16){
										system("CLS");
										goto giocoprincipale;
									}
								}
							}
						}
					}
		
						if(arena[centroy][centrox] == 'o'){
					
							punteggio = punteggio + 250*contax;
							system("CLS");									//IN CASO IL GIOCATORE SI SCONTRA CON LE o
							goto giocoprincipale;
						}
						if(arena[centroy][centrox] == 'X'){				
							contax++;										//SE BECCA LE X
						}
						arena[centroy][centrox] = P1;
					}
		
					for(int i = 0;i<16;i++){								//DA QUI IN POI E' PRATICAMENTE IDENTICO PER ANCHE LE ALTRE DIREZIONI
						arena[16][i] = ' ';
					}
					flagboss = 0;
				}
			
		else if(attacco == 2 && flagboss == 1){
			
			for(int i=0;i<16;i++){
			
				Sleep(30);
				system("CLS");
				stampa2(arena,contax);
			
				for(int j=0;j<16;j++){
					
					if(arena[j][i] == 'X'){
							
							arena[j][i] = ' ';
							arena[j][i+1] = 'X';
					}
				
					if(arena[j][i] == 'o'){
					
						arena[j][i] = ' ';
					
						arena[j][i+1] = 'o';
					
						if(kbhit()){
							mov = getch();
							fflush(stdin);
							
								if(mov == 'a'){
			
									
									arena[centroy][centrox] = ' ';
									centrox--;
									if(centrox<0){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 'd'){
									
									arena[centroy][centrox] = ' ';
									centrox++;
									if(centrox>16){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 'w'){
									
									arena[centroy][centrox] = ' ';
									centroy--;
									if(centroy<0){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 's'){
									
									arena[centroy][centrox] = ' ';
									centroy++;
									if(centroy>16){
										system("CLS");
										goto giocoprincipale;
									}
								}
						}
					}
				}
				
				if(arena[centroy][centrox] == 'o'){
					
					punteggio = punteggio + 250*contax;
					goto giocoprincipale;
				}
				if(arena[centroy][centrox] == 'X'){
					contax++;
				}
				
				arena[centroy][centrox] = P1;
			}
		
			for(int i = 0;i<16;i++){
				arena[i][16] = ' ';
			}
			flagboss = 0;
		}
		
		else if(attacco == 3 && flagboss == 1){
			
			for(int i=16;i>=0;i--){
			
				Sleep(30);
				system("CLS");
				stampa2(arena,contax);
			
				for(int j=0;j<16;j++){
					
					if(arena[i][j] == 'X'){
							
							arena[i][j] = ' ';
							arena[i-1][j] = 'X';
					}
				
					if(arena[i][j] == 'o'){
					
						arena[i][j] = ' ';
					
						arena[i-1][j] = 'o';
						
						if(kbhit()){
							mov = getch();
							fflush(stdin);
							
								if(mov == 'a'){
			
									
									arena[centroy][centrox] = ' ';
									centrox--;
									if(centrox<0){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 'd'){
									
									arena[centroy][centrox] = ' ';
									centrox++;
									if(centrox>16){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 'w'){
									
									arena[centroy][centrox] = ' ';
									centroy--;
									if(centroy<0){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 's'){
									
									arena[centroy][centrox] = ' ';
									centroy++;
									if(centroy>16){
										system("CLS");
										goto giocoprincipale;
									}
								}
						}
					}
				}
				if(arena[centroy][centrox] == 'o'){
					
					
					punteggio = punteggio + 250*contax;
					system("CLS");
					goto giocoprincipale;
				}
				if(arena[centroy][centrox] == 'X'){
					contax++;
				}
				arena[centroy][centrox] = P1;
			}
		
			for(int i = 0;i<=16;i++){
				arena[i][0] = ' ';
			}
			flagboss = 0;
		}

		else if(attacco == 4 && flagboss == 1){
			
			for(int i=16;i>=0;i--){
			
				Sleep(10);
				system("CLS");
				stampa2(arena,contax);
			
				for(int j=0;j<16;j++){
					
					if(arena[j][i] == 'X'){
							
							arena[j][i] = ' ';
							arena[j][i-1] = 'X';
					}
				
					if(arena[j][i] == 'o'){
					
						arena[j][i] = ' ';
					
						arena[j][i-1] = 'o';
					
						if(kbhit()){
							mov = getch();
							fflush(stdin);
							
								if(mov == 'a'){
			
									
									arena[centroy][centrox] = ' ';
									centrox--;
									if(centrox<0){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 'd'){
									
									arena[centroy][centrox] = ' ';
									centrox++;
									if(centrox>16){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 'w'){
								
									arena[centroy][centrox] = ' ';
									centroy--;
									if(centroy<0){
										system("CLS");
										goto giocoprincipale;
									}
								}
								else if(mov == 's'){
									
									arena[centroy][centrox] = ' ';
									centroy++;
									if(centroy>16){
										system("CLS");
										goto giocoprincipale;
									}
								}
						}
					}
				}
				if(arena[centroy][centrox] == 'o'){
					
					punteggio = punteggio + 250*contax;
					system("CLS");
					goto giocoprincipale;
				}
				if(arena[centroy][centrox] == 'X'){
					contax++;
				}
		
				arena[centroy][centrox] = P1;
			}
		
			for(int i = 0;i<=16;i++){
				arena[0][i] = ' ';
			}
			flagboss = 0;
		}
		
		system("CLS");
		stampa2(arena,contax);
			
	}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//SECONDO MINIGIOCO 
		
		gioco2:
			
			ricomincia:
				
			su = 0;
			giu = 0;
			dx = 0;					//FLAG DEI MOVIMENTI PER LA PALLA
			sx = 0;
			movimentox = 0;
			
			for(int i=0;i<C;i++){
					for(int j=0;j<R;j++){
						arena[i][j] = ' ';	
					}
				}
			
				arena[8][0] = P1;
				arena[7][0] = P1;
				arena[6][0] = P1;	
				arena[9][0] = P1;
				
				arena[8][16] = 'X';
				arena[7][16] = 'X';
				arena[6][16] = 'X';			//SPAWN DELLE BARRE DI GIOCO
				arena[9][16] = 'X';
				
				arena[7][1] = palla;
			
				dx = 1;
				su = 1;						//INIZIO PALLA 
				
			for(;;){
				
				if(punti == 3){
					
					punteggio = punteggio + 750;
					system("CLS");						//AGGIUNTA DEI PUNTI SE GIOCO COMPLETO
					goto giocoprincipale;
				}
				else if(punti_avversario == 3){
					system("CLS");
					goto giocoprincipale;
				}
				system("CLS");
				
				system("CLS");
				stampa3(arena,punti,punti_avversario);
				
//-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------	
				
				if(dx && su){				//DESTRA E SU 
				
					
					for(int i = 16;i>=0;i--){
						
						movimentox = 1+rand()%2;
							
							if(movimentox == 1){
								
								for(int i=0;i<17;i++){
											
											if(arena[i][16] == 'X'){
												
												if(arena[i-1][16] != ' '){			//SPOSTAMENTO DELLA BARRA AVVERSARIA
													
													break;
												}
												else{
													
													arena[i-1][16] = 'X';
												
													arena[i][16] = ' ';
												}
								
											}
										}
							}
							else{
								
								for(int i=16;i>=0;i--){
											
											if(arena[i][16] == 'X'){
												
												if(arena[i+1][16] != ' '){
													
													break;
												}
												
												arena[i+1][16] = 'X';
												
												arena[i][16] = ' ';
								
											}
										}
								
							}
						
						if(kbhit()){
							mov = getch();
							fflush(stdin);
				
								if(mov == 'a'){
									
									
										for(int i=0;i<17;i++){
											
											if(arena[i][0] == P1){
												
												if(arena[i-1][0] != ' '){
																				//SPOSTAMENTO BARRA GIOCATORE CON a E d SIMILE AL GIOCO PRINCIPALE, SI APPLICA PER TUTTE LE OPZIONI SOTTO
													break;
												}
												else{
													
													arena[i-1][0] = P1;
												
													arena[i][0] = ' ';
												}
								
											}
										}
								}
								else if(mov == 'd'){
									
									for(int i=16;i>=0;i--){
											
												
												
											if(arena[i][0] == P1){
												
												
												if(arena[i+1][0] != ' '){
													
													break;
												}
												
												arena[i+1][0] = P1;
												
												arena[i][0] = ' ';
								
											}
										}
								}
					}
						
						for(int j = 0;j<17;j++){
							
							 if(arena[i][j] == palla){
							 	
							 	if(arena[i][j+1] == 'X' && j == 15){
							 		
							 		dx = 0;
							 		
							 		sx = 1;
							 		
							 		int direzione;
							 		
							 		direzione = 1 + rand()%2;				//CICLI PER IL MOVIMENTO DELLA PALLA CON CONTROLLI IN CASO RIMBALZASSE SUI MURI O SULLE BARRE
							 		
							 		if(direzione == 1){
							 			
							 			su = 1;
							 			giu = 0;
									 }
									 else{
									 	giu = 1;
									 	su = 0;
									 }
									 
									 break;
								 }
							 	
							 	if(i==0){
							 		
							 		su = 0;
							 		giu = 1;
							 		break;
								 }
								if(arena[i][j+1] == ' ' && j == 15){
									
									punti++;							//PUNTO SEGNATO
									goto ricomincia;
								}
							 	
							 	system("CLS");
							 	arena[i-1][j+1] = palla;
							 
								arena[i][j] = ' ';
							 	system("CLS");
								stampa3(arena,punti,punti_avversario);
							 }
						}
					}
					
				}
				
				
				
				else if(dx && giu){			//DESTRA E GIU'
					
					for(int i = 0;i<17;i++){
						
						movimentox = 1+rand()%2;
							
							if(movimentox == 1){
								
								for(int i=0;i<17;i++){
											
											if(arena[i][16] == 'X'){
												
												if(arena[i-1][16] != ' '){
													
													break;
												}
												else{
													
													arena[i-1][16] = 'X';
												
													arena[i][16] = ' ';
												}
								
											}
										}
							}
							else{
								
								for(int i=16;i>=0;i--){
											
											if(arena[i][16] == 'X'){
												
												if(arena[i+1][16] != ' '){
													
													break;
												}
												
												arena[i+1][16] = 'X';
												
												arena[i][16] = ' ';
								
											}
										}
								
							}
						
						if(kbhit()){
							mov = getch();
							fflush(stdin);
				
								if(mov == 'a'){
									
									
										for(int i=0;i<17;i++){
											
											if(arena[i][0] == P1){
												
												if(arena[i-1][0] != ' '){
													
													break;
												}
												else{
													
													arena[i-1][0] = P1;
												
													arena[i][0] = ' ';
												}
								
											}
										}
								}
								else if(mov == 'd'){
									
									for(int i=16;i>=0;i--){
											
												
												
											if(arena[i][0] == P1){
												
												
												if(arena[i+1][0] != ' '){
													
													break;
												}
												
												arena[i+1][0] = P1;
												
												arena[i][0] = ' ';
								
											}
										}
								}
					}
						
						for(int j = 0;j<17;j++){
							
							 if(arena[i][j] == palla){
							 	
							 	if(arena[i][j+1] == 'X' && j == 15){
							 		
							 		dx = 0;
							 		
							 		sx = 1;
							 		
							 		int direzione;
							 		
							 		direzione = 1 + rand()%2;
							 		
							 		if(direzione == 1){
							 			
							 			su = 1;
							 			giu = 0;
									 }
									 else{
									 	giu = 1;
									 	su = 0;
									 }
									 
									 break;
								 }
							 	
							 	if(i==16){
							 		
							 		su = 1;
							 		giu = 0;
							 		break;
								 }
								if(arena[i][j+1] == ' ' && j == 15){
									
									punti++;
									goto ricomincia;
								}
							 	
							 	system("CLS");
							 	arena[i+1][j+1] = palla;
								arena[i][j] = ' ';
							 	system("CLS");
								stampa3(arena,punti,punti_avversario);
							 }
						}
					}
					
				}
				
				
				else if(sx && su){				//SINISTRA E SU 
				
					for(int i = 16;i>=0;i--){
						
						movimentox = 1+rand()%2;
							
							if(movimentox == 1){
								
								for(int i=0;i<17;i++){
											
											if(arena[i][16] == 'X'){
												
												if(arena[i-1][16] != ' '){
													
													break;
												}
												else{
													
													arena[i-1][16] = 'X';
												
													arena[i][16] = ' ';
												}
								
											}
										}
							}
							else{
								
								for(int i=16;i>=0;i--){
											
											if(arena[i][16] == 'X'){
												
												if(arena[i+1][16] != ' '){
													
													break;
												}
												
												arena[i+1][16] = 'X';
												
												arena[i][16] = ' ';
								
											}
										}
								
							}
						
						if(kbhit()){
							mov = getch();
							fflush(stdin);
				
								if(mov == 'a'){
									
									
										for(int i=0;i<17;i++){
											
											if(arena[i][0] == P1){
												
												if(arena[i-1][0] != ' '){
													
													break;
												}
												else{
													
													arena[i-1][0] = P1;
												
													arena[i][0] = ' ';
												}
								
											}
										}
								}
								else if(mov == 'd'){
									
									for(int i=16;i>=0;i--){
											
												
												
											if(arena[i][0] == P1){
												
												
												if(arena[i+1][0] != ' '){
													
													break;
												}
												
												arena[i+1][0] = P1;
												
												arena[i][0] = ' ';
								
											}
										}
								}
					}
						
						for(int j = 16;j>=0;j--){
							
							 if(arena[i][j] == palla){
							 	
							 	if(arena[i][j-1] == 'S' && j == 1){
							 		
							 		dx = 1;
							 		
							 		sx = 0;
							 		
							 		int direzione;
							 		
							 		direzione = 1 + rand()%2;
							 		
							 		if(direzione == 1){
							 			
							 			su = 1;
							 			giu = 0;
									 }
									 else{
									 	giu = 1;
									 	su = 0;
									 }
									 
									 break;
								 }
							 	
							 	if(i==0){
							 		
							 		su = 0;
							 		giu = 1;
							 		break;
								 }
								if(arena[i][j-1] == ' ' && j == 1){
									
									punti_avversario++;
									goto ricomincia;
								}
							 	
							 	system("CLS");
							 	arena[i-1][j-1] = palla;
							 
								
								
								arena[i][j] = ' ';
							 	system("CLS");
								stampa3(arena,punti,punti_avversario);
							 }
						}
					}
					
				}

				else if(sx && giu){				//SINISTRA E GIU
					
					for(int i = 0;i<17;i++){
						
							movimentox = 1+rand()%2;
							
							if(movimentox == 1){
								
								for(int i=0;i<17;i++){
											
											if(arena[i][16] == 'X'){
												
												if(arena[i-1][16] != ' '){
													
													break;
												}
												else{
													
													arena[i-1][16] = 'X';
												
													arena[i][16] = ' ';
												}
								
											}
										}
							}
							else{
								
								for(int i=16;i>=0;i--){
											
											if(arena[i][16] == 'X'){
												
												if(arena[i+1][16] != ' '){
													
													break;
												}
												
												arena[i+1][16] = 'X';
												
												arena[i][16] = ' ';
								
											}
										}
								
							}
						
						
							if(kbhit()){
							mov = getch();
							fflush(stdin);
				
								if(mov == 'a'){
									
									
										for(int i=0;i<17;i++){
											
											if(arena[i][0] == P1){
												
												if(arena[i-1][0] != ' '){
													
													break;
												}
												else{
													
													arena[i-1][0] = P1;
												
													arena[i][0] = ' ';
												}
								
											}
										}
								}
								else if(mov == 'd'){
									
									for(int i=16;i>=0;i--){
											
												
												
											if(arena[i][0] == P1){
												
												
												if(arena[i+1][0] != ' '){
													
													break;
												}
												
												arena[i+1][0] = P1;
												
												arena[i][0] = ' ';
								
											}
										}
								}
					}
						
						for(int j = 16;j>=0;j--){
							
							 if(arena[i][j] == palla){
							 	
							 	if(arena[i][j-1] == 'S' && j == 1){
							 		
							 		dx = 1;
							 		
							 		sx = 0;
							 		
							 		int direzione;
							 		
							 		direzione = 1 + rand()%2;
							 		
							 		if(direzione == 1){
							 			
							 			su = 1;
							 			giu = 0;
									 }
									 else{
									 	giu = 1;
									 	su = 0;
									 }
									 
									 break;
								 }
							 	
							 	if(i==16){
							 		
							 		su = 1;
							 		giu = 0;
							 		break;
								 }
								if(arena[i][j-1] == ' ' && j == 1){
									
									punti_avversario++;
									goto ricomincia;
								}
							 	
							 	system("CLS");
							 	arena[i+1][j-1] = palla;
							 
								
								
								arena[i][j] = ' ';
							 	system("CLS");
								stampa3(arena,punti,punti_avversario);
							 }
						}
					}
					
				}
			}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

		//TERZO MINIGIOCO 
		
		gioco3:
				
				for(int i=0;i<C;i++){
					for(int j=0;j<R;j++){
						arena[i][j] = ' ';		//AZZERAMENTO 
					}
				}
				
				system("CLS");
				stampa4(arena,punteggiosalto);
				
				arena[7][2] = P1;				//SPAWN DEL GIOCATORE
				
					
				for(;;){	
				
					ricominciasalto:
						
					int flagx = 0;
				
					if(flagx == 0){
						
							max = rand()%12;
				
								for(int i = 0;i<max;i++){
									
									arena[i][16] = 'X';
					
								if(i+1 == max){					//GENERAZIONE CASUALE DEGLI OSTACOLI CON 3 BUCHI PER PERMETTERE AL GIOCATORE DI PASSARE
						
									for(int j=max+3;j<17;j++){
							
										arena[j][16] = 'X';
									}
								}
					

							}
						
						flagx = 1;
					}
					

					if(flagx == 1){
					
					for(int y=16;y>=0;y--){
					
					if(kbhit()){
						
						mov = getch();
						fflush(stdin);
						
					}
							
						if(mov == 'a'){								//CICLI PER MOVIMENTO DEL GIOCATORE
							
							for(int i = 0;i<17;i++){
							
							if(arena[i][2] == P1){					//PER ANDAR IN SU
								
								
								if(i-1<0){
									
									break;
								}
								
								if(arena[i][3] == 'X' || arena[i-1][3] == 'X'){
									
									punteggio = punteggio + punteggiosalto*250;			//AUMENTO DEI PUNTI E RIMOZIONE DELLE VARIE X CON RITORNO ALLO SPAWN DEGLI OSTACOLI
									system("CLS");
									goto giocoprincipale;
								}
								
								arena[i][2] = ' ';
								arena[i-1][2] = P1;
								break;
							}
							
							}
						}
						else{
						
						for(int i = 0;i<17;i++){
							
							if(arena[i][2] == P1){			//PER ANDAR IN GIU'
								
								if(i+1 >16){
							
									break;
								}
								if(arena[i][3] == 'X' || arena[i+1][3] == 'X' ){
									
									punteggio = punteggio + punteggiosalto*250;
									system("CLS");
									goto giocoprincipale;
								}
								
								arena[i][2] = ' ';
								arena[i+1][2] = P1;
								
								
								break;
								
							}
					}
				}
					
					for(int z = 16;z>=0;z--){
						
						if(arena[z][y] == 'X'){
							
							if(y-1<0){
								
								punteggiosalto++;
								
								for(int i=0;i<17;i++){			//MOVIMENTO DEGLI OSTACOLI
									
									arena[i][0] = ' ';
								}
								
								flagx = 0;
								goto ricominciasalto;
							}
							
							arena[z][y] = ' ';
							arena[z][y-1] = 'X';
						}
					}
					
					system("CLS");
					stampa4(arena,punteggiosalto);
				}
				
			}
					
				system("CLS");
				Sleep(60);
				stampa4(arena,punteggiosalto);
			}		

//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

			//INIZIO QUARTO MINIGIOCO
					
			gioco4: 
			
			punteggiosalto = 0;
			int flagx = 0;
			
			for(int i=0;i<C;i++){
					for(int j=0;j<R;j++){
						arena[i][j] = ' ';	
					}
				}
				
				arena[7][2] = P1;
				
				for(int i = 0;i<17;i++){
					
					arena[0][i] = 219;
					arena[1][i] = 219;
					arena[2][i] = 219;				//CREAZIONE DEL TUNNEL
					arena[3][i] = 219;
					arena[4][i] = 219;
					arena[5][i] = 219;
					
					
					arena[11][i] = 219;
					arena[12][i] = 219;
					arena[13][i] = 219;
					arena[14][i] = 219;
					arena[15][i] = 219;
					arena[16][i] = 219;
				}
				
				system("CLS");
				stampa4(arena,punteggiosalto);
				
			for(;;){
			
				if(flagx == 0){
						
					max = 1 +  rand()%5;
							
					for(int i=6;i<11;i++){
									
						arena[i][12] = 'X';			//GENERAZIONE DEGLI OSTACOLI
								
					}
						arena[5+max][12] = ' ';
									
						flagx = 1;
					}
				
				if(flagx == 1){
					
					for(int y=12;y>=0;y--){
						
						//INIZIO MOVIMENTO 
						if(kbhit()){
								
								mov = getch();
								fflush(stdin);
					
								if(mov == 'a'){
							
							for(int i = 0;i<17;i++){					//MOVIMENTO PRATICAMENTE IDENTICO AI GIOCHI PRECEDENTI
							
							if(arena[i][2] == P1){
								
								if(i-1<6){
							
									goto fine1;
								}
								
								if(arena[i][3] == 'X' || arena[i-1][3] == 'X'){
									
									punteggio = punteggio + punteggiosalto*150;
									system("CLS");
									goto giocoprincipale;
								}
								
								arena[i][2] = ' ';
								arena[i-1][2] = P1;
								break;
							}
							
							}
						}
						
						else{
						
						for(int i = 0;i<17;i++){
							
							
							
							if(arena[i][2] == P1){
								
								if(i+1>10){
							
									goto fine1;
								}
								if(arena[i][3] == 'X' || arena[i+1][3] == 'X' ){
									
									punteggio = punteggio + punteggiosalto*150;
									system("CLS");
									goto giocoprincipale;
								}
								
								arena[i][2] = ' ';
								arena[i+1][2] = P1;
								
								
								break;
								
							}
					}
		
						}	
					}
					//FINE MOVIMENTO
					
					
					for(int z = 10;z>=5;z--){
						
						if(arena[z][y] == 'X'){
							
							if(arena[z][y-1] == P1){
								
								punteggio = punteggio + 150*punteggiosalto;			//AVANZAMENTO DEGLI OSTACOLI CON IL CALCOLO DEI PUNTEGGI
								
								goto giocoprincipale;
							}
							
							if(y-1<0){
								
								punteggiosalto++;
								
								for(int i=6;i<11;i++){
									
									arena[i][0] = ' ';
								}
								
								flagx = 0;
								break;
							}
							
							arena[z][y] = ' ';
							arena[z][y-1] = 'X';
						}
					}
					
					system("CLS");
					stampa4(arena,punteggiosalto);
				}
				
					
				}
				system("CLS");
				stampa4(arena,punteggiosalto);
			}		
		}


//--------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
							


void stampa(char _arena[C][R],int _punteggio,int _n_missili,int _tempo,int livello){				//STAMPA GIOCO PRINCIPALE
	
	printf("       %c%c",218,196);
	for(int i=0;i<R+1;i++){
		printf("%c%c",196,196);
	}
	printf("%c%c\n",196,191);				

	printf("       %c %c",179,218);
	
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	
	printf("%c %c\n",191,179);
	
	if(livello<10){
		printf("       %c %c LIVELLO = %d                      %c %c",179,179,livello,179,179);
	}
	else{
		printf("       %c %c LIVELLO = %d                     %c %c",179,179,livello,179,179);
	}
	printf("\n");
	if(_punteggio<10){
			printf("       %c %c PUNTEGGIO = %d                    %c %c",179,179,_punteggio,179,179);
	}
	else if(_punteggio<100){
			printf("       %c %c PUNTEGGIO = %d                   %c %c",179,179,_punteggio,179,179);
	}
	else if(_punteggio<1000){
			printf("       %c %c PUNTEGGIO = %d                  %c %c",179,179,_punteggio,179,179);
	}
	else if(_punteggio<10000){
			printf("       %c %c PUNTEGGIO = %d                 %c %c",179,179,_punteggio,179,179);
	}
	else{
			printf("       %c %c PUNTEGGIO = %d                %c %c",179,179,_punteggio,179,179);
	}
	printf("\n");
	if(_n_missili<10){
		printf("       %c %c MISSILI = %d                      %c %c",179,179,_n_missili,179,179);
	}
	else{
		printf("       %c %c MISSILI = %d                     %c %c",179,179,_n_missili,179,179);
	}
	printf("\n");
	if(_tempo/10<10){
		printf("       %c %c TEMPO = %d                        %c %c",179,179,_tempo/10,179,179);
	}
	else{
		printf("       %c %c TEMPO = %d                       %c %c",179,179,_tempo/10,179,179);
	}
	
	printf("\n");
	printf("       %c %c",179,192);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c",217,179);
	printf("\n");
	
	
		
	printf("       %c %c",179,218);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c\n",191,179);

	for(int i=0;i<C;i++){
		
		printf("       %c %c",179,179);
		
		for(int j=0;j<R;j++){
			
			printf("%2c",_arena[i][j]);
		}
	
		printf("%c %c",179,179);
		
		printf("\n");
	}
	
	printf("       %c %c",179,192);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c\n",217,179);
	
	printf("       %c%c%c",192,196,196);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c%c%c\n",196,196,217);
}

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

void stampa2(char _arena[C][R],int _n_missili){			//STAMPA PRIMO MINIGIOCO
	
	printf("       %c%c",218,196);
	for(int i=0;i<R+1;i++){
		printf("%c%c",196,196);
	}
	printf("%c%c\n",196,191);

	printf("       %c %c",179,218);
	
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	
	printf("%c %c\n",191,179);
	
	printf("       %c %c LIVELLO = BOSS BATTLE            %c %c",179,179,179,179);
	
	printf("\n");
	
	printf("       %c %c STAGE = %d                        %c %c",179,179,1,179,179);
	printf("\n");
	
	if(_n_missili==1){
		printf("       %c %c OBBIETTIVI = 1/5                 %c %c",179,179,179,179);
	}
	else if(_n_missili==0){
		printf("       %c %c OBBIETTIVI = 0/5                 %c %c",179,179,179,179);
	}
	else if(_n_missili==2){
		printf("       %c %c OBBIETTIVI = 2/5                 %c %c",179,179,179,179);
	}
	else if(_n_missili==3){
		printf("       %c %c OBBIETTIVI = 3/5                 %c %c",179,179,179,179);
	}
	else if(_n_missili==4){
		printf("       %c %c OBBIETTIVI = 4/5                 %c %c",179,179,179,179);
	}
	else if(_n_missili==5){
		printf("       %c %c OBBIETTIVI = 5/5                 %c %c",179,179,179,179);
	}
	
	printf("\n");

		printf("       %c %c                                  %c %c",179,179,179,179);
	
	printf("\n");
	printf("       %c %c",179,192);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c",217,179);
	printf("\n");
	
	
		
	printf("       %c %c",179,218);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c\n",191,179);

	for(int i=0;i<C;i++){
		
		printf("       %c %c",179,179);
		
		for(int j=0;j<R;j++){
			
			printf("%2c",_arena[i][j]);
		}
	
		printf("%c %c",179,179);
		
		printf("\n");
	}
	
	printf("       %c %c",179,192);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c\n",217,179);
	
	printf("       %c%c%c",192,196,196);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c%c%c\n",196,196,217);
}




void stampa3(char _arena[C][R],int p1, int p2){			//STAMPA SECONDO MINIGIOCO
	
	printf("       %c%c",218,196);
	for(int i=0;i<R+1;i++){
		printf("%c%c",196,196);
	}
	printf("%c%c\n",196,191);

	printf("       %c %c",179,218);
	
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	
	printf("%c %c\n",191,179);
	
	printf("       %c %c LIVELLO = BOSS BATTLE            %c %c",179,179,179,179);
	
	printf("\n");
	
	printf("       %c %c STAGE = %d                        %c %c",179,179,2,179,179);
	printf("\n");
	
	if(p1==1){
		printf("       %c %c I TUOI PUNTI = 1/3               %c %c",179,179,179,179);
	}
	else if(p1==0){
		printf("       %c %c I TUOI PUNTI = 0/3               %c %c",179,179,179,179);
	}
	else if(p1==2){
		printf("       %c %c I TUOI PUNTI = 2/3               %c %c",179,179,179,179);
	}
	else if(p1==3){
		printf("       %c %c I TUOI PUNTI = 3/3               %c %c",179,179,179,179);
	}
	printf("\n");
	
	if(p2==1){
		printf("       %c %c I SUOI PUNTI = 1/3               %c %c",179,179,179,179);
	}
	else if(p2==0){
		printf("       %c %c I SUOI PUNTI = 0/3               %c %c",179,179,179,179);
	}
	else if(p2==2){
		printf("       %c %c I SUOI PUNTI = 2/3               %c %c",179,179,179,179);
	}
	else if(p2==3){
		printf("       %c %c I SUOI PUNTI = 3/3               %c %c",179,179,179,179);
	}
	

		
	
	printf("\n");
	printf("       %c %c",179,192);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c",217,179);
	printf("\n");
	
	
		
	printf("       %c %c",179,218);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c\n",191,179);

	for(int i=0;i<C;i++){
		
		printf("       %c %c",179,179);
		
		for(int j=0;j<R;j++){
			
			printf("%2c",_arena[i][j]);
		}
	
		printf("%c %c",179,179);
		
		printf("\n");
	}
	
	printf("       %c %c",179,192);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c\n",217,179);
	
	printf("       %c%c%c",192,196,196);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c%c%c\n",196,196,217);
}

void stampa4(char _arena[C][R],int punti){					//STAMPA TERZO E QUARTO MINIGIOCO
	
	printf("       %c%c",218,196);
	for(int i=0;i<R+1;i++){
		printf("%c%c",196,196);
	}
	printf("%c%c\n",196,191);

	printf("       %c %c",179,218);
	
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	
	printf("%c %c\n",191,179);
	
	printf("       %c %c LIVELLO = BOSS BATTLE            %c %c",179,179,179,179);
	
	printf("\n");
	
	printf("       %c %c STAGE = %d                        %c %c",179,179,3,179,179);
	printf("\n");
	
	
		printf("       %c %c I TUOI PUNTI = %d                 %c %c",179,179,punti,179,179);
	
	printf("\n");
	
	printf("       %c %c                                  %c %c",179,179,179,179);
	
	printf("\n");
	printf("       %c %c",179,192);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c",217,179);
	printf("\n");
	
	
		
	printf("       %c %c",179,218);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c\n",191,179);

	for(int i=0;i<C;i++){
		
		printf("       %c %c",179,179);
		
		for(int j=0;j<R;j++){
			
			printf("%2c",_arena[i][j]);
		}
	
		printf("%c %c",179,179);
		
		printf("\n");
	}
	
	printf("       %c %c",179,192);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c %c\n",217,179);
	
	printf("       %c%c%c",192,196,196);
	for(int i=0;i<R;i++){
		printf("%c%c",196,196);
	}
	printf("%c%c%c\n",196,196,217);
}



