import java.util.Arrays;
import java.net.*;
import java.io.*;

class EchoServer {
    public static void log(Object... args) {
        System.err.println(Arrays.toString(args));
    }
    public static void main(String ars[]) throws IOException {
    	int port = 9876;
    	ServerSocket ss = new ServerSocket(port); // crea server socket
    	log("accepting connections on port " + port);
    	Socket socket = ss.accept(); // aspettiamo connessione client
		InputStream is = socket.getInputStream();
		OutputStream os = socket.getOutputStream();
		os.write("hello, I'm EchoServer!\n".getBytes());
		byte buffer[] = new byte[256];
		is.read(buffer); // wait for client input
		String line = 	new String(buffer);
		// add '?' to input
		line += "?\n";
		os.write(line.getBytes()); // write reponse
        log("have a nice day... " + socket);
    }
}