import java.net.*;
import java.io.*;


public class serverDue{
    public static void main(String[] args) throws IOException{
        int port = 9876; 
        String strIn;
        String strOut;

        ServerSocket ss = new ServerSocket(port);
        System.out.println("Server Socket in attesa del client...");
        Socket socket = ss.accept();

        InputStream is = socket.getInputStream();
        OutputStream os = socket.getOutputStream();
        BufferedReader bf = new BufferedReader(new InputStreamReader(is));

        os.write("Hello sono ServerDue...\n\r".getBytes());
        do{
            os.write("Digita una parola: ".getBytes());
            strIn = new String(bf.readLine());
            strOut = "Hai digitato: "+strIn+"?\r\n";
            os.write(strOut.getBytes());
        }while(strIn.equals((String)"Ciao!") == false);
        
        os.write("Grazie per aver giocato con me!".getBytes());
    }
}
