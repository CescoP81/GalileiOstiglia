import java.util.Arrays;
import java.net.*;
import java.io.*;

class EchoServer2 {
    public static void log(Object... args) {
        System.err.println(Arrays.toString(args));
    }
    public static void main(String ars[]) throws IOException {
        int port = 9876;                                                    // Porta su cui risponde il ServerSocket
        String lineInSS;                                                    // Stringa per la riga letta dal ServerSocket
        String lineOutSS;                                                   // Stringa da pubblicare sul ServerSocket
        ServerSocket ss = new ServerSocket(port);                           // Crea server socket che "ascolta" sulla port
		
        log("accepting connections on port " + port);
        Socket socket = ss.accept();                                        // aspettiamo connessione client -> Telnet 'open localhost 9876'
        InputStream is = socket.getInputStream();                           // Creo un input stream da SocketServer
        OutputStream os = socket.getOutputStream();                         // Creo un output stream su SocketServer
        BufferedReader bf = new BufferedReader(new InputStreamReader(is));  // Creo un BufferedReader per leggere stringhe dall'input stream.
        
        do{                                                                 // entro in un ciclo while finche ServerSocket non riceve "ciao!"
            os.write("hello, I'm EchoServer!\r\n".getBytes());              // ServerSocket manda al client un messaggio (\n line feed, \r carriage return)
            os.write("Insert a string: ".getBytes());                       // ServerSocket manda al client un messaggio
            lineInSS = new String(bf.readLine());                           // Leggo la stringa inserita dal client fino al carattere 'invio'
            lineOutSS = "You said "+lineInSS+"? ;)\r\n";                    // Creo la stringa da rimandare al client.
            os.write(lineOutSS.getBytes());                                 // Scrivo la risposta lineOutSS sul ServerSocket
        }while(!lineInSS.equals("ciao!"));                        // Verifico che ServerSocket non abbia ricevuto la stringa 'ciao!' che lo fa terminare.
        log("have a nice day... " + socket);
    }
}