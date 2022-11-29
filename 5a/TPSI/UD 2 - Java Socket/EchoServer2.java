import java.util.Arrays;
import java.net.*;
import java.io.*;

class EchoServer2 {
	public static void log(Object... args) {
		System.err.println(Arrays.toString(args));
	}
	public static void main(String ars[]) throws IOException {
		int port = 9876;
        String lineInSS;
        String lineOutSS;
        ServerSocket ss = new ServerSocket(port); // crea server socket
		
        log("accepting connections on port " + port);
		Socket socket = ss.accept(); // aspettiamo connessione client
		InputStream is = socket.getInputStream();
		OutputStream os = socket.getOutputStream();
        BufferedReader bf = new BufferedReader(new InputStreamReader(is));
        
        do{
		    os.write("hello, I'm EchoServer!\r\n".getBytes());
            os.write("Insert a string: ".getBytes());
		    lineInSS = new String(bf.readLine());
		    lineOutSS = "You said "+lineInSS+"? ;)\r\n";
		    os.write(lineOutSS.getBytes()); // write reponse
        }while(!lineInSS.equals("ciao!"));
		log("have a nice day... " + socket);
	}
}