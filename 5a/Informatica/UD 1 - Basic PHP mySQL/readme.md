### Nozioni di base in PHP e mySQL   

**/require**   
Cartella contenente file con funzioni o file con spezzoni di codice da includere con il comando require().

**/res**   
Cartella contenente tutto quello che è 'documentazione' ed in particolare:  
- [x] Schema ER in formato *.drawio e *.png
- [x] File sql con creazione tabella (ddl) e popolamento iniziale (dml)
- [x] Eventuali altri file *.pdf di documentazione del progetto.

**p02.php**   
Visualizzazione della tabella 'studenti' presente sul database, con style Bootstrap.  

**p02bis.php**   
Come pagina p02 ma la tabella è stata spostata nel file snippet 'showResultSetTable.php' nella cartella '/require'.   

**p02tris.php**   
Come pagina p02 ma la tabella è stata spostata nella funzione presente nel file 'mylib.php' nella cartella '/require'.  

**studenti.php**  
Pagina che permette le seguenti operazioni sulla tabella 'studenti':  
- [x] Visualizzazione degli studenti presenti.  
- [x] Visualizzazione form inserimento dati nuovo studente.  
- [x] Inserimento effettivo dei dati nella tabella studenti.