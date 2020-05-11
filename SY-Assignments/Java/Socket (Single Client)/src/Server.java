import java.io.BufferedReader;
import java.io.DataInputStream;
import java.io.InputStreamReader;
import java.net.ServerSocket;
import java.net.Socket;
import java.util.*;


public class Server {
	
	static Scanner scan = new Scanner(System.in);
	
	public static void main (String[] args) throws Exception{
		ServerSocket serverSocket = new ServerSocket(6969);
		Socket clientSocket = serverSocket.accept();
		System.out.println("Client Connected!");
		
		DataInputStream msgRec = new DataInputStream(clientSocket.getInputStream());
		// BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
		
		while (true) {
			String msg = msgRec.readUTF();
			System.out.println("Client: " + msg);
			if (msg.equalsIgnoreCase("exit")) {
				break;
			}
		}
		clientSocket.close();		
	}
}
