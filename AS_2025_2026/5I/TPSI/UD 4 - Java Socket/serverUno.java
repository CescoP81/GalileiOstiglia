import java.io.*;
import java.net.*;

public class serverUno {
    public static void main(String[] args) throws IOException{
        int port = 9876;
        ServerSocket ss = new ServerSocket(port);
        System.out.println("In attesa sulla porta "+port);

        Socket socket = ss.accept();
        InputStream is = socket.getInputStream();
        OutputStream os = socket.getOutputStream();

        os.write("ServerSocket ti sta ascoltando...".getBytes());
    }    
}